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
