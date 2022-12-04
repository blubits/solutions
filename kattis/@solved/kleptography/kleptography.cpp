#include <iostream>
#include <string>

using namespace std;

int main() {
    string end, key, encoded, decoded;
    getline(cin, end);
    getline(cin, end);
    getline(cin, encoded);
    for (int i = 0; i < encoded.size() - end.size(); i++) {
        decoded += 'x';
    }
    for (int i = 0; i < encoded.size(); i++) {
        key += 'x';
    }
    decoded += end;
    for (int i = encoded.size() - end.size() - 1; i >= 0; i--) {
        int bi = encoded[i + end.size()] - 'a',
            ai = decoded[i + end.size()] - 'a';
        char ki = 'a' + ((26 + bi - ai) % 26);
        decoded[i] = ki;
        key[i + end.size()] = ki;
    }
    cout << decoded << endl;
    return 0;
}
