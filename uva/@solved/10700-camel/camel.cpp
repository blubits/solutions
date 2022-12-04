#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string expr;
        getline(cin, expr);
        stringstream e(expr);

        vector<int> nums;
        vector<char> ops;
        int num;
        char op;
        e >> num;
        nums.push_back(num);
        while (e >> op >> num) {
            nums.push_back(num);
            ops.push_back(op);
        }

        vector<long long int> to_add;
        long long int curr_mult = nums[0];
        vector<long long int> to_mult;
        long long int curr_add = nums[0];
        for (int i = 0; i < ops.size(); i++) {
            if (ops[i] == '+') {
                curr_add += nums[i + 1];
                to_add.push_back(curr_mult);
                curr_mult = nums[i + 1];
            } else {
                curr_mult *= nums[i + 1];
                to_mult.push_back(curr_add);
                curr_add = nums[i + 1];
            }
        }

        to_add.push_back(curr_mult);
        to_mult.push_back(curr_add);

        long long int mn = 0;
        for (auto c : to_add) {
            mn += c;
        }

        long long int mx = 1;
        for (auto c : to_mult) {
            mx *= c;
        }

        cout << "The maximum and minimum are " << mx << " and " << mn << "."
             << endl;
    }
}
