# Atari ST GCC setup

![GEM screenshot](gem_screenshot.png)

Setup a virtual machine with [Vagrant](https://www.vagrantup.com/) and installs [MiNT's tool chain](http://vincent.riviere.free.fr/soft/m68k-atari-mint/) for **GCC 4.x** and download the latest version of [EmuTOS](https://sourceforge.net/projects/emutos/). Also includes a configuration file for [Hatari](http://hatari.tuxfamily.org/) and sample C source code.

Just run:

````console
vagrant up
````

So, just wait provision ends.

Few tips:

* Edit your code inside `./src` structure, in virtual machine it's
  mapped as `/vagrant/src`;
* Use `vagrant ssh` to access the virtual machine and `vagrant help`
  for more details;
* To compile, use `m68k-atari-mint-gcc «program».c -o «program».tos`;
* To start Hatari, run `hatari -c hatari.conf`, this configuration file
  uses EmuTOS instead TOS;
* In Hatari `./src` is mapped as `C:` drive;
* Press «Contro»+«Z» to open EmuCON2;
* Happy Hacking!