#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> stalagmites, stalactites;
    for (int i = 0; i < N; i++) {
        int ht;
        cin >> ht;
        if (i % 2 == 0) stalagmites.push_back(ht);
        else stalactites.push_back(ht);
    }
    sort(stalagmites.begin(), stalagmites.end());
    sort(stalactites.begin(), stalactites.end());
    int min_hit = INF, min_hit_cnt = 1;
    for (int m = 1; m <= H; m++) {
        int stalactites_hit = stalactites.end() - lower_bound(stalactites.begin(), stalactites.end(), H - m + 1); 
        int stalagmites_hit = stalagmites.end() - lower_bound(stalagmites.begin(), stalagmites.end(), m); 
        if (stalactites_hit + stalagmites_hit < min_hit) {
            min_hit = stalactites_hit + stalagmites_hit;
            min_hit_cnt = 1;
        } else if (stalactites_hit + stalagmites_hit == min_hit) {
            min_hit_cnt++;
        }
    }
    cout << min_hit << " " << min_hit_cnt << endl;
    return 0;
}