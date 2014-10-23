
/*!
		@file			application.c
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			22.10.14

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#include <XCFoundation/XCFoundation.h>

// Check if thread local storage is avaiable
#if XCF__hasAttribute(TLS)
	XCFAttribute(TLS, STDCall) XCFInteger_t myInteger = 0U;
#endif

XCFUInteger_t XCFApplication__main(XCFUInteger_t const argc, XCFString_t const argv[]) {

	// Your app code goes here
	
	{
		// Check if atomics are avaiable
		#if XCF__hasFeature(Atomics)
			XCFAtomicInt8_t atomicChar = 0;
			
			atomicChar = XCFAtomicInt8__fetchAndAdd(&atomicChar, 1);
		#endif
		
		// Crash the program
		XCF().panic("Hello world");
	}
	
	return 0;
}
