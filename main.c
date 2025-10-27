#include <stdio.h>
#include <stdlib.h>
#include "expr.h"

int main(int argc, char **argv){
    FILE *fp = NULL;
    Expr *fuck = NULL;
    if (argc != 2){
        fprintf(stderr,"Usage: %s filename\n",argv[0]);
        exit(1);
    }
    if (!(fp = fopen(argv[1],"r"))){
        printf("Can't open %s.\n",argv[1]);
        exit(2);
    }
    fclose(fp);

    fuck = parser("-1 - 2 - -3 + 4");
    printf("%d\n",calcExpr(fuck));
    delExpr(fuck);

    return 0;
}
