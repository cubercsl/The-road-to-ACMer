#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define dbg(args...)                             \
    do                                           \
    {                                            \
        cout << "\033[32;1m" << #args << " -> "; \
        err(args);                               \
    } while (0)
#else
#define dbg(...)
#endif
void err()
{
    cout << "\033[39;0m" << endl;
}
template <template <typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args)
{
    for (auto x : a) cout << x << ' ';
    err(args...);
}
template <typename T, typename... Args>
void err(T a, Args... args)
{
    cout << a << ' ';
    err(args...);
}
/****************************************************************************************************/

map<char, int> M;

inline bool calc(stack<int>& num, char op)
{
    int tmp;
    if (op == '+')
        tmp = num.top(), num.pop(), tmp += num.top(), num.pop();
    else if (op == '-')
        tmp = num.top(), num.pop(), tmp = num.top() - tmp, num.pop();
    else if (op == '*')
        tmp = num.top(), num.pop(), tmp *= num.top(), num.pop();
    else if (op == '/')
    {
        tmp = num.top();
        num.pop();
        if (tmp == 0 || num.top() % tmp != 0) return false;
        tmp = num.top() / tmp;
        num.pop();
    }
    num.push(tmp);
    return true;
}

int eval(const string& str)
{
    // dbg(str);
    stack<int> num;
    stack<char> op;
    op.push('#');
    int i = 0;
    char ope;
    while (i < str.length())
    {
        char t = str[i];
        if (t == '(')
            op.push(t), i++;
        else if (t == ')')
        {
            while (op.top() != '(')
            {
                if (!calc(num, op.top())) return -1;
                op.pop();
            }
            op.pop(), i++;
        }
        else if (t == '+' || t == '-' || t == '*' || t == '/')
        {
            while (M[op.top()] >= M[t])
            {
                if (!calc(num, op.top())) return -1;
                op.pop();
            }
            op.push(t), i++;
        }
        else
        {
            int tmp = 0;
            while (isdigit(str[i]))
                (tmp *= 10) += str[i++] - '0';
            num.push(tmp);
        }
    }
    while (op.top() != '#')
    {
        if (!calc(num, op.top())) return -1;
        op.pop();
    }
    return num.top();
}
string a[10];
int ans;
void solve(string line, int cnt)
{
    int res = eval(line);
    if (res != 24) return;
    ans = min(cnt, ans);
}
int work(vector<int>& pos)
{
    int ret = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (pos[i] > pos[j]) ret += 2;
        }
    }
    return ret;
}
int main()
{
    M['+'] = 1, M['-'] = 1, M['*'] = 2, M['/'] = 2;
    vector<int> pos;
    for (int i = 0, j; i < 4; i++)
    {
        cin >> a[i];
        pos.push_back(i);
    }
    ans = 998;
    string maps = "+-*/";
    do
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 0; k < 4; k++)
                {
                    int cnt = work(pos);
                    string line;
                    // 1
                    line += ("(");
                    line += (a[pos[0]]);
                    line += (maps[i]);
                    line += a[pos[1]];
                    line += (")");
                    line += maps[j];
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 1 + cnt);
                    // 2
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += "(";
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += ")";
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 1 + cnt);
                    //3
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += a[pos[1]];
                    line += maps[j];
                    line += "(";
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    line += ")";
                    solve(line, 1 + cnt);
                    //4
                    line = "";
                    line += "(";
                    line += a[pos[0]];
                    line += maps[i];
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += ")";
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 1 + cnt);
                    //5
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += "(";
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    line += ")";
                    solve(line, 1 + cnt);
                    //6
                    line = "";
                    line += "(";
                    line += a[pos[0]];
                    line += maps[i];
                    line += a[pos[1]];
                    line += ")";
                    line += maps[j];
                    line += "(";
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    line += ")";
                    solve(line, 2 + cnt);
                    // 7
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += "(";
                    line += a[pos[1]];
                    line += maps[j];
                    line += "(";
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    line += ")";
                    line += ")";
                    solve(line, 2 + cnt);
                    //8
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += "(";
                    line += "(";
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += ")";
                    line += maps[k];
                    line += a[pos[3]];
                    line += ")";
                    solve(line, 2 + cnt);
                    // 9
                    line = "";
                    line += a[pos[0]];
                    line += maps[i];
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 0 + cnt);
                    // 10
                    line = "";
                    line += "(";
                    line += "(";
                    line += a[pos[0]];
                    line += maps[i];
                    line += a[pos[1]];
                    line += ")";
                    line += maps[j];
                    line += a[pos[2]];
                    line += ")";
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 2 + cnt);
                    // 11
                    line = "";
                    line += "(";
                    line += a[pos[0]];
                    line += maps[i];
                    line += "(";
                    line += a[pos[1]];
                    line += maps[j];
                    line += a[pos[2]];
                    line += ")";
                    line += ")";
                    line += maps[k];
                    line += a[pos[3]];
                    solve(line, 2 + cnt);
                }
            }
        }
    } while (next_permutation(pos.begin(), pos.end()));
    if (ans == 998)
        cout << "impossible" << endl;
    else
        cout << ans << endl;
    return 0;
}
