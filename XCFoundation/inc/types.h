
/*!
		@file			types.h
		@version		1.0
		@copyright		< Pro Fusion , 2014 >
		@date			22.10.14
	
		@brief
		{$BRIEF}

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#if !defined(XCFPrivate_hGuard__inc_types_h)
	#define XCFPrivate_hGuard__inc_types_h

	#if !defined(XCFPrivate_hGuard)
		#error Do not directly include this file. Use <XCFoundation/XCFoundation.h> instead.
	#endif

	#define XCF__defineType(_type, _name)	\
		typedef _type			XCF ## _name ## _t

	#define XCF__hasType(_type)		(XCFPrivate_hasType__ ## _type == 1)

	#include <stdarg.h>		// va_list

	// --- Standard types
	XCF__defineType(const char *	,	String			);
	#define XCFPrivate_hasType__String			1

	XCF__defineType(char *			,	MutableString	);
	#define XCFPrivate_hasType__MutableString	1

	XCF__defineType(va_list			,	VAList			);
	#define XCFPrivate_hasType__VAList			1

	#define XCFVAList__begin(_ap, _arg)	va_start(_ap, _arg)
	#define XCFVAList__end(_ap)			va_end(_ap)

	// --- Integer Types
	#define allocArray(...)		allocArray(__VA_ARGS__, 0)
	
	#define XCFPrivate_typeInfo__genMembers(_typeName)				\
		XCF ## _typeName ## _t *(*const alloc)(void);				\
		void *(*const allocArray)(XCFSize_t dim1, ...)

	#define XCFPrivate_typeInfo__structMinMax(_typeName)			\
		struct XCFPrivate_typeInfo__ ## _typeName {					\
			XCF ## _typeName ## _t const minValue;					\
			XCF ## _typeName ## _t const maxValue;					\
			XCFPrivate_typeInfo__genMembers(_typeName);				\
		};															\
		extern struct XCFPrivate_typeInfo__ ## _typeName const XCFPrivate_typeInfo__ ## _typeName;

	#define XCFPrivate_typeInfo__structMax(_typeName)				\
		struct XCFPrivate_typeInfo__ ## _typeName {					\
			XCF ## _typeName ## _t const maxValue;					\
			XCFPrivate_typeInfo__genMembers(_typeName);				\
		};															\
		extern struct XCFPrivate_typeInfo__ ## _typeName const XCFPrivate_typeInfo__ ## _typeName;

	#include <stddef.h>		// size_t
	#include <stdint.h>		// int_*

	#if defined(SIZE_MAX)
		XCF__defineType(size_t			,	Size			);
	#else
		XCF__defineType(uint_fast32_t	,	Size			);
		#define SIZE_MAX UINT_FAST32_MAX
	#endif

	#define XCFPrivate_hasType__Size		1

	#include <XCFoundation/inc/portability.h>	// XCF__hasFeature

	#if defined(INT_FAST8_MAX)
		XCF__defineType(int_fast8_t		,	Char		);
		XCF__defineType(uint_fast8_t	,	UChar		);

		#define XCFPrivate_hasType__Char		1
		#define XCFPrivate_hasType__UChar		1

		XCFPrivate_typeInfo__structMinMax	(Char)		;
		XCFPrivate_typeInfo__structMax		(UChar)		;

		#define XCFChar()		(XCFPrivate_typeInfo__Char)
		#define XCFUChar()		(XCFPrivate_typeInfo__UChar)

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFChar_t		,	AtomicChar	);
			XCF__defineType(volatile XCFUChar_t		,	AtomicUChar	);

			#define XCFPrivate_hasType__AtomicChar			1
			#define XCFPrivate_hasType__AtomicUChar			1

			XCFPrivate_atomics__defineFunctions(Char);
			XCFPrivate_atomics__defineFunctions(UChar);
		#endif
	#endif

	#if defined(INT_FAST16_MAX)
		XCF__defineType(int_fast16_t	,	Short		);
		XCF__defineType(uint_fast16_t	,	UShort		);

		#define XCFPrivate_hasType__Short		1
		#define XCFPrivate_hasType__UShort		1

		XCFPrivate_typeInfo__structMinMax	(Short)		;
		XCFPrivate_typeInfo__structMax		(UShort)	;

		#define XCFShort()		(XCFPrivate_typeInfo__Short)
		#define XCFUShort()		(XCFPrivate_typeInfo__UShort)

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFShort_t		,	AtomicShort	);
			XCF__defineType(volatile XCFUShort_t		,	AtomicUShort);

			#define XCFPrivate_hasType__AtomicShort			1
			#define XCFPrivate_hasType__AtomicUShort		1

			XCFPrivate_atomics__defineFunctions(Short);
			XCFPrivate_atomics__defineFunctions(UShort);
		#endif
	#endif

	#if defined(INT_FAST32_MAX)
		XCF__defineType(int_fast32_t	,	Integer		);
		XCF__defineType(uint_fast32_t	,	UInteger	);

		#define XCFPrivate_hasType__Integer		1
		#define XCFPrivate_hasType__UInteger	1

		XCFPrivate_typeInfo__structMinMax	(Integer)	;
		XCFPrivate_typeInfo__structMax		(UInteger)	;

		#define XCFInteger()	(XCFPrivate_typeInfo__Integer)
		#define XCFUInteger()	(XCFPrivate_typeInfo__UInteger)

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFInteger_t	,	AtomicInteger	);
			XCF__defineType(volatile XCFUInteger_t	,	AtomicUInteger	);

			#define XCFPrivate_hasType__AtomicInteger		1
			#define XCFPrivate_hasType__AtomicUInteger		1

			XCFPrivate_atomics__defineFunctions(Integer);
			XCFPrivate_atomics__defineFunctions(UInteger);
		#endif
	#endif

	#if defined(INT_FAST64_MAX)
		XCF__defineType(int_fast64_t	,	LInteger	);
		XCF__defineType(uint_fast64_t	,	ULInteger	);

		#define XCFPrivate_hasType__LInteger	1
		#define XCFPrivate_hasType__ULInteger	1

		XCFPrivate_typeInfo__structMinMax	(LInteger)	;
		XCFPrivate_typeInfo__structMax		(ULInteger)	;

		#define XCFLInteger()	(XCFPrivate_typeInfo__LInteger)
		#define XCFULInteger()	(XCFPrivate_typeInfo__ULInteger)

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFLInteger_t	,	AtomicLInteger	);
			XCF__defineType(volatile XCFULInteger_t	,	AtomicULInteger	);

			#define XCFPrivate_hasType__AtomicLInteger		1
			#define XCFPrivate_hasType__AtomicULInteger		1

			XCFPrivate_atomics__defineFunctions(LInteger);
			XCFPrivate_atomics__defineFunctions(ULInteger);
		#endif
	#endif

	#undef XCFPrivate_typeInfo__structMinMax
	#undef XCFPrivate_typeInfo__structMax

	// --- Precise Integer
	#if defined(INT8_MAX)
		XCF__defineType(int8_t			,	Int8		);
		XCF__defineType(uint8_t			,	UInt8		);

		#define XCFPrivate_hasType__Int8		1
		#define XCFPrivate_hasType__UInt8		1

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFInt8_t		,	AtomicInt8		);
			XCF__defineType(volatile XCFUInt8_t		,	AtomicUInt8		);

			#define XCFPrivate_hasType__AtomicInt8			1
			#define XCFPrivate_hasType__AtomicUInt8			1

			XCFPrivate_atomics__defineFunctions(Int8);
			XCFPrivate_atomics__defineFunctions(UInt8);
		#endif
	#endif

	#if defined(INT16_MAX)
		XCF__defineType(int16_t			,	Int16		);
		XCF__defineType(uint16_t		,	UInt16		);

		#define XCFPrivate_hasType__Int16		1
		#define XCFPrivate_hasType__UInt16		1

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFInt16_t		,	AtomicInt16		);
			XCF__defineType(volatile XCFUInt16_t	,	AtomicUInt16	);

			#define XCFPrivate_hasType__AtomicInt16			1
			#define XCFPrivate_hasType__AtomicUInt16		1

			XCFPrivate_atomics__defineFunctions(Int16);
			XCFPrivate_atomics__defineFunctions(UInt16);
		#endif
	#endif

	#if defined(INT32_MAX)
		XCF__defineType(int32_t			,	Int32		);
		XCF__defineType(uint32_t		,	UInt32		);

		#define XCFPrivate_hasType__Int32		1
		#define XCFPrivate_hasType__UInt32		1

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFInt32_t		,	AtomicInt32		);
			XCF__defineType(volatile XCFUInt32_t	,	AtomicUInt32	);

			#define XCFPrivate_hasType__AtomicInt32			1
			#define XCFPrivate_hasType__AtomicUInt32		1

			XCFPrivate_atomics__defineFunctions(Int32);
			XCFPrivate_atomics__defineFunctions(UInt32);
		#endif
	#endif

	#if defined(INT64_MAX)
		XCF__defineType(int64_t			,	Int64		);
		XCF__defineType(uint64_t		,	UInt64		);

		#define XCFPrivate_hasType__Int64		1
		#define XCFPrivate_hasType__UInt64		1

		#if XCF__hasFeature(Atomics)
			XCF__defineType(volatile XCFInt64_t		,	AtomicInt64		);
			XCF__defineType(volatile XCFUInt64_t	,	AtomicUInt64	);

			#define XCFPrivate_hasType__AtomicInt64			1
			#define XCFPrivate_hasType__AtomicUInt64		1

			XCFPrivate_atomics__defineFunctions(Int64);
			XCFPrivate_atomics__defineFunctions(UInt64);
		#endif
	#endif
	

#endif
