#include <fstream>
#include <functional>
#include <iostream>
#include <queue>

class MedianFinder {
   private:
    int size;
    std::priority_queue<int> leq_median;
    std::priority_queue<int, std::vector<int>, std::greater<int>> ge_median;

   public:
    MedianFinder();
    int get_median();
    void add(int a);
};

MedianFinder::MedianFinder() : size(0) {}

int MedianFinder::get_median() {
    if (size == 0) {
        return -1;
    } else {
        return leq_median.top();
    }
}

void MedianFinder::add(int a) {
    if (size++ == 0) {
        leq_median.push(a);
        return;
    } else {
        if (a < get_median()) {
            leq_median.push(a);
        } else {
            ge_median.push(a);
        }
        if (size % 2 == 0) {
            // even, check for imbalance (len(leq_median) > len(ge_median))
            if (leq_median.size() > ge_median.size()) {
                ge_median.push(leq_median.top());
                leq_median.pop();
            }
        } else {
            // odd, check for imbalance (len(leq_median) < len(ge_median))
            if (leq_median.size() < ge_median.size()) {
                leq_median.push(ge_median.top());
                ge_median.pop();
            }
        }
    }
}

int main() {
    std::ifstream infile;
    MedianFinder mf;
    int a, sum = 0;
    infile.open("Median.txt");
    while (infile >> a) {
        mf.add(a);
        sum = (sum + mf.get_median()) % 10000;
    }
    std::cout << sum << std::endl;
    return 0;
}
