
/*!
		@file			XCF.c
		@version		{$VERSION}
		@copyright		< Pro Fusion , 2014 >
		@date			23.10.14

		Copyright 2014 Pro Fusion. All rights reserved.
 */

#define XCFPrivate_hGuard
#include <XCFoundation/inc/XCF.h>
#include <stdlib.h>
#include <stdio.h>

void *XCF__alloc(XCFSize_t sz)
{
	return NULL;
}

void XCF__panic(XCFString_t const fmt, ...)
{
	XCFVAList_t ap;
	
	XCFVAList__begin(ap, fmt);
	vfprintf(stderr, fmt, ap);
	XCFVAList__end(ap);
	
	exit(EXIT_FAILURE);
}

struct XCFPrivate_vTable const XCFPrivate_vTable =	{
														.alloc	= XCF__alloc,
														.panic	= XCF__panic
													};