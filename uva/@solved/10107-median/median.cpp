#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> v;
    int k;
    while (cin >> k) {
        v.push_back(k);
        sort(v.begin(), v.end());
        if (v.size() % 2) {
            cout << v[v.size() / 2];
        } else {
            cout << (v[v.size() / 2] + v[v.size() / 2 - 1]) / 2;
        }
        cout << endl;
    }
}
