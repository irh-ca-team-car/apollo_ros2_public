#!/bin/bash

set -e # exit on first error

install_adolc()
{

    echo "Prepare to install ADOLC ..."
    TEMP_DIR=$(mktemp -d)
    CWD=~/ros2/src/apollo-ros2
    ADOLC_DIR=$CWD/ADOL-C
    echo $TEMP_DIR
    echo $CWD

    if [ -e "/usr/local/include/adolc" ]; then
        echo "ADOLC is already installed"
    else
        echo "Installing ADOLC"
        cd $TEMP_DIR
        git clone https://github.com/coin-or/ADOL-C
        cd ADOL-C
        git checkout e1fe4761ba54042b37fdff4b03215120ff8671e1
        autoreconf -fi
        ./configure --prefix=/usr/local/  --enable-sparse
        make
        sudo make install
    fi

    yes | rm $TEMP_DIR -rd 

}

install_adolc
