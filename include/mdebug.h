#ifndef __MDEBUG_H__
#define __MDEBUG_H__

#ifdef __Cplusplus
extern "C"{
#endif

#include "mlanguage.h"

/*
* ex. DEBUG({
*           printf("test\n");    
*       })
*/
#ifdef _DEBUG_
#define DEBUG(code) code
#else
#define DEBUG(code) 
#endif

extern void hexdump(uint8 *buffer, int len);


#ifdef __Cplusplus
}
#endif

#endif