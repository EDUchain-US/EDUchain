
Debian
====================
This directory contains files used to package EDCd/EDC-qt
for Debian-based Linux systems. If you compile EDCd/EDC-qt yourself, there are some useful files here.

## EDC: URI support ##


EDC-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install EDC-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your EDCqt binary to `/usr/bin`
and the `../../share/pixmaps/EDC128.png` to `/usr/share/pixmaps`

EDC-qt.protocol (KDE)

