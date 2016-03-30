/*
 * MIT License
 *
 * CARGO Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
