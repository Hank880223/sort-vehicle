# ncnn-sort-vehicle
## Build i.mx8m plus bsp
It is recommended that your computer hard disk capacity is greater than 200G

Install the required dependencies :
    
    $ sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio
    $ sudo apt-get install python python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2
    $ sudo apt-get install libegl1-mesa libsdl1.2-dev pylint3 xterm curl repo

Download jdk-8u191-linux-x64.tar.gz

<https://drive.google.com/file/d/1Sps67mj1zB2ekNy2aiOTLThGOJ3kW1xb/view?usp=sharing>

Install Java Development Kit :

    $ sudo mkdir /usr/java
    $ sudo tar xf jdk-8u191-linux-x64.tar.gz -C /usr/java
    
Add environmental variables to /etc/profile and source

    $ sudo vim /etc/profile
      export JAVA_HOME=/usr/java/jdk1.8.0_191
      export PATH=/usr/java/jdk1.8.0_191/bin:$PATH
      
    $ source /etc/profile
    $ sudo update-alternatives --install /usr/bin/java java /usr/java/jdk1.8.0_191/bin/java 300
    $ sudo update-alternatives --install /usr/bin/javac javac /usr/java/jdk1.8.0_191/bin/javac 300
    $ sudo update-alternatives --install /usr/bin/javaws javaws /usr/java/jdk1.8.0_191/bin/javaws 300
    $ sudo update-alternatives --config java
    $ sudo update-alternatives --config javac
    $ sudo update-alternatives --config javaws

Confirm java version is 1.8.0_191

    $ java -version

Git account settings :
    
    $ git config --global user.name "user name"
    $ git config --global user.email user.name@wpi-group.com
    
Repo environmental settings :

    $ cd ~
    $ mkdir ~/bin
    $ curl http://commondatastorage.googleapis.com/git-repo-downloads/repo > ~/bin/repo
    $ chmod a+x ~/bin/repo
    $ export PATH=~/bin:$PATH
    $ mkdir <Yocto Project>
    $ cd <Yocto Project>
    $ repo init -u https://source.codeaurora.org/external/imx/imx-manifest -b imx-linux-zeus -m imx-5.4.70-2.3.3.xml
    $ repo sync
    
BSP version can inquired from here 

<https://source.codeaurora.org/external/imx/imx-manifest/log/?h=imx-linux-zeus>

BSP environment settings :

Choose your i.MX8 MACHINE
* imx8qmmek <- i.MX 8 QuadMax
* imx8qxpmek
* imx8qxpc0mek
* imx8dxmek
* imx8mqevk
* imx8mmevk
* imx8mnevk
* imx8mpevk <- i.MX 8M Plus
* imx8dxlevk

`$ EULA=1 MACHINE=imx8mpevk DISTRO=fsl-imx-xwayland source ./imx-setup-release.sh -b buildxwayland`

local.conf setting :

add command to <Yocto Project>/buildxwayland/conf/local.conf

    $ IMAGE_INSTALL_append = "packagegroup-imx-ml"
    
BSP compiler :
    
    $ bitbake imx-image-full
    
## Cross compile ncnn with i.mx8m plus for aarch64
    $ git clone https://github.com/Tencent/ncnn.git
    $ cd ncnn
    $ git submodule update --init
    $ mkdir build && cd build
    $ . /opt/bsp-5.4.70-2.3.3/environment-setup-aarch64-poky-linux
    $ cmake ..
    $ make -j`nproc` && make install
    

