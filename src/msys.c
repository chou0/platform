#include <unistd.h>
#include <sys/reboot.h>

int msys_reboot()
{
    sync();
    return reboot(RB_AUTOBOOT);
}