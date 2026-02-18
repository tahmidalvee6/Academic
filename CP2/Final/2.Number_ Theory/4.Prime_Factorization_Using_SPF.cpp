#include <bits/stdc++.h>
using namespace std;

const int N = 1000000;
int spf[N + 1];

void sieveSPF() {
    for (int i = 1; i <= N; i++)
        spf[i] = i;

    for (int i = 2; i * i <= N; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j <= N; j += i) {
                if (spf[j] == j)
                    spf[j] = i;
            }
        }
    }
}

int main() {
    sieveSPF();

    int n;
    cin >> n;

    while (n != 1) {
        cout << spf[n] << " ";
        n /= spf[n];
    }

    return 0;
}





/*
🔗 Practice Problems

Codeforces

https://codeforces.com/problemset/problem/1034/A

https://codeforces.com/problemset/problem/17/A



LeetCode

https://leetcode.com/problems/count-primes/

https://leetcode.com/problems/ugly-number/
*/



# 1. Dictionary & Set 

# 2. dictionary hoilo jkhane amdr word meaning er pair hoy

# 3. first amdr word ta thake trpr amdr word er meaning ta thake 

# 4. syntax
# 5. key : value

info = {
    "key" : "value",
    "name" : "Alvee",
    "learning" : "coding",
    'age' : 35,
    "is_adult" : True,
    "mark" : 95.5,
    
    # 6. amra list akare o rakhte pari
    "subject" : ["python", "c", "java"],
    
    
    # 7. tuple akare o rakhte pari
    "topics" : ("dictionary", "set")
}

print(info)
print(type(info))





# 8. dictionary hoilo unordered...mane amn kono fixed rule nai j konta age ashbe konta pore ashbe

# 9. dictionary are mutable...r duplicate keys create korte parbo na....key akta e hbe...meaning onk gula hoite pare


# 10. access korar jnno..amra dic er nam likhe key er nam likhte pari...oigular meaning gula chole ashbe
print(info["name"])
print(info["topics"])
print(info["subject"])
print(info["mark"])








# 11. amra name er modde value chng kore notun value dite chassi
info["name"] = "Tahmid"







# 12. abr chaile notun value add o korte parbo
info["name"] = "Tahmid"
info["surname"] = "Alvee"












# 13. empty dictionary ba null dictionary
null-_dic = {}
print(null_dic)


















# 1. Nested Dictionary

# 2. dictionary er nested mane kono key er value k amra dictionary banaite pari...dictionary er modde arekta dictionary

student = {
    "name" : 'Tahmid Alvee'
    "subject" : {
        "phy" : 97,
        "chem" : 98,
        "math" : 95
    }
}
print(student)

# 3. student dic er modde subject dict er gula print korte
print(student["subjects"])


# 4. jodi nested dic er key gula print koraite hoy
print(student["subjects"]["chem"])








# 1. Dictionary Method
