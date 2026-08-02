#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <stack>
using namespace std;

namespace PP
{
    map<char, vector<string>> grammar;
    map<char, set<char>> firstSet, followSet;
    map<char, map<char, string>> table;
    char startSym;

    bool isNT(char c) { return isupper((unsigned char)c); }

    set<char> first(char X)
    {
        if (!isNT(X)) return {X};
        if (!firstSet[X].empty()) return firstSet[X];

        for (string& alt : grammar[X])
        {
            bool nullable = true;
            for (char s : alt)
            {
                if (s == '#') break;
                set<char> f = first(s);
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
            for (auto it = grammar.begin(); it != grammar.end(); ++it)
                for (string& alt : it->second)
                    for (size_t i = 0; i < alt.size(); i++)
                    {
                        if (!isNT(alt[i])) continue;
                        bool nullable = true;
                        for (size_t j = i + 1; j < alt.size(); j++)
                        {
                            set<char> f = first(alt[j]);
                            for (char t : f) if (t != '#') changed |= followSet[alt[i]].insert(t).second;
                            if (!f.count('#')) { nullable = false; break; }
                        }
                        if (nullable)
                            for (char t : followSet[it->first]) changed |= followSet[alt[i]].insert(t).second;
                    }
        }
    }

    void buildTable(const vector<string>& productions)
    {
        grammar.clear(); firstSet.clear(); followSet.clear(); table.clear();

        for (const string& rule : productions)
        {
            char lhs = rule[0];
            string rhs = rule.substr(rule.find("->") + 2), alt;
            for (size_t i = 0; i <= rhs.size(); i++)
                if (i == rhs.size() || rhs[i] == '|') { grammar[lhs].push_back(alt); alt.clear(); }
                else alt += rhs[i];
        }

        startSym = productions[0][0];
        for (auto it = grammar.begin(); it != grammar.end(); ++it) first(it->first);
        computeFollow();

        for (auto it = grammar.begin(); it != grammar.end(); ++it)
            for (string& alt : it->second)
            {
                if (alt == "#") { for (char b : followSet[it->first]) table[it->first][b] = "#"; continue; }
                bool nullable = true;
                for (char s : alt)
                {
                    set<char> f = first(s);
                    for (char t : f) if (t != '#') table[it->first][t] = alt;
                    if (!f.count('#')) { nullable = false; break; }
                }
                if (nullable) for (char b : followSet[it->first]) table[it->first][b] = alt;
            }
    }
}

bool predictiveParse(const vector<string>& productions, const string& input)
{
    PP::buildTable(productions);

    stack<char> st;
    st.push('$');
    st.push(PP::startSym);
    string src = input + "$";
    size_t i = 0;

    while (!st.empty())
    {
        char top = st.top(), cur = src[i];
        if (top == cur) { st.pop(); i++; }
        else if (!PP::isNT(top) || !PP::table[top].count(cur)) return false;
        else
        {
            string prod = PP::table[top][cur];
            st.pop();
            if (prod != "#")
                for (auto it = prod.rbegin(); it != prod.rend(); ++it) st.push(*it);
        }
    }
    return i == src.size();
}

int main()
{
    vector<string> productions = { "E->TQ", "Q->+TQ|#", "T->i" };

    string input = "i+i+i";

    if (predictiveParse(productions, input))
        cout << "Accepted" << endl;
    else
        cout << "Rejected" << endl;

    return 0;
}
