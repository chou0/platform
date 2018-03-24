#include <stdio.h>
#include "mdebug.h"

void hexdump(uint8 *buffer, int len)
{
    while (len--)
    {
        printf("%02x ", buffer++);
    }
    
    printf("\n");
}