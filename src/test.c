#include <stdio.h>
#include "mnet.h"

int main(int argc, char **args)
{
    int enable = mnet_check_connectble(args[1], atoi(args[2]), atoi(args[3]));
    
    printf("able: %d \n", enable);    
	return 0;
}
