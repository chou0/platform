#ifndef __MFILE_H__
#define __MFILE_H__

#ifdef __Cplusplus
extern "C"{
#endif

extern int mfile_touch(char *fname);
extern int mfile_rm(char *fname);

#ifdef __Cplusplus
}
#endif

#endif