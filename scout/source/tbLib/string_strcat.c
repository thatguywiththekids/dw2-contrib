#include <exec/types.h>
#include <proto/exec.h>
#include <string.h>
#include "tblib.h"
#include "SDI_compiler.h"

/* /// "_strcat()" */
void _strcat( STRPTR *str,
              STRPTR cat )
{
    STRPTR tmp;

    if (*str) {
        tmp = AllocVec(strlen(*str) + strlen(cat) + 2, MEMF_CLEAR | MEMF_PUBLIC);
        if (tmp) {
            strcpy(tmp, *str);
            strcat(tmp, cat);
            FreeVec(*str);
            *str = tmp;
        }
    } else {
        *str = _strdup(cat);
    }
}
/* \\\ */
