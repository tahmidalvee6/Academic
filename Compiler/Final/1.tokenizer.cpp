#include <bits/stdc++.h>
using namespace std;

// token lists
vector<string> kw, id, num, str, op, sym;

// keyword list
string kwList[] = {"int","float","char","double","void","if","else",
                   "while","for","do","return","break","continue","struct"};

// check if word is keyword
bool isKw(string w) {
    for (string k : kwList) {
        if (k == w) {
            return true;
        }
    }
    return false;
}

// save word into correct list
void saveWord(string w) {
    if (w.empty()) {
        return;
    }
    if (isKw(w)) {
        kw.push_back(w);
    }
    else if (isdigit(w[0])) {
        num.push_back(w);
    }
    else if (isalpha(w[0]) || w[0] == '_') {
        id.push_back(w);
    }
}

// scan code character by character
void scan(string code) {
    int i = 0, n = code.size();

    while (i < n) {

        // skip spaces
        if (isspace(code[i])) {
            i++; continue;
        }

        // string or char literal
        if (code[i] == '"' || code[i] == '\'') {
            char q = code[i];
            string s(1, q); i++;
            while (i < n && code[i] != q) {
                s += code[i]; i++;
            }
            str.push_back(s + q); i++;
            continue;
        }

        // number like 42 or 3.14
        if (isdigit(code[i])) {
            string s;
            while (i < n && (isdigit(code[i]) || code[i] == '.')) {
                s += code[i]; i++;
            }
            num.push_back(s); continue;
        }

        // word like int myVar _count
        if (isalpha(code[i]) || code[i] == '_') {
            string s;
            while (i < n && (isalnum(code[i]) || code[i] == '_')) {
                s += code[i]; i++;
            }
            saveWord(s); continue;
        }

        // 2 char operator like == != ++
        if (i + 1 < n) {
            string two = {code[i], code[i+1]};
            if (two=="==" || two=="!=" || two==">=" || two=="<=" ||
                two=="++" || two=="--" || two=="&&" || two=="||") {
                op.push_back(two); i += 2; continue;
            }
        }

        // 1 char operator like + - =
        if (string("+-*/%=<>!&|").find(code[i]) != string::npos) {
            op.push_back(string(1, code[i])); i++; continue;
        }

        // symbol like ; , ( ) { }
        if (string(";,(){}[]").find(code[i]) != string::npos) {
            sym.push_back(string(1, code[i])); i++; continue;
        }

        i++;
    }
}

// print a token list
void print(string label, vector<string> list) {
    cout << "\n[" << label << "]\n";
    if (list.empty()) {
        cout << "  (none)\n"; return;
    }
    for (string t : list) {
        cout << "  " << t << "\n";
    }
}

// main
int main() {

    // take input from user
    cout << "Enter code (type END to finish):\n\n";
    string code, line;
    while (getline(cin, line) && line != "END") {
        code += line + "\n";
    }

    // scan and print
    scan(code);
    cout << "\n===== LEXICAL ANALYSIS =====";
    print("Keywords",    kw);
    print("Identifiers", id);
    print("Numbers",     num);
    print("Strings",     str);
    print("Operators",   op);
    print("Symbols",     sym);

    return 0;
}



// Input :
/*
int a = 10;
float b = 3.14;
char c = 'x';
char name[] = "hello";
if (a > 5) {
    a++;
}
else {
    a--;
}
while (a != 0) {
    a = a - 1;
}
return 0;
END
*/




// Output :
/*
===== LEXICAL ANALYSIS =====

[Keywords]
  int
  float
  char
  if
  else
  while
  return

[Identifiers]
  main
  a
  b
  c
  name

[Numbers]
  10
  3.14
  5
  0
  1

[Strings]
  'x'
  "hello"

[Operators]
  =
  >
  ++
  --
  !=
  -
  +

[Symbols]
  ;
  (
  )
  {
  }
  [
  ]
*/



