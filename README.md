# SDL2Boilerplate

SDL2 Boilerplate for a basic window in C/C++14.
Tried & tested on Ubuntu 20.04.3 LTS (Focal Fossa)

## Requirements

- [SDL2](https://github.com/libsdl-org/SDL)(`SDL2.h` and `libSDL2.a`/`libSDL2.so` along with any other SDL2 dependencies)
- [CMake](https://cmake.org/)(3.16 or newer)
- GMake
- GCC compiler version that is C++ 14 compliant -- I did not try building with other compilers.

### Linux (Debian/Ubuntu)

`sudo apt install build-essential`

### Linux (Fedora/RHEL/CentOS)

`sudo yum install gcc gcc-c++ make`

## Building

From the cloned directory:

```bash
cmake -S . -B bin
cmake --build bin
```

## Running

`./build/main`

Press `ESC` or hit the `X` in the window frame to quit out.

## License

SDL2Boilerplate is licensed under the Apache 2 license.
See the [LICENSE](https://github.com/Kingcitaldo125/PySnake/blob/main/LICENSE) file for more details.
