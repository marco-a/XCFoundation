
/*!
		@file			inc/portability/compiler/GCC.h
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			23.10.14
	
		@brief
		{$BRIEF}

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#if !defined(XCFPrivate_hGuard__inc_portability_compiler_GCC_h)
	#define XCFPrivate_hGuard__inc_portability_compiler_GCC_h

	#if !defined(XCFPrivate_hGuard)
		#error Do not directly include this file. Use <XCFoundation/XCFoundation.h> instead.
	#endif

	#include <XCFoundation/inc/portability.h>

	#if !defined(XCFAttribute__TLS)
		#define XCFAttribute__TLS			__thread
	#endif

	#if !defined(XCFAttribute__noreturn)
		#define XCFAttribute__noreturn		__attribute__((__noreturn__))
	#endif

	/* UC */
	#if XCF__getCompilerVer() >= 40100
		#define XCFPrivate_features__Atomics	1

		#define XCFPrivate_atomics__fetchAndAdd(_type)																												\
			static inline XCFAtomic ## _type ## _t XCFAtomic ## _type ## __fetchAndAdd(XCFAtomic ## _type ## _t *const var, XCFAtomic ## _type ## _t const val) {	\
				return __sync_fetch_and_add(var, val);																												\
			}

		#define XCFPrivate_atomics__addAndFetch(_type)																												\
			static inline XCFAtomic ## _type ## _t XCFAtomic ## _type ## __addAndFetch(XCFAtomic ## _type ## _t *const var, XCFAtomic ## _type ## _t const val) {	\
				return __sync_add_and_fetch(var, val);																												\
			}

		#define XCFPrivate_atomics__defineFunctions(_type)	\
			XCFPrivate_atomics__fetchAndAdd(_type)			\
			XCFPrivate_atomics__addAndFetch(_type)

	#endif

#endif
