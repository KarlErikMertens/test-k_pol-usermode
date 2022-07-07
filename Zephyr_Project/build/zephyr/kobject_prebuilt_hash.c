/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: /usr/bin/gperf --output-file kobject_prebuilt_hash_preprocessed.c --multiple-iterations 10 kobject_prebuilt_hash.gperf  */
/* Computed positions: -k'1-2' */

#line 6 "kobject_prebuilt_hash.gperf"

#include <kernel.h>
#include <toolchain.h>
#include <syscall_handler.h>
#include <string.h>
#line 12 "kobject_prebuilt_hash.gperf"
struct z_object;
static struct z_futex_data futex_data[4] = {
Z_FUTEX_DATA_INITIALIZER(futex_data[0]), Z_FUTEX_DATA_INITIALIZER(futex_data[1]), Z_FUTEX_DATA_INITIALIZER(futex_data[2]), Z_FUTEX_DATA_INITIALIZER(futex_data[3])};

#define TOTAL_KEYWORDS 27
#define MIN_WORD_LENGTH 8
#define MAX_WORD_LENGTH 8
#define MIN_HASH_VALUE 0
#define MAX_HASH_VALUE 26
/* maximum key range = 27, duplicates = 0 */

#ifdef __GNUC__
__inline
#else
#ifdef __cplusplus
inline
#endif
#endif
/*ARGSUSED*/
static unsigned int
hash ( const char *str,  size_t len)
{
  static unsigned char asso_values[] =
    {
       2,  4,  2, 13, 13, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 13, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 20, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 11, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
       6, 27, 27, 27, 27, 19, 27, 27, 27, 27,
      27,  0,  1, 27, 27, 27, 15, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27,  5, 27, 27,
      27, 16, 13, 27, 27,  3, 27, 27, 27, 27,
      14, 27, 27, 27, 27, 27, 27, 27,  3, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27,  1, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      15,  3, 11, 27, 27, 27, 27, 27, 13, 27,
      27, 27, 27, 27, 27, 27,  9, 27, 27, 27,
      27, 27, 27, 27, 11, 27, 27, 27, 27, 27,
      27, 27,  0, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 12, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27,  7, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27
    };
  return asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]];
}

static unsigned char __unused lengthtable[] =
  {
     8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
     8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8
  };

static struct z_object wordlist[] =
  {
#line 27 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125bc0, {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 25 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125b90, {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 36 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005dc000, {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 16384 }},
#line 35 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005d9000, {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 12288 }},
#line 39 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e0200, {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[1] }},
#line 40 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e0280, {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[0] }},
#line 37 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e0100, {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[3] }},
#line 38 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e0180, {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[2] }},
#line 22 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125000, {}, K_OBJ_THREAD, 0, { .thread_id = 0 }},
#line 17 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a150, {}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 19 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a1e0, {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 33 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000001bb8c0, {}, K_OBJ_THREAD, 0, { .thread_id = 5 }},
#line 18 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a1b0, {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 26 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125ba8, {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 24 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125b78, {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 28 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125c78, {}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 29 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125ca0, {}, K_OBJ_TIMER, 0, { .unused = 0 }},
#line 34 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005d6000, {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 12288 }},
#line 32 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000127360, {}, K_OBJ_THREAD, 0, { .thread_id = 3 }},
#line 31 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000126f80, {}, K_OBJ_THREAD, 0, { .thread_id = 4 }},
#line 30 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000126ba0, {}, K_OBJ_THREAD, 0, { .thread_id = 2 }},
#line 23 "kobject_prebuilt_hash.gperf"
    {(char *)0x0000000000125500, {}, K_OBJ_THREAD, 0, { .thread_id = 1 }},
#line 21 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a240, {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 16 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a120, {}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 20 "kobject_prebuilt_hash.gperf"
    {(char *)0x000000000011a210, {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 42 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e04d0, {}, K_OBJ_STACK, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 41 "kobject_prebuilt_hash.gperf"
    {(char *)0x00000000005e0370, {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }}
  };

static inline struct z_object *
z_object_lookup ( const char *str,  size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
       unsigned int key = hash((const char *)&str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == sizeof(void *))
          {
             const char *s = wordlist[key].name;

            if (str == s)
              return &wordlist[key];
          }
    }
  return 0;
}
#line 43 "kobject_prebuilt_hash.gperf"

struct z_object *z_object_gperf_find(const void *obj)
{
    return z_object_lookup((const char *)obj, sizeof(void *));
}

void z_object_gperf_wordlist_foreach(_wordlist_cb_func_t func, void *context)
{
    int i;

    for (i = MIN_HASH_VALUE; i <= MAX_HASH_VALUE; i++) {
        if (wordlist[i].name != NULL) {
            func(&wordlist[i], context);
        }
    }
}

#ifndef CONFIG_DYNAMIC_OBJECTS
struct z_object *z_object_find(const void *obj)
	ALIAS_OF(z_object_gperf_find);

void z_object_wordlist_foreach(_wordlist_cb_func_t func, void *context)
	ALIAS_OF(z_object_gperf_wordlist_foreach);
#endif

uint8_t _thread_idx_map[4] = { 0xc0,  0xff,  0xff,  0xff, };
