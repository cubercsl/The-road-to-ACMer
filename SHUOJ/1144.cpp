#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    set<int>s;
    while(n--){
        int num;
        cin>>num;
        s.insert(num);
    }
    cout<<s.size()<<endl;
    int flag=0;
    for(set<int>::iterator it=s.begin();it!=s.end();it++)
    {
        if(flag++)
            cout<<" ";
        cout<<*it;
    }
    cout<<endl;
	return 0;
}

