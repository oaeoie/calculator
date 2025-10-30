typedef struct expr{
    char *oper;
    struct expr *opnd1;
    struct expr *opnd2;
}Expr;
