
/*!
		@file			portability.h
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			22.10.14
	
		@brief
		{$BRIEF}

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#if !defined(XCFPrivate_hGuard__inc_portability_h)
	#define XCFPrivate_hGuard__inc_portability_h

	#if !defined(XCFPrivate_hGuard)
		#error Do not directly include this file. Use <XCFoundation/XCFoundation.h> instead.
	#endif

	/* Get C dialect */
	#define XCF__getCDialect()	XCFPrivate_CDial

	#define XCFCDialect__89		1u
	#define XCFCDialect__94		2u
	#define XCFCDialect__99		3u
	#define XCFCDialect__11		4u

	#if !defined(__STDC_VERSION__)
		#define XCFPrivate_CDial	XCFCDialect__89
	#elif __STD_C_VERSION__ == 199409L
		#define XCFPrivate_CDial	XCFCDialect__94
	#elif __STD_C_VERSION__ == 199901L
		#define XCFPrivate_CDial	XCFCDialect__99
	#elif __STD_C_VERSION__ == 201112L
		#define XCFPrivate_CDial	XCFCDialect__11
	#endif

	/* C89 & C94 are not supported */
	#if XCF__getCDialect() == XCFCDialect__89 || XCF__getCDialect() == XCFCDialect__94
		#error Unsupported C dialect.
	#elif XCF__getCDialect() == XCFDialect__11
		#include <XCFoundation/inc/portability/dialect/C11.h>
	#endif

	/* Get compiler */
	#define XCF__getCompiler()		XCFPrivate_comp
	#define XCF__getCompilerVer()	XCFPrivate_compVer

	#define XCFCompiler__GCC	 1u
	#define XCFCompiler__MSVC	 2u
	#define XCFCompiler__UNKN	99u

	#if defined(__GNUC__)
		#define XCFPrivate_comp		XCFCompiler__GCC
		#define XCFPrivate_compVer	(__GNUC__ * 10000U + __GNUC_MINOR__ * 100U + __GNUC_PATCHLEVEL__)

		#include <XCFoundation/inc/portability/compiler/GCC.h>
	#elif defined(_MSC_VER)
		#define XCFPrivate_comp	XCFCompiler__MSVC
		#define XCFPrivate_compVer	_MSC_VER

		#include <XCFoundation/inc/portability/compiler/MSVC.h>
	#else
		#define XCFPrivate_comp		XCFCompiler__UNKN
		#define XCFPrivate_compVer	0u

		#include <XCFoundation/inc/portability/compiler/UNKN.h>
	#endif

	/* Features */
	#define XCF__hasFeature(_feature)	(XCFPrivate_features__ ## _feature == 1)
	#define XCF__hasAttribute(_attr)	(XCFPrivate_features__Attribute__ ## _attr == 1)
	
	#if defined(XCFAttribute__TLS)
		#define XCFPrivate_features__Attribute__TLS			1
	#endif

	#if defined(XCFAttribute__noreturn)
		#define XCFPrivate_features__Attribute__noreturn	1
	#endif

	#if !defined(XCFAttribute__STDCall)
		#define XCFAttribute__STDCall		
	#endif

	#define __cf_getMacroName1(_0, _1, macroName, ...)				macroName
	#define __cf_getMacroName2(_0, _1, _2, macroName, ...)			macroName
	#define __cf_getMacroName3(_0, _1, _2, _3, macroName, ...)		macroName
	#define __cf_getMacroName4(_0, _1, _2, _3, _4, macroName, ...)	macroName

	#define cf_getMacroName1(macroName, args...)				__cf_getMacroName1(_0, ##args, macroName ## __1, macroName ## __0)(args)
	#define cf_getMacroName2(macroName, args...)				__cf_getMacroName2(_0, ##args, macroName ## __2, macroName ## __1, macroName ## __0)(args)
	#define cf_getMacroName3(macroName, args...)				__cf_getMacroName3(_0, ##args, macroName ## __3, macroName ## __2, macroName ## __1, macroName ## __0)(args)
	#define cf_getMacroName4(macroName, args...)				__cf_getMacroName4(_0, ##args, macroName ## __4, macroName ## __3, macroName ## __2, macroName ## __1, macroName ## __0)(args)

	//#define XCFAttribute(_attr)			XCFAttribute__ ## _attr
	#define XCFAttribute__1(_0)				XCFAttribute__ ## _0
	#define XCFAttribute__2(_0, _1)			XCFAttribute__1(_0) XCFAttribute__1(_1)
	#define XCFAttribute__3(_0, _1, _2)		XCFAttribute__2(_0, _1) XCFAttribute__1(_2)
	#define XCFAttribute__4(_0, _1, _2, _3)	XCFAttribute__2(_0, _1) XFAttribute__2(_2, _3)

	#define XCFAttribute(...)		cf_getMacroName4(XCFAttribute, ##__VA_ARGS__)
	
#endif
