#Karl
EHLIP=192.168.200.2
echo ${EHLIP}

cd Zephyr_Project
west build -p auto -b acrn_ehl_seco -- -DCONF_FILE=prj0.conf
cd ..
cp Zephyr_Project/build/zephyr/zephyr.elf sbl_os_generator_lokal/zephyr0.elf

cd sbl_os_generator_lokal
./create_container_lokal.sh

ssh root@${EHLIP} 'umount /boot'
ssh root@${EHLIP} 'rm /boot/sbl_os'
scp sbl_os_new root@${EHLIP}:/boot/sbl_os
ssh root@${EHLIP} 'ls -l /boot'
ssh root@${EHLIP} 'date'
ssh root@${EHLIP} 'sync'
