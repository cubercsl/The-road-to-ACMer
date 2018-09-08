#include <bits/stdc++.h>
using namespace std;

map<char, int> L;
map<char, int> R;

string change(const string& str)
{
    string ret;
    stack<char> s;
    s.push('#');
    for (int i = 0; i < str.length(); i++)
    {
        char t = str[i];
        if (t == '(')
            s.push(t);
        else if (t == ')')
        {
            while (s.top() != '(')
            {
                ret += s.top();
                s.pop();
                ret += ' ';
            }
            s.pop();
        }
        else if (t == '+' || t == '-' || t == '*' || t == 'd')
        {
            while (L[s.top()] >= R[t])
            {
                ret += s.top();
                ret += ' ';
                s.pop();
            }
            s.push(t);
        }
        else
        {
            while (isdigit(str[i]))
                ret += str[i++];
            i--, ret += ' ';
        }
    }
    while (s.top() != '#')
    {
        ret += s.top();
        ret += ' ';
        s.pop();
    }
    return ret;
}

pair<int, int> operator+(pair<int, int> a, pair<int, int> b)
{
    long long vec[] = {a.first + b.first, a.first + b.second, a.second + b.first, a.second + b.second};
    sort(vec, vec + 4);
    return {vec[0], vec[3]};
}

pair<int, int> operator-(pair<int, int> a, pair<int, int> b)
{
    long long vec[] = {a.first - b.first, a.first - b.second, a.second - b.first, a.second - b.second};
    sort(vec, vec + 4);
    return {vec[0], vec[3]};
}

pair<int, int> operator*(pair<int, int> a, pair<int, int> b)
{
    long long vec[] = {a.first * b.first, a.first * b.second, a.second * b.first, a.second * b.second};
    sort(vec, vec + 4);
    return {vec[0], vec[3]};
}

pair<int, int> operator^(pair<int, int> a, pair<int, int> b)
{
    if (a.first < 0) a.first = 0;
    if (b.first < 1) b.first = 1;
    long long vec[] = {a.first, a.second, a.first * b.first, a.first * b.second, a.second * b.first, a.second * b.second};
    sort(vec, vec + 6);
    return {vec[0], vec[5]};
}

pair<int, int> solve(const string& str)
{
    stack<pair<int, int>> s;
    int i = 0;

    pair<int, int> tmp;
    while (i < str.length())
    {
        if (str[i] == ' ')
        {
            i++;
            continue;
        }
        if (str[i] == '+')
            tmp = s.top(), s.pop(), tmp = tmp + s.top(), s.pop(), i++;
        else if (str[i] == '-')
            tmp = s.top(), s.pop(), tmp = s.top() - tmp, s.pop(), i++;
        else if (str[i] == '*')
            tmp = s.top(), s.pop(), tmp = tmp * s.top(), s.pop(), i++;
        else if (str[i] == 'd')
            tmp = s.top(), s.pop(), tmp = s.top() ^ tmp, s.pop(), i++;
        else
        {
            int x = 0;
            while (isdigit(str[i]))
                x = x * 10 + str[i++] - '0';
            tmp = {x, x};
        }
        s.push(tmp);
    }
    return s.top();
}

int main()
{
    L['+'] = 1, L['-'] = 1, L['*'] = 2, L['d'] = 3;
    R['+'] = 1, R['-'] = 1, R['*'] = 2, R['d'] = 4;
    string s;
    while (cin >> s)
    {
        string tmp = change(s);
        // cerr << tmp << endl;
        auto res = solve(tmp);
        cout << res.first << " " << res.second << "\n";
    }
}
/*
2d2+4d5*(1-6)
*/