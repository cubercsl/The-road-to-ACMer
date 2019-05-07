#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 101000;

int t;
int n;
int arr[MAXN],b[MAXN];

int main() {

    scanf("%d", &t);
    for(int test = 0; test < t; ++test) {
        scanf("%d", &n);
        for(int i = 0; i < n; ++i)
            scanf("%d", &arr[i]), b[i] = arr[i];
        sort(b,b+n);
        int pos = n-1;
        for(int i=n-1;i>=0;i--){
            if(arr[i] == b[pos]){
                pos--;
            }
        }
        printf("%d\n",pos + 1);

    }

}
