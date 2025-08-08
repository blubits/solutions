#include <bits/stdc++.h>
using namespace std;

#define LSOne(S) ((S) & (-S))

typedef long long ll;
typedef pair<int, int> ii;
typedef tuple<int, int, int> iii;
typedef vector<int> vi;
typedef vector<ii> vii;

const int INF = 0x3f3f3f3f;
const int NINF = 0xcfcfcfcf;
const ll LLINF = 0x3f3f3f3f3f3f3f3f;
const double EPS = 1e-9;

int main() {
    int N, t;
    cin >> N >> t;
    vector<int> A(N); 
    vector<bool> visited(N);
    ll sum = 0, even_sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        sum += ll(A[i]);
        if (A[i] % 2 == 0) {
            even_sum += ll(A[i]);
        }
    }
    if (t == 1) {
        cout << 7 << endl;
    } else if (t == 2) {
        if (A[0] == A[1]) {
            cout << "Equal" << endl;
        } else if (A[0] > A[1]) {
            cout << "Bigger" << endl;
        } else {
            cout << "Smaller" << endl;
        }
    } else if (t == 3) {
        vector<int> B = {A[0], A[1], A[2]};
        sort(B.begin(), B.end());
        cout << B[1] << endl;
    } else if (t == 4) {
        cout << sum << endl;
    } else if (t == 5) {
        cout << even_sum << endl;
    } else if (t == 6) {
        for (int i = 0; i < N; i++) {
            cout << char('a' + (A[i] % 26));
        }
        cout << endl;
    } else {
        int i = 0;
        visited[i] = true;
        while (1) {
            i = A[i];
            if (!(0 <= i && i < N)) {
                cout << "Out" << endl;
                break;
            } else if (i == N - 1) {
                cout << "Done" << endl;
                break;
            } else if (visited[i]) {
                cout << "Cyclic" << endl;
                break;
            } else {
                visited[i] = true;
            }
        }
    }
    return 0;
}