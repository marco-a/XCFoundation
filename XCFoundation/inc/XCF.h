
/*!
		@file			inc/XCF.h
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			23.10.14
	
		@brief
		{$BRIEF}

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#if !defined(XCFPrivate_hGuard__inc_XCF_h)
	#define XCFPrivate_hGuard__inc_XCF_h

	#if !defined(XCFPrivate_hGuard)
		#error Do not directly include this file. Use <XCFoundation/XCFoundation.h> instead.
	#endif

	#include <XCFoundation/inc/types.h>
	#include <XCFoundation/inc/portability.h>

	struct XCFPrivate_vTable {
		XCFAttribute(STDCall)	void *(*const alloc)(XCFSize_t const sz);
		XCFAttribute(noreturn)	void (*const panic)(XCFString_t const fmt, ...);
	};

	XCFAttribute(STDCall)		void *XCF__alloc(XCFSize_t sz);
	XCFAttribute(noreturn)		void XCF__panic(XCFString_t const fmt, ...);

	extern struct XCFPrivate_vTable const XCFPrivate_vTable;

	#define XCF()	(XCFPrivate_vTable)

#endif
