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

#define CARGO_TRUE  0;
#define CARGO_FALSE 1;

/*
 * @brief Defines a boolean flag.
 * Both form will be intepreted as true --myFlag=true or --myFlag.
 *
 * @param flag The flag name
 * @param userVar Where the value will be stored (CARGO_TRUE | GARGO_FALSE)
 * @param defaultValue The default value if the flag is not found
 * @param usage Flag usage
 */
void cargoBoolean(
        char* flag,
        int*  userVar,
        int   defaultValue,
        char* usage);

/*
 * @brief Defines an integer flag.
 *
 * @param flag The flag name
 * @param userVar Where the value will be stored
 * @param defaultValue The default value if the flag is not found
 * @param usage Flag usage
 */
void cargoInteger(
        char* flag,
        int*  userVar,
        int   defaultValue,
        char* usage);

/*
 * @brief Defines a float flag.
 *
 * @param flag The flag name
 * @param userVar Where the value will be stored
 * @param defaultValue The default value if the flag is not found
 * @param usage Flag usage
 */
void cargoFloat(
        char*  flag, 
        float* userVar,
        float  defaultValue,
        char*  usage);

/*
 * @brief Defines a String flag.
 *
 * Value is truncated if userVarSize can not contain it.
 *
 * @param flag The flag name
 * @param userVar Where the value will be stored
 * @param userVarSize The lenght of userVar data char array
 * @param defaultValue The default value if the flag is not found
 * @param usage Flag usage
 */
void cargoString(
        char* flag, 
        char* userVar,
        int   userVarSize,
        char* defaultValue,
        char* usage);

/*
 * @brief Parse arguments
 */
void cargoParse(int argc, char* argv[]);

/*
 * @brief Print flags usage to stdout
 */
void cargoPrintUsage();

/*
 * @brief Get the usage string as a null terminated char array.
 */
char* cargoGetUsage();

#endif // CARGO_H
