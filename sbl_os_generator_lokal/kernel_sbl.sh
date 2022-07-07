python3 \
slimbootloader/BootloaderCorePkg/Tools/GenContainer.py \
create -cl \
CMDL:$1:0 \
KRNL:$2:0 \
INRD:$3:0 \
-o sbl_os_kernel \
-t CLASSIC \
-k OS1_TestKey_Pub_RSA2048_priv.pem \
-s 0
