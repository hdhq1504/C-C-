#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    string s = "   ngon ngu    lap trinh    Java";
    stringstream ss(s);
    string tmp;
    vector<string> v;
    while (ss >> tmp)
    {
        v.push_back(tmp);
    }

    for (string x : v)
    {
        cout << x << endl;
    }
    return 0;   
}