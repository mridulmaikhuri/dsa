#include <bits/stdc++.h>
using namespace std;

pair<int,int> manacher_odd(string s) {
    int n = s.size();
    s = '$' + s + '^';

    vector<int> p(n + 2);
    int l = 1, r = 1;

    for (int i = 1;i <= n;i ++) {
        p[i] = max(0, min(r - i, p[l + (r - i)]));

        while (s[i - p[i] - 1] == s[i + p[i] + 1]) {
            p[i] ++;
        }

        if (i + p[i] > r) {
            l = i - p[i];
            r = i + p[i];
        }
    }

    int c = 0, m = 0;
    for (int i = 1;i <= n;i ++) {
        if (p[i] > m) {
            m = p[i];
            c = i;
        }
    }

    return make_pair(c, m);
}

void manacher(string& s) {
    string t;
    for (auto c : s) {
        t += string("#") + c;
    }

    auto res = manacher_odd(t + '#');
    int c = res.first;
    int m = res.second;

    cout<<s.substr((c - 1 - m)/2, m);
}

int main() {
    string s = "forgeeksskeegfor";

    manacher(s);
}