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

#include <stdlib.h>
#include <stdio.h>
#include <cargo.h>

// Minunit include BEGIN
/* Copyright (C) 2002 John Brewer */
#define mu_assert(message, test) do { \
    if (!(test)) return message; \
} while (0)
#define mu_run_test(test) do { \
    char *message = test(); \
    tests_run++; \
    if (message) return message; \
} while (0)
int tests_run = 0;
// Minunit include END


static char* test_boolean() {
    
    return "error";
}

static char* cargo_test(char* test_name) {

    mu_run_test(test_boolean);

    return NULL;

}

int main(int argc, char* argv[])
{

    char* result = cargo_test(argv[1]);

    if (result != 0)
        printf("%s\n", result);

    return result != NULL;

}

