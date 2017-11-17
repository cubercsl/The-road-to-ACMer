/*
This is the special judge checker for problem 429
Local usage: spj x.in x.out 
*/

#include <bits/stdc++.h>
using namespace std;

#define AC 0
#define WA 1
#define ERROR -1

int spj(FILE* input, FILE* user_output);

void close_file(FILE* f) {
    if (f != NULL) {
        fclose(f);
    }
}

int main(int argc, char* args[]) {
    FILE *input = NULL, *user_output = NULL;
    int result;
    if (argc != 3) {
        printf("Usage: spj x.in x.out\n");
        return ERROR;
    }
    printf("Pending...\n");
    input = fopen(args[1], "r");
    user_output = fopen(args[2], "r");
    if (input == NULL || user_output == NULL) {
        printf("Failed to open output file\n");
        close_file(input);
        close_file(user_output);
        return ERROR;
    }

    result = spj(input, user_output);
    printf("%s\n", result ? "Wrong Answer!" : "Accepted!");

    close_file(input);
    close_file(user_output);
    return result;
}

const int N = 26;
const int maxn = N * N * N * N + 4;
const char str[] = "Impossible";
bool vis[N][N][N][N];
bool check(int s[], int n) {
    assert(n < maxn);
    memset(vis, 0, sizeof(vis));
    for (int i = 3; i < n; i++) {
        if (vis[s[i - 3]][s[i - 2]][s[i - 1]][s[i]]) return false;
        vis[s[i - 3]][s[i - 2]][s[i - 1]][s[i]] = true;
    }
    return true;
}
char s[500005];
int spj(FILE* input, FILE* user_output) {
    printf("Running & Checking...\n");
    int T = 0, n;
    int a[maxn];
    while (fscanf(user_output, "%s", s) != EOF) {
        if (fscanf(input, "%d", &n) == EOF) return WA;
        printf("Case #%d: ", ++T);
        if (n < maxn) {
            if (n != strlen(s)) return WA;
            for (int i = 0; i < n; i++) {
                if (s[i] < 'a' || s[i] > 'z') return WA;
                a[i] = s[i] - 'a';
            }
            if (!check(a, n)) return WA;
        } else {
            if (strcmp(s, str) != 0) return WA;
        }
        printf("Accepted!\n");
    }
    if (fscanf(input, "%d", &n) != EOF) return WA;
    return AC;
}