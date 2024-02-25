#include <iostream>
#include <sstream>
#include <string>

using namespace std;

#define GREEN 0
#define YELLOW 1
#define RED 2

int main() {
    string s;
    int c = 1;
    while (getline(cin, s)) {
        stringstream ss(s);
        bool green[3601];
        for (int i = 0; i <= 3600; i++) green[i] = true;
        int k;
        while (ss >> k) {
            int ct = 0;
            int status = GREEN;
            for (int i = 0; i <= 3600; i++) {
                if (status == GREEN && ct == k - 5)
                    status = YELLOW;
                else if (status == YELLOW && ct == k)
                    status = RED;
                else if (status == RED && ct == k)
                    status = GREEN;
                if (ct == k) ct = 0;
                if (status == GREEN)
                    green[i] = green[i] && true;
                else
                    green[i] = false;
                ct++;
            }
        }
        bool unsynced = false, never_broke = true;
        for (int i = 0; i <= 3600; i++) {
            if (unsynced && green[i]) {
                cout << "Set " << c++ << " synchs again at " << i / 60
                     << " minute(s) and " << i % 60
                     << " second(s) after all turning green." << endl;
                never_broke = false;
                break;
            }
            if (!green[i] && !unsynced) unsynced = true;
        }
        if (never_broke)
            cout << "Set " << c++ << " is unable to synch after one hour."
                 << endl;
    }
}
