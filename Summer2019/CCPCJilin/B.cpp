#include <bits/stdc++.h>
using namespace std;

struct Time
{
    int h,m,day;
    char t[10], city[20];
    Time() {day = 0;}
    void input()
    {
        scanf("%d:%d%s", &h, &m, t);
        scanf("%s",city);
        if(t[0] == 'A' && h == 12) h = 0;
        if(t[0] == 'P' && h != 12) h = 12 + h;
        if(city[0] == 'B'){
            h -= 8;
            if(h < 0){
                day--;
                h  += 24;
            }
        } else if(city[0] == 'W'){
            h += 5;
            if(h >= 24){
                h -= 24;
                day++;
            }
        } else if(city[0] == 'L'){
            day = 0;
        } else {
            h -= 3;
            if(h < 0){
                day--;
                h  += 24;
            }
        }
    }

    void convert(char *city){
        if(city[0] == 'B'){
            h += 8;
            if(h >= 24){
                day++;
                h  -= 24;
            }
        } else if(city[0] == 'W'){
            h -= 5;
            if(h < 0){
                h += 24;
                day--;
            }
        } else if(city[0] == 'L'){
            // day = 0;
            return;
        } else {
            h += 3;
            if(h >= 24){
                h -= 24;
                day++;
            }
        }
    }
    void output(){
        if(day == 0) printf("Today");
        else if(day == 1) printf("Tomorrow");
        else printf("Yesterday");
        if(h >= 12) {
            t[0] = 'P';
            if(h > 12) h -= 12;
        } else {
            t[0] = 'A';
            if(h == 0) h = 12;
        }
        printf(" %d:%02d %s\n",h,m,t);
    }

};

int main()
{
    int T,kase = 1;
    scanf("%d", &T);
    while (T--)
    {
        Time a;
        a.input();
        char tmp[20];
        scanf("%s",tmp);
        a.convert(tmp);
        printf("Case %d: ",kase++);
        a.output();
    }
}
