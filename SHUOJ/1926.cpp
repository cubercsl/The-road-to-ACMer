#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;

int check(string s)
{
    int len=s.length();
    for(int i=0; i<len; i++)
        if(s[i]!=s[len-1-i])
            return i;
    return -1;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string s;
        cin>>s;
        int diff=check(s);
        if(diff==-1)
            cout<<"YES"<<endl;
        else
        {
            string tmp=s;
            string s1=s.erase(diff,1);
            string s2=tmp.erase(tmp.length()-1-diff,1);
            // cout<<s1<<endl;
            // cout<<s2<<endl;
            if(check(s1)==-1||check(s2)==-1)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }

    return 0;
}
