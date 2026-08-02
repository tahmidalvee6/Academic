#include <iostream>   
#include <vector>
#include <string>
using namespace std;

vector<string> eliminateLeftRecursion(const vector<string>& productions)
{
    vector<string> result;

    for (const string& rule : productions)
    {
        size_t arrow = rule.find("->");
        if (arrow == string::npos) continue;

        string lhs = rule.substr(0, arrow);
        string rhs = rule.substr(arrow + 2);

        vector<string> alpha;
        vector<string> beta;
        string current;

        for (size_t i = 0; i <= rhs.size(); i++)
        {
            if (i == rhs.size() || rhs[i] == '|')
            {
                if (!current.empty())
                {
                    if (current.substr(0, lhs.size()) == lhs)
                        alpha.push_back(current.substr(lhs.size()));
                    else
                        beta.push_back(current);
                }
                current.clear();
            }
            else
            {
                current += rhs[i];
            }
        }

        if (alpha.empty())
        {
            result.push_back(rule);
        }
        else
        {
            string prime = lhs + "'";
            string first = lhs + "->";
            for (size_t i = 0; i < beta.size(); i++)
            {
                first += beta[i] + prime;
                if (i + 1 < beta.size()) first += "|";
            }
            result.push_back(first);

            string second = prime + "->";
            for (size_t i = 0; i < alpha.size(); i++)
                second += alpha[i] + prime + "|";
            second += "#";
            result.push_back(second);
        }
    }

    return result;
}

int main()
{
    vector<string> productions = { "A->A+B|B" };

    vector<string> result = eliminateLeftRecursion(productions);

    cout << "Output:" << endl;
    for (const string& r : result)
        cout << r << endl;

    return 0;
}
