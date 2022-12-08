#include <iostream>
#include <string>

using namespace std;

int main() {
    int sz;
    string num;
    /**
     *  --      0
     * |  |     1/2
     * |  |
     *  --      3
     * |  |     4/5
     * |  |
     *  --      6
     */
    bool map[10][7] = {
        {1, 1, 1, 0, 1, 1, 1},  // 0
        {0, 0, 1, 0, 0, 1, 0},  // 1
        {1, 0, 1, 1, 1, 0, 1},  // 2
        {1, 0, 1, 1, 0, 1, 1},  // 3
        {0, 1, 1, 1, 0, 1, 0},  // 4
        {1, 1, 0, 1, 0, 1, 1},  // 5
        {1, 1, 0, 1, 1, 1, 1},  // 6
        {1, 0, 1, 0, 0, 1, 0},  // 7
        {1, 1, 1, 1, 1, 1, 1},  // 8
        {1, 1, 1, 1, 0, 1, 1},  // 9
    };

    while (cin >> sz >> num && !(sz == 0 && num == "0")) {
        // print top
        int k;
        k = 0;
        for (char c : num) {
            bool print_top = map[int(c) - '0'][0];
            char seg1 = ' ';
            if (print_top) seg1 = '-';
            cout << " ";
            for (int i = 0; i < sz; i++) cout << seg1;
            cout << " ";
            if (k++ != num.size() - 1) cout << " ";
        }
        cout << endl;
        // print side 1
        // print top
        for (int i = 0; i < sz; i++) {
            k = 0;
            for (char c : num) {
                bool print_left = map[int(c) - '0'][1];
                bool print_right = map[int(c) - '0'][2];
                char seg2 = ' ', seg3 = ' ';
                if (print_left) seg2 = '|';
                if (print_right) seg3 = '|';
                cout << seg2;
                for (int i = 0; i < sz; i++) cout << " ";
                cout << seg3;
                if (k++ != num.size() - 1) cout << " ";
            }
            cout << endl;
        }
        // print middle
        k = 0;
        for (char c : num) {
            bool print_middle = map[int(c) - '0'][3];
            char seg4 = ' ';
            if (print_middle) seg4 = '-';
            cout << " ";
            for (int i = 0; i < sz; i++) cout << seg4;
            cout << " ";
            if (k++ != num.size() - 1) cout << " ";
        }
        cout << endl;
        // print side 2
        for (int i = 0; i < sz; i++) {
            k = 0;
            for (char c : num) {
                bool print_left = map[int(c) - '0'][4];
                bool print_right = map[int(c) - '0'][5];
                char seg5 = ' ', seg6 = ' ';
                if (print_left) seg5 = '|';
                if (print_right) seg6 = '|';
                cout << seg5;
                for (int i = 0; i < sz; i++) cout << " ";
                cout << seg6;
                if (k++ != num.size() - 1) cout << " ";
            }
            cout << endl;
        }
        // print bottom
        k = 0;
        for (char c : num) {
            bool print_bottom = map[int(c) - '0'][6];
            char seg7 = ' ';
            if (print_bottom) seg7 = '-';
            cout << " ";
            for (int i = 0; i < sz; i++) cout << seg7;
            cout << " ";
            if (k++ != num.size() - 1) cout << " ";
        }
        cout << endl << endl;
    }
}
