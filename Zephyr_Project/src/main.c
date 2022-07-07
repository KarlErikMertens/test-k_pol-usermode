
#include <zephyr.h>
#include <sys/printk.h>
#include <kernel.h>
#include <sys/sem.h>
#include <sys/mem_manage.h>
#include <device.h>
#include <app_memory/app_memdomain.h>
#include <drivers/virtualization/ivshmem.h>
#include <app_memory/mem_domain.h>

#define OUTPUT_DEBUG (1)

#if (1 == OUTPUT_DEBUG)
#define DEBUG(...) printk(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

#define STACKSIZE 1000
#define PRIORITY 0

/*typedef struct
{
	struct k_poll_event doorbell_evt;
	struct k_poll_signal doorbell_sig;
} context_k_poll;*/

/*typedef struct
{
	struct k_poll_event *ptr_doorbell_evt;
	struct k_poll_signal *ptr_doorbell_sig;
} context_k_poll;*/

// void thread_routine(struct k_poll_signal *ptr_doorbell_sig, void *param2, void *param3);
//  void thread_routine(void *param1, void *param2, void *param3);
void thread_routine(struct k_poll_signal *ptr_doorbell_sig, struct k_poll_event *ptr_doorbell_evt, void *param3);
//   void thread_routine(context_k_poll *ptr_k_poll_variables, void *param2, void *param3);
//   void thread_routine(context_k_poll *ptr_k_poll_ptr_variables, void *param2, void *param3);

struct k_mem_domain domain;

// struct k_mem_partition evt_part;
// struct k_mem_partition sig_part;

K_APPMEM_PARTITION_DEFINE(evt_part);
K_APPMEM_PARTITION_DEFINE(sig_part);

// K_APPMEM_PARTITION_DEFINE(part);

K_APP_DMEM(evt_part)
struct k_poll_event doorbell_evt;
K_APP_DMEM(sig_part)
struct k_poll_signal doorbell_sig;

/*K_APP_DMEM(part)
context_k_poll k_poll_variables;*/

struct k_thread thread;

K_THREAD_STACK_DEFINE(thread_stack, STACKSIZE);

K_HEAP_DEFINE(thread_heap, 100);

