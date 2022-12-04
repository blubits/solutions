#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<long long int> nums;
    set<long long int> sums;
    long long int num;
    char c;
    while (cin >> num) {
        nums.push_back(num);
        cin >> c;
    }
    for (long long int i = 0; i < (1 << (nums.size() - 1)); i++) {
        long long int sum = 0;
        string curr_num = to_string(nums[0]);
        for (int j = 0; j < nums.size(); j++) {
            if (i & (1 << j)) {
                curr_num += to_string(nums[j + 1]);
            }
            else {
                sum += stoll(curr_num);
                if (j != nums.size() - 1) curr_num = to_string(nums[j + 1]);
                else curr_num = "0";
            }
        }
        sum += stoll(curr_num);
        //cout << i << ": " << sum;
        sums.insert(sum);
    }
    cout << sums.size() << endl;
}