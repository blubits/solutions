#include <iostream>
#include <string>

using namespace std;

int main() {
    string input, rev, ans = "";
    getline(cin, input);
    for (int c1 = 1; c1 < input.size(); c1++) {
        for (int c2 = c1 + 1; c2 < input.size(); c2++) {
            rev.clear();
            // reverse [0..c1)
            for (int i = c1 - 1; i >= 0; i--) {
                rev += input[i];
            }
            // reverse [c1..c2)
            for (int i = c2 - 1; i >= c1; i--) {
                rev += input[i];
            }
            // reverse [c2..n)
            for (int i = input.size() - 1; i >= c2; i--) {
                rev += input[i];
            }
            if (ans.empty() || rev < ans) {
                ans = rev;
            }
        }
    }
    cout << ans << endl;
}