int main(void)
{
	// struct k_poll_event *ptr_doorbell_evt;
	// struct k_poll_signal *ptr_doorbell_sig;

	// context_k_poll *k_poll_ptr_variables;

	// k_poll_ptr_variables->ptr_doorbell_evt = &doorbell_evt;
	// k_poll_ptr_variables->ptr_doorbell_sig = &doorbell_sig;

	struct k_mem_partition *partitions[] = {&evt_part, &sig_part};
	// struct k_mem_partition *partitions[] = {&part};

	/*ptr_doorbell_evt = (struct k_poll_event *)k_mem_map(CONFIG_MMU_PAGE_SIZE, K_MEM_PERM_RW);
	evt_part.start = (uintptr_t)ptr_doorbell_evt;
	evt_part.size = CONFIG_MMU_PAGE_SIZE;
	evt_part.attr = K_MEM_PARTITION_P_RW_U_RW;

	ptr_doorbell_sig = (struct k_poll_signal *)k_mem_map(CONFIG_MMU_PAGE_SIZE, K_MEM_PERM_RW);
	sig_part.start = (uintptr_t)ptr_doorbell_sig;
	sig_part.size = CONFIG_MMU_PAGE_SIZE;
	sig_part.attr = K_MEM_PARTITION_P_RW_U_RW;*/

	int size = 0;
	uint16_t vector = 0;

	const struct device *ptr_ivshmem_device = device_get_binding(CONFIG_IVSHMEM_DEV_NAME);

	if (!ptr_ivshmem_device)
	{
		DEBUG("\nptr_ivshmem_device device cannot be found\n")
		return 0;
	}

	// k_thread_access_grant(&thread, &k_poll_variables.doorbell_sig, &k_poll_variables.doorbell_evt, ptr_ivshmem_device);
	// k_thread_access_grant(&thread, &doorbell_sig, &doorbell_evt, ptr_ivshmem_device, k_poll_ptr_variables->ptr_doorbell_evt, k_poll_ptr_variables->ptr_doorbell_sig, k_poll_ptr_variables);
	k_thread_access_grant(&thread, &doorbell_sig, &doorbell_evt, ptr_ivshmem_device);
	//  k_thread_access_grant(&thread, ptr_doorbell_sig, ptr_doorbell_evt, ptr_ivshmem_device);
	//  k_object_access_grant(ptr_doorbell_sig, &thread);
	//  k_object_access_grant(ptr_doorbell_evt, &thread);
	//  k_object_access_all_grant(ptr_doorbell_sig);

	// k_poll_signal_init(ptr_doorbell_sig);
	// k_poll_event_init(ptr_doorbell_evt, K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, ptr_doorbell_sig);

	k_poll_signal_init(&doorbell_sig);
	k_poll_event_init(&doorbell_evt, K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, &doorbell_sig);

	// k_poll_signal_init(&k_poll_variables.doorbell_sig);
	// k_poll_event_init(&k_poll_variables.doorbell_evt, K_POLL_TYPE_SIGNAL, K_POLL_MODE_NOTIFY_ONLY, &k_poll_variables.doorbell_sig);

	// create a vector notification handler
	// if (ivshmem_register_handler(ptr_ivshmem_device, ptr_doorbell_sig, vector))
	if (ivshmem_register_handler(ptr_ivshmem_device, &doorbell_sig, vector))
	// if (ivshmem_register_handler(ptr_ivshmem_device, &k_poll_variables.doorbell_sig, vector))
	{
		DEBUG("Could not get notifications on vector %u", vector)
		return 0;
	}

	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, (void *)ptr_doorbell_evt, (void *)ptr_doorbell_sig, NULL, PRIORITY, K_USER, K_FOREVER);
	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, (void *)&doorbell_evt, (void *)&doorbell_sig, NULL, PRIORITY, K_USER, K_FOREVER);
	k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, &doorbell_sig, &doorbell_evt, NULL, PRIORITY, K_USER, K_FOREVER);
	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, &k_poll_variables, NULL, NULL, PRIORITY, K_USER, K_FOREVER);
	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, k_poll_ptr_variables, NULL, NULL, PRIORITY, K_USER, K_FOREVER);
	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, NULL, NULL, NULL, PRIORITY, K_USER, K_FOREVER);
	// k_thread_create(&thread, thread_stack, STACKSIZE, (k_thread_entry_t)thread_routine, &doorbell_sig, NULL, NULL, PRIORITY, K_USER, K_FOREVER);

	k_thread_heap_assign(&thread, &thread_heap);

	size = ARRAY_SIZE(partitions);
	k_mem_domain_init(&domain, size, partitions);

	k_mem_domain_add_thread(&domain, &thread);

	k_thread_start(&thread);
}

// void thread_routine(void *param1, void *param2, void *param3)
// void thread_routine(struct k_poll_signal *ptr_doorbell_sig, void *param2, void *param3)
void thread_routine(struct k_poll_signal *ptr_doorbell_sig, struct k_poll_event *ptr_doorbell_evt, void *param3)
//  void thread_routine(context_k_poll *ptr_k_poll_variables, void *param2, void *param3)
//  void thread_routine(context_k_poll *ptr_k_poll_ptr_variables, void *param2, void *param3)
{
	// create the pointer to the data of the shm areas code data, safe data, unsafe data and safety results data
	// struct k_poll_event *ptr_doorbell_evt = (struct k_poll_event *)param1;
	// struct k_poll_signal *ptr_doorbell_sig = (struct k_poll_signal *)param2;

	k_poll(ptr_doorbell_evt, 1, K_FOREVER);
	k_poll_signal_init(ptr_doorbell_sig);

	// k_poll(&doorbell_evt, 1, K_FOREVER);
	// k_poll_signal_init(&doorbell_sig);

	// k_poll(&doorbell_evt, 1, K_FOREVER);
	// k_poll_signal_init(ptr_doorbell_sig);

	// k_poll(&ptr_k_poll_variables->doorbell_evt, 1, K_FOREVER);
	// k_poll_signal_init(&ptr_k_poll_variables->doorbell_sig);

	// k_poll(ptr_k_poll_ptr_variables->ptr_doorbell_evt, 1, K_FOREVER);
	// k_poll_signal_init(ptr_k_poll_ptr_variables->ptr_doorbell_sig);

	printk("\ntest\n");
}
