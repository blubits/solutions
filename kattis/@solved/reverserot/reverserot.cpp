#include <iostream>
#include <string>

using namespace std;

int main() {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ_.";
    int k;
    while (cin >> k && k != 0) {
        string message, enc;
        cin >> message;
        for (int i = message.length() - 1; i >= 0; i--) {
            int idx = alphabet.find(message[i]);
            enc += alphabet[(idx + k) % 28];
        }
        cout << enc << endl;
    }
    return 0;
}
