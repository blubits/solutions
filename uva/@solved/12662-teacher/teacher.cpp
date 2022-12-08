#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    cin >> t;
    string row[t];
    for (int i = 0; i < t; i++) cin >> row[i];
    int a;
    cin >> a;
    while (a--) {
        int idx;
        cin >> idx;
        idx--;
        string p_left = "@", p_right = "@";
        int s_left = 0, s_right = 0;
        for (int i = idx - 1; i >= 0; i--) {
            s_left++;
            if (row[i] != "?") {
                p_left = row[i];
                break;
            }
        }
        for (int i = idx + 1; i < t; i++) {
            s_right++;
            if (row[i] != "?") {
                p_right = row[i];
                break;
            }
        }
        // printf("%d %c | %d %c\n", s_left, p_left, s_right, p_right);
        if (row[idx] != "?") {
            cout << row[idx] << endl;
        } else if (p_left == "@" || (p_right != "@" && s_left > s_right)) {
            for (int i = 0; i < s_right; i++) {
                if (i != 0) cout << " of ";
                cout << "left";
            }
            cout << " of " << p_right << endl;
        } else if (p_right == "@" || (p_left != "@" && s_left < s_right)) {
            for (int i = 0; i < s_left; i++) {
                if (i != 0) cout << " of ";
                cout << "right";
            }
            cout << " of " << p_left << endl;
        } else {
            cout << "middle of " << p_left << " and " << p_right << endl;
        }
    }
}
