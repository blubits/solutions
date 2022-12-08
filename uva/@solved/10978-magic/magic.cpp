#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int t;
    while (cin >> t && t != 0) {
        string card, word;
        vector<string> cards(t);
        int ptr = -1;
        while (t--) {
            cin >> card >> word;
            for (int i = 0; i < word.size(); i++) {
                ptr = (ptr + 1) % cards.size();
                while (!cards[ptr].empty()) ptr = (ptr + 1) % cards.size();
            }
            cards[ptr] = card;
        }
        for (int i = 0; i < cards.size(); i++) {
            cout << cards[i];
            if (i == cards.size() - 1)
                cout << endl;
            else
                cout << " ";
        }
    }
}
