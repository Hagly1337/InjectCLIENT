#pragma once

#ifndef OXORANY_INCLUDE_H
#define OXORANY_INCLUDE_H

// extern void hikari_strenc(void);
// extern void hikari_indibr(void);
// extern void hikari_bcf(void);
// extern void hikari_fla(void);

// #define HIKARI_CONTROL_FLOW __attribute((__annotate__(("fla"))))
// #define HIKARI_STRING_encryptION __attribute((__annotate__(("strenc"))))
// #define HIKARI_BRANCHING __attribute((__annotate__(("indibr"))))
// #define HIKARI_FUNCTION_WRAPPER __attribute((__annotate__(("fw"))))

//disable /GL for warning C4307 in msvc
#define OXORANY_DISABLE_OBFUSCATION
//use OXORANY_USE_BIT_CAST for remove float double src data
#define OXORANY_USE_BIT_CAST

#include "oxorany.h"

//to change Marco in a easy way
#define WRAPPER_MARCO oxorany
#define WRAPPER_MARCO_FLT oxorany_flt

template <typename T>
static OXORANY_FORCEINLINE void copy_string_without_return(T* target, const T* source)
{
	while (*source) {
		*target = *source;
		++source;
		++target;
	}
	*target = 0;
}

#define WRAPPER_MARCO_DEFINE_STRING_ARRAY(type,name,s) type name[sizeof(s)/sizeof(type)]; copy_string_without_return(name, WRAPPER_MARCO(s))

#endif