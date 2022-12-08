#include <iostream>
#include <string>

using namespace std;

bool is_vowel(char a) {
    return a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u';
}

int main() {
    string s;
    getline(cin, s);
    bool vowel = false, print = true;
    int chars = 0;
    for (auto c : s) {
        if (!vowel && is_vowel(c)) {
            vowel = true;
            chars = 2;
        }
        if (vowel && chars > 0) {
            print = false;
            chars--;
        } else if (chars == 0) {
            vowel = false;
        }
        if (print) cout << c;
        print = true;
    }
    cout << endl;
    return 0;
}
