#include <iostream>
#include <stack>

using namespace std;

int main() {
    stack<int> s, g;
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        s.push(k);
    }
    while (!s.empty()) {
        g.push(s.top());
        s.pop();
        if (g.size() >= 2) {
            int c1 = g.top();
            g.pop();
            int c2 = g.top();
            g.pop();
            if ((c1 + c2) % 2 != 0) {
                g.push(c2);
                g.push(c1);
            }
        }
    }
    cout << g.size() << endl;
    return 0;
}
