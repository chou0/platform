#ifndef __MTIME_H__
#define __MTIME_H__

#ifdef __Cplusplus
extern "C"{
#endif

#include "mlanguage.h"

extern uint64 mtime_get_timestamp(int level);
extern void mtime_timestamp_dump(uint64 timestamp);


#ifdef __Cplusplus
}
#endif

#endif