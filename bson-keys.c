/*
 * Copyright 2013 MongoDB, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */


#include <stdio.h>

#include "bson-keys.h"
#include "bson-string.h"


/*
 *--------------------------------------------------------------------------
 *
 * bson_uint32_to_string --
 *
 *       Converts @value to a string.
 *
 *       If @value is from 0 to 1000, it will use a constant string in the
 *       data section of the library.
 *
 *       If not, a string will be formatted using @str and snprintf(). This
 *       is much slower, of course and therefore we try to optimize it out.
 *
 *       @strptr will always be set. It will either point to @str or a
 *       constant string. You will want to use this as your key.
 *
 * Parameters:
 *       @value: A #uint32_t to convert to string.
 *       @strptr: (out): A pointer to the resulting string.
 *       @str: (out): Storage for a string made with snprintf.
 *       @size: Size of @str.
 *
 * Returns:
 *       The number of bytes in the resulting string.
 *
 * Side effects:
 *       None.
 *
 *--------------------------------------------------------------------------
 */

size_t
bson_uint32_to_string (uint32_t value,      /* IN */
                       const char **strptr, /* OUT */
                       char *str,           /* OUT */
                       size_t size)         /* IN */
{
   *strptr = str;

   return bson_snprintf (str, size, "%u", value);
}
