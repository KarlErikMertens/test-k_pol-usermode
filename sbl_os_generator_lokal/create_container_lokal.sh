python3 slimbootloader/BootloaderCorePkg/Tools/GenContainer.py create -cl \
CMDL:hv_cmdline_bdf.txt:0 \
ACRN:ACRN.bin:0 \
MVM0:zephyr0.txt:0 \
ZEP0:zephyr0.elf:0 \
ACM0:acpi_vm0.txt:0 \
ACB0:ACPI_VM0.bin:0 \
MVM1:zephyr1.txt:0 \
ZEP1:zephyr1.elf:0 \
ACM1:acpi_vm1.txt:0 \
ACB1:ACPI_VM1.bin:0 \
LMOD:rtlinux.txt:0 \
LKER:bzImage:0 \
ACM2:acpi_vm2.txt:0 \
ACB2:ACPI_VM2.bin:0 \
-o sbl_os_new \
-t MULTIBOOT \
-k OS1_TestKey_Pub_RSA2048_priv.pem \
-s 0
