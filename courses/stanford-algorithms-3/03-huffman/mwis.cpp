#include <algorithm>
#include <bitset>
#include <fstream>
#include <iostream>
#include <vector>

int main() {
    std::ifstream infile;
    infile.open("mwis.txt");

    int N;
    infile >> N;
    std::vector<long long int> weights(N);
    for (int i = 0; i < N; i++) {
        infile >> weights[i];
    }

    // DP:
    // mwis[0] = 0, mwis[1] = weights[0]
    // mwis[i] = max(mwis[i - 1], mwis[i - 2] + weights[i - 1])
    std::vector<long long int> mwis(N + 100);
    mwis[0] = 0;
    mwis[1] = weights[0];
    for (int i = 2; i <= N; i++) {
        mwis[i] = std::max(mwis[i - 1], mwis[i - 2] + weights[i - 1]);
    }

    long long int i = N;
    std::bitset<1010> in_mwis;
    while (i > 0) {
        if (mwis[i] == mwis[i - 1]) {
            i -= 1;
        } else {
            in_mwis.set(i);
            i -= 2;
        }
    }
    std::cout << in_mwis.test(1) << in_mwis.test(2) << in_mwis.test(3)
              << in_mwis.test(4) << in_mwis.test(17) << in_mwis.test(117)
              << in_mwis.test(517) << in_mwis.test(997) << std::endl;
}