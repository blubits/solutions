#include <iostream>
#include <vector>

std::vector<int> max_sum(int N) {
    int i = 1;
    std::vector<int> nums;
    while (N >= (2 * i + 1)) {
        nums.push_back(i);
        N -= i;
        i++;
    }
    nums.push_back(N);
    return nums;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<int> nums = max_sum(N);
    std::cout << nums.size() << std::endl;
    for (int i : nums) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
