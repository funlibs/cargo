CARGO
=====

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
