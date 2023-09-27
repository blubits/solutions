#include <bits/stdc++.h>
#define INF 1e9
#define LLINF 4e18
using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int main() {
    int N;
    cin >> N;
    vector<bool> busnumbers(1001);
    while (N--) {
        int bn;
        cin >> bn;
        busnumbers[bn] = true;
    }
    int st = -1, en = -1;
    bool contig = false;
    for (int i = 0; i <= 1000; i++) {
        if (busnumbers[i] && !contig) {
            st = i;
            contig = true;
        } else if (busnumbers[i] && contig) {
            en = i;
        }
        if (!busnumbers[i] && contig) {
            contig = false;
            if (st < en - 1) printf("%d-%d ", st, en);
            else if (st < en) printf("%d %d ", st, en);
            else printf("%d ", st);
        }
    }
    if (contig) {
        contig = false;
        if (st < en - 1) printf("%d-%d ", st, en);
        else if (st < en) printf("%d %d ", st, en);
        else printf("%d ", st);
    }
    return 0;
}