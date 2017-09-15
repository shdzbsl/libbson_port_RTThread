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


#ifndef BSON_MACROS_H
#define BSON_MACROS_H


//#if !defined(BSON_INSIDE) && !defined(BSON_COMPILATION)
//#error "Only <bson.h> can be included directly."
//#endif


#include <stdio.h>
#include <stdint.h>

#ifdef __cplusplus
#include <algorithm>
#endif

#include "bson-config.h"


#ifdef __cplusplus
#define BSON_BEGIN_DECLS extern "C" {
#define BSON_END_DECLS }
#else
#define BSON_BEGIN_DECLS
#define BSON_END_DECLS
#endif


#if defined (__GNUC__)
#define BSON_GNUC_CHECK_VERSION(major, minor) \
   ((__GNUC__ > (major)) ||                   \
    ((__GNUC__ == (major)) && (__GNUC_MINOR__ >= (minor))))
#else
#define BSON_GNUC_CHECK_VERSION(major, minor) 0
#endif


#if defined (__GNUC__)
#define BSON_GNUC_IS_VERSION(major, minor) \
   ((__GNUC__ == (major)) && (__GNUC_MINOR__ == (minor)))
#else
#define BSON_GNUC_IS_VERSION(major, minor) 0
#endif



/* Decorate public functions:
 * - if BSON_STATIC, we're compiling a program that uses libbson as a static
 *   library, don't decorate functions
 * - else if BSON_COMPILATION, we're compiling a static or shared libbson, mark
 *   public functions for export from the shared lib (which has no effect on
 *   the static lib)
 * - else, we're compiling a program that uses libbson as a shared library,
 *   mark public functions as DLL imports for Microsoft Visual C
 */

#define BSON_API
#define BSON_CALL


#define BSON_EXPORT(type) BSON_API type BSON_CALL


#define BSON_MIN(a, b) (((a) < (b)) ? (a) : (b))


#define BSON_MAX(a, b) (((a) > (b)) ? (a) : (b))


#define BSON_ABS(a) (((a) < 0) ? ((a) * -1) : (a))


#define BSON_ALIGN_OF_PTR (sizeof (void *))


#define BSON_ALIGNED_BEGIN(_N)      __attribute__((aligned(_N)))
#define BSON_ALIGNED_END(_N)


#define bson_str_empty(s) (!s[0])
#define bson_str_empty0(s) (!s || !s[0])



#define BSON_FUN_TIME   rt_time


#define BSON_FUNC   __FUNCTION__

#define BSON_ASSERT(test)                                  \
   do {                                                    \
      if (!(BSON_LIKELY (test))) {                         \
         rt_kprintf (                                      \
                  "%s:%d %s(): precondition failed: %s\n", \
                  __FILE__,                                \
                  __LINE__,                                \
                  BSON_FUNC,                               \
                  #test);                                  \
         while (1);                                         \
      }                                                    \
   } while (0)


#define BSON_STATIC_ASSERT(s) BSON_STATIC_ASSERT_ (s, __LINE__)
#define BSON_STATIC_ASSERT_JOIN(a, b) BSON_STATIC_ASSERT_JOIN2 (a, b)
#define BSON_STATIC_ASSERT_JOIN2(a, b) a##b
#define BSON_STATIC_ASSERT_(s, l)                             \
   typedef char BSON_STATIC_ASSERT_JOIN (static_assert_test_, \
                                         __LINE__)[(s) ? 1 : -1]


#define BSON_GNUC_CONST
#define BSON_GNUC_WARN_UNUSED_RESULT


#define BSON_GNUC_NULL_TERMINATED
#define BSON_GNUC_INTERNAL

#define BSON_LIKELY(v) v
#define BSON_UNLIKELY(v) v



#define BSON_GNUC_PRINTF(f, v) __attribute__ ((format (printf, f, v)))


// based on rtthread RTOS.

#define BSON_MEM_MALLOC     rt_malloc
#define BSON_MEM_CALLOC     rt_calloc
#define BSON_MEM_RELLOC     rt_realloc
#define BSON_MEM_FREE       rt_free

#define BSON_FILE_OPEN(path, mode)      open(path, mode, 0)
#define BSON_FILE_READ(fd, buf, len)    read(fd, buf, len)
#define BSON_FILE_WRITE(fd, buf, len)   write(fd, buf, len)
#define BSON_FILE_CLOSE(fd)             close(fd)

#define BSON_PRINTF         rt_kprintf


#define BSON_WORD_SIZE  32



#define BSON_INLINE   __inline



#define BSON_ENSURE_ARRAY_PARAM_SIZE(_n) static(_n)
#define BSON_TYPEOF typeof


#if BSON_GNUC_CHECK_VERSION(3, 1)
#define BSON_GNUC_DEPRECATED __attribute__ ((__deprecated__))
#else
#define BSON_GNUC_DEPRECATED
#endif


#if BSON_GNUC_CHECK_VERSION(4, 5)
#define BSON_GNUC_DEPRECATED_FOR(f) \
   __attribute__ ((deprecated ("Use " #f " instead")))
#else
#define BSON_GNUC_DEPRECATED_FOR(f) BSON_GNUC_DEPRECATED
#endif

// Song: added
struct timeval {
uint32_t tv_sec; /* seconds */
uint32_t tv_usec; /* microseconds */
};


#endif /* BSON_MACROS_H */
