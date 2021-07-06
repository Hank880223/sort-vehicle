# ncnn-sort-vehicle
## How to build i.MX8M Plus BSP


## Cross compile ncnn with i.MX8M Plus for aarch64
    $ git clone https://github.com/Tencent/ncnn.git
    $ cd ncnn
    $ git submodule update --init
    $ mkdir build && cd build
    $ . /opt/bsp-5.4.70-2.3.3/environment-setup-aarch64-poky-linux
    $ cmake ..
    $ make -j`nproc` && make install
    
move install/ include and lib folder to ncnn-sort-vehicle folder
```
└─ncnn-sort-vehicle
    ├─include
    │  └─ncnn
    ├─lib
    └─src
```    
    
## Build ncnn-sort-vehicle
    $ mkdir build && cd build
    $ . /opt/bsp-5.4.70-2.3.3/environment-setup-aarch64-poky-linux
    $ cmake ..
    $ make -j`nproc`

## How to use 
