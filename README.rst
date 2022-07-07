Gegebenheiten Pürfen:
-passenden Kernel für den sbl_os_generator?

-befindet sich die Zephyr Bauumgebung auf der commit ID: 74c00d0b4e534519ca9a8f5d589163766658e097?
Wenn nicht, funktioniert wahrscheinlich die zweite doorbell nicht.
Wenn die comit ID nicht passt, so wird gewechselt:
git fetch origin 74c00d0b4e534519ca9a8f5d589163766658e097
git checkout FETCH_HEAD
git switch -c <name_des_branches>

Vor der Ausührung des Programms:
- in den Datein delete_flashLinux.sh, deleteLinux.sh, flasLinux.sh und flashZephyr.sh die IP Adresse anpassen.
aktuelle Adresse:  EHLIP=192.168.200.2 
neue Adresse: EHLIP=<neue IP Adresse>

- in den Datein delete_flashLinux.sh und flashLinux.sh den Speicherpfad der Linux Datein anpassen.
aktueller Speicherpfad: cd /home/user/zephyrproject/ISI_Programme/isiApp/Linux_VM 
neuer Speicherpfad: cd /<Speicherpfad>/isiApp/Linux_VM

Zum ausführen des Programms:
-Zephyr:
1. das skript flashZephyr.sh ausführen.
Dadruch werden die beiden Programme für die zephyr VMs gebaut. Im Anschluss werden die zwei .elf Datein aus dem build Ordner in den sbl_os Generator kopiert und dieser ausgeführt. Das dadruch erstellte sbl_os wird daraufhin auf das Board kopiert.
2. das Board neu starten. Dafür gibt es zwei Möglichkeiten:
	1. Das Board einmal vom Strom trennen
	2. in die Console der seriellen Schnittstelle den Befehl "reboot" eingeben

- Linux Variante 1:
1. ausführen des skripts flash_deleteLinux.sh
Dadruch werden die alten Linux Datein gelöscht, und die neuen (geänderten) Linux Datein übertragen.
Außerdem wird das skript für den Ivshemem Treiber , welches für den Shared Memory nötig ist, ausgeführt.
Ebenfalls werden von allen "Modulen" Objektdatein erstellt und im Anschluss zu einer Objektdatei zusammengeführt.
Zum Schluss wird diese Objektdatei direkt ausgeführt und so das Linux Prorgamm gestartet.

- Linux Variante 2
1. ausführen des skripts deleteLinux.sh
Dadruch werden die alten Linux Datein gelöscht
2. ausführen des skripts flashLinux.sh
Die neuen (geänderten) Linux Datein werden übertragen.
Außerdem wird das skript für den Ivshemem Treiber , welches für den Shared memory nötig ist, ausgeführt.
Ebenfalls werden von allen "Modulen" Objektdatein erstellt und im Anschluss zu einer Objektdatei zusammengeführt.
Zum Schluss wird diese Objektdatei direkt ausgeführt und so das Linux Prorgamm gestartet.

Vorgehen beim Ausführen der skripte:
1. Ausführen des skirpts flash Zephyr.sh.
2. Warten, bis das skript komplett ausgeführt wurde.
3. Das Board neu starten.
4. Ausführen von Linux Variante 1 oder 2.
