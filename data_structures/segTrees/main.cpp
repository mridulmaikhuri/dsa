#include <bits/stdc++.h>
using namespace std;

class segTree {
private:
    vector<int> arr;
public:
    segTree(int n) {
        arr.resize(4*n + 1);
    }

    void build(vector<int>& nums, int i, int l, int r) {
        if (l == r) {
            arr[i] = nums[l];
            return;
        }

        int m = l + (r - l)/2;
        build(nums, 2*i, l, m);
        build(nums, 2*i + 1, m + 1, r);

        arr[i] = arr[2*i] + arr[2*i + 1];
    }

    int query(int i, int l, int r, int s, int e) {
        if (s > e) return 0;
        if (l == s && r == e) return arr[i];

        int m = l + (r - l)/2;
        return query(2*i, l, m, s, min(e, m)) + query(2*i + 1, m + 1, r, max(s, m + 1), e);
    }

    void update(int i, int l, int r, int p, int v) {
        if (l == r) {
            arr[i] = v;
            return; 
        }

        int m = l + (r - l)/2;
        if (p <= m) {
            update(i*2, l, m, p, v);
        } else {
            update(i*2 + 1, m + 1, r, p, v);
        }

        arr[i] = arr[2*i] + arr[2*i + 1];
    }
};


int main() {
    int n;
    cout<<"Enter the size of the array"<<endl;
    cin>>n;

    vector<int> nums(n);
    cout<<"Enter the elements of the array"<<endl;
    for (int i = 0;i < n;i ++) {
        cin>>nums[i];
    }

    segTree sg1(n);
    sg1.build(nums, 1, 0, n - 1);

    int t;
    cout<<"Enter the no of queries"<<endl;
    cin>>t;

    while (t --) {
        int q;
        cout<<"Enter the type of query"<<endl;
        cin>>q;

        if (q == 1) {
            int l, r;
            cout<<"Enter the value of l and r"<<endl;
            cin>>l>>r;

            cout<<sg1.query(1, 0, n - 1, l, r)<<endl;
        } else {
            int p, v;
            cout<<"Enter the index and new value"<<endl;
            cin>>p>>v;

            sg1.update(1, 0, n - 1, p, v);
            cout<<"Value successfully updated"<<endl; 
        }
    }

    return 0;
}