#include <bits/stdc++.h>
using namespace std;

#define MAX_SIZE 100

double numbers[MAX_SIZE];
char operators[MAX_SIZE];
int numTop = -1;
int opTop = -1;

void pushNumber(double value) {
    numbers[++numTop] = value;
}

double popNumber() {
    return numbers[numTop--];
}

void pushOperator(char op) {
    operators[++opTop] = op;
}

char popOperator() {
    return operators[opTop--];
}

int getPrecedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    if (op == '+' || op == '-') {
        return 1;
    }
    return 0;
}

void doMath() {
    double b = popNumber();
    double a = popNumber();
    char op = popOperator();

    if (op == '+') {
        pushNumber(a + b);
    } else if (op == '-') {
        pushNumber(a - b);
    } else if (op == '*') {
        pushNumber(a * b);
    } else if (op == '/') {
        pushNumber(a / b);
    }
}

void evaluate(string expression) {
    int i = 0;

    while (i < expression.size()) {
        char ch = expression[i];

        if (ch == ' ' || ch == '\t') {
            i++;
            continue;
        }

        if (ch >= '0' && ch <= '9') {
            double value = 0;
            double decimal = 0.1;
            bool hasDot = false;

            while (i < expression.size() && (expression[i] >= '0' && expression[i] <= '9' || expression[i] == '.')) {
                if (expression[i] == '.') {
                    hasDot = true;
                } else if (!hasDot) {
                    value = value * 10 + (expression[i] - '0');
                } else {
                    value = value + (expression[i] - '0') * decimal;
                    decimal = decimal * 0.1;
                }
                i++;
            }

            pushNumber(value);
            continue;
        }

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (opTop >= 0 && getPrecedence(operators[opTop]) >= getPrecedence(ch)) {
                doMath();
            }
            pushOperator(ch);
            i++;
            continue;
        }

        if (ch == '(') {
            pushOperator('(');
            i++;
            continue;
        }

        if (ch == ')') {
            while (opTop >= 0 && operators[opTop] != '(') {
                doMath();
            }
            popOperator();
            i++;
            continue;
        }

        i++;
    }

    while (opTop >= 0) {
        doMath();
    }

    cout << "Result = " << popNumber() << "\n\n";

    numTop = -1;
    opTop = -1;
}

int main() {
    cout << "=== Desk Calculator ===\n";
    cout << "Type expression and press Enter. Type exit to quit.\n\n";

    string line;

    while (true) {
        cout << ">> ";
        getline(cin, line);

        if (line == "exit") {
            break;
        }

        if (!line.empty()) {
            evaluate(line);
        }
    }

    return 0;
}



/*
Input and Output :
=== Desk Calculator ===
Type expression and press Enter. Type exit to quit.

>> 3 + 5
Result = 8

>> 3 + 4 * 2
Result = 11

>> (3 + 4) * 2
Result = 14

>> 10 / 4
Result = 2.5

*/
