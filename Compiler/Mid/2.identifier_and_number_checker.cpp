#include <iostream> 
#include <cctype> 
#include <string> 
using namespace std; 
bool isIdentifier(const string& s) { 
if (!(isalpha(s[0]) || s[0] == '_')) return false; 
for (int i = 1; i < s.size(); i++) { 
if (!(isalnum(s[i]) || s[i] == '_')) return false; 
    } 
    return true; 
} 
 
bool isNumber(const string& s) { 
    bool dotSeen = false, expSeen = false; 
    int i = 0; 
    if (s[i] == '+' || s[i] == '-') i++; 
    for (; i < s.size(); i++) { 
        if (isdigit(s[i])) continue; 
        else if (s[i] == '.' && !dotSeen) dotSeen = true; 
        else if ((s[i] == 'e' || s[i] == 'E') && !expSeen) { 
            expSeen = true; 
            if (i+1 < s.size() && (s[i+1]=='+' || s[i+1]=='-')) i++; 
        } 
        else return false; 
    } 
    return true; 
} 
