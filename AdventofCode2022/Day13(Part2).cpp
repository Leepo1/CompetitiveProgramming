#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <math.h>
#include <vector>
#include <map>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <sstream>
using namespace std;

vector <string> split(string s)
{
    s = s.substr(1, s.size() - 2);
    vector <string> ans;
    int depth = 0;
    string tmp = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '[') depth++;
        else if (s[i] == ']') depth--;
        else if (s[i] == ',' && depth == 0)
        {
            ans.push_back(tmp);
            tmp.clear();
        }
        if (s[i] != ',' || (s[i] == ',' && depth != 0)) tmp.push_back(s[i]);
    }
    if (tmp.size() != 0) ans.push_back(tmp);
    return ans;
}

int compare(vector <string> left, vector <string> right)
{
    for (int i = 0; i < min(left.size(), right.size()); i++)
    {
        if (left[i][0] != '[' && right[i][0] != '[')
        {
            if (stoi(left[i]) - stoi(right[i]) != 0)
                return stoi(left[i]) - stoi(right[i]);
        }
        else if (left[i][0] == '[' && right[i][0] != '[')
        {
            int x = compare(split(left[i]), split("[" + right[i] + "]"));
            if (x != 0)
                return x;
        }
        else if (left[i][0] != '[' && right[i][0] == '[')
        {
            int x = compare(split("[" + left[i] + "]"), split(right[i]));
            if (x != 0)
                return x;
        }
        else
        {
            int x = compare(split(left[i]), split(right[i]));
            if (x != 0)
                return x;
        }
    }
    return left.size() - right.size();
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen("Day13i.txt", "r", stdin);

    vector <string> v = {"[[2]]", "[[6]]"};
    string line;
    while (cin >> line)
        v.push_back(line);

    sort(v.begin(), v.end(), [](string s1, string s2)
    {
        return compare(split(s1), split(s2)) < 0;
    });

    cout << (find(v.begin(), v.end(), "[[2]]") - v.begin() + 1) * (find(v.begin(), v.end(), "[[6]]") - v.begin() + 1);
}
