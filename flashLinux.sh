#this script flashes the linux vm with an new ivshmem test applikation
#Karl
EHLIP=192.168.200.2 
echo ${EHLIP}

cd /home/user/zephyrproject/ISI_Programme/isiApp/Linux_VM

ssh root@${EHLIP} 'rm l_vm_main.c'
ssh root@${EHLIP} 'rm l_vm_main'
ssh root@${EHLIP} 'rm ivshmem_driver.sh'

scp ivshmem_driver.sh root@${EHLIP}:~
scp l_vm_main.c root@${EHLIP}:~

ssh root@${EHLIP} 'gcc l_vm_main.c -o l_vm_main -lrt'
ssh root@${EHLIP} './ivshmem_driver.sh'
ssh root@${EHLIP} './l_vm_main'
ssh root@${EHLIP} 'date'   
ssh root@${EHLIP} 'sync'


