import re

print("Enter your code :")

code = ""
while True:
    line = input()
    if line == "END":
        break
    code += line + "\n"

pattern = r"//.*?$|/\*.*?\*/"

clean_code = re.sub(pattern, "", code, flags=re.DOTALL | re.MULTILINE)

print("\nCode after removing comments:")
print(clean_code)





"""
Input :
#include <iostream>
using namespace std;
int main() {
    int x = 10; // x value
    int y = 20; // y value
    /* calculate
       the sum */
    int sum = x + y;
    int diff = x - y; // difference
    return 0;
}
END
"""



"""
Output :
Code after removing comments:
#include <iostream>
using namespace std;
int main() {
    int x = 10; 
    int y = 20; 
    
    int sum = x + y;
    int diff = x - y; 
    return 0;
}
"""
