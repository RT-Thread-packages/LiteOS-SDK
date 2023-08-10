/* ----------------------------------------------------------------------------
 * Copyright (c) Huawei Technologies Co., Ltd. 2013-2019. All rights reserved.
 * Description: Type define
 * Author: Huawei LiteOS Team
 * Create: 2013-01-01
 * Redistribution and use in source and binary forms, with or without modification,
 * are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright notice, this list of
 * conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright notice, this list
 * of conditions and the following disclaimer in the documentation and/or other materials
 * provided with the distribution.
 * 3. Neither the name of the copyright holder nor the names of its contributors may be used
 * to endorse or promote products derived from this software without specific prior written
 * permission.
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
 * ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * --------------------------------------------------------------------------- */

/**
 * @defgroup los_typedef Type define
 * @ingroup kernel
 */

#ifndef _LOS_TYPEDEF_H
#define _LOS_TYPEDEF_H

#include <rtthread.h>

#ifdef __cplusplus
#if __cplusplus
extern "C" {
#endif /* __cplusplus */
#endif /* __cplusplus */

#define OS_STRING(x)  #x
#define X_STRING(x) OS_STRING(x)

/* type definitions */
typedef rt_uint8_t          UINT8;
typedef rt_uint16_t         UINT16;
typedef rt_uint32_t         UINT32;
typedef rt_uint64_t         UINT64;
typedef rt_int8_t           INT8;
typedef rt_int16_t          INT16;
typedef rt_int32_t          INT32;
typedef rt_int64_t          INT64;

typedef float              FLOAT;
typedef double             DOUBLE;
typedef char               CHAR;

#ifdef ARCH_CPU_64BIT
typedef unsigned long      UINTPTR;
typedef signed long        INTPTR;
#ifndef RT_USING_LIBC
typedef INT64              ssize_t;
typedef UINT64             size_t;
#endif /* RT_USING_LIBC */
#else
typedef unsigned int       UINTPTR;
typedef signed int         INTPTR;
#ifndef RT_USING_LIBC
typedef INT32              ssize_t;
typedef UINT32             size_t;
#endif /* RT_USING_LIBC */
#endif /* ARCH_CPU_64BIT */
typedef UINTPTR            AARCHPTR;
typedef size_t             BOOL;

typedef volatile INT32     Atomic;
typedef volatile INT64     Atomic64;

#define VOID               void
#define STATIC             static

#ifndef FALSE
#define FALSE              0U
#endif

#ifndef TRUE
#define TRUE               1U
#endif

#ifndef NULL
#define NULL               ((VOID *)0)
#endif

#ifdef YES
#undef YES
#endif
#define YES                1

#ifdef NO
#undef NO
#endif
#define NO                 0

#define OS_NULL_BYTE       ((UINT8)0xFF)
#define OS_NULL_SHORT      ((UINT16)0xFFFF)
#define OS_NULL_INT        ((UINT32)0xFFFFFFFF)

#ifndef LOS_OK
#define LOS_OK             0
#endif

#ifndef LOS_NOK
#define LOS_NOK            1
#endif

#define OS_FAIL            1
#define OS_ERROR           (UINT32)(-1)
#define OS_INVALID         (UINT32)(-1)

#define asm __asm
#ifdef typeof
#undef typeof
#endif
#define typeof __typeof__

#ifndef LOS_LABEL_DEFN
#define LOS_LABEL_DEFN(label) label
#endif

#ifndef LOSARC_ALIGNMENT
#define LOSARC_ALIGNMENT 8
#endif
/* And corresponding power of two alignment */
#ifndef LOSARC_P2ALIGNMENT
#ifdef LOSCFG_AARCH64
#define LOSARC_P2ALIGNMENT 3
#else
#define LOSARC_P2ALIGNMENT 2
#endif
#endif

/* Give a type or object explicit minimum alignment */
#if !defined(LOSBLD_ATTRIB_ALIGN)
#define LOSBLD_ATTRIB_ALIGN(__align__) __attribute__((aligned(__align__)))
#endif

/* Assign a defined variable to a specific section */
#if !defined(LOSBLD_ATTRIB_SECTION)
#define LOSBLD_ATTRIB_SECTION(__sect__) __attribute__((section(__sect__)))
#endif

/*
 * Tell the compiler not to throw away a variable or function. Only known
 * available on 3.3.2 or above. Old version's didn't throw them away,
 * but using the unused attribute should stop warnings.
 */
#define LOSBLD_ATTRIB_USED __attribute__((used))

#ifdef __cplusplus
#if __cplusplus
}
#endif /* __cplusplus */
#endif /* __cplusplus */

#endif /* _LOS_TYPEDEF_H */
