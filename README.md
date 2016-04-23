CARGO
=====
[![Build Status](https://travis-ci.org/libgame/cargo.svg?branch=master)](https://travis-ci.org/libgame/cargo)
[![Build status](https://ci.appveyor.com/api/projects/status/qbqgrdeuikjt6gic/branch/master?svg=true)](https://ci.appveyor.com/project/ssbx/cargo/branch/master)

Simple and stupid C argument (argv) parser.

Build
-----
Just include cargo.h to your project.

CARGO tests are built with CMake for all platforms.
You can also use the fake configure script provided to set it up on unix:
```sh
$ ./configure
$ make
```

Doc
---
Depends on Doxygen.
```sh
$ make cargo_doc
```

Example
-------
To handle the following program arguments:
```sh
./myprog --flag1 --flag2= --flag3=hello --flag4="Hello world"
```

You could write this:
```c
[...]

int main(int argc, char* argv[])
{
    char* f1 = cargoFlag("flag1", "FALSE", argc, argv);         // f1 = "TRUE"
    char* f2 = cargoFlag("flag2", "defaultval", argc, argv);    // f2 = ""
    char* f3 = cargoFlag("flag3", "bye", argc, argv);           // f3 = "hello"
    char* f4 = cargoFlag("flag4", "Bye world", argc, argv);     // f4 = "Hello world"
    char* f5 = cargoFlag("flag5", "default", argc, argv);       // f5 = "default"
    char* f6 = cargoFlag("flag6", "FALSE", argc, argv);         // f6 = "FALSE"

[...]
```
