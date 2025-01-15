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
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    // Case 1: n = 1. Pooh stays in Rabbit's house.
    if (n == 1) cout << 0 << endl;
    // Case 2: n > 1.
    // Case 2a: min(a, b, c) = a or b. 
    // Pooh eats at Rabbit's house, then goes to Owl's/Eeyore's house,
    // then goes back and forth until he eats n times.
    else if (min(a, min(b, c)) == a || min(a, min(b, c)) == b) {
        cout << min(a, min(b, c)) * (n - 1) << endl;
    }
    // Case 2b: min(a, b, c) = c. 
    // Pooh eats at Rabbit's house, then goes to Owl's/Eeyore's house,
    // wherever is shorter. Then he goes back and forth between Owl's
    // and Eeyore's house.
    else {
        cout << c * (n - 2) + min(a, b) << endl;
    }
    

    return 0;
}