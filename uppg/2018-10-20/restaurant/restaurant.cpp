#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main() {
    while (1) {
        int T;
        cin >> T;
        if (!T) return 0;
        int p_in = 0;
        int p_out = 0;
        while (T--) {
            string command;
            int m;
            cin >> command >> m;
            if (command == "DROP") {
                p_in += m;
                cout << "DROP 2 " << m << endl;
            } else {
                // command == "TAKE"
                int plates_to_clean = m;
                if (p_out == 0) {
                    // case 1: nothing in out
                    // solution: move everything from p_in to p_out
                    // and take accordingly
                    // cout << "c1" << endl;
                    p_out = p_in;
                    p_in = 0;
                    cout << "MOVE 2->1 " << p_out << endl;
                    p_out -= plates_to_clean;
                    cout << "TAKE 1 " << plates_to_clean << endl;
                } else if (p_out < plates_to_clean) {
                    // case 2: something in out, not enough
                    //         plates to clean in out
                    // (1) clean everything first
                    // cout << "c2" << endl;
                    cout << "TAKE 1 " << p_out << endl;
                    plates_to_clean -= p_out;
                    p_out = 0;
                    // (2) move everything from p_in to p_out;
                    cout << "MOVE 2->1 " << p_in << endl;
                    p_out = p_in;
                    p_in = 0;
                    // (3) clean
                    p_out -= plates_to_clean;
                    cout << "TAKE 1 " << plates_to_clean << endl;
                } else {
                    // case 3: something in out, enough plates to clean in out
                    // simply clean everything
                    // cout << "c3" << endl;
                    cout << "TAKE 1 " << plates_to_clean << endl;
                    p_out -= plates_to_clean;
                }
            }
            // cout << p_in << " " << p_out << endl;
        }
        cout << endl;
    }
}
