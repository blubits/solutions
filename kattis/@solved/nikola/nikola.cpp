#include <bits/stdc++.h>

using namespace std;

int max_sq;
vector<long long int> cost;
long long int tot[1000][1000];

long long int dp(long long int sq, long long int last_jump, long long int rec) {
    if (!(0 <= sq && sq < max_sq)) return 1000000000;
    if (sq == 0 && last_jump == 0) return dp(sq + 1, 1, 1);
    if (sq == max_sq - 1) return tot[sq][last_jump] = cost[sq];
    if (tot[sq][last_jump] != -1) return tot[sq][last_jump];

    return tot[sq][last_jump] = cost[sq] + min(
        dp(sq + last_jump + 1, last_jump + 1, rec + 1), 
        dp(sq - last_jump, last_jump, rec + 1)
    );

}

int main() {
    cin >> max_sq;
    cost.resize(max_sq);
    for (int i = 0; i < max_sq; i++) cin >> cost[i];
    memset(tot, -1, sizeof(tot));
    cout << dp(0, 0, 0) << endl;
}