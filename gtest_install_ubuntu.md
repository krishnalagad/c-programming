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
```

Install GMock
```bash
# Assuming you are starting in your home directory
mkdir -p $HOME/build
cd $HOME/build

# Configure CMake to build both gtest and gmock
sudo cmake /usr/src/googletest/ # This path assumes that Google Test is still located here

# Build (this builds both Google Test and Google Mock)
sudo make

# Copy the Google Mock libraries to /usr/lib (or another directory in your library path)
sudo cp lib/libgmock* /usr/lib/

# Create links in your local library directory for easier use with linking in projects
sudo ln -s /usr/lib/libgmock.a /usr/local/lib/googletest/libgmock.a
sudo ln -s /usr/lib/libgmock_main.a /usr/local/lib/googletest/libgmock_main.a

cd ..
sudo rm -rf build

```

Install libraries globally now
```bash
cd /usr/src/googletest
mkdir build
cd build
cmake ..
make
sudo make install
```
