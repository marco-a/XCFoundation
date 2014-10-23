
/*!
		@file			types.c
		@version		{$VERSION}
		@copyright		< Pro Fusion , 2014 >
		@date			22.10.14

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#define XCFPrivate_hGuard
#include <XCFoundation/inc/types.h>

#define XCFPrivate_typeInfo__structMinMax(_typeName, _nBits)																			\
	struct XCFPrivate_typeInfo__ ## _typeName const XCFPrivate_typeInfo__ ## _typeName =	{											\
																								.minValue = INT_FAST ## _nBits ## _MIN,	\
																								.maxValue = INT_FAST ## _nBits ## _MAX	\
																							}

#define XCFPrivate_typeInfo__structMax(_typeName, _nBits)		\
	struct XCFPrivate_typeInfo__ ## _typeName const XCFPrivate_typeInfo__ ## _typeName =	{											\
																								.maxValue = INT_FAST ## _nBits ## _MAX	\
																							}
#if XCF__hasType(Char)
	XCFPrivate_typeInfo__structMinMax(Char, 8);
	XCFPrivate_typeInfo__structMax(UChar, 8);
#endif

#if XCF__hasType(Short)
	XCFPrivate_typeInfo__structMinMax(Short, 16);
	XCFPrivate_typeInfo__structMax(UShort, 16);
#endif

#if XCF__hasType(Integer)
	XCFPrivate_typeInfo__structMinMax(Integer, 32);
	XCFPrivate_typeInfo__structMax(UInteger, 32);
#endif

#if XCF__hasType(LInteger)
	XCFPrivate_typeInfo__structMinMax(LInteger, 64);
	XCFPrivate_typeInfo__structMax(ULInteger, 64);
#endif

#undef XCFPrivate_typeInfo__structMinMax
#undef XCFPrivate_typeInfo__structMax
