%{
#include "calc.tab.h"
#include <stdlib.h>
%}

%%
[0-9]+(\.[0-9]+)?   { yylval.fval = atof(yytext); return NUM; }
[+\-*/()]           { return yytext[0]; }
\n                  { return EOL; }
[ \t]               ;
.                   ;
%%

int yywrap() { return 1; }



/*
Input:
12+3*4
Output tokens:
NUM(12)   '+'   NUM(3)   '*'   NUM(4)   EOL
*/




/*
Lex/Flex Setup 
1. Install MSYS2

Download from:

MSYS2

Open MSYS2 UCRT64 terminal.

2. Install Flex, Bison, GCC

Run:

pacman -Syu

Then:

pacman -S flex bison gcc make
3. Create Files
calc.l → Lex code
calc.y → Yacc/Bison code
4. Generate Files
bison -d calc.y
flex calc.l
5. Compile
gcc lex.yy.c calc.tab.c -o calc
6. Run
./calc

Example input:

5+2

Output:

Result = 7.00
*/




















/*File 1: calc.l (LEX file)*/
%{
#include "calc.tab.h"
%}

%%

[0-9]+(\.[0-9]+)?   { yylval.fval = atof(yytext); return NUM; }
[ \t]               { /* skip spaces */ }
\n                  { return EOL; }
"+"                 { return '+'; }
"-"                 { return '-'; }
"*"                 { return '*'; }
"/"                 { return '/'; }
"("                 { return '('; }
")"                 { return ')'; }
.                   { return yytext[0]; }

%%

int yywrap() { return 1; }







/*File 2: calc.y (YACC file)*/
%{
#include <stdio.h>
#include <stdlib.h>

void yyerror(const char *msg);
int yylex(void);
%}

%union {
    double fval;
}

%token <fval> NUM
%token EOL

%left '+' '-'
%left '*' '/'
%right UMINUS

%type <fval> expr

%%

input:
    /* empty */
    | input expr EOL    { printf("Result = %lf\n", $2); }
    ;

expr:
      expr '+' expr     { $$ = $1 + $3; }
    | expr '-' expr     { $$ = $1 - $3; }
    | expr '*' expr     { $$ = $1 * $3; }
    | expr '/' expr     { $$ = $1 / $3; }
    | '-' expr %prec UMINUS { $$ = -$2; }
    | '(' expr ')'      { $$ = $2; }
    | NUM               { $$ = $1; }
    ;

%%

void yyerror(const char *msg) {
    fprintf(stderr, "Error: %s\n", msg);
}

int main() {
    printf("Calculator ready. Enter expression:\n");
    yyparse();
    return 0;
}




/*
Compile & Run (Linux/Ubuntu)
bash# Step 1: Install tools (once only)
sudo apt install flex bison gcc

# Step 2: Compile
bison -d calc.y
flex calc.l
gcc calc.tab.c lex.yy.c -o calc -lfl

# Step 3: Run
./calc

Sample Input/Output
Calculator ready. Enter expression:
3 + 4 * 2
Result = 11.000000
(5 + 5) * (2 + 3)
Result = 50.000000
-3 + 7
Result = 4.000000

*/
