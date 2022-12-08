#include <algorithm>
#include <iostream>

using namespace std;

int main() {
    string w;
    long long int k;
    while (cin >> w >> k && !(w == "#" && k == 0)) {
        sort(w.begin(), w.end());
        long long int t = 0;
        do {
            next_permutation(w.begin(), w.end());
            t++;
            // cout << t << " " << k << " " << w << endl;
        } while (t < k - 1);
        cout << w << endl;
    }
}
