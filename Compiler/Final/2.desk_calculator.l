%{
#include<stdio.h>
#include<stdlib.h>

int result = 0;
char op = '+';
%}

%%

[0-9]+ {
    int num = atoi(yytext);

    switch(op)
    {
        case '+': result += num; break;
        case '-': result -= num; break;
        case '*': result *= num; break;
        case '/': result /= num; break;
    }
}

[+\-*/] {
    op = yytext[0];
}

\n {
    printf("Result = %d\n", result);

    result = 0;
    op = '+';
}

[ \t] ;

%%

int main()
{
    printf("Enter Expression:\n");
    yylex();
    return 0;
}




/*
Example Input
5+3
10-2
4*5
20/4


Output
Result = 8
Result = 8
Result = 20
Result = 5
*/
