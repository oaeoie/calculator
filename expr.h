typedef struct expr{
    char *oper;
    struct expr *opnd1;
    struct expr *opnd2;
}Expr;

int calcExpr(Expr *expression);
int nonary(Expr *expression);
int unary(Expr *expression);
int binary(Expr *expression);
Expr *parser(char *s);
Expr *parserb(char *s);
Expr *parseru(char *s);
Expr *parsern(char *s);
Expr *genExpr(char *s);
void delExpr(Expr *expression);
char *nextbOp(char *s);
char *nextuOp(char *s);
