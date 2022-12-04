#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <functional>

int diff(std::pair<int, int> p) { return p.first - p.second; }

double ratio(std::pair<int, int> p) { 
    return double(p.first) / double(p.second); 
}

int main() {
    std::ifstream infile;
    infile.open("jobs.txt");

    int a;
    std::vector<std::pair<int, int>> jobs;
    while (infile >> a) {
        jobs.resize(a);
        for (int i = 0; i < a; i++) {
            infile >> jobs[i].first >> jobs[i].second;
        }
    }
    std::sort(jobs.begin(), jobs.end(), [](std::pair<int, int> left, std::pair<int, int> right) {
        if (ratio(left) == ratio(right)) {
            return left.first > right.first;
        }
        return ratio(left) > ratio(right);
    });
    long long int ct = 0, wsum = 0;
    for (auto p: jobs) {
        ct += p.second;
        wsum += (ct * p.first);
    }
    std::cout << wsum << std::endl;
}