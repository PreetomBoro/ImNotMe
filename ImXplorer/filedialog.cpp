#include <nfd.h>
#include <stdio.h>
#include <stdlib.h>
#include "filedialog.h"

nfdchar_t filedialog()
{
    nfdchar_t *outpath = NULL;
    nfdresult_t result = NFD_PickFolder(NULL, &outpath);
    if(result == NFD_OKAY)
        return *outpath;
    return NULL;
}


