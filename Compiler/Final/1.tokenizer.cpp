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



/*
#include <stdio.h>

// This is a single line comment

int main()
{
    /* Multi-line
       Comment */

    int a, c = 10;
    int b = 15;
    a = b + c;

    printf("%d", a);

    return 0;
}



#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

// Remove Comments
string removeComments(string code)
{
    string result;

    for (int i = 0; i < code.length(); i++)
    {
        // Single-line comment
        if (code[i] == '/' && i + 1 < code.length() && code[i + 1] == '/')
        {
            while (i < code.length() && code[i] != '\n')
                i++;
        }

        // Multi-line comment
        else if (code[i] == '/' && i + 1 < code.length() && code[i + 1] == '*')
        {
            i += 2;

            while (i + 1 < code.length())
            {
                if (code[i] == '*' && code[i + 1] == '/')
                {
                    i++;
                    break;
                }
                i++;
            }
        }

        else
        {
            result += code[i];
        }
    }

    return result;
}

// Check separator
bool isSeparator(char ch)
{
    string sep = "(){}[],;";
    return sep.find(ch) != string::npos;
}

// Check operator
bool isOperator(char ch)
{
    string op = "+-*/=%<>!";
    return op.find(ch) != string::npos;
}

// Tokenizer
void tokenize(string code)
{
    vector<string> tokens;
    string token = "";

    for (char ch : code)
    {
        if (isspace(ch))
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token = "";
            }
        }

        else if (isSeparator(ch) || isOperator(ch))
        {
            if (!token.empty())
            {
                tokens.push_back(token);
                token = "";
            }

            string temp;
            temp += ch;
            tokens.push_back(temp);
        }

        else
        {
            token += ch;
        }
    }

    if (!token.empty())
        tokens.push_back(token);

    cout << "\nTokens:\n\n";

    for (string t : tokens)
    {
        cout << t << endl;
    }
}

int main()
{
    ifstream file("input.c");

    if (!file)
    {
        cout << "Cannot open input.c";
        return 0;
    }

    string code, line;

    while (getline(file, line))
    {
        code += line + "\n";
    }

    file.close();

    string cleanedCode = removeComments(code);

    cout << "Code After Removing Comments:\n\n";
    cout << cleanedCode << endl;

    tokenize(cleanedCode);

    return 0;
}



*/
