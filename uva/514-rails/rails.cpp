#include <stack>
#include <vector>
#include <iostream>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        while (1) {
            vector<int> posns;
            for (int i = 0; i < n; i++) {
                int num;
                cin >> num;
                if (num == 0) break;
                else posns.push_back(num);
            }
            if (posns.empty()) break;

            stack<int> s;
            bool is_stack_permutation = true;
            int k = 1, i = 0;
            s.push(k);
            while (!s.empty() || i < n) {
                if (!s.empty() && posns[i] == s.top()) {
                    s.pop();
                    i++;
                } else {
                    k++;
                    if (k > n) {
                        is_stack_permutation = false;
                        break;
                    }
                    s.push(k);
                }
            }

            cout << (is_stack_permutation ? "Yes" : "No") << endl;
        }
        cout << endl;
    }
}