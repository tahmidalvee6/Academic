%{
#include <stdio.h>
#include <stdlib.h>

#define MAX 100
double val_stack[MAX];
char op_stack[MAX];
int val_top = -1, op_top = -1;

void push_val(double v) { val_stack[++val_top] = v; }
void push_op(char c)    { op_stack[++op_top] = c; }
double pop_val()        { return val_stack[val_top--]; }
char pop_op()           { return op_stack[op_top--]; }

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void apply_op() {
    double b = pop_val();
    double a = pop_val();
    char op = pop_op();
    switch (op) {
        case '+': push_val(a + b); break;
        case '-': push_val(a - b); break;
        case '*': push_val(a * b); break;
        case '/': push_val(a / b); break;
    }
}
%}

%%

[0-9]+(\.[0-9]+)?   { push_val(atof(yytext)); }

[+\-*/]             {
                        while (op_top >= 0 && op_stack[op_top] != '(' &&
                               precedence(op_stack[op_top]) >= precedence(yytext[0]))
                            apply_op();
                        push_op(yytext[0]);
                    }

"("                 { push_op('('); }

")"                 {
                        while (op_top >= 0 && op_stack[op_top] != '(')
                            apply_op();
                        pop_op();
                    }

[ \t]+              ;  /* skip spaces */

\n                  {
                        while (op_top >= 0)
                            apply_op();
                        printf("Result = %g\n", pop_val());
                        val_top = -1;
                    }

.                   ;  /* ignore anything else */

%%

int main() {
    printf("Desk Calculator (enter expression, Ctrl+D to exit):\n");
    yylex();
    return 0;
}

int yywrap() { return 1; }
