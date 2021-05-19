
#include<iostream>
#include <algorithm>

using namespace std;

int MAX(int a[], int n) {
    sort(a, a + n);
    long long ans = 0;

    for(int i = 0;i < n; i++) {
        ans = (ans + ((long long)a[i]*i) % 1000000007) % 1000000007;
    }
    return (int)ans;
}

int main() {
    int a[]= {1,2,3};

    cout << MAX(a, sizeof(a)/sizeof(a[0]));
    return 0;
}