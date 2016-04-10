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

#include <string.h>
#include <stdlib.h>

#define FLAG_MAX_SIZE 80

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
static char* cargoFlag(
        char*  name, 
        char*  defaultValue,
        int    argc,
        char** argv)
{
    // generate the flag name
    char flagName[FLAG_MAX_SIZE];
    strcpy(&flagName[0], "--");
    strcpy(&flagName[2], name);
    strcpy(&flagName[strlen(name) + 2], "=");

    // return value
    char* content = NULL;

    // iterate over argv
    int j;
    for (j = 0; j < argc; j++)
    {

        char* arg = argv[j];

        if (strncmp(flagName, arg, strlen(flagName)) == 0)
        { // flag found with "="

            if (strlen(flagName) == strlen(arg)) // no content
            {

                if (content != NULL) free(content);
                content = malloc(1);
                *content = '\0';

                continue;

            }

            // there is some content
            if (content != NULL) free(content);
            content = malloc(strlen(arg) - strlen(flagName) + 1);
            strcpy(content, &arg[strlen(flagName)]);

        }
        else if (strncmp(flagName, arg, strlen(flagName) - 1) == 0)
        { // found partial flag --${name}

            // set content to true if it is the end of the str
            if (strlen(arg) == strlen(flagName) -1)
            {

                if (content != NULL) free(content);
                content = malloc(strlen("TRUE") + 1);
                strcpy(content, "TRUE");

            }
        }
    }

    if (content == NULL)
    { // flag not found set default

        content = malloc(strlen(defaultValue) + 1);
        strcpy(content, defaultValue);

    }

    return content;

}

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // CARGO_H

