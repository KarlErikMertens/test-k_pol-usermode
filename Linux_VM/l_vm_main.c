// includes the the necessary libraries to use standard inputs and outputs, timers and signals
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <stdint.h>
#include <sched.h>
#include <pthread.h>
#include <sys/wait.h>

#define OUTPUT_DEBUG (1)

#if (1 == OUTPUT_DEBUG)
#define DEBUG(...) printf(__VA_ARGS__);
#else
#define DEBUG(...)
#endif

int main()
{

	char *ptr_shm_1;
	int file_ptr_shm_1;
	uint32_t *ptr_doorbell_vm_1;

	// open device for the doorbell shm 1
	if ((file_ptr_shm_1 = open("/sys/class/uio/uio2/device/resource0", O_RDWR)) == -1)
	{
		perror("Can't open Device1 BAR0");
		return (1);
	}
	// map the doorbell shm 1
	if ((ptr_shm_1 = mmap(NULL, getpagesize(), PROT_READ | PROT_WRITE, MAP_SHARED, file_ptr_shm_1, 0)) == MAP_FAILED)
	{
		perror("mmap() Device1 BAR 0 failed");
		return (1);
	}

	ptr_doorbell_vm_1 = (uint32_t *)(ptr_shm_1 + 0xc);

	*ptr_doorbell_vm_1 = 0;

	munmap(ptr_shm_1, getpagesize());
	close(file_ptr_shm_1);

	return 0;
}
