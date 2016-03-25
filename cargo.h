/*
 * CARGO Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 * 
 * This file is provided to you under the Apache License, Version 2.0
 * (the "License"); you may not use this file except in compliance with
 * the License.  You may obtain a copy of the License at
 * 
 *   http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
 * WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.  See
 * the License for the specific language governing permissions and limitations
 * under the License.
 */

/**
 * @file cargo.h
 */
#ifndef CARGO_H
#define CARGO_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @brief Get the content of a flag the default value, or the string "TRUE".
 *
 * Example:
 *
 * To handle the following program arguments:
 * ./myprog --flag1 --flag2= --flag3=hello --flag4="Hello world"
 *
 * char* f1 = cargoFlag("flag1", "FALSE", argc, argv); // f1 = "TRUE"
 * char* f2 = cargoFlag("flag2", "defaultval", argc, argv); // f2 = ""
 * char* f3 = cargoFlag("flag3", "bye", argc, argv); // f1 = "hello"
 * char* f4 = cargoFlag("flag4", "Bye world", argc, argv); // f1 = "Hello world"
 * char* f5 = cargoFlag("flag5", "default", argc, argv); // f1 = "default"
 * char* f6 = cargoFlag("flag6", "FALSE", argc, argv); // f1 = "FALSE"
 *
 * @param flag The flag name
 * @param defaultValue The default value if the flag is not found
 * @param argc The original main(argc,_) value
 * @param argv The original main(_,argv) value
 *
 * @return A charra array containing the flag value
 */
char* cargoFlag(
        char*  flag, 
        char*  defaultValue,
        int    argc,
        char** argv);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CARGO_H
