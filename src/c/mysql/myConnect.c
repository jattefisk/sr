#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <mysql/mysql.h>

int main(int argc, char **argv)
{
    int    i;

    char    *db = NULL;
    char    *host = NULL;
    char    *passwd = NULL;
    char    *user = NULL;
    unsigned int    port = 0;

    MYSQL    *mysql = NULL;

    for (i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "-db")) {
            db = argv[++i];
        } else if (!strcmp(argv[i], "-host")) {
            host = argv[++i];
        } else if (!strcmp(argv[i], "-passwd")) {
            passwd = argv[++i];
        } else if (!strcmp(argv[i], "-port")) {
            port = atoi(argv[++i]);
        } else if (!strcmp(argv[i], "-user")) {
            user = argv[++i];
        }
    }

    fprintf(stdout, "Testing connection to MySQL host[%s] on port[%d] with user[%s] and password[%s] for databse[%s]\n",
        host, port, user, passwd, db);

    if (!(mysql = mysql_init(NULL))) {
        fprintf(stderr, "Failed to initialize MYSQL * structure\n");
        return (0);
    }

    if (!mysql_real_connect(mysql, host, user, passwd, db, port, NULL, 0)) {
        fprintf(stderr, "Failed in mysql_real_connect[%s]\n", mysql_error(mysql));
    } else {
        fprintf(stdout, "->success\n");
    }

    mysql_close(mysql);
}
