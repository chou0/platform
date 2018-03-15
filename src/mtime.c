#include <stdio.h>
#include <sys/time.h>
#include "mtime.h"

void mtime_timestamp_dump(uint64 timestamp)
{
    printf("timestamp: %lld \n", timestamp);    
}

uint64 mtime_get_timestamp(int level)
{
    unsigned long long timestamp;
    struct timeval current;
    
    gettimeofday(&current, NULL);

    if (level == 1)
    { 
        timestamp = (uint64)current.tv_sec * 1000 + (uint64)current.tv_usec / 1000;
    }
    else if (level == 2)
    {
        timestamp = (uint64)current.tv_sec * 1000 * 1000 + (uint64)current.tv_usec;
    }
   
    return timestamp;
}

