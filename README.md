CARGO
=====

[![Build Status](https://travis-ci.org/ssbx/cargo.svg?branch=master)](https://travis-ci.org/ssbx/cargo)
[![Build status](https://ci.appveyor.com/api/projects/status/visw2qqt04yqfttp/branch/master?svg=true)](https://ci.appveyor.com/project/ssbx/cargo/branch/master)

C argument (argv) parser.

Build
-----
CARGO is build with CMake for all platforms.

You can also use the fake configure script provided to set it up on unix:
```sh
$ ./configure
$ cd build && make all && make test
```

Doc
---
Depends on Doxygen:
```sh
$ make cargo_doc
```
