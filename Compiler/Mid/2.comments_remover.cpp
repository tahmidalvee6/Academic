#include <bits/stdc++.h>
using namespace std;

int main() {

    string code = "";
    string line;

    cout << "Enter your code:" << endl;

    while (getline(cin, line)) {
        if (line == "END") break;
        code += line + "\n";
    }

    string state = "NORMAL";

    for (int i = 0; i < code.size(); i++) {
        char c = code[i];
        char next = '\0';
        if (i + 1 < code.size()) {
            next = code[i + 1];
        }

        if (state == "NORMAL") {
            if (c == '/' && next == '/') {
                state = "SINGLE";
                i++;
            }
            else if (c == '/' && next == '*') {
                state = "MULTI";
                i++;
            }
            else if (c == '"') {
                state = "STRING";
                cout << c;
            }
            else if (c == '\'') {
                state = "CHAR";
                cout << c;
            }
            else {
                cout << c;
            }
        }

        else if (state == "SINGLE") {
            if (c == '\n') {
                cout << '\n';
                state = "NORMAL";
            }
        }

        else if (state == "MULTI") {
            if (c == '*' && next == '/') {
                state = "NORMAL";
                i++;
            }
        }

        else if (state == "STRING") {
            cout << c;
            if (c == '\\') {
                cout << next;
                i++;
            }
            else if (c == '"') {
                state = "NORMAL";
            }
        }

        else if (state == "CHAR") {
            cout << c;
            if (c == '\\') {
                cout << next;
                i++;
            }
            else if (c == '\'') {
                state = "NORMAL";
            }
        }
    }

    return 0;
}



/*
Input :
#include <iostream>
using namespace std;
int main() {
    int x = 10; // x value
    int y = 20; // y value
    /* calculate
       the sum */
    // int sum = x + y;
    // int diff = x - y; // difference
    // return 0;
}
END
/*
