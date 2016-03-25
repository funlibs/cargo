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
#include <string.h>
#include <stdlib.h>

#define FLAG_MAX_SIZE 80

char* cargoFlag(
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

