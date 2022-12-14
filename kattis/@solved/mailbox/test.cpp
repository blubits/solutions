#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

#define gc getchar unlocked
#ifndef ONLINE JUDGE
#define gc getchar
#endif  // ONLINE JUDGE

#define pc putchar_unlocked
#ifndef ONLINE JUDGE
#define pc putchar
#endif  // ONLINE JUDGE

#define fRead freopen("input.txt", "r", stdin)
#define fWrite freopen("output.txt", "w", stdout)

#define eps 1e-8
#define inf 0x3f3f3f3f
#define INF 2e18
#define LL long long
#define ULL unsigned long long
#define PI acos(-1.0)
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define pLL pair<LL, LL>
#define ff first
#define ss second
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define SQR(a) ((a) * (a))
#define Unique(a) sort(all(a)), a.erase(unique(all(a)), a.end())
#define min3(a, b, c) min(a, min(b, c))
#define max3(a, b, c) max(a, max(b, c))
#define min4(a, b, c, d) min(min(a, b), min(c, d))
#define max4(a, b, c, d) max(max(a, b), max(c, d))
#define max5(a, b, c, d, e) max(max3(a, b, c), max(d, e))
#define min5(a, b, c, d, e) min(min3(a, b, c), min(d, e))
#define Iterator(a) __typeof__(a.begin())
#define rIterator(a) __typeof__(a.rbegin())
#define FOR(a, it) for (Iterator(a) it = a.begin(); it != a.end(); it++)
#define rFOR(a, it) for (rIterator(a) it = a.rbegin(); it != a.rend(); it++)
#define FastRead                  \
    ios_base::sync_with_stdio(0); \
    cin.tie(0)
#define CasePrint       \
    pc('C');            \
    pc('a');            \
    pc('s');            \
    pc('e');            \
    pc(' ');            \
    write(qq++, false); \
    pc(':');            \
    pc(' ')
#define vi vector<int>
#define vL vector<LL>
#define For(I, A, B) for (int I = (A); I < (B); ++I)
#define rFor(I, A, B) for (int I = (A); I >= (B); --I)
#define Rep(I, N) For(I, 0, N)
#define REP(I, N) For(I, 1, N + 1)
#define gti int, vi, greater<int>
#define gtL LL, vL, greater<LL>

const int MOD = 1e9 + 7;
int fx[] = {-1, +0, +1, +0, +1, +1, -1, -1, +0};
int fy[] = {+0, -1, +0, +1, +1, -1, +1, -1, +0};
template <typename T>
using orderset =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename T>
inline T GCD(T a, T b) {
    a = abs(a);
    b = abs(b);
    if (a < b) swap(a, b);
    while (b) {
        a = a % b;
        swap(a, b);
    }
    return a;
}
template <typename T>
inline T EGCD(T a, T b, T &x, T &y) {
    if (a == 0) {
        x = 0;
        y = 1;
        return b;
    }
    T x1, y1;
    T d = EGCD(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
template <typename T>
inline T LCM(T x, T y) {
    T tp = GCD(x, y);
    if ((x / tp) * 1. * y > 9e18) return 9e18;
    return (x / tp) * y;
}
template <typename T>
inline T BigMod(T A, T B, T M = MOD) {
    T ret = 1;
    while (B) {
        if (B & 1) ret = (ret * A) % M;
        A = (A * A) % M;
        B = B >> 1;
    }
    return ret;
}
template <typename T>
inline T InvMod(T A, T M = MOD) {
    return BigMod(A, M - 2, M);
}
/*---------------------------fast I/O------------------------------------*/
#define scani2(a, b) scani(a), scani(b)
#define scani3(a, b, c) scani(a), scani(b), scani(c)
#define scani4(a, b, c, d) scani(a), scani(b), scani(c), scani(d)
#define scani5(a, b, c, d, e) scani(a), scani(b), scani(c), scani(d), scani(e)
template <typename T>
T scani(T &n) {
    n = 0;
    bool negative = false;
    char c = gc();
    while (c < '0' || c > '9') {
        if (c == '-') negative = true;
        c = gc();
    }
    while (c >= '0' && c <= '9') {
        n = n * 10 + c - 48;
        c = gc();
    }
    if (negative) n = ~(n - 1);
    return n;
}
template <typename T>
void write(T n, int type = true) {
    if (n < 0) {
        pc('-');
        n = -n;
    }
    if (!n) {
        pc('0');
        if (type == 32)
            pc(' ');
        else if (type)
            pc('\n');
        return;
    }
    char buff[22];
    int len = 0;
    while (n) buff[len++] = n % 10 + 48, n /= 10;
    for (int i = len - 1; i >= 0; i--) pc(buff[i]);
    if (type == 32)
        pc(' ');
    else if (type)
        pc('\n');
}
int scans(char *a) {
    int i = 0;
    char c = 0;
    while (c < 33) c = gc();
    while (c > 33) {
        a[i++] = c;
        c = gc();
    }
    a[i] = 0;
    return i;
}
/*********************************************** End of template
 * *********************************************/
const int N = 2000006;
const int M = 2222;

int dp[111][111][111];

int ans_me(int lf, int rt, int rem) {
    if (lf > rt) return 0;
    if (rem == 1) return rt * (rt + 1) / 2 - lf * (lf - 1) / 2;
    int &ret = dp[lf][rt][rem];
    if (ret != -1) return ret;
    ret = inf;
    for (int i = lf; i <= rt; i++)
        ret = min(ret,
                  i + max(ans_me(lf, i - 1, rem - 1), ans_me(i + 1, rt, rem)));
    return ret;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int t;
    scani(t);
    while (t--) {
        int n, k;
        scani2(n, k);
        write(ans_me(1, k, n));
    }
    return 0;
}
