#include <bits/stdc++.h>
using namespace std;

vector<int> manacher_odd(string s)
{
    int n = s.size();
    s = '$' + s + '^';

    vector<int> p(n + 2);
    int l = 1, r = 1;

    for (int i = 1; i <= n; i++)
    {
        p[i] = max(0, min(r - i, p[l + (r - i)]));

        while (s[i - p[i] - 1] == s[i + p[i] + 1])
        {
            p[i]++;
        }

        if (i + p[i] > r)
        {
            l = i - p[i];
            r = i + p[i];
        }
    }

    return vector<int>(begin(p) + 1, end(p) - 1);
}

vector<int> manacher(string &s)
{
    string t;
    for (auto c : s)
    {
        t += string("#") + c;
    }

    auto res = manacher_odd(t + '#');
    return vector<int>(begin(res) + 1, end(res) - 1);
}

int main()
{
    string s = "oabcbadef";

    vector<int> res = manacher(s);

    int c = 0, m = 0;
    int n = res.size();
    for (int i = 0;i < n;i ++) {
        if (res[i] > m) {
            m = res[i];
            c = i;
        }
    }

    cout<<s.substr((c - m + 1)/2, m);
}