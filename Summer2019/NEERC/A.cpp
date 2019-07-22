#include<bits/stdc++.h>
using namespace std;

int main(){
    double t,p;
    cin >> t >> p;
    double sum = 0;
    if(p >= 20){
        double d = (100 - p) / t;
        double tmp = p - 20;
        sum += tmp / d;
        sum += 40 / d;
    } else{
        double tmp = 20 - p;
        double a = tmp *2 + 80;
        double d = a / t;
        sum += 2*p / d;
    }
    cout << fixed << setprecision(6) << sum <<endl;
}