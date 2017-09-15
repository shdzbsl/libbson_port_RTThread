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


//#ifdef __APPLE__
//#include <mach/clock.h>
//#include <mach/mach.h>
//#include <mach/mach_time.h>
//#include <sys/time.h>
//#endif


#include "bson-config.h"
#include "bson-compat.h"

#include "bson-clock.h"


/*
 *--------------------------------------------------------------------------
 *
 * bson_gettimeofday --
 *
 *       A wrapper around gettimeofday() with fallback support for Windows.
 *
 * Returns:
 *       0 if successful.
 *
 * Side effects:
 *       @tv is set.
 *
 *--------------------------------------------------------------------------
 */

int
bson_gettimeofday (struct timeval *tv) /* OUT */
{

    // Song: added
    tv->tv_usec = 0;
    BSON_FUN_TIME(&tv->tv_sec);
    
    return 0;
}


/*
 *--------------------------------------------------------------------------
 *
 * bson_get_monotonic_time --
 *
 *       Returns the monotonic system time, if available. A best effort is
 *       made to use the monotonic clock. However, some systems may not
 *       support such a feature.
 *
 * Returns:
 *       The monotonic clock in microseconds.
 *
 * Side effects:
 *       None.
 *
 *--------------------------------------------------------------------------
 */

int64_t
bson_get_monotonic_time (void)
{
   struct timeval tv;

   bson_gettimeofday (&tv);
   return (tv.tv_sec * 1000000UL) + tv.tv_usec;
}
