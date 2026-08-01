#include <vector>
#include <string>
using namespace std;

vector<string> leftFactor(const vector<string>& productions)
{
    vector<string> result;

    for (const string& rule : productions)
    {
        size_t pos = rule.find("->");
        if (pos == string::npos)
        {
            result.push_back(rule);
            continue;
        }

        string lhs = rule.substr(0, pos);
        string rhs = rule.substr(pos + 2);

        vector<string> parts;
        string current;

        for (size_t i = 0; i <= rhs.size(); i++)
        {
            if (i == rhs.size() || rhs[i] == '|')
            {
                parts.push_back(current);
                current.clear();
            }
            else
            {
                current += rhs[i];
            }
        }

        // need at least 2 alternatives to factor anything
        if (parts.size() < 2)
        {
            result.push_back(rule);
            continue;
        }

        string common = parts[0];
        for (size_t i = 1; i < parts.size(); i++)
        {
            size_t j = 0;
            while (j < common.size() && j < parts[i].size() && common[j] == parts[i][j])
                j++;
            common = common.substr(0, j);
        }

        if (common.empty())
        {
            result.push_back(rule);
        }
        else
        {
            string prime = lhs + "'";
            result.push_back(lhs + "->" + common + prime);

            string second = prime + "->";
            for (size_t i = 0; i < parts.size(); i++)
            {
                string beta = parts[i].substr(common.size());
                if (beta.empty()) beta = "#";
                second += beta;
                if (i + 1 < parts.size()) second += "|";
            }
            result.push_back(second);
        }
    }

    return result;
}
