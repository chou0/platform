#include <stdio.h>
#include "mdebug.h"

void hexdump(uint8 *buffer, int len)
{
    int i;
    
    for (i = 0; i < len; i++)
    {
        printf("%02x ", buffer[i]);
    }
    
    printf("\n");
}