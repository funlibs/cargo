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
#include "cargo.h"
#include "stdio.h"

int main(int argc, char* argv[])
{
    char* f1 = cargoFlag("flag1", "FALSE", argc, argv);
    char* f2 = cargoFlag("flag2", "defaultval", argc, argv);
    char* f3 = cargoFlag("flag3", "bye", argc, argv);
    char* f4 = cargoFlag("flag4", "Bye world", argc, argv);
    char* f5 = cargoFlag("flag5", "default", argc, argv);
    char* f6 = cargoFlag("flag5", "FALSE", argc, argv);

    printf("f1 = %s\n", f1);
    printf("f2 = %s\n", f2);
    printf("f3 = %s\n", f3);
    printf("f4 = %s\n", f4);
    printf("f5 = %s\n", f5);

    return 0;

}
