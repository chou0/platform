#ifndef __MTIMESTAMP_H__
#define __MTIMESTAMP_H__

#ifdef __Cplusplus
extern "C"{
#endif

#include <stdint.h>

extern uint64_t mts_get_uts();
extern uint64_t mts_get_mts();

#ifdef __Cplusplus
}
#endif

#endif