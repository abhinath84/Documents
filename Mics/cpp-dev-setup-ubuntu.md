# Intrduction

C++ Developer setup in ubuntu linux distro.

## Installation

### camke

If `apt` installing latest version of cmake, then use below command:

```sh
$ sudo apt install cmake
```

> NOTE: execute command `camke --version` to check which version of camke `apt` will be intalled.

If `apt` doesn't installing latest cmake version then follow [this link](https://apt.kitware.com) to install latest cmake version.

once installation is complete, execute below command to check:

```sh
$ cmake --version
```

### gcc

To install C/C++ compiler (gcc/g++) and other dev toolkit execute below commands:

```sh
$ sudo apt install build-essential checkinstall zlib1g-dev libssl-dev -y
```

once installation is complete, execute below command to check:

```sh
# gcc
$ gcc --version

# g++
$ g++ --version
```
