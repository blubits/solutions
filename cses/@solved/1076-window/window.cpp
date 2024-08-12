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

    void balance() {
        int bal = lower.size() - higher.size(); // either 1 or 0
        // if bal = 2, offload from low -> high
        // if bal = -1, offload from high -> low
        if (bal < 0) {
            lower.insert(*higher.begin());
            higher.erase(higher.begin());
        } else if (bal > 1) {
            higher.insert(*lower.rbegin());
            lower.erase(lower.find(*lower.rbegin()));
        }
    }

public:
    MedianFinder() {}

    void print() {
        cout << "[";
        for (auto x = lower.begin(); x != lower.end(); x++) cout << *x << ",";
        cout << "] [";
        for (auto x = higher.rbegin(); x != higher.rend(); x++) cout << *x << ",";
        cout << "]" << endl;
    }

    int median() {
        if (lower.empty()) return INF;
        return *lower.rbegin();
    }

    void insert(int x) {
        // Invariants:
        // - lower = higher or lower + 1 = higher (lower < higher)
        // - lower contains <= median
        // - higher contains > median
        if (x > median()) higher.insert(x);
        else lower.insert(x);
        balance();
    }

    void remove(int x) {
        if (x > median()) higher.erase(higher.find(x));
        else lower.erase(lower.find(x));
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
    cout << mf.median();
    for (int i = M; i < N; i++) {
        mf.remove(A[i - M]);
        mf.insert(A[i]);
        cout << " " << mf.median();
    }
    cout << endl;
}