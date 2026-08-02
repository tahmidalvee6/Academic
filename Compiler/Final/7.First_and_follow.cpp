#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;

map<char, vector<string>> grammar;
map<char, set<char>> firstSet, followSet;
char startSym;

bool isNT(char c) { return isupper((unsigned char)c); }

set<char> FIRST(char X)
{
    if (!isNT(X)) return {X};
    if (!firstSet[X].empty()) return firstSet[X];

    for (string& alt : grammar[X])
    {
        if (alt == "#") { firstSet[X].insert('#'); continue; }
        bool nullable = true;
        for (char s : alt)
        {
            set<char> f = FIRST(s);
            for (char t : f) if (t != '#') firstSet[X].insert(t);
            if (!f.count('#')) { nullable = false; break; }
        }
        if (nullable) firstSet[X].insert('#');
    }
    return firstSet[X];
}

void computeFollow()
{
    followSet[startSym].insert('$');
    bool changed = true;
    while (changed)
    {
        changed = false;
        for (auto& entry : grammar)
        {
            char A = entry.first;
            for (string& alt : entry.second)
                for (size_t i = 0; i < alt.size(); i++)
                {
                    if (!isNT(alt[i])) continue;
                    bool nullable = true;
                    for (size_t j = i + 1; j < alt.size(); j++)
                    {
                        set<char> f = FIRST(alt[j]);
                        for (char t : f) if (t != '#') changed |= followSet[alt[i]].insert(t).second;
                        if (!f.count('#')) { nullable = false; break; }
                    }
                    if (nullable)
                        for (char t : followSet[A]) changed |= followSet[alt[i]].insert(t).second;
                }
        }
    }
}

void computeFirstFollow(const vector<string>& productions)
{
    grammar.clear(); firstSet.clear(); followSet.clear();

    for (const string& rule : productions)
    {
        char lhs = rule[0];
        string rhs = rule.substr(rule.find("->") + 2), alt;
        for (size_t i = 0; i <= rhs.size(); i++)
        {
            if (i == rhs.size() || rhs[i] == '|') { grammar[lhs].push_back(alt); alt.clear(); }
            else alt += rhs[i];
        }
    }
    startSym = productions[0][0];
    for (auto& entry : grammar) FIRST(entry.first);
    computeFollow();
}

void printFirstFollow()
{
    cout << "\nFIRST SETS :\n";
    for (auto& entry : firstSet)
    {
        cout << "FIRST(" << entry.first << ") = { ";
        for (char c : entry.second) cout << c << " ";
        cout << "}\n";
    }
    cout << "\nFOLLOW SETS :\n";
    for (auto& entry : followSet)
    {
        cout << "FOLLOW(" << entry.first << ") = { ";
        for (char c : entry.second) cout << c << " ";
        cout << "}\n";
    }
}

int main()
{
    vector<string> productions = { "A->BA'", "A'->+BA'|#", "B->i" };

    computeFirstFollow(productions);
    printFirstFollow();

    return 0;
}
