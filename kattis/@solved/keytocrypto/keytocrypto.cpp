#include <iostream>
#include <string>

using namespace std;

int main() {
    string cipher, key, message;
    getline(cin, cipher);
    getline(cin, key);
    for (int i = 0; i < cipher.length(); i++) {
        int base = cipher[i] - 'A';
        int shift = key[i] - 'A';
        char mc = 'A' + ((26 + base - shift) % 26);
        message += mc;
        key += mc;
    }
    cout << message << endl;
    return 0;
}
