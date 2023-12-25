#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int m, u, d;
int m_in, m_dec, u_in, u_dec;

map<string, int> drink_names;
string names[10];
int un[10], costn[10];
bool threes[10];

int memo[10][1500][2000];
int pre[10][1500][2000];    // 1 if with, 2 if without

bool dp(int drink, int u_left, int m_left) {
    if (u_left == 0 && m_left == 0) return true;
    if (u_left < 0 || m_left < 0 || drink >= d) return false;
    if (memo[drink][u_left][m_left] != -1) return memo[drink][u_left][m_left];
    if (u_left - un[drink] < 0 || m_left - costn[drink] < 0) {
        bool without = dp(drink + 1, u_left, m_left);
        if (without) {
            pre[drink][u_left][m_left] = 2;
            return memo[drink][u_left][m_left] = true;
        } else {
            return memo[drink][u_left][m_left] = false;
        }
    } else {
        bool with = dp(drink, u_left - un[drink], m_left - costn[drink]);
        bool without = dp(drink + 1, u_left, m_left);
        if (with) {
            pre[drink][u_left][m_left] = 1;
            return memo[drink][u_left][m_left] = true;
        } else if (without) {
            pre[drink][u_left][m_left] = 2;
            return memo[drink][u_left][m_left] = true;
        } else {
            return memo[drink][u_left][m_left] = false;
        }
    }
}

int main() {
    memset(memo, -1, sizeof memo);
    memset(pre, 0, sizeof pre);
    scanf("%d.%d %d.%d %d\n", &m_in, &m_dec, &u_in, &u_dec, &d);
    m = m_in * 100 + m_dec;
    u = (u_in * 10 + u_dec) * 6;
    for (int i = 0; i < d; i++) {
        string name, size;
        int strength;
        float cost;
        cin >> name >> strength >> size >> cost;
        drink_names[name] = i;
        names[i] = name;
        costn[i] = cost * 100;
        if (size == "1/1") {
            un[i] = strength * 60;
        } else if (size == "1/2") {
            un[i] = (strength * 60) / 2;
        } else {
            un[i] = (strength * 60) / 3;
        }
    }
    if (dp(0, u, m)) {
        int cd = 0, cu = u, cm = m;
        int curr_ct = 0;
        while (!(cu == 0 && cm == 0)) {
            if (pre[cd][cu][cm] == 1) {
                curr_ct++;
                cu -= un[cd];
                cm -= costn[cd]; 
            } else {
                if (curr_ct != 0) cout << names[cd] << " " << curr_ct << endl;
                curr_ct = 0;
                cd += 1;
            }
        }
        cout << names[cd] << " " << curr_ct << endl;
    } else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}