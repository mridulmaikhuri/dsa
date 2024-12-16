#include <bits/stdc++.h>
using namespace std;

vector<int> zfunction(string s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1;i < n;i ++) {
        if (i < r) {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]]) {
            z[i] ++;
        }
        if (i + z[i] > r) {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    string s = "aaaabbbbaaaa";
    vector<int> z = zfunction(s);
    int n = z.size();
    for (int i = 0;i < n;i ++) {
        cout<<z[i]<<endl;
    }
    return 0;
}