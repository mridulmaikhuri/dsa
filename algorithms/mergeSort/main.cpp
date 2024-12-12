#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& a, int l, int m, int r) {
    int s1 = m - l + 1;
    int s2 = r - m;
    vector<int> left(s1), right(s2);

    for (int i = 0; i < s1; i++) {
        left[i] = a[l + i];
    }
    for (int i = 0; i < s2; i++) {
        right[i] = a[m + 1 + i];
    }

    int i = 0, j = 0, k = l;
    while (i < s1 && j < s2) {
        if (left[i] < right[j]) {
            a[k ++] = left[i ++];
        } else {
            a[k ++] = right[j ++];
        }
    }
    while (i < s1) {
        a[k ++] = left[i ++];
    }
    while (j < s2) {
        a[k ++] = right[j ++];
    }
}
void mergeSort(vector<int>& a, int l, int r) {
    if (l >= r) return;

    int m = l + (r - l)/2;
    mergeSort(a, l, m);
    mergeSort(a, m + 1, r);
    merge(a, l, m, r);
}
int main() {
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    vector<int> a(n);
    cout<<"Enter the elements of the array: ";
    for (int i = 0;i < n;i ++) cin>>a[i];

    cout<<"The elements of the original array are: ";
    for (int i = 0;i < n;i ++) cout<<a[i]<<" ";
    cout<<"\n";

    mergeSort(a, 0, n - 1);
    cout<<"The elements of the sorted array are: ";
    for (int i = 0;i < n;i ++) cout<<a[i]<<" ";
    cout<<"\n";
    return 0;
}