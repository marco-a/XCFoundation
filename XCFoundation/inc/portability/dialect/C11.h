
/*!
		@file			inc/portability/dialect/C11.h
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			23.10.14
	
		@brief
		{$BRIEF}

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#if !defined(XCFPrivate_hGuard__inc_portability_dialect_C11_h)
	#define XCFPrivate_hGuard__inc_portability_dialect_C11_h

	#if !defined(XCFPrivate_hGuard)
		#error Do not directly include this file. Use <XCFoundation/XCFoundation.h> instead.
	#endif

	#if !defined(XCFAttribute__TLS)
		#define XCFAttribute__TLS			_Thread_local
	#endif

	#if !defined(XCFAttribute__noreturn)
		#define XCFAttribute__noreturn		_Noreturn
	#endif

#endif
