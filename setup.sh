#!/bin/bash
cd $(dirname $0)
echo $(pwd)

sudo apt update
sudo apt install libfftw3-dev -y
sudo apt install libopencv-dev -y

command -v nvcc && sudo apt install libtorch-dev -y 
command -v nvcc || sudo apt install libtorch-cpu -y
command -v tegrastats && sudo apt install libtorch-dev -y 

sudo apt-get install gcc g++ gfortran git patch wget pkg-config liblapack-dev libmetis-dev -y
sudo apt install libeigen3-dev -y
sudo apt install ros-foxy-eigen3-cmake-module -y
sudo apt install libopenmpi-dev -y
sudo apt install libyaml-cpp-dev -y
sudo apt-get remove proj-bin -y
sudo apt install libmynteye-dev -y
sudo apt install libadolc2 -y
git submodule init
git submodule update

curr_dir=$(pwd)
if [ -e ~/git/setup-workstation ]
then
    curr_dir=$(pwd)
    cd ~/git/setup-workstation
    git pull
    cd required
    cat setup_cuda.sh
    cd $curr_dir
fi
sudo apt install libnvinfer-dev libnvonnxparsers-dev libnvparsers-dev libnvinfer-plugin-dev -y

cd $curr_dir
sudo apt-get install git build-essential cmake libboost-dev -y
sudo apt-get install doxygen graphviz -y
[ -e ../ad-rss-lib ] || git clone https://github.com/irh-ca-team-car/ad-rss-lib.git
[ -e ./ad-rss-lib ] && mv ./ad-rss-lib ..

 cd ../ad-rss-lib
 git submodule update --init
 sudo apt-get install libboost-all-dev libpugixml-dev libgtest-dev libpython2-dev libpython3-dev -y
 sudo apt-get install castxml -y
 sudo apt install liblapacke-dev -y
 pip install --user pygccxml pyplusplus xmlrunner
pip3 install --user pygccxml pyplusplus xmlrunner


cd $curr_dir
cd osqp
git submodule init
git submodule update
[ -e ./build ] || mkdir build
cd build

cmake -G "Unix Makefiles" ..
cmake --build .
sudo cmake --build . --target install

cd $curr_dir

cd json
[ -e ./build ] || mkdir build
cd build

cmake -G "Unix Makefiles" ..
cmake --build .
sudo cmake --build . --target install

cd $curr_dir

if [ -e /usr/local/lib/libproj.so.12.0.0 ]
then
    [ -e PROJ ] && sudo rm PROJ -rd
fi
[ -e proj-4.9.3 ] || wget https://download.osgeo.org/proj/proj-4.9.3.tar.gz
[ -e proj-4.9.3 ] || tar -xvf proj-4.9.3.tar.gz
[ -e PROJ ] || sudo mv proj-4.9.3 PROJ
[ -e proj-4.9.3.tar.gz ] && rm proj-4.9.3.tar.gz
cd PROJ
[ -e ./build ] || mkdir build
cd build

cmake -G "Unix Makefiles" ..
cmake --build .
sudo cmake --build . --target install

cd $curr_dir

if [ ! -e portaudio ]
then
    wget http://files.portaudio.com/archives/pa_stable_v190700_20210406.tgz
    tar -xvf pa_stable_v190700_20210406.tgz
    rm pa_stable_v190700_20210406.tgz

    sudo apt-get install libasound-dev -y
    cd portaudio
    ./configure && make
    sudo make install

    cd ~/git/setup-workstation
    git pull
    cd required
    cat setup_cuda.sh
    cd $curr_dir
fi

cd $curr_dir
cd util
bash install-adolc.sh
bash install-ipopt.sh

sudo rm /usr/bin/gcc
sudo ln /usr/bin/gcc-7 /usr/bin/gcc

cd $curr_dir 
cd ..

[ -e flir_boson_usb ] || git clone git@github.com:irh-ca-team-car/flir_boson_usb.git
[ -e imu_tools ] || git clone git@github.com:irh-ca-team-car/imu_tools.git
[ -e mynteye-ros-improved ] || git clone git@github.com:irh-ca-team-car/mynteye-ros-improved.git -b ros2
bash mynteye-ros-improved/setup.sh
[ -e oscc-commander ] || git clone git@github.com:irh-ca-team-car/oscc-commander.git
[ -e radar_ars408 ] || git clone git@github.com:irh-ca-team-car/radar_ars408.git
[ -e ros2_canbus ] || git clone git@github.com:irh-ca-team-car/ros2_canbus.git
[ -e rslidar_msg ] || git clone git@github.com:irh-ca-team-car/rslidar_msg.git
[ -e rslidar_sdk ] || git clone git@github.com:irh-ca-team-car/rslidar_sdk.git
[ -e zed-ros2-wrapper ] || git clone https://github.com/stereolabs/zed-ros2-wrapper.git
[ -e septentrio_gnss_driver ] || git clone git@github.com:septentrio-gnss/septentrio_gnss_driver.git -b ros2

[ -e rslidar_sdk ] && cd rslidar_sdk
git submodule init
git submodule update

cd $curr_dir 
cd ..
cd rslidar_sdk
git submodule init
git submodule update
cd ..

sudo apt install ros-foxy-nmea-msgs -y
sudo apt install ros-foxy-gps-msgs -y
sudo apt install ros-foxy-geographic-msgs -y
sudo apt install ros-foxy-camera-calibration-parsers ros-foxy-camera-info-manager -y
sudo apt install ros-foxy-can-msgs -y
sudo apt install libgeographic-dev -y
sudo apt install libosmium2-dev -y
sudo apt install libfreeimage-dev -y
sudo apt install libprotobuf-dev -y
sudo apt install protobuf-compiler -y
sudo apt autoremove -y
sudo apt-get install -y  libpcap-dev -y