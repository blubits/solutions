#include <iostream>
#include <vector>
using namespace std;

int main() {
    int t, c = 1;
    while (cin >> t) {
        vector<int> left;
        int i = 1;
        while (t - i >= 0) {
            left.push_back(i);
            t -= i++;
        }
        left[left.size() - 1] += t;
        int lspace = 2 * left.size() - 2, ldots = 0;
        int rdots = 0;
        cout << "Tower #" << c++ << endl;
        for (int a = 0; a < left.size(); a++) {
            int lsz = left[a];

            // LEFT TOP
            for (int _ = 0; _ < lspace; _++) cout << " ";
            cout << "#**";
            for (int _ = 0; _ < ldots; _++) cout << ".";

            // RIGHT TOP
            for (int _ = 0; _ < rdots; _++) cout << ".";
            if (lspace != 0)
                cout << "**";
            else
                cout << "..";
            cout << "#";

            cout << endl;

            for (int _ = 0; _ < lsz - 1; _++) {
                // LEFT MID
                for (int _ = 0; _ < lspace; _++) cout << " ";
                cout << "#";
                for (int _ = 0; _ < ldots + 2; _++) cout << ".";

                // RIGHT MID
                for (int _ = 0; _ < rdots + 2; _++) cout << ".";
                cout << "#";
                cout << endl;
            }
            lspace -= 2;
            ldots += 2;
            if (lspace != 0) rdots += 2;
        }
        cout << endl;
    }
}
