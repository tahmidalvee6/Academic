#include <bits/stdc++.h>
using namespace std;

int isIdentifier(string s) {
    if (!isalpha(s[0]) && s[0] != '_') {
        return 0;
    }
    for (int i = 1; i < s.size(); i++) {
        char c = s[i];
        if (!isalpha(c) && !isdigit(c) && c != '_') {
            return 0;
        }
    }
    return 1;
}

int isNumber(string s) {
    int dot = 0;
    int exp = 0;
    int start = 0;
    if (s[0] == '+' || s[0] == '-') {
        start = 1;
    }
    for (int i = start; i < s.size(); i++) {
        char c = s[i];
        if (isdigit(c)) {
            continue;
        }
        else if (c == '.' && dot == 0) {
            dot = 1;
        }
        else if ((c == 'e' || c == 'E') && exp == 0) {
            exp = 1;
            char next = s[i+1];
            if (next == '+' || next == '-') {
                i++;
            }
        }
        else {
            return 0;
        }
    }
    return 1;
}

int main() {
    string token;
    cout << "Enter a token: ";
    cin >> token;
    if (isIdentifier(token)) {
        cout << token << " is a valid Identifier" << endl;
    }
    else if (isNumber(token)) {
        cout << token << " is a valid Number" << endl;
    }
    else {
        cout << token << " is Invalid" << endl;
    }
    return 0;
}
