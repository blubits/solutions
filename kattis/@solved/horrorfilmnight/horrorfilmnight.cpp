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
    vector<bool> a, b;
    int ka, kb, k;
    cin >> ka;
    a.resize(1000000, false);
    for (int i = 0; i < ka; i++) {
        cin >> k;
        a[k] = true;
    }
    cin >> kb;
    b.resize(1000000, false);
    for (int i = 0; i < kb; i++) {
        cin >> k;
        b[k] = true;
    }
    int ct = 0;
    bool a_like = false, b_like = false;
    for (int i = 0; i <= 999999; i++) {
        if (a[i] && b[i]) {
            //cout << i << " both" << endl;
            ct++;
            a_like = true;
            b_like = true;
        }
        else if (a[i]) {
            if (a_like && !b_like) continue;
            //cout << i << " a" << endl;
            ct++;
            a_like = true;
            b_like = false;
        } else if (b[i]) {
            if (!a_like && b_like) continue;
            //cout << i << " b" << endl;
            ct++;
            a_like = false;
            b_like = true;
        }
    } 
    cout << ct << endl;
    return 0;
}