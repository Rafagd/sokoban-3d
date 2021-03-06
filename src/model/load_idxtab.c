#include "model/load_idxtab.h"

#include<assert.h>
#include<errno.h>
#include<linux/limits.h>
#include<string.h>

#include "assert/ptr.h"
#include "file/read_file.h"
#include "model/idxtab.h"
#include "model/idxtab_row.h"
#include "string/arrjoin.h"
#include "string/chrcount.h"
#include "string/empty.h"
#include "string/rtrim.h"

void s3d_model_load_idxtab(s3d_model_idxtab *tab, const char *path) {
    char *lines;

    {
        static char path_buf[PATH_MAX];

        s3d_strarrjoin(path_buf, { path, "/idxtab" });

        lines = s3d_read_file(path_buf, 1, 0);
    }

    int num_rows = s3d_strchrcount(lines, '\n');

    s3d_model_idxtab_row *rows = (
        malloc((num_rows + 1) * sizeof(tab->rows[0]))
    );

    s3d_model_idxtab_row *row_ptr = rows;

    for(
        char *tokptr, *line = strtok_r(lines, "\n", &tokptr);
        line;
        line = strtok_r(0, "\n", &tokptr)
    ) {
        s3d_strrtrim(line, "\r");

        char *tok = assert_ptr(strtok(line, " "));

        errno = 0;

        char *endptr = 0;

        row_ptr->idx_ptr = (void *)(strtol(tok, &endptr, 10) * 4);

        assert(!errno && s3d_strempty(endptr));

        tok = assert_ptr(strtok(0, " "));

        endptr = 0;

        row_ptr->num_idx = strtol(tok, &endptr, 10);

        assert(!errno && s3d_strempty(endptr));

        ++row_ptr;
    }

    tab->num_rows = num_rows;
    tab->rows = rows;
}
