# ncnn-sort-vehicle
## Build i.mx8m plus bsp
Install the required dependencies
    
    $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio
    $ sudo apt-get install python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2
    $ sudo apt-get install libegl1-mesa libsdl1.2-dev pylint3 xterm curl repo
    
## Cross compile ncnn with i.mx8m plus for aarch64
    $ git clone https://github.com/Tencent/ncnn.git
    $ cd ncnn
    $ git submodule update --init
    $ mkdir build && cd build
    $ . /opt/bsp-5.4.70-2.3.3/environment-setup-aarch64-poky-linux
    $ cmake ..
    $ make -j`nproc` && make install
    

