MEMORY
    {
    RAM (wx) : ORIGIN = (0 + 0x100000), LENGTH = (268435456 - 0x100000)
    LOCORE (wx) : ORIGIN = 0x1000, LENGTH = (0x10000 - 0x1000)
    }
  OUTPUT_FORMAT("elf64-x86-64")
  OUTPUT_ARCH("i386:x86-64")
ENTRY("__start")
SECTIONS
{
 .locore :
 {
 _locore_start = .;
 *(.locore)
 *(.locore.*)
 . = ALIGN(0x1000);
 _locore_end = .;
 _lorodata_start = .;
 *(.lorodata)
 . = ALIGN(0x1000);
 _lodata_start = .;
 *(.lodata)
 . = ALIGN(0x1000);
 z_shared_kernel_page_start = .;
 *(.tss)
 *(.gdt)
 *(.trampolines)
 . = ALIGN(0x1000);
 z_shared_kernel_page_end = .;
 ASSERT(z_shared_kernel_page_end - z_shared_kernel_page_start == 4096,
        "shared kernel area is not one memory page");
 . = ALIGN(0x1000);
 _lodata_end = .;
 } > LOCORE
 _locore_size = _lorodata_start - _locore_start;
 _lorodata_size = _lodata_start - _lorodata_start;
 _lodata_size = _lodata_end - _lodata_start;
 text :
 {
 . = ALIGN(16);
 __rom_region_start = .;
 __text_region_start = .;
 z_mapped_start = .;
 *(.text)
 *(.text.*)
 _kobject_text_area_start = .;
 *(".kobject_data.text*")
 _kobject_text_area_end = .;
 _kobject_text_area_used = _kobject_text_area_end - _kobject_text_area_start;
 PROVIDE(z_object_gperf_find = .);
 PROVIDE(z_object_gperf_wordlist_foreach = .);
 . = MAX(., _kobject_text_area_start + 256);
 ASSERT(
  256 >= _kobject_text_area_used,
"Reserved space for kobject text area is too small. Please change CONFIG_KOBJECT_TEXT_AREA to a larger number."
  );
 . = ALIGN(0x1000);
 } > RAM
 __text_region_end = .;
 __text_region_size = __text_region_end - __text_region_start;
 __rodata_region_start = .;
 initlevel :
 {
  __init_start = .;
  __init_PRE_KERNEL_1_start = .; KEEP(*(SORT(.z_init_PRE_KERNEL_1[0-9]_*))); KEEP(*(SORT(.z_init_PRE_KERNEL_1[1-9][0-9]_*)));
  __init_PRE_KERNEL_2_start = .; KEEP(*(SORT(.z_init_PRE_KERNEL_2[0-9]_*))); KEEP(*(SORT(.z_init_PRE_KERNEL_2[1-9][0-9]_*)));
  __init_POST_KERNEL_start = .; KEEP(*(SORT(.z_init_POST_KERNEL[0-9]_*))); KEEP(*(SORT(.z_init_POST_KERNEL[1-9][0-9]_*)));
  __init_APPLICATION_start = .; KEEP(*(SORT(.z_init_APPLICATION[0-9]_*))); KEEP(*(SORT(.z_init_APPLICATION[1-9][0-9]_*)));
  __init_SMP_start = .; KEEP(*(SORT(.z_init_SMP[0-9]_*))); KEEP(*(SORT(.z_init_SMP[1-9][0-9]_*)));
  __init_end = .;
 } > RAM
 devices :
 {
  __device_start = .;
  __device_PRE_KERNEL_1_start = .; KEEP(*(SORT(.z_device_PRE_KERNEL_1[0-9]_*))); KEEP(*(SORT(.z_device_PRE_KERNEL_1[1-9][0-9]_*)));
  __device_PRE_KERNEL_2_start = .; KEEP(*(SORT(.z_device_PRE_KERNEL_2[0-9]_*))); KEEP(*(SORT(.z_device_PRE_KERNEL_2[1-9][0-9]_*)));
  __device_POST_KERNEL_start = .; KEEP(*(SORT(.z_device_POST_KERNEL[0-9]_*))); KEEP(*(SORT(.z_device_POST_KERNEL[1-9][0-9]_*)));
  __device_APPLICATION_start = .; KEEP(*(SORT(.z_device_APPLICATION[0-9]_*))); KEEP(*(SORT(.z_device_APPLICATION[1-9][0-9]_*)));
  __device_SMP_start = .; KEEP(*(SORT(.z_device_SMP[0-9]_*))); KEEP(*(SORT(.z_device_SMP[1-9][0-9]_*)));
  __device_end = .;
 } > RAM
 initlevel_error :
 {
  KEEP(*(SORT(.z_init_[_A-Z0-9]*)))
 }
 ASSERT(SIZEOF(initlevel_error) == 0, "Undefined initialization levels used.")
 z_object_assignment_area : SUBALIGN(4) { _z_object_assignment_list_start = .; KEEP(*(SORT_BY_NAME(._z_object_assignment.static.*))); _z_object_assignment_list_end = .; } > RAM
 app_shmem_regions :
 {
  __app_shmem_regions_start = .;
  KEEP(*(SORT(.app_regions.*)));
  __app_shmem_regions_end = .;
 } > RAM
 bt_l2cap_fixed_chan_area : SUBALIGN(4) { _bt_l2cap_fixed_chan_list_start = .; KEEP(*(SORT_BY_NAME(._bt_l2cap_fixed_chan.static.*))); _bt_l2cap_fixed_chan_list_end = .; } > RAM
 bt_gatt_service_static_area : SUBALIGN(4) { _bt_gatt_service_static_list_start = .; KEEP(*(SORT_BY_NAME(._bt_gatt_service_static.static.*))); _bt_gatt_service_static_list_end = .; } > RAM
 k_p4wq_initparam_area : SUBALIGN(4) { _k_p4wq_initparam_list_start = .; KEEP(*(SORT_BY_NAME(._k_p4wq_initparam.static.*))); _k_p4wq_initparam_list_end = .; } > RAM
 irq_alloc :
 {
  __irq_alloc_start = .;
  KEEP(*(SORT_BY_NAME("._irq_alloc*")));
  __irq_alloc_end = .;
 } > RAM
 log_strings_sections :
 {
  __log_strings_start = .;
  KEEP(*(SORT(.log_strings*)));
  __log_strings_end = .;
 } > RAM
 log_const_sections :
 {
  __log_const_start = .;
  KEEP(*(SORT(.log_const_*)));
  __log_const_end = .;
 } > RAM
 log_backends_sections :
 {
  __log_backends_start = .;
  KEEP(*("._log_backend.*"));
  __log_backends_end = .;
 } > RAM
 shell_area : SUBALIGN(4) { _shell_list_start = .; KEEP(*(SORT_BY_NAME(._shell.static.*))); _shell_list_end = .; } > RAM
 shell_root_cmds_sections :
 {
  __shell_root_cmds_start = .;
  KEEP(*(SORT(.shell_root_cmd_*)));
  __shell_root_cmds_end = .;
 } > RAM
 font_entry_sections :
 {
  __font_entry_start = .;
  KEEP(*(SORT_BY_NAME("._cfb_font.*")))
  __font_entry_end = .;
 } > RAM
 tracing_backend_area : SUBALIGN(4) { _tracing_backend_list_start = .; KEEP(*(SORT_BY_NAME(._tracing_backend.static.*))); _tracing_backend_list_end = .; } > RAM
 zephyr_dbg_info :
 {
  KEEP(*(".dbg_thread_info"));
 } > RAM
 device_handles :
 {
  __device_handles_start = .;
  KEEP(*(SORT(.__device_handles_pass1*)));
  __device_handles_end = .;
 } > RAM
 rodata :
 {
 . = ALIGN(16);
 *(.rodata)
 *(.rodata.*)
 . = ALIGN(0x1000);
 . = ALIGN(8);
 _mmu_region_list_start = .;
 KEEP(*("._mmu_region.static.*"))
 _mmu_region_list_end = .;
 . = ALIGN(32);
 _kobject_rodata_area_start = .;
 . = . + 272;
 _kobject_rodata_area_end = .;
 } > RAM
 . = ALIGN(0x1000);
 __rodata_region_end = .;
 __rodata_region_size = __rodata_region_end - __rodata_region_start;
 __rom_region_end = .;
 app_smem :
 {
  . = ALIGN(0x1000);;
  _app_smem_start = .;
  . = ALIGN(0x1000);;
  z_data_smem_z_libc_partition_part_start = .;
  KEEP(*(data_smem_z_libc_partition_data*))
  z_data_smem_z_libc_partition_bss_start = .;
  KEEP(*(data_smem_z_libc_partition_bss*))
  z_data_smem_z_libc_partition_bss_end = .;
  . = ALIGN(0x1000);;
  z_data_smem_z_libc_partition_part_end = .;
  . = ALIGN(0x1000);;
  z_data_smem_sig_part_part_start = .;
  KEEP(*(data_smem_sig_part_data*))
  z_data_smem_sig_part_bss_start = .;
  KEEP(*(data_smem_sig_part_bss*))
  z_data_smem_sig_part_bss_end = .;
  . = ALIGN(0x1000);;
  z_data_smem_sig_part_part_end = .;
  . = ALIGN(0x1000);;
  z_data_smem_evt_part_part_start = .;
  KEEP(*(data_smem_evt_part_data*))
  z_data_smem_evt_part_bss_start = .;
  KEEP(*(data_smem_evt_part_bss*))
  z_data_smem_evt_part_bss_end = .;
  . = ALIGN(0x1000);;
  z_data_smem_evt_part_part_end = .;
  . = ALIGN(0x1000);;
  _app_smem_end = .;
 } > RAM
 z_data_smem_z_libc_partition_part_size = z_data_smem_z_libc_partition_part_end - z_data_smem_z_libc_partition_part_start;
 z_data_smem_z_libc_partition_bss_size = z_data_smem_z_libc_partition_bss_end - z_data_smem_z_libc_partition_bss_start;
 z_data_smem_sig_part_part_size = z_data_smem_sig_part_part_end - z_data_smem_sig_part_part_start;
 z_data_smem_sig_part_bss_size = z_data_smem_sig_part_bss_end - z_data_smem_sig_part_bss_start;
 z_data_smem_evt_part_part_size = z_data_smem_evt_part_part_end - z_data_smem_evt_part_part_start;
 z_data_smem_evt_part_bss_size = z_data_smem_evt_part_bss_end - z_data_smem_evt_part_bss_start;
 _image_ram_start = _app_smem_start;
 _app_smem_size = _app_smem_end - _app_smem_start;
 _app_smem_num_words = _app_smem_size >> 2;
 _app_smem_rom_start = LOADADDR(app_smem);
 _app_smem_num_words = _app_smem_size >> 2;
 bss (NOLOAD) :
 {
 . = ALIGN(16);
 . = ALIGN(0x1000);
 __kernel_ram_start = .;
 __bss_start = .;
 *(.bss)
 *(.bss.*)
 *(COMMON)
 . = ALIGN(4);
 __bss_end = .;
 } > RAM
 __bss_num_dwords = (__bss_end - __bss_start) >> 2;
noinit (NOLOAD) :
{
        *(.noinit)
        *(".noinit.*")
 z_user_stacks_start = .;
 *(.user_stacks*)
 z_user_stacks_end = .;
} > RAM
 datas :
 {
 . = ALIGN(16);
 *(.data)
 *(.data.*)
 } > RAM
        device_states :
        {
                __device_states_start = .;
  KEEP(*(".z_devstate"));
  KEEP(*(".z_devstate.*"));
                __device_states_end = .;
        } > RAM
 initshell :
 {
  __shell_module_start = .;
  KEEP(*(".shell_module_*"));
  __shell_module_end = .;
  __shell_cmd_start = .;
  KEEP(*(".shell_cmd_*"));
  __shell_cmd_end = .;
 } > RAM
 log_dynamic_sections :
 {
  __log_dynamic_start = .;
  KEEP(*(SORT(.log_dynamic_*)));
  __log_dynamic_end = .;
 } > RAM
 _static_thread_data_area : SUBALIGN(4) { __static_thread_data_list_start = .; KEEP(*(SORT_BY_NAME(.__static_thread_data.static.*))); __static_thread_data_list_end = .; } > RAM
 _static_kernel_objects_begin = .;
 k_timer_area : SUBALIGN(4) { _k_timer_list_start = .; *(SORT_BY_NAME(._k_timer.static.*)); _k_timer_list_end = .; } > RAM
 k_mem_slab_area : SUBALIGN(4) { _k_mem_slab_list_start = .; *(SORT_BY_NAME(._k_mem_slab.static.*)); _k_mem_slab_list_end = .; } > RAM
 k_mem_pool_area : SUBALIGN(4) { _k_mem_pool_list_start = .; *(SORT_BY_NAME(._k_mem_pool.static.*)); _k_mem_pool_list_end = .; } > RAM
 k_heap_area : SUBALIGN(4) { _k_heap_list_start = .; *(SORT_BY_NAME(._k_heap.static.*)); _k_heap_list_end = .; } > RAM
 k_mutex_area : SUBALIGN(4) { _k_mutex_list_start = .; *(SORT_BY_NAME(._k_mutex.static.*)); _k_mutex_list_end = .; } > RAM
 k_stack_area : SUBALIGN(4) { _k_stack_list_start = .; *(SORT_BY_NAME(._k_stack.static.*)); _k_stack_list_end = .; } > RAM
 k_msgq_area : SUBALIGN(4) { _k_msgq_list_start = .; *(SORT_BY_NAME(._k_msgq.static.*)); _k_msgq_list_end = .; } > RAM
 k_mbox_area : SUBALIGN(4) { _k_mbox_list_start = .; *(SORT_BY_NAME(._k_mbox.static.*)); _k_mbox_list_end = .; } > RAM
 k_pipe_area : SUBALIGN(4) { _k_pipe_list_start = .; *(SORT_BY_NAME(._k_pipe.static.*)); _k_pipe_list_end = .; } > RAM
 k_sem_area : SUBALIGN(4) { _k_sem_list_start = .; *(SORT_BY_NAME(._k_sem.static.*)); _k_sem_list_end = .; } > RAM
 k_queue_area : SUBALIGN(4) { _k_queue_list_start = .; *(SORT_BY_NAME(._k_queue.static.*)); _k_queue_list_end = .; } > RAM
 k_condvar_area : SUBALIGN(4) { _k_condvar_list_start = .; *(SORT_BY_NAME(._k_condvar.static.*)); _k_condvar_list_end = .; } > RAM
 _net_buf_pool_area : SUBALIGN(4)
 {
  _net_buf_pool_list = .;
  KEEP(*(SORT_BY_NAME("._net_buf_pool.static.*")))
 } > RAM
 _static_kernel_objects_end = .;
    pagetables :
    {
    . = ALIGN(4096);
    z_x86_pagetables_start = .;
    KEEP(*(.dummy_pagetables))
    z_x86_kernel_ptables = . - 4096;
    } > RAM
 z_kobject_data_begin = .;
 kobject_data :
 {
 PROVIDE(_thread_idx_map = .);
 . = ALIGN(32);
 . = . + 1600;
        } > RAM
 . = ALIGN(0x1000);
 _image_ram_end = .;
 z_mapped_end = .;
 _end = .;
 __kernel_ram_end = (0 + 0x100000) + (268435456 - 0x100000);
 __kernel_ram_size = __kernel_ram_end - __kernel_ram_start;
 z_mapped_size = z_mapped_end - z_mapped_start;
 .stab 0 : { *(.stab) }
 .stabstr 0 : { *(.stabstr) }
 .stab.excl 0 : { *(.stab.excl) }
 .stab.exclstr 0 : { *(.stab.exclstr) }
 .stab.index 0 : { *(.stab.index) }
 .stab.indexstr 0 : { *(.stab.indexstr) }
 .gnu.build.attributes 0 : { *(.gnu.build.attributes .gnu.build.attributes.*) }
 .comment 0 : { *(.comment) }
 .debug 0 : { *(.debug) }
 .line 0 : { *(.line) }
 .debug_srcinfo 0 : { *(.debug_srcinfo) }
 .debug_sfnames 0 : { *(.debug_sfnames) }
 .debug_aranges 0 : { *(.debug_aranges) }
 .debug_pubnames 0 : { *(.debug_pubnames) }
 .debug_info 0 : { *(.debug_info .gnu.linkonce.wi.*) }
 .debug_abbrev 0 : { *(.debug_abbrev) }
 .debug_line 0 : { *(.debug_line .debug_line.* .debug_line_end ) }
 .debug_frame 0 : { *(.debug_frame) }
 .debug_str 0 : { *(.debug_str) }
 .debug_loc 0 : { *(.debug_loc) }
 .debug_macinfo 0 : { *(.debug_macinfo) }
 .debug_weaknames 0 : { *(.debug_weaknames) }
 .debug_funcnames 0 : { *(.debug_funcnames) }
 .debug_typenames 0 : { *(.debug_typenames) }
 .debug_varnames 0 : { *(.debug_varnames) }
 .debug_pubtypes 0 : { *(.debug_pubtypes) }
 .debug_ranges 0 : { *(.debug_ranges) }
 .debug_macro 0 : { *(.debug_macro) }
 /DISCARD/ :
 {
 *(.got)
 *(.got.plt)
 *(.igot)
 *(.igot.plt)
 *(.iplt)
 *(.plt)
 *(.note.GNU-stack)
 *(.rel.*)
 *(.rela.*)
 }
}
