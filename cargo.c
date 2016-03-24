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

#define CARGO_MAX_FLAGS 20

#define CARGO_INT_T 0
#define CARGO_BOOL_T 1
#define CARGO_STRING_T 2

typedef struct {
    char* name;
    void* userVar;
    int   type;
    int   intValue;
    char* strValue;
    int   strSize;
    char* usage;
} Flag;

Flag* CARGO_flags = NULL;
int   CARGO_flagCount;

void cargoBoolean(
        char* name,
        int*  userVar,
        int   defaultValue,
        char* usage)
{
    if (CARGO_flags == NULL) {
        CARGO_flags = calloc(CARGO_MAX_FLAGS, sizeof(Flag));
        CARGO_flagCount = 0;
    }

    Flag flag;
    flag.type = CARGO_BOOL_T;
    flag.name = name;
    flag.userVar = (void*) userVar;
    flag.intValue = defaultValue;
    flag.usage = usage;

    CARGO_flags[CARGO_flagCount] = flag;
    CARGO_flagCount ++;

}

void cargoInteger32(
        char* name,
        int*  userVar,
        int   defaultValue,
        char* usage)
{

    if (CARGO_flags == NULL) {
        CARGO_flags = calloc(CARGO_MAX_FLAGS, sizeof(Flag));
        CARGO_flagCount = 0;
    }

    Flag flag;
    flag.type = CARGO_INT_T;
    flag.name = name;
    flag.userVar = (void*) userVar;
    flag.intValue = defaultValue;
    flag.usage = usage;

    CARGO_flags[CARGO_flagCount] = flag;
    CARGO_flagCount ++;

}

void cargoString(
        char* name, 
        char* userVar,
        int   userVarSize,
        char* defaultValue,
        char* usage)
{

    if (CARGO_flags == NULL) {
        CARGO_flags = calloc(CARGO_MAX_FLAGS, sizeof(Flag));
        CARGO_flagCount = 0;
    }

    Flag flag;
    flag.type = CARGO_STRING_T;
    flag.name = name;
    flag.userVar = (void*) userVar;
    flag.strSize = userVarSize;
    flag.strValue = defaultValue;
    flag.usage = usage;

    CARGO_flags[CARGO_flagCount] = flag;
    CARGO_flagCount ++;

}

char* cargoGetArg(char* argument)
{
    return strstr(argument, "=");
}

void cargoSetIntFlag(int argc, char* argv[], Flag* flag)
{
    int i;
    char searchFlag[sizeof(flag->name) + 3];
    strcpy(searchFlag, "--");
    strcpy(&searchFlag[2], flag->name);
    strcpy(&searchFlag[sizeof(flag->name) + 2], "=");

    for (i = 0; i < argc; i++) 
    {
        char* argument = argv[i];
        if (strncmp(argument,searchFlag, sizeof(flag->name) + 3) == 0)
        { // found
            char* index = cargoGetArg(argument);
            if (index == NULL) continue;
            char  ivalue[sizeof(index) - 1];
            strncpy(ivalue, &index[1], sizeof(ivalue));
            int value = atoi(ivalue);
            int* uv= (int*) flag->userVar;
            *uv = value;
            break;
        }
    }
}

void cargoSetBoolFlag(int argc, char* argv[], Flag* flag)
{

    int i;
    char searchFlag[sizeof(flag->name) + 3];
    strcpy(searchFlag, "--");
    strcpy(&searchFlag[2], flag->name);
    strcpy(&searchFlag[sizeof(flag->name) + 2], "=");

    for (i = 0; i < argc; i++)
    {
        char* argument = argv[i];
        if (strncmp(argument, searchFlag, sizeof(flag->name) + 3) == 0)
        {
            int* uv = (int*) flag->userVar;
            char* flagVal = cargoGetArg(argument);
            if (flagVal == NULL) // olmost bit not defined
            {
                *uv = flag->intValue;
                continue;
            }
            if (
                    strncmp(flagVal, "=true", 5) == 0 ||
                    strncmp(flagVal, "=1",    2) == 0) 
            {
                *uv = CARGO_TRUE;
            } else {
                *uv = CARGO_FALSE;

            }
        }
        else if (strncmp(argument, searchFlag, sizeof(flag->name) + 2) == 0)
        {
            int* uv = (int*) flag->userVar;
            *uv = CARGO_TRUE;
        }
    }
}

void cargoParse(int argc, char* argv[])
{

    if (CARGO_flags == NULL) return;

    int i;
    Flag f;
    for (i=0; i < CARGO_flagCount; i++)
    {
        f = CARGO_flags[i];
        if (f.type == CARGO_INT_T) {
            int* uv = (int*) f.userVar;
            *uv = f.intValue;
            cargoSetIntFlag(argc, argv, &f);
        } else if (f.type == CARGO_BOOL_T) {
            int* uv = (int*) f.userVar;
            *uv = f.intValue;
            cargoSetBoolFlag(argc, argv ,&f);
        } else if (f.type == CARGO_STRING_T) {
            char* uv = (char*) f.userVar;
            memset(uv, '\0', f.strSize);
            strcpy(uv , f.strValue);
        }
    }
}

void cargoPrintUsage()
{
}

char* cargoGetUsage()
{
}
