#include <fstream>
#include <iostream>
#include <unordered_map>

int main() {
    std::unordered_map<long long int, int> numbers;
    std::ifstream infile;
    long long int a;
    infile.open("2sum.txt");
    while (infile >> a) {
        if (numbers.count(a) == 0) {
            numbers[a] = 1;
        } else {
            numbers[a] += 1;
        }
    }
    int count = 0;
    for (int i = -10000; i <= 10000; i++) {
        for (auto p : numbers) {
            auto first = p.first;
            auto second = i - p.first;
            auto second_count = 0;
            if (numbers.count(second) != 0) second_count = numbers[second];
            if ((first != second && second_count > 0) ||
                (first == second && second_count == 2)) {
                std::cout << first << " + " << second << " = " << i
                          << std::endl;
                count++;
                break;
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
