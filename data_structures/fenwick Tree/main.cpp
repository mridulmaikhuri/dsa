#include <bits/stdc++.h>
using namespace std;

class FenwickTree {
private:
    vector<int> bit;
    int n;
public:
    FenwickTree (int n) {
        bit.resize(n + 1, 0);
        this->n = n;
    }

    FenwickTree(vector<int>& arr) : FenwickTree(arr.size()) {
        int n = arr.size();
        for (int i = 0;i < n;i ++) {
            update(i, arr[i]);
        }
    }

    void update(int idx, int delta) {
        idx ++;
        while (idx <= n) {
            bit[idx] += delta;
            idx += (idx & -idx);
        }
    }

    int query(int idx) {
        idx ++;
        int ans = 0;
        while (idx > 0) {
            ans += bit[idx];
            idx -= (idx & -idx);
        }

        return ans;
    }

};

int main() {
    int n;
    cout<<"Enter the no of elements"<<endl;
    cin>>n;

    vector<int> arr(n);
    cout<<"Enter the elements of the array"<<endl;
    for (int i = 0;i < n;i ++) {
        cin>>arr[i];
    }

    FenwickTree ft(arr);

    int t;
    cout<<"Enter the no of queries"<<endl;
    cin>>t;



    while (t --) {
        int q;
        cout<<"Enter the type of queries"<<endl;
        cin>>q;

        if (q == 1) {
            int idx, val;
            cout<<"Enter the new index and the new value"<<endl;
            cin>>idx>>val;

            ft.update(idx, val - arr[idx]);
            arr[idx] = val;

            cout<<"value updated successfully"<<endl;
        } else {
            int start, end;
            cout<<"Enter the start and end of the range"<<endl;
            cin>>start>>end;

            cout<<"The sum of the range is "<<ft.query(end) - ft.query(start - 1)<<endl;
        }
    }

    return 0;
}