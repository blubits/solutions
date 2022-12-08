#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
    //                           finger 1  2  3  4  5  6  7  8  9  10
    map<char, vector<bool>> f = {{'c', {0, 1, 1, 1, 0, 0, 1, 1, 1, 1}},
                                 {'d', {0, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
                                 {'e', {0, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
                                 {'f', {0, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
                                 {'g', {0, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
                                 {'a', {0, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
                                 {'b', {0, 1, 0, 0, 0, 0, 0, 0, 0, 0}},
                                 {'C', {0, 0, 1, 0, 0, 0, 0, 0, 0, 0}},
                                 {'D', {1, 1, 1, 1, 0, 0, 1, 1, 1, 0}},
                                 {'E', {1, 1, 1, 1, 0, 0, 1, 1, 0, 0}},
                                 {'F', {1, 1, 1, 1, 0, 0, 1, 0, 0, 0}},
                                 {'G', {1, 1, 1, 1, 0, 0, 0, 0, 0, 0}},
                                 {'A', {1, 1, 1, 0, 0, 0, 0, 0, 0, 0}},
                                 {'B', {1, 1, 0, 0, 0, 0, 0, 0, 0, 0}}};

    int t;
    cin >> t;
    string tune;
    getline(cin, tune);
    while (t--) {
        int played[10] = {0};
        bool pressed[10] = {false};
        getline(cin, tune);
        for (auto note : tune) {
            auto pressing = f[note];
            for (int f = 0; f < 10; f++) {
                if (pressing[f]) {
                    if (!pressed[f]) {
                        pressed[f] = true;
                        played[f]++;
                    }
                } else {
                    pressed[f] = false;
                }
            }
        }
        for (int f = 0; f < 10; f++) {
            cout << played[f];
            if (f != 9)
                cout << " ";
            else
                cout << endl;
        }
    }
    return 0;
}
