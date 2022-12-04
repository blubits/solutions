#include <iostream>
#include <string>

using namespace std;

int main() {
    int t;
    while (cin >> t && t) {
        string word, mword;
        int mpair = -1;
        cin.ignore();
        while (t--) {
            getline(cin, word);
            int pair = 0;
            for (int i = 0; i < word.size() - 1; i++) {
                if (word[i] == word[i + 1] &&
                    (word[i] == 'a' || word[i] == 'e' || word[i] == 'i' ||
                     word[i] == 'o' || word[i] == 'u' || word[i] == 'y')) {
                    pair++;
                }
            }
            if (pair > mpair) {
                mpair = pair;
                mword = word;
            }
        }
        cout << mword << endl;
    }
}
