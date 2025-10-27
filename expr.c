#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "expr.h"


int calcExpr(Expr *expression){
    if (!(expression->opnd1)){
        return nonary(expression);
    }
    if (!(expression->opnd2)){
        return unary(expression);
    }
    else{
        return binary(expression);
    }

}

int nonary(Expr *expression){
    return atoi(expression->oper);

}

int unary(Expr *expression){
    if(!(strcmp(expression->oper,"-"))){
        return -calcExpr(expression->opnd1);
    }
    if (!(strcmp(expression->oper,"+"))){
        return calcExpr(expression->opnd1);
    }
    else {
        fprintf(stderr,"what is this unary?\n");
        exit(2);
    }

}

int binary(Expr *expression){
    int iszero;
    if(!(strcmp(expression->oper,"+"))){
        return calcExpr(expression->opnd1) + calcExpr(expression->opnd2);
    }

    if(!(strcmp(expression->oper,"-"))){
        return calcExpr(expression->opnd1) - calcExpr(expression->opnd2);
    }

    if(!(strcmp(expression->oper,"*"))){
        return calcExpr(expression->opnd1) + calcExpr(expression->opnd2);
    }


    if(!(strcmp(expression->oper,"/"))){
        if(!(iszero = calcExpr(expression->opnd2))){
            fprintf(stderr,"Can't divide by zero\n");
            exit(3);
        }

        return calcExpr(expression->opnd1) / iszero;
    }


    else {
        fprintf(stderr,"what is this unary operator?\n");
        exit(2);
    }


}

Expr *parser(char *s){
    char *cp = malloc((strlen(s)+1) * sizeof(char));
    Expr *ep;
    strcpy(cp,s);
    ep = parserb(cp);
    free(cp);
    return ep;
}

Expr *parserb(char *s){
    Expr *ep = NULL;
    char *op = nextbOp(s);
    char buf[3] = "";


    if(!(op)){
        return parseru(s);
    }
    printf("Binary: %s Op:%c\n",s,*op);
    buf[0] = *op;
    ep = genExpr(buf);
    *op = '\0';
    ep->opnd1 = parserb(s);
    ep->opnd2 = parserb(op+1);

    return ep;
}


Expr *parseru(char *s){
    Expr *ep = NULL;
    char *op = nextuOp(s);
    char buf[3] = "";
    if (!(op)){
        return parsern(s);
    }
    printf("Unary: %s Op: %c\n",s,*op);
    buf[0] = *op;
    ep = genExpr(buf);
    *op = '\0';
    ep->opnd1 = parserb(op+1);

    return ep;

}

Expr *parsern(char *s){
    printf("Nonary: %s\n",s);
    return genExpr(s);

}


Expr *genExpr(char *s){
    Expr *expp = malloc(sizeof(Expr));
    char *op = malloc((strlen(s) + 1) * sizeof(char));
    strcpy(op,s);
    expp->oper = op;
    return expp;
}

void delExpr(Expr *expression){
    if (expression->oper){
        free(expression->oper);
    }
    if(expression->opnd1){
        free(expression->opnd1);
    }
    if(expression->opnd2){
        free(expression->opnd2);
    }
    free(expression);
}

char *nextbOp(char *s){
    char *fst = s;
    char *op = NULL;
    op || (op = strstr(s,"+"));
    op || (op = strstr(s,"-"));
    op || (op = strstr(s,"*"));
    op || (op = strstr(s,"/"));

    if (!(op)){
        return NULL;
    }
    while(*fst==' '){
        fst++;
    }


    if (fst != op){
       return op;
    }

    return nextbOp(fst+1);

}

char *nextuOp(char *s){
    char *op = NULL;
    op || (op = strstr(s,"+"));
    op || (op = strstr(s,"-"));

    return op;

}

char *nextnOp(char *s){
    char *p = s;
    while (*p == ' '){
        p++;
    }
    return p;
}
