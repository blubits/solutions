#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 1e9;
const ll LLINF = 4e18;
const double EPS = 1e-9;

int allrobots = 0;

// u: last robot destroyed (robot 0 is the Mega Buster)
// mask: what i can destroy (what is within my capabilities && hasn't been destroyed yet)
int count_paths(int u, int mask) {

}

vector<int> robomasks;

int main() {
    int T;
    cin >> T;
    while (T--) {
        robomasks.clear();
        int N;
        cin >> N;
        allrobots = (1 << N) - 1;
        cin.ignore();
        for (int i = 0; i < N + 1; i++) {
            string s;
            getline(cin, s);
            robomasks.push_back(bitset<64>(s).to_ulong());
        }
        for (auto i: robomasks) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}