#include <bits/stdc++.h>
#define LSOne(S) ((S) & (-S))
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

class MedianFinder {
    multiset<int> lower, higher;
    ll lower_sum, higher_sum;

    void balance() {
        int bal = lower.size() - higher.size();  // either 1 or 0
        // if bal = 2, offload from low -> high
        // if bal = -1, offload from high -> low
        if (bal < 0) {
            int to_remove = *higher.begin();
            lower.insert(*higher.begin());
            higher.erase(higher.begin());
            lower_sum += to_remove;
            higher_sum -= to_remove;
        } else if (bal > 1) {
            int to_remove = *lower.rbegin();
            higher.insert(*lower.rbegin());
            lower.erase(lower.find(*lower.rbegin()));
            higher_sum += to_remove;
            lower_sum -= to_remove;
        }
    }

   public:
    MedianFinder() : lower_sum(0), higher_sum(0) {}

    ll cost() {
        return abs(lower_sum - ll(lower.size()) * median()) +
               abs(higher_sum - ll(higher.size()) * median());
    }

    ll median() {
        if (lower.empty()) return INF;
        return *lower.rbegin();
    }

    void insert(int x) {
        // Invariants:
        // - lower = higher or lower + 1 = higher (lower < higher)
        // - lower contains <= median
        // - higher contains > median
        if (x > median()) {
            higher.insert(x);
            higher_sum += x;
        } else {
            lower.insert(x);
            lower_sum += x;
        }
        balance();
    }

    void remove(int x) {
        if (x > median()) {
            higher.erase(higher.find(x));
            higher_sum -= x;
        } else {
            lower.erase(lower.find(x));
            lower_sum -= x;
        }
        balance();
    }
};

int main() {
    MedianFinder mf;
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) mf.insert(A[i]);
    cout << mf.cost();
    for (int i = M; i < N; i++) {
        mf.remove(A[i - M]);
        mf.insert(A[i]);
        cout << " " << mf.cost();
    }
    cout << endl;
}