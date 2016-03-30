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
