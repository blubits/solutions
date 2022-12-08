#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
    int a, b;
    while (cin >> a >> b && !(a == 0 && b == 0)) {
        unordered_set<int> jack;
        int i = 0;
        while (a--) {
            int k;
            cin >> k;
            jack.insert(k);
        }
        while (b--) {
            int k;
            cin >> k;
            if (jack.find(k) != jack.end()) i++;
        }
        cout << i << endl;
    }
}
