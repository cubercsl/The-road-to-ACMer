#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        int cnt=0;
        while(m--)
        {
            int num;
            cin>>num;
            for(int i=num;i<n;i++)
            {
                if(i%num==0)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }
	return 0;
}

