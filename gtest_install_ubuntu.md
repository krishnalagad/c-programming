# Google Test Installation on Ubuntu

The following steps are used to install Google Test (gtest) on an Ubuntu system. These commands download the library, build it from source, and set up the environment for using Google Test.

```bash
sudo apt-get install -y libgtest-dev cmake
mkdir -p $HOME/build
cd $HOME/build
sudo cmake /usr/src/googletest/googletest
sudo make
sudo cp lib/libgtest* /usr/lib/
cd ..
sudo rm -rf build
sudo mkdir /usr/local/lib/googletest
sudo ln -s /usr/lib/libgtest.a /usr/local/lib/googletest/libgtest.a
sudo ln -s /usr/lib/libgtest_main.a /usr/local/lib/googletest/libgtest_main.a

