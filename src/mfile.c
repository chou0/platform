#include <stdio.h>
#include <sys/types.h>  
#include <sys/stat.h>
#include <fcntl.h>
#include "mlog.h"

int mfile_touch(char *fname)
{
    int fd;
    
    if (NULL == fname)
    {
        mlog("tag name is null"); 
        return -1;
    }
    
    if (access(fname, F_OK) == F_OK)
    {
        return 0;        
    }
    
    if ((fd = open(fname, O_CREAT | O_TRUNC | O_WRONLY, S_IREAD)) <= 0)
    {
        mlog("create file tag failed"); 
        return -1;    
    }
    
    close(fd);
    if (access(fname, F_OK) != F_OK)
    {
        return -1;        
    }
    
    return 0;
}

int mfile_rm(char *fname)
{
    if (NULL == fname)
    {
        mlog("tag name is null"); 
        return -1;
    }
    
    if (access(fname, F_OK) != F_OK)
    {
        return 0;        
    } 
    
    return unlink(fname); 
}
