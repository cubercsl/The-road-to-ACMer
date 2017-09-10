#include <bits/stdc++.h>
using namespace std;
#define clr(a, x) memset(a, x, sizeof(a))
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define X first
#define Y second
#define fastin                    \
    ios_base::sync_with_stdio(0); \
    cin.tie(0);
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int INF = 0x3f3f3f3f;
const double eps = 1e-6;

int a[72], b[72];

bool check(int a[])
{
    for (int i = 0; i < 72; i++)
        if (a[i] != a[i / 9 * 9]) return false;
    return true;
}

void rotation(int a[], int k)
{
    int t;

    switch (k)
    {
    case 0:
    {
        t = a[0], a[0] = a[4], a[4] = a[8], a[8] = t;
        t = a[1], a[1] = a[6], a[6] = a[3], a[3] = t;
        t = a[2], a[2] = a[5], a[5] = a[7], a[7] = t;
        t = a[9], a[9] = a[35], a[35] = a[40], a[40] = t;
        t = a[11], a[11] = a[34], a[34] = a[41], a[41] = t;
        t = a[10], a[10] = a[30], a[30] = a[42], a[42] = t;
        t = a[14], a[14] = a[29], a[29] = a[43], a[43] = t;
        t = a[13], a[13] = a[27], a[27] = a[44], a[44] = t;
        t = a[18], a[18] = a[67], a[67] = a[53], a[53] = t;
        break;
    }
    case 1:
    {
        t = a[9], a[9] = a[13], a[13] = a[17], a[17] = t;
        t = a[10], a[10] = a[15], a[15] = a[12], a[12] = t;
        t = a[11], a[11] = a[14], a[14] = a[16], a[16] = t;
        t = a[18], a[18] = a[8], a[8] = a[49], a[49] = t;
        t = a[20], a[20] = a[7], a[7] = a[50], a[50] = t;
        t = a[19], a[19] = a[3], a[3] = a[51], a[51] = t;
        t = a[23], a[23] = a[2], a[2] = a[52], a[52] = t;
        t = a[22], a[22] = a[0], a[0] = a[53], a[53] = t;
        t = a[27], a[27] = a[40], a[40] = a[62], a[62] = t;
        break;
    }
    case 2:
    {
        t = a[18], a[18] = a[22], a[22] = a[26], a[26] = t;
        t = a[19], a[19] = a[24], a[24] = a[21], a[21] = t;
        t = a[20], a[20] = a[23], a[23] = a[25], a[25] = t;
        t = a[27], a[27] = a[17], a[17] = a[58], a[58] = t;
        t = a[29], a[29] = a[16], a[16] = a[59], a[59] = t;
        t = a[28], a[28] = a[12], a[12] = a[60], a[60] = t;
        t = a[32], a[32] = a[11], a[11] = a[61], a[61] = t;
        t = a[31], a[31] = a[9], a[9] = a[62], a[62] = t;
        t = a[0], a[0] = a[49], a[49] = a[71], a[71] = t;
        break;
    }
    case 3:
    {
        t = a[27], a[27] = a[31], a[31] = a[35], a[35] = t;
        t = a[28], a[28] = a[33], a[33] = a[30], a[30] = t;
        t = a[29], a[29] = a[32], a[32] = a[34], a[34] = t;
        t = a[0], a[0] = a[26], a[26] = a[67], a[67] = t;
        t = a[2], a[2] = a[25], a[25] = a[68], a[68] = t;
        t = a[1], a[1] = a[21], a[21] = a[69], a[69] = t;
        t = a[5], a[5] = a[20], a[20] = a[70], a[70] = t;
        t = a[4], a[4] = a[18], a[18] = a[71], a[71] = t;
        t = a[9], a[9] = a[58], a[58] = a[44], a[44] = t;
        break;
    }
    case 4:
    {
        t = a[36], a[36] = a[40], a[40] = a[44], a[44] = t;
        t = a[37], a[37] = a[42], a[42] = a[39], a[39] = t;
        t = a[38], a[38] = a[41], a[41] = a[43], a[43] = t;
        t = a[63], a[63] = a[53], a[53] = a[4], a[4] = t;
        t = a[65], a[65] = a[52], a[52] = a[5], a[5] = t;
        t = a[64], a[64] = a[48], a[48] = a[6], a[6] = t;
        t = a[68], a[68] = a[47], a[47] = a[7], a[7] = t;
        t = a[67], a[67] = a[45], a[45] = a[8], a[8] = t;
        t = a[54], a[54] = a[13], a[13] = a[35], a[35] = t;
        break;
    }
    case 5:
    {
        t = a[45], a[45] = a[49], a[49] = a[53], a[53] = t;
        t = a[46], a[46] = a[51], a[51] = a[48], a[48] = t;
        t = a[47], a[47] = a[50], a[50] = a[52], a[52] = t;
        t = a[36], a[36] = a[62], a[62] = a[13], a[13] = t;
        t = a[38], a[38] = a[61], a[61] = a[14], a[14] = t;
        t = a[37], a[37] = a[57], a[57] = a[15], a[15] = t;
        t = a[41], a[41] = a[56], a[56] = a[16], a[16] = t;
        t = a[40], a[40] = a[54], a[54] = a[17], a[17] = t;
        t = a[63], a[63] = a[22], a[22] = a[8], a[8] = t;
        break;
    }
    case 6:
    {
        t = a[54], a[54] = a[58], a[58] = a[62], a[62] = t;
        t = a[55], a[55] = a[60], a[60] = a[57], a[57] = t;
        t = a[56], a[56] = a[59], a[59] = a[61], a[61] = t;
        t = a[45], a[45] = a[71], a[71] = a[22], a[22] = t;
        t = a[47], a[47] = a[70], a[70] = a[23], a[23] = t;
        t = a[46], a[46] = a[66], a[66] = a[24], a[24] = t;
        t = a[50], a[50] = a[65], a[65] = a[25], a[25] = t;
        t = a[49], a[49] = a[63], a[63] = a[26], a[26] = t;
        t = a[37], a[37] = a[31], a[31] = a[17], a[17] = t;
        break;
    }
    case 7:
    {
        t = a[63], a[63] = a[67], a[67] = a[71], a[71] = t;
        t = a[64], a[64] = a[69], a[69] = a[66], a[66] = t;
        t = a[65], a[65] = a[68], a[68] = a[70], a[70] = t;
        t = a[54], a[54] = a[44], a[44] = a[31], a[31] = t;
        t = a[56], a[56] = a[43], a[43] = a[32], a[32] = t;
        t = a[55], a[55] = a[39], a[39] = a[33], a[33] = t;
        t = a[59], a[59] = a[38], a[38] = a[34], a[34] = t;
        t = a[58], a[58] = a[36], a[36] = a[35], a[35] = t;
        t = a[45], a[45] = a[4], a[4] = a[26], a[26] = t;
        break;
    }
    case 8:
    {
        t = a[19], a[19] = a[69], a[69] = a[48], a[48] = t;
        t = a[20], a[20] = a[68], a[68] = a[52], a[52] = t;
        t = a[21], a[21] = a[64], a[64] = a[51], a[51] = t;
        t = a[28], a[28] = a[39], a[39] = a[15], a[15] = t;
        t = a[32], a[32] = a[38], a[38] = a[16], a[16] = t;
        t = a[33], a[33] = a[37], a[37] = a[12], a[12] = t;
        break;
    }
    case 9:
    {
        t = a[28], a[28] = a[42], a[42] = a[57], a[57] = t;
        t = a[29], a[29] = a[41], a[41] = a[61], a[61] = t;
        t = a[30], a[30] = a[37], a[37] = a[60], a[60] = t;
        t = a[1], a[1] = a[48], a[48] = a[24], a[24] = t;
        t = a[5], a[5] = a[47], a[47] = a[25], a[25] = t;
        t = a[6], a[6] = a[46], a[46] = a[21], a[21] = t;
        break;
    }
    case 10:
    {
        t = a[1], a[1] = a[51], a[51] = a[66], a[66] = t;
        t = a[2], a[2] = a[50], a[50] = a[70], a[70] = t;
        t = a[3], a[3] = a[46], a[46] = a[69], a[69] = t;
        t = a[10], a[10] = a[57], a[57] = a[33], a[33] = t;
        t = a[14], a[14] = a[56], a[56] = a[34], a[34] = t;
        t = a[15], a[15] = a[55], a[55] = a[30], a[30] = t;
        break;
    }
    case 11:
    {
        t = a[10], a[10] = a[61], a[61] = a[39], a[39] = t;
        t = a[11], a[11] = a[59], a[59] = a[43], a[43] = t;
        t = a[12], a[12] = a[55], a[55] = a[42], a[42] = t;
        t = a[19], a[19] = a[66], a[66] = a[6], a[6] = t;
        t = a[23], a[23] = a[65], a[65] = a[7], a[7] = t;
        t = a[24], a[24] = a[64], a[64] = a[3], a[3] = t;
        break;
    }
    case 12:
    {
        t = a[10], a[10] = a[39], a[39] = a[61], a[61] = t;
        t = a[11], a[11] = a[43], a[43] = a[59], a[59] = t;
        t = a[12], a[12] = a[42], a[42] = a[55], a[55] = t;
        t = a[19], a[19] = a[6], a[6] = a[66], a[66] = t;
        t = a[23], a[23] = a[7], a[7] = a[65], a[65] = t;
        t = a[24], a[24] = a[3], a[3] = a[64], a[64] = t;
        break;
    }
    case 13:
    {
        t = a[1], a[1] = a[66], a[66] = a[51], a[51] = t;
        t = a[2], a[2] = a[70], a[70] = a[50], a[50] = t;
        t = a[3], a[3] = a[69], a[69] = a[46], a[46] = t;
        t = a[10], a[10] = a[33], a[33] = a[57], a[57] = t;
        t = a[14], a[14] = a[34], a[34] = a[56], a[56] = t;
        t = a[15], a[15] = a[30], a[30] = a[55], a[55] = t;
        break;
    }
    case 14:
    {
        t = a[28], a[28] = a[57], a[57] = a[42], a[42] = t;
        t = a[29], a[29] = a[61], a[61] = a[41], a[41] = t;
        t = a[30], a[30] = a[60], a[60] = a[37], a[37] = t;
        t = a[1], a[1] = a[24], a[24] = a[48], a[48] = t;
        t = a[5], a[5] = a[25], a[25] = a[47], a[47] = t;
        t = a[6], a[6] = a[21], a[21] = a[46], a[46] = t;
        break;
    }
    case 15:
    {
        t = a[19], a[19] = a[48], a[48] = a[69], a[69] = t;
        t = a[20], a[20] = a[52], a[52] = a[68], a[68] = t;
        t = a[21], a[21] = a[51], a[51] = a[64], a[64] = t;
        t = a[28], a[28] = a[15], a[15] = a[39], a[39] = t;
        t = a[32], a[32] = a[16], a[16] = a[38], a[38] = t;
        t = a[33], a[33] = a[12], a[12] = a[37], a[37] = t;
        break;
    }
    case 16:
    {
        t = a[63], a[63] = a[71], a[71] = a[67], a[67] = t;
        t = a[64], a[64] = a[66], a[66] = a[69], a[69] = t;
        t = a[65], a[65] = a[70], a[70] = a[68], a[68] = t;
        t = a[54], a[54] = a[31], a[31] = a[44], a[44] = t;
        t = a[56], a[56] = a[32], a[32] = a[43], a[43] = t;
        t = a[55], a[55] = a[33], a[33] = a[39], a[39] = t;
        t = a[59], a[59] = a[34], a[34] = a[38], a[38] = t;
        t = a[58], a[58] = a[35], a[35] = a[36], a[36] = t;
        t = a[45], a[45] = a[26], a[26] = a[4], a[4] = t;
        break;
    }
    case 17:
    {
        t = a[54], a[54] = a[62], a[62] = a[58], a[58] = t;
        t = a[55], a[55] = a[57], a[57] = a[60], a[60] = t;
        t = a[56], a[56] = a[61], a[61] = a[59], a[59] = t;
        t = a[45], a[45] = a[22], a[22] = a[71], a[71] = t;
        t = a[47], a[47] = a[23], a[23] = a[70], a[70] = t;
        t = a[46], a[46] = a[24], a[24] = a[66], a[66] = t;
        t = a[50], a[50] = a[25], a[25] = a[65], a[65] = t;
        t = a[49], a[49] = a[26], a[26] = a[63], a[63] = t;
        t = a[37], a[37] = a[17], a[17] = a[31], a[31] = t;
        break;
    }
    case 18:
    {
        t = a[45], a[45] = a[53], a[53] = a[49], a[49] = t;
        t = a[46], a[46] = a[48], a[48] = a[51], a[51] = t;
        t = a[47], a[47] = a[52], a[52] = a[50], a[50] = t;
        t = a[36], a[36] = a[13], a[13] = a[62], a[62] = t;
        t = a[38], a[38] = a[14], a[14] = a[61], a[61] = t;
        t = a[37], a[37] = a[15], a[15] = a[57], a[57] = t;
        t = a[41], a[41] = a[16], a[16] = a[56], a[56] = t;
        t = a[40], a[40] = a[17], a[17] = a[54], a[54] = t;
        t = a[63], a[63] = a[8], a[8] = a[22], a[22] = t;
        break;
    }
    case 19:
    {
        t = a[36], a[36] = a[44], a[44] = a[40], a[40] = t;
        t = a[37], a[37] = a[39], a[39] = a[42], a[42] = t;
        t = a[38], a[38] = a[43], a[43] = a[41], a[41] = t;
        t = a[63], a[63] = a[4], a[4] = a[53], a[53] = t;
        t = a[65], a[65] = a[5], a[5] = a[52], a[52] = t;
        t = a[64], a[64] = a[6], a[6] = a[48], a[48] = t;
        t = a[68], a[68] = a[7], a[7] = a[47], a[47] = t;
        t = a[67], a[67] = a[8], a[8] = a[45], a[45] = t;
        t = a[54], a[54] = a[35], a[35] = a[13], a[13] = t;
        break;
    }
    case 20:
    {
        t = a[27], a[27] = a[35], a[35] = a[31], a[31] = t;
        t = a[28], a[28] = a[30], a[30] = a[33], a[33] = t;
        t = a[29], a[29] = a[34], a[34] = a[32], a[32] = t;
        t = a[0], a[0] = a[67], a[67] = a[26], a[26] = t;
        t = a[2], a[2] = a[68], a[68] = a[25], a[25] = t;
        t = a[1], a[1] = a[69], a[69] = a[21], a[21] = t;
        t = a[5], a[5] = a[70], a[70] = a[20], a[20] = t;
        t = a[4], a[4] = a[71], a[71] = a[18], a[18] = t;
        t = a[9], a[9] = a[44], a[44] = a[58], a[58] = t;
        break;
    }
    case 21:
    {
        t = a[18], a[18] = a[26], a[26] = a[22], a[22] = t;
        t = a[19], a[19] = a[21], a[21] = a[24], a[24] = t;
        t = a[20], a[20] = a[25], a[25] = a[23], a[23] = t;
        t = a[27], a[27] = a[58], a[58] = a[17], a[17] = t;
        t = a[29], a[29] = a[59], a[59] = a[16], a[16] = t;
        t = a[28], a[28] = a[60], a[60] = a[12], a[12] = t;
        t = a[32], a[32] = a[61], a[61] = a[11], a[11] = t;
        t = a[31], a[31] = a[62], a[62] = a[9], a[9] = t;
        t = a[0], a[0] = a[71], a[71] = a[49], a[49] = t;
        break;
    }
    case 22:
    {
        t = a[9], a[9] = a[17], a[17] = a[13], a[13] = t;
        t = a[10], a[10] = a[12], a[12] = a[15], a[15] = t;
        t = a[11], a[11] = a[16], a[16] = a[14], a[14] = t;
        t = a[18], a[18] = a[49], a[49] = a[8], a[8] = t;
        t = a[20], a[20] = a[50], a[50] = a[7], a[7] = t;
        t = a[19], a[19] = a[51], a[51] = a[3], a[3] = t;
        t = a[23], a[23] = a[52], a[52] = a[2], a[2] = t;
        t = a[22], a[22] = a[53], a[53] = a[0], a[0] = t;
        t = a[27], a[27] = a[62], a[62] = a[40], a[40] = t;
        break;
    }
    case 23:
    {
        t = a[0], a[0] = a[8], a[8] = a[4], a[4] = t;
        t = a[1], a[1] = a[3], a[3] = a[6], a[6] = t;
        t = a[2], a[2] = a[7], a[7] = a[5], a[5] = t;
        t = a[9], a[9] = a[40], a[40] = a[35], a[35] = t;
        t = a[11], a[11] = a[41], a[41] = a[34], a[34] = t;
        t = a[10], a[10] = a[42], a[42] = a[30], a[30] = t;
        t = a[14], a[14] = a[43], a[43] = a[29], a[29] = t;
        t = a[13], a[13] = a[44], a[44] = a[27], a[27] = t;
        t = a[18], a[18] = a[53], a[53] = a[67], a[67] = t;
        break;
    }
    default:;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);
#endif
    int T;
    bool flag;

    scanf("%d", &T);
    while (T--)
    {
        flag = false;
        for (int i = 0; i < 72; i++) scanf("%d", &a[i]);
        if (check(a)) flag = true;
        for (int i = 0; !flag && i < 24; i++)
        {
            memcpy(b, a, sizeof(b));
            rotation(b, i);
            if (check(b)) flag = true;
        }
        for (int i = 0; !flag && i < 576; i++)
        {
            memcpy(b, a, sizeof(b));
            rotation(b, i / 24);
            rotation(b, i % 24);
            if (check(b)) flag = true;
        }
        for (int i = 0; !flag && i < 13824; i++)
        {
            memcpy(b, a, sizeof(b));
            rotation(b, i / 576);
            rotation(b, i / 24 % 24);
            rotation(b, i % 24);
            if (check(b)) flag = true;
        }
        puts(flag?"YES":"NO");
    }

    return 0;
}
