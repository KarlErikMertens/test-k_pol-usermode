
/* auto-generated by gen_syscalls.py, don't edit */
#ifndef ZEPHYR_SYSCALL_LIST_H
#define ZEPHYR_SYSCALL_LIST_H

#define K_SYSCALL_ADC_CHANNEL_SETUP 0
#define K_SYSCALL_ADC_READ 1
#define K_SYSCALL_ADC_READ_ASYNC 2
#define K_SYSCALL_ATOMIC_ADD 3
#define K_SYSCALL_ATOMIC_AND 4
#define K_SYSCALL_ATOMIC_CAS 5
#define K_SYSCALL_ATOMIC_NAND 6
#define K_SYSCALL_ATOMIC_OR 7
#define K_SYSCALL_ATOMIC_PTR_CAS 8
#define K_SYSCALL_ATOMIC_PTR_SET 9
#define K_SYSCALL_ATOMIC_SET 10
#define K_SYSCALL_ATOMIC_SUB 11
#define K_SYSCALL_ATOMIC_XOR 12
#define K_SYSCALL_BBRAM_CHECK_INVALID 13
#define K_SYSCALL_BBRAM_CHECK_POWER 14
#define K_SYSCALL_BBRAM_CHECK_STANDBY_POWER 15
#define K_SYSCALL_BBRAM_GET_SIZE 16
#define K_SYSCALL_BBRAM_READ 17
#define K_SYSCALL_BBRAM_WRITE 18
#define K_SYSCALL_CAN_ATTACH_MSGQ 19
#define K_SYSCALL_CAN_DETACH 20
#define K_SYSCALL_CAN_GET_CORE_CLOCK 21
#define K_SYSCALL_CAN_GET_STATE 22
#define K_SYSCALL_CAN_RECOVER 23
#define K_SYSCALL_CAN_SEND 24
#define K_SYSCALL_CAN_SET_MODE 25
#define K_SYSCALL_CAN_SET_TIMING 26
#define K_SYSCALL_CLOCK_GETTIME 27
#define K_SYSCALL_COUNTER_CANCEL_CHANNEL_ALARM 28
#define K_SYSCALL_COUNTER_GET_FREQUENCY 29
#define K_SYSCALL_COUNTER_GET_GUARD_PERIOD 30
#define K_SYSCALL_COUNTER_GET_MAX_TOP_VALUE 31
#define K_SYSCALL_COUNTER_GET_NUM_OF_CHANNELS 32
#define K_SYSCALL_COUNTER_GET_PENDING_INT 33
#define K_SYSCALL_COUNTER_GET_TOP_VALUE 34
#define K_SYSCALL_COUNTER_GET_VALUE 35
#define K_SYSCALL_COUNTER_IS_COUNTING_UP 36
#define K_SYSCALL_COUNTER_SET_CHANNEL_ALARM 37
#define K_SYSCALL_COUNTER_SET_GUARD_PERIOD 38
#define K_SYSCALL_COUNTER_SET_TOP_VALUE 39
#define K_SYSCALL_COUNTER_START 40
#define K_SYSCALL_COUNTER_STOP 41
#define K_SYSCALL_COUNTER_TICKS_TO_US 42
#define K_SYSCALL_COUNTER_US_TO_TICKS 43
#define K_SYSCALL_DAC_CHANNEL_SETUP 44
#define K_SYSCALL_DAC_WRITE_VALUE 45
#define K_SYSCALL_DEVICE_GET_BINDING 46
#define K_SYSCALL_DEVICE_USABLE_CHECK 47
#define K_SYSCALL_DMA_CHAN_FILTER 48
#define K_SYSCALL_DMA_RELEASE_CHANNEL 49
#define K_SYSCALL_DMA_REQUEST_CHANNEL 50
#define K_SYSCALL_DMA_START 51
#define K_SYSCALL_DMA_STOP 52
#define K_SYSCALL_EC_HOST_CMD_PERIPH_INIT 53
#define K_SYSCALL_EC_HOST_CMD_PERIPH_SEND 54
#define K_SYSCALL_EEPROM_GET_SIZE 55
#define K_SYSCALL_EEPROM_READ 56
#define K_SYSCALL_EEPROM_WRITE 57
#define K_SYSCALL_ENTROPY_GET_ENTROPY 58
#define K_SYSCALL_ESPI_CONFIG 59
#define K_SYSCALL_ESPI_FLASH_ERASE 60
#define K_SYSCALL_ESPI_GET_CHANNEL_STATUS 61
#define K_SYSCALL_ESPI_READ_FLASH 62
#define K_SYSCALL_ESPI_READ_LPC_REQUEST 63
#define K_SYSCALL_ESPI_READ_REQUEST 64
#define K_SYSCALL_ESPI_RECEIVE_OOB 65
#define K_SYSCALL_ESPI_RECEIVE_VWIRE 66
#define K_SYSCALL_ESPI_SAF_ACTIVATE 67
#define K_SYSCALL_ESPI_SAF_CONFIG 68
#define K_SYSCALL_ESPI_SAF_FLASH_ERASE 69
#define K_SYSCALL_ESPI_SAF_FLASH_READ 70
#define K_SYSCALL_ESPI_SAF_FLASH_WRITE 71
#define K_SYSCALL_ESPI_SAF_GET_CHANNEL_STATUS 72
#define K_SYSCALL_ESPI_SAF_SET_PROTECTION_REGIONS 73
#define K_SYSCALL_ESPI_SEND_OOB 74
#define K_SYSCALL_ESPI_SEND_VWIRE 75
#define K_SYSCALL_ESPI_WRITE_FLASH 76
#define K_SYSCALL_ESPI_WRITE_LPC_REQUEST 77
#define K_SYSCALL_ESPI_WRITE_REQUEST 78
#define K_SYSCALL_FLASH_ERASE 79
#define K_SYSCALL_FLASH_GET_PAGE_COUNT 80
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_IDX 81
#define K_SYSCALL_FLASH_GET_PAGE_INFO_BY_OFFS 82
#define K_SYSCALL_FLASH_GET_PARAMETERS 83
#define K_SYSCALL_FLASH_GET_WRITE_BLOCK_SIZE 84
#define K_SYSCALL_FLASH_READ 85
#define K_SYSCALL_FLASH_READ_JEDEC_ID 86
#define K_SYSCALL_FLASH_SFDP_READ 87
#define K_SYSCALL_FLASH_SIMULATOR_GET_MEMORY 88
#define K_SYSCALL_FLASH_WRITE 89
#define K_SYSCALL_FLASH_WRITE_PROTECTION_SET 90
#define K_SYSCALL_GPIO_GET_PENDING_INT 91
#define K_SYSCALL_GPIO_PIN_CONFIGURE 92
#define K_SYSCALL_GPIO_PIN_INTERRUPT_CONFIGURE 93
#define K_SYSCALL_GPIO_PORT_CLEAR_BITS_RAW 94
#define K_SYSCALL_GPIO_PORT_GET_RAW 95
#define K_SYSCALL_GPIO_PORT_SET_BITS_RAW 96
#define K_SYSCALL_GPIO_PORT_SET_MASKED_RAW 97
#define K_SYSCALL_GPIO_PORT_TOGGLE_BITS 98
#define K_SYSCALL_HWINFO_CLEAR_RESET_CAUSE 99
#define K_SYSCALL_HWINFO_GET_DEVICE_ID 100
#define K_SYSCALL_HWINFO_GET_RESET_CAUSE 101
#define K_SYSCALL_HWINFO_GET_SUPPORTED_RESET_CAUSE 102
#define K_SYSCALL_I2C_CONFIGURE 103
#define K_SYSCALL_I2C_RECOVER_BUS 104
#define K_SYSCALL_I2C_SLAVE_DRIVER_REGISTER 105
#define K_SYSCALL_I2C_SLAVE_DRIVER_UNREGISTER 106
#define K_SYSCALL_I2C_TRANSFER 107
#define K_SYSCALL_I2S_BUF_READ 108
#define K_SYSCALL_I2S_BUF_WRITE 109
#define K_SYSCALL_I2S_CONFIGURE 110
#define K_SYSCALL_I2S_TRIGGER 111
#define K_SYSCALL_IPM_MAX_DATA_SIZE_GET 112
#define K_SYSCALL_IPM_MAX_ID_VAL_GET 113
#define K_SYSCALL_IPM_SEND 114
#define K_SYSCALL_IPM_SET_ENABLED 115
#define K_SYSCALL_IVSHMEM_GET_ID 116
#define K_SYSCALL_IVSHMEM_GET_MEM 117
#define K_SYSCALL_IVSHMEM_GET_SEMAPHORE 118
#define K_SYSCALL_IVSHMEM_GET_VECTORS 119
#define K_SYSCALL_IVSHMEM_INT_PEER 120
#define K_SYSCALL_IVSHMEM_REGISTER_HANDLER 121
#define K_SYSCALL_KSCAN_CONFIG 122
#define K_SYSCALL_KSCAN_DISABLE_CALLBACK 123
#define K_SYSCALL_KSCAN_ENABLE_CALLBACK 124
#define K_SYSCALL_K_BUSY_WAIT 125
#define K_SYSCALL_K_CONDVAR_BROADCAST 126
#define K_SYSCALL_K_CONDVAR_INIT 127
#define K_SYSCALL_K_CONDVAR_SIGNAL 128
#define K_SYSCALL_K_CONDVAR_WAIT 129
#define K_SYSCALL_K_FLOAT_DISABLE 130
#define K_SYSCALL_K_FLOAT_ENABLE 131
#define K_SYSCALL_K_FUTEX_WAIT 132
#define K_SYSCALL_K_FUTEX_WAKE 133
#define K_SYSCALL_K_IS_PREEMPT_THREAD 134
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_IN_GET 135
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_BACKING_STORE_PAGE_OUT_GET 136
#define K_SYSCALL_K_MEM_PAGING_HISTOGRAM_EVICTION_GET 137
#define K_SYSCALL_K_MEM_PAGING_STATS_GET 138
#define K_SYSCALL_K_MEM_PAGING_THREAD_STATS_GET 139
#define K_SYSCALL_K_MSGQ_ALLOC_INIT 140
#define K_SYSCALL_K_MSGQ_GET 141
#define K_SYSCALL_K_MSGQ_GET_ATTRS 142
#define K_SYSCALL_K_MSGQ_NUM_FREE_GET 143
#define K_SYSCALL_K_MSGQ_NUM_USED_GET 144
#define K_SYSCALL_K_MSGQ_PEEK 145
#define K_SYSCALL_K_MSGQ_PURGE 146
#define K_SYSCALL_K_MSGQ_PUT 147
#define K_SYSCALL_K_MUTEX_INIT 148
#define K_SYSCALL_K_MUTEX_LOCK 149
#define K_SYSCALL_K_MUTEX_UNLOCK 150
#define K_SYSCALL_K_OBJECT_ACCESS_GRANT 151
#define K_SYSCALL_K_OBJECT_ALLOC 152
#define K_SYSCALL_K_OBJECT_RELEASE 153
#define K_SYSCALL_K_PIPE_ALLOC_INIT 154
#define K_SYSCALL_K_PIPE_GET 155
#define K_SYSCALL_K_PIPE_PUT 156
#define K_SYSCALL_K_PIPE_READ_AVAIL 157
#define K_SYSCALL_K_PIPE_WRITE_AVAIL 158
#define K_SYSCALL_K_POLL 159
#define K_SYSCALL_K_POLL_SIGNAL_CHECK 160
#define K_SYSCALL_K_POLL_SIGNAL_INIT 161
#define K_SYSCALL_K_POLL_SIGNAL_RAISE 162
#define K_SYSCALL_K_POLL_SIGNAL_RESET 163
#define K_SYSCALL_K_QUEUE_ALLOC_APPEND 164
#define K_SYSCALL_K_QUEUE_ALLOC_PREPEND 165
#define K_SYSCALL_K_QUEUE_CANCEL_WAIT 166
#define K_SYSCALL_K_QUEUE_GET 167
#define K_SYSCALL_K_QUEUE_INIT 168
#define K_SYSCALL_K_QUEUE_IS_EMPTY 169
#define K_SYSCALL_K_QUEUE_PEEK_HEAD 170
#define K_SYSCALL_K_QUEUE_PEEK_TAIL 171
#define K_SYSCALL_K_SEM_COUNT_GET 172
#define K_SYSCALL_K_SEM_GIVE 173
#define K_SYSCALL_K_SEM_INIT 174
#define K_SYSCALL_K_SEM_RESET 175
#define K_SYSCALL_K_SEM_TAKE 176
#define K_SYSCALL_K_SLEEP 177
#define K_SYSCALL_K_STACK_ALLOC_INIT 178
#define K_SYSCALL_K_STACK_POP 179
#define K_SYSCALL_K_STACK_PUSH 180
#define K_SYSCALL_K_STR_OUT 181
#define K_SYSCALL_K_THREAD_ABORT 182
#define K_SYSCALL_K_THREAD_CREATE 183
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_GET 184
#define K_SYSCALL_K_THREAD_CUSTOM_DATA_SET 185
#define K_SYSCALL_K_THREAD_DEADLINE_SET 186
#define K_SYSCALL_K_THREAD_JOIN 187
#define K_SYSCALL_K_THREAD_NAME_COPY 188
#define K_SYSCALL_K_THREAD_NAME_SET 189
#define K_SYSCALL_K_THREAD_PRIORITY_GET 190
#define K_SYSCALL_K_THREAD_PRIORITY_SET 191
#define K_SYSCALL_K_THREAD_RESUME 192
#define K_SYSCALL_K_THREAD_STACK_SPACE_GET 193
#define K_SYSCALL_K_THREAD_START 194
#define K_SYSCALL_K_THREAD_SUSPEND 195
#define K_SYSCALL_K_THREAD_TIMEOUT_EXPIRES_TICKS 196
#define K_SYSCALL_K_THREAD_TIMEOUT_REMAINING_TICKS 197
#define K_SYSCALL_K_TIMER_EXPIRES_TICKS 198
#define K_SYSCALL_K_TIMER_REMAINING_TICKS 199
#define K_SYSCALL_K_TIMER_START 200
#define K_SYSCALL_K_TIMER_STATUS_GET 201
#define K_SYSCALL_K_TIMER_STATUS_SYNC 202
#define K_SYSCALL_K_TIMER_STOP 203
#define K_SYSCALL_K_TIMER_USER_DATA_GET 204
#define K_SYSCALL_K_TIMER_USER_DATA_SET 205
#define K_SYSCALL_K_UPTIME_TICKS 206
#define K_SYSCALL_K_USLEEP 207
#define K_SYSCALL_K_WAKEUP 208
#define K_SYSCALL_K_YIELD 209
#define K_SYSCALL_LED_BLINK 210
#define K_SYSCALL_LED_GET_INFO 211
#define K_SYSCALL_LED_OFF 212
#define K_SYSCALL_LED_ON 213
#define K_SYSCALL_LED_SET_BRIGHTNESS 214
#define K_SYSCALL_LED_SET_CHANNEL 215
#define K_SYSCALL_LED_SET_COLOR 216
#define K_SYSCALL_LED_WRITE_CHANNELS 217
#define K_SYSCALL_LOG_BUFFERED_CNT 218
#define K_SYSCALL_LOG_FILTER_SET 219
#define K_SYSCALL_LOG_PANIC 220
#define K_SYSCALL_LOG_PROCESS 221
#define K_SYSCALL_MAXIM_DS3231_GET_SYNCPOINT 222
#define K_SYSCALL_MAXIM_DS3231_REQ_SYNCPOINT 223
#define K_SYSCALL_MDIO_BUS_DISABLE 224
#define K_SYSCALL_MDIO_BUS_ENABLE 225
#define K_SYSCALL_MDIO_READ 226
#define K_SYSCALL_MDIO_WRITE 227
#define K_SYSCALL_NET_ADDR_NTOP 228
#define K_SYSCALL_NET_ADDR_PTON 229
#define K_SYSCALL_NET_ETH_GET_PTP_CLOCK_BY_INDEX 230
#define K_SYSCALL_NET_IF_GET_BY_INDEX 231
#define K_SYSCALL_NET_IF_IPV4_ADDR_ADD_BY_INDEX 232
#define K_SYSCALL_NET_IF_IPV4_ADDR_LOOKUP_BY_INDEX 233
#define K_SYSCALL_NET_IF_IPV4_ADDR_RM_BY_INDEX 234
#define K_SYSCALL_NET_IF_IPV4_SET_GW_BY_INDEX 235
#define K_SYSCALL_NET_IF_IPV4_SET_NETMASK_BY_INDEX 236
#define K_SYSCALL_NET_IF_IPV6_ADDR_ADD_BY_INDEX 237
#define K_SYSCALL_NET_IF_IPV6_ADDR_LOOKUP_BY_INDEX 238
#define K_SYSCALL_NET_IF_IPV6_ADDR_RM_BY_INDEX 239
#define K_SYSCALL_PECI_CONFIG 240
#define K_SYSCALL_PECI_DISABLE 241
#define K_SYSCALL_PECI_ENABLE 242
#define K_SYSCALL_PECI_TRANSFER 243
#define K_SYSCALL_PHY_CONFIGURE_LINK 244
#define K_SYSCALL_PHY_GET_LINK_STATE 245
#define K_SYSCALL_PHY_LINK_CALLBACK_SET 246
#define K_SYSCALL_PHY_READ 247
#define K_SYSCALL_PHY_WRITE 248
#define K_SYSCALL_PS2_CONFIG 249
#define K_SYSCALL_PS2_DISABLE_CALLBACK 250
#define K_SYSCALL_PS2_ENABLE_CALLBACK 251
#define K_SYSCALL_PS2_READ 252
#define K_SYSCALL_PS2_WRITE 253
#define K_SYSCALL_PTP_CLOCK_GET 254
#define K_SYSCALL_PWM_GET_CYCLES_PER_SEC 255
#define K_SYSCALL_PWM_PIN_CAPTURE_CYCLES 256
#define K_SYSCALL_PWM_PIN_DISABLE_CAPTURE 257
#define K_SYSCALL_PWM_PIN_ENABLE_CAPTURE 258
#define K_SYSCALL_PWM_PIN_SET_CYCLES 259
#define K_SYSCALL_SENSOR_ATTR_GET 260
#define K_SYSCALL_SENSOR_ATTR_SET 261
#define K_SYSCALL_SENSOR_CHANNEL_GET 262
#define K_SYSCALL_SENSOR_SAMPLE_FETCH 263
#define K_SYSCALL_SENSOR_SAMPLE_FETCH_CHAN 264
#define K_SYSCALL_SPI_RELEASE 265
#define K_SYSCALL_SPI_TRANSCEIVE 266
#define K_SYSCALL_SYSCON_GET_BASE 267
#define K_SYSCALL_SYSCON_GET_SIZE 268
#define K_SYSCALL_SYSCON_READ_REG 269
#define K_SYSCALL_SYSCON_WRITE_REG 270
#define K_SYSCALL_SYS_CACHE_DATA_ALL 271
#define K_SYSCALL_SYS_CACHE_DATA_RANGE 272
#define K_SYSCALL_SYS_CACHE_INSTR_ALL 273
#define K_SYSCALL_SYS_CACHE_INSTR_RANGE 274
#define K_SYSCALL_SYS_CLOCK_HW_CYCLES_PER_SEC_RUNTIME_GET 275
#define K_SYSCALL_SYS_CSRAND_GET 276
#define K_SYSCALL_SYS_RAND32_GET 277
#define K_SYSCALL_SYS_RAND_GET 278
#define K_SYSCALL_UART_CONFIGURE 279
#define K_SYSCALL_UART_CONFIG_GET 280
#define K_SYSCALL_UART_DRV_CMD 281
#define K_SYSCALL_UART_ERR_CHECK 282
#define K_SYSCALL_UART_IRQ_ERR_DISABLE 283
#define K_SYSCALL_UART_IRQ_ERR_ENABLE 284
#define K_SYSCALL_UART_IRQ_IS_PENDING 285
#define K_SYSCALL_UART_IRQ_RX_DISABLE 286
#define K_SYSCALL_UART_IRQ_RX_ENABLE 287
#define K_SYSCALL_UART_IRQ_TX_DISABLE 288
#define K_SYSCALL_UART_IRQ_TX_ENABLE 289
#define K_SYSCALL_UART_IRQ_UPDATE 290
#define K_SYSCALL_UART_LINE_CTRL_GET 291
#define K_SYSCALL_UART_LINE_CTRL_SET 292
#define K_SYSCALL_UART_MUX_FIND 293
#define K_SYSCALL_UART_POLL_IN 294
#define K_SYSCALL_UART_POLL_OUT 295
#define K_SYSCALL_UART_RX_DISABLE 296
#define K_SYSCALL_UART_RX_ENABLE 297
#define K_SYSCALL_UART_TX 298
#define K_SYSCALL_UART_TX_ABORT 299
#define K_SYSCALL_USER_FAULT 300
#define K_SYSCALL_WDT_DISABLE 301
#define K_SYSCALL_WDT_FEED 302
#define K_SYSCALL_WDT_SETUP 303
#define K_SYSCALL_ZEPHYR_FPUTC 304
#define K_SYSCALL_ZEPHYR_FWRITE 305
#define K_SYSCALL_ZEPHYR_READ_STDIN 306
#define K_SYSCALL_ZEPHYR_WRITE_STDOUT 307
#define K_SYSCALL_ZSOCK_ACCEPT 308
#define K_SYSCALL_ZSOCK_BIND 309
#define K_SYSCALL_ZSOCK_CLOSE 310
#define K_SYSCALL_ZSOCK_CONNECT 311
#define K_SYSCALL_ZSOCK_FCNTL 312
#define K_SYSCALL_ZSOCK_GETHOSTNAME 313
#define K_SYSCALL_ZSOCK_GETSOCKNAME 314
#define K_SYSCALL_ZSOCK_GETSOCKOPT 315
#define K_SYSCALL_ZSOCK_GET_CONTEXT_OBJECT 316
#define K_SYSCALL_ZSOCK_INET_PTON 317
#define K_SYSCALL_ZSOCK_LISTEN 318
#define K_SYSCALL_ZSOCK_POLL 319
#define K_SYSCALL_ZSOCK_RECVFROM 320
#define K_SYSCALL_ZSOCK_SELECT 321
#define K_SYSCALL_ZSOCK_SENDMSG 322
#define K_SYSCALL_ZSOCK_SENDTO 323
#define K_SYSCALL_ZSOCK_SETSOCKOPT 324
#define K_SYSCALL_ZSOCK_SHUTDOWN 325
#define K_SYSCALL_ZSOCK_SOCKET 326
#define K_SYSCALL_ZSOCK_SOCKETPAIR 327
#define K_SYSCALL_Z_CURRENT_GET 328
#define K_SYSCALL_Z_ERRNO 329
#define K_SYSCALL_Z_LOG_HEXDUMP_FROM_USER 330
#define K_SYSCALL_Z_LOG_MSG2_RUNTIME_VCREATE 331
#define K_SYSCALL_Z_LOG_MSG2_STATIC_CREATE 332
#define K_SYSCALL_Z_LOG_STRING_FROM_USER 333
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_LOCK 334
#define K_SYSCALL_Z_SYS_MUTEX_KERNEL_UNLOCK 335
#define K_SYSCALL_Z_ZSOCK_GETADDRINFO_INTERNAL 336
#define K_SYSCALL_BAD 337
#define K_SYSCALL_LIMIT 338


#ifndef _ASMLANGUAGE

#include <stdint.h>

#endif /* _ASMLANGUAGE */

#endif /* ZEPHYR_SYSCALL_LIST_H */