#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool comparator(vector<int> &l, vector<int> &r) {
    if (l[2] == r[2]) {
        int lv = l[0] * l[1] * l[2];
        int rv = r[0] * r[1] * r[2];
        return lv < rv;
    }
    return l[2] < r[2];
}

int main() {
    vector<vector<int>> boxes;
    int n;
    while (cin >> n && n != 0) {
        boxes.clear();
        while (n--) {
            vector<int> box(3);
            cin >> box[0] >> box[1] >> box[2];
            boxes.push_back(box);
        }
        sort(boxes.begin(), boxes.end(), comparator);
        cout << boxes[boxes.size() - 1][0] * boxes[boxes.size() - 1][1] * boxes[boxes.size() - 1][2] << endl;
    }
    return 0;
}