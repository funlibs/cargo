/*
 * MIT License
 *
 * CGLM Copyright (c) 2016 Sebastien Serre <ssbx@sysmo.io>.
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
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <cargo.h>


/*
 * vesult, mresult and fresult values have been computed the C++ glm library.
 */

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

static char* TEST_VALUE;
static char* TEST_EXPECTED;

static char* cargo_compare()
{
    printf("Compare %s to %s\n", TEST_VALUE, TEST_EXPECTED);

    int diff = strcmp(TEST_VALUE, TEST_EXPECTED);
    mu_assert("Compare does not match", diff == 0);

    return NULL;
}

static char* cargo_test(int argc, char** argv)
{

    char* testType  = cargoFlag("type", "UNDEFINED", argc, argv);
    TEST_VALUE = cargoFlag("val", "UNDEFINED", argc, argv);
    printf("type is %s %d\n", testType, strcmp(testType, "boolean"));

    int diff;
    char* result = NULL;
    if (strcmp(testType, "boolean") == 0) {
        TEST_EXPECTED = "TRUE";
    } else if (strcmp(testType, "empty") == 0)
        TEST_EXPECTED = "";
    else if (strcmp(testType, "value") == 0)
        TEST_EXPECTED = "innerValue";
    else if (strcmp(testType, "missing") == 0)
        TEST_EXPECTED = "UNDEFINED";
    else {
        return "no such test";
    }

    mu_run_test(cargo_compare);

    return NULL;

}

int main(int argc, char* argv[])
{
    char* result = cargo_test(argc, argv);

    if (result != 0)
        printf("%s\n", result);

    return result != NULL;

}

