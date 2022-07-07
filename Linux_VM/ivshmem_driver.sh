modprobe uio
modprobe uio_pci_generic
echo "1af4 1110" > /sys/bus/pci/drivers/uio_pci_generic/new_id

# Move all IRQs to core 0.
for i in `cat /proc/interrupts | grep '^ *[0-9]*[0-9]:' | awk {'print $1'} | sed 's/:$//' `;
do
    echo setting $i to affine for core zero
    echo 1 > /proc/irq/$i/smp_affinity
done

# Move all rcu tasks to core 0.
for i in `pgrep rcu`; do taskset -pc 0 $i; done

# Change realtime attribute of all rcu tasks to SCHED_OTHER and priority 0
for i in `pgrep rcu`; do chrt -v -o -p 0 $i; done

# Change realtime attribute of all tasks to SCHED_OTHER and priority 0
for i in `pgrep /1`; do chrt -v -o -p 0 $i; done

# Change realtime attribute of all tasks to SCHED_OTHER and priority 0
for i in `ps -A -o pid`; do chrt -v -o -p 0 $i; done

# disabling timer migration
echo disabling timer migration
echo 0 > /proc/sys/kernel/timer_migration