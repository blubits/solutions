#include <iostream>
#include <string>
#include <vector>

using namespace std;

int value(string card) {
    char c = card[0];
    if (c == 'A')
        return 14;
    else if (c == 'K')
        return 13;
    else if (c == 'Q')
        return 12;
    else if (c == 'J')
        return 11;
    else if (c == 'T')
        return 10;
    return card[0] - '0';
}

char suit(string card) { return card[1]; }

const int HIGH_CARD = 100;
const int PAIR = 200;
const int TWO_PAIRS = 300;
const int THREE_OF_A_KIND = 400;
const int STRAIGHT = 500;
const int FLUSH = 600;
const int FULL_HOUSE = 700;
const int FOUR_OF_A_KIND = 800;
const int STRAIGHT_FLUSH = 900;

int get_value(vector<string> &black, vector<string> &white, int &black_val,
              int &white_val) {
    return 0;
}

int main() {
    vector<string> black, white;
    string card;
    while (!cin.eof()) {
        for (int i = 0; i < 5; i++) {
            cin >> card;
            black.push_back(card);
        }
        for (int i = 0; i < 5; i++) {
            cin >> card;
            white.push_back(card);
        }
        int b = 0, w = 0;
        get_value(black, white, b, w);
        if (b > w)
            cout << "Black wins.";
        else if (b < w)
            cout << "White wins.";
        else
            cout << "Tie.";
        cout << endl;
    }
}
