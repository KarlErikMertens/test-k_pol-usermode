/* ANSI-C code produced by gperf version 3.1 */
/* Command-line: /usr/bin/gperf --output-file kobject_hash_preprocessed.c --multiple-iterations 10 kobject_hash.gperf  */
/* Computed positions: -k'1-2' */

#line 6 "kobject_hash.gperf"

#include <kernel.h>
#include <toolchain.h>
#include <syscall_handler.h>
#include <string.h>
#line 12 "kobject_hash.gperf"
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
hash (register const char *str, register size_t len)
{
  static unsigned char asso_values[] =
    {
       2, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 15,  1,  0,  8,
      22, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 17, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 11, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      15, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 13, 27, 27, 27,
      27, 18, 27, 27, 27, 27, 27,  4,  3, 27,
      27, 27, 17, 27, 27, 27, 27, 27, 27, 27,
       4, 27, 27, 15, 27, 27, 27, 17,  0, 27,
      27,  3, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 10, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
       3,  6, 11, 27, 27, 27, 27, 27,  9, 27,
      27, 27, 27, 27, 27, 27,  6, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27,  5, 27, 27, 27, 27, 27, 27, 27,
       5, 27, 27, 27, 27, 27, 27, 27,  2, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27,  5, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27, 27, 27, 27, 27,
      27, 27, 27, 27, 27, 27
    };
  return asso_values[(unsigned char)str[1]] + asso_values[(unsigned char)str[0]];
}

static unsigned char lengthtable[] =
  {
     8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,
     8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8,  8
  };

static struct z_object wordlist[] =
  {
#line 40 "kobject_hash.gperf"
    {"\200\022^\000\000\000\000\000", {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[0] }},
#line 38 "kobject_hash.gperf"
    {"\200\021^\000\000\000\000\000", {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[2] }},
#line 39 "kobject_hash.gperf"
    {"\000\022^\000\000\000\000\000", {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[1] }},
#line 37 "kobject_hash.gperf"
    {"\000\021^\000\000\000\000\000", {}, K_OBJ_FUTEX, 0, { .futex_data = &futex_data[3] }},
#line 36 "kobject_hash.gperf"
    {"\000\320]\000\000\000\000\000", {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 16384 }},
#line 35 "kobject_hash.gperf"
    {"\000\240]\000\000\000\000\000", {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 12288 }},
#line 29 "kobject_hash.gperf"
    {"\240l\022\000\000\000\000\000", {}, K_OBJ_TIMER, 0, { .unused = 0 }},
#line 28 "kobject_hash.gperf"
    {"xl\022\000\000\000\000\000", {}, K_OBJ_MUTEX, 0, { .unused = 0 }},
#line 24 "kobject_hash.gperf"
    {"xk\022\000\000\000\000\000", {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 27 "kobject_hash.gperf"
    {"\300k\022\000\000\000\000\000", {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 33 "kobject_hash.gperf"
    {"\300\310\033\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 5 }},
#line 19 "kobject_hash.gperf"
    {"\340\241\021\000\000\000\000\000", {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 18 "kobject_hash.gperf"
    {"\260\241\021\000\000\000\000\000", {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 26 "kobject_hash.gperf"
    {"\250k\022\000\000\000\000\000", {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 25 "kobject_hash.gperf"
    {"\220k\022\000\000\000\000\000", {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 22 "kobject_hash.gperf"
    {"\000`\022\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 0 }},
#line 32 "kobject_hash.gperf"
    {"`\203\022\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 3 }},
#line 31 "kobject_hash.gperf"
    {"\200\177\022\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 4 }},
#line 30 "kobject_hash.gperf"
    {"\240{\022\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 2 }},
#line 34 "kobject_hash.gperf"
    {"\000p]\000\000\000\000\000", {}, K_OBJ_THREAD_STACK_ELEMENT, 0, { .stack_size = 12288 }},
#line 23 "kobject_hash.gperf"
    {"\000e\022\000\000\000\000\000", {}, K_OBJ_THREAD, 0, { .thread_id = 1 }},
#line 17 "kobject_hash.gperf"
    {"P\241\021\000\000\000\000\000", {}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 21 "kobject_hash.gperf"
    {"@\242\021\000\000\000\000\000", {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 16 "kobject_hash.gperf"
    {" \241\021\000\000\000\000\000", {}, K_OBJ_DRIVER_UART, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }},
#line 42 "kobject_hash.gperf"
    {"\320\024^\000\000\000\000\000", {}, K_OBJ_STACK, 0 | K_OBJ_FLAG_INITIALIZED, { .unused = 0 }},
#line 41 "kobject_hash.gperf"
    {"p\023^\000\000\000\000\000", {}, K_OBJ_POLL_SIGNAL, 0, { .unused = 0 }},
#line 20 "kobject_hash.gperf"
    {"\020\242\021\000\000\000\000\000", {}, K_OBJ_DRIVER_IVSHMEM, 0 | K_OBJ_FLAG_DRIVER, { .unused = 0 }}
  };

struct z_object *
z_object_lookup (register const char *str, register size_t len)
{
  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
      register unsigned int key = hash (str, len);

      if (key <= MAX_HASH_VALUE)
        if (len == lengthtable[key])
          {
            register const char *s = wordlist[key].name;

            if (*str == *s && !memcmp (str + 1, s + 1, len - 1))
              return &wordlist[key];
          }
    }
  return 0;
}
#line 43 "kobject_hash.gperf"

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
