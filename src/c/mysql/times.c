#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include <time.h>
// #include <sys/times.h>

#include "mysql/mysql.h"

static char *dbG;
static char *dbhG;
static char *dbuG;
static char *dbpG;
static MYSQL *mysql;

int main(int argc, char **argv)
{
    int    i = 0;
    int    rc = 0;
    char    query[1024];
    MYSQL_RES    *result = NULL;
    MYSQL_ROW    row;

    dbuG = "svc4.55";
    dbpG = "svc4.55";
    dbhG = "194.14.251.209";
    dbG = "sandbox";

    // parse command line arguments
    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--db")) {
            dbhG = strdup(argv[++i]);
            dbuG = strdup(argv[++i]);
            dbpG = strdup(argv[++i]);
            dbG = strdup(argv[++i]);
        }
    }

    mysql = (MYSQL *) calloc(1, sizeof(MYSQL));

    if (!mysql_init(mysql)) {
        fprintf(stderr, "Failed to initialize MySQL handle\n");
        return (1);
    }

    if (!mysql_real_connect(mysql, dbhG, dbuG, dbpG, NULL, 0, NULL, 0)) {
        fprintf(stderr, "Failed to connect to MySQL[%s]\n",
            mysql_error(mysql));
    }

    if (!mysql_select_db(mysql, dbG)) {
        fprintf(stderr, "Failed to select database[%s]\n", dbG);
    }

    snprintf(query, sizeof(query), "SELECT UNIX_TIMESTAMP(NOW())");

    if ((rc = mysql_query(mysql, query))) {
        fprintf(stderr, "Failed MySQL: status[%d], query[%s]\n",
            rc, query);
        mysql_errno(mysql);

        mysql_close(mysql);
        return (1);
    }

    if (!(result = mysql_store_result(mysql))) {
        fprintf(stderr, "Failed to store MySQL result\n");
        mysql_close(mysql);
        return (1);
    }

    if (row = mysql_fetch_row(result)) {
        fprintf(stdout, "SELECT UNIX_TIMESTAMP(NOW())[%s]\n", row[0]);
    }

    mysql_free_result(result);

    mysql_close(mysql);
}

