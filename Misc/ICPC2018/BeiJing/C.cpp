// ybmj
#include <bits/stdc++.h>
using namespace std;
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define lson_len (len - (len >> 1))
#define rson_len (len >> 1)
#define pb(x) push_back(x)
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define my_unique(a) a.resize(distance(a.begin(), unique(a.begin(), a.end())))
#define my_sort_unique(c) (sort(c.begin(), c.end())), my_unique(c)
const double PI = acos(-1.0);
const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
int card[4][15], order[15];
map<string, int> Hash;
map<int, string> rHash;
vector<int> table, lau;
bool sta;
void init() {
    Hash["A"] = 1;
    Hash["2"] = 2;
    Hash["3"] = 3;
    Hash["4"] = 4;
    Hash["5"] = 5;
    Hash["6"] = 6;
    Hash["7"] = 7;
    Hash["8"] = 8;
    Hash["9"] = 9;
    Hash["10"] = 10;
    Hash["J"] = 11;
    Hash["Q"] = 12;
    Hash["K"] = 13;
    order[0] = 10;
    order[1] = 2;
    order[2] = 3;
    order[3] = 4;
    order[4] = 5;
    order[5] = 6;
    order[6] = 7;
    order[7] = 8;
    order[8] = 9;
    order[9] = 1;
    order[10] = 11;
    order[11] = 13;
    order[12] = 12;
    rHash[1] = "A";
    rHash[2] = "2";
    rHash[3] = "3";
    rHash[4] = "4";
    rHash[5] = "5";
    rHash[6] = "6";
    rHash[7] = "7";
    rHash[8] = "8";
    rHash[9] = "9";
    rHash[10] = "10";
    rHash[11] = "J";
    rHash[12] = "Q";
    rHash[13] = "K";
}

void Launch(int i, int rank) {
    lau.clear();
    if (i == 0) {
        if (card[i][rank]) {
            card[i][rank]--;
            sta = true;
            lau.pb(rank);
            return;
        } else {
            sta = false;
            for (int k = 0, c; k < 13; k++) {
                c = order[k];
                if (card[i][c]) {
                    card[i][c]--;
                    lau.pb(c);
                    return;
                }
            }
            return;
        }
    }
    if (i == 1) {
        if (card[i][rank]) {
            while (card[i][rank] > 0) {
                lau.pb(rank);
                card[i][rank]--;
            }
            sta = true;
            return;
        } else {
            sta = false;
            for (int k = 0, c; k < 13; k++) {
                c = order[k];
                if (card[i][c]) {
                    card[i][c]--;
                    lau.pb(c);
                    return;
                }
            }
            return;
        }
    }
    if (i == 2) {
        if (card[i][rank]) {
            while (card[i][rank] > 0) {
                lau.pb(rank);
                card[i][rank]--;
            }
            sta = true;
            return;
        } else {
            int num = 100;
            int t = -1;
            for (int k = 0, c; k < 13; k++) {
                c = order[k];
                if (num > card[i][c] && card[i][c] > 0) {
                    num = card[i][c];
                    t = c;
                }
            }
            while (card[i][t] > 0) {
                lau.pb(t);
                card[i][t]--;
            }
            sta = false;
            return;
        }
    }
    if (i == 3) {
        if (card[i][rank] == 3 || card[i][rank] == 4) {
            while (card[i][rank] > 0) {
                lau.pb(rank);
                card[i][rank]--;
            }
            sta = true;
            return;
        } else {
            sta = true;
            while (card[i][rank] > 0) {
                lau.pb(rank);
                card[i][rank]--;
            }
            for (int k = 0, c; k < 13; k++) {
                c = order[k];
                if (card[i][c]) {
                    sta = false;
                    card[i][c]--;
                    lau.pb(c);
                    return;
                }
            }
            return;
        }
    }
    // cout << "fcuk" << endl;
}

void judge(int now, int cha) {
    if (sta == true) {
        for (auto &v : lau) card[cha][v]++;
        for (auto &v : table) card[cha][v]++;
    } else {
        for (auto &v : lau) card[now][v]++;
        for (auto &v : table) card[now][v]++;
    }
    table.clear();
    lau.clear();
}
bool lie(int cha, int rank) {  // lie : true
    if (rank == 14) rank = 1;
    if (cha == 0 || cha == 1 || cha == 2) {
        if (card[cha][rank]) return false;
        return true;
    }
    if (cha == 3) {
        if (card[cha][rank] == 3 || card[cha][rank] == 4) return false;
        for (int i = 1; i <= 13; i++) {
            if (i != rank && card[cha][i]) {
                return true;
            }
        }
        return false;
    }
}
bool challenge(int now, int cha, int rank) {
    if (cha == 0) {
        if (((now + 1) % 4 == cha) && lie(cha, rank + 1)) {
            judge(now, cha);
            return true;
        }
        int sz = 0;
        // for (auto &v : lau)
        // if (v == rank) sz++;
        sz = lau.size();
        if (sz + card[cha][rank] > 4) {
            judge(now, cha);
            return true;
        }
        return false;
    }
    if (cha == 1) {
        if (((now + 1) % 4 == cha) && lie(cha, rank + 1)) {
            judge(now, cha);
            return true;
        }
        return false;
    }
    if (cha == 2) {
        if (card[cha][rank] == 4) {
            judge(now, cha);
            return true;
        }
        return false;
    }
    if (cha == 3) {
        int sz = 0;
        for (int i = 1; i <= 13; i++) sz += card[now][i];
        if (sz == 0) {
            judge(now, cha);
            return true;
        }
        return false;
    }
}
int play() {
    int now = 0;
    int rank = 1;
    while (true) {
        Launch(now, rank);
        bool flag = false;  // nobody challenge.
        for (int i = 1; i < 4; i++) {
            int cha = (now + i) % 4;
            if (challenge(now, cha, rank) == true) {
                table.clear();
                flag = true;
                break;
            }
        }
        if (!flag)
            for (auto &v : lau) table.pb(v);
        lau.clear();
        int sz = 0;
        for (int i = 1; i <= 13; i++) sz += card[now][i];
        if (sz == 0) break;
        now = (now + 1) % 4;
        rank++;
        if (rank == 14) rank = 1;
    }
    return now;
}

void debug() {
    for (int i = 0; i < 4; i++) {
        for (int k = 1; k <= 13; k++) {
            cout << card[i][k] << ' ';
        }
        cout << endl;
    }
}
int main() {
    //	/*
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    //	*/
    std::ios::sync_with_stdio(false);
    init();
    string s;
    while (cin >> s) {
        clr(card, 0);
        card[0][Hash[s]]++;
        for (int i = 1; i < 13; i++) {
            cin >> s;
            card[0][Hash[s]]++;
        }
        for (int i = 1; i < 4; i++) {
            for (int k = 0; k < 13; k++) {
                cin >> s;
                card[i][Hash[s]]++;
            }
        }
        // ----
        lau.clear();
        table.clear();
        int win = play();

        // debug();
        // ---
        for (int i = 0; i < 4; i++) {
            if (i == win)
                cout << "WINNER" << endl;
            else {
                vector<string> tmp;
                for (int k = 1; k <= 13; k++) {
                    while (card[i][k] > 0) {
                        tmp.pb(rHash[k]);
                        card[i][k]--;
                    }
                }
                for (int i = 0; i < tmp.size(); i++) {
                    if (i)
                        cout << ' ' << tmp[i];
                    else
                        cout << tmp[i];
                }
                cout << endl;
            }
        }
    }
}