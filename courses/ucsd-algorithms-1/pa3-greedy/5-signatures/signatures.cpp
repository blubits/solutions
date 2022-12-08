#include <algorithm>
#include <iostream>
#include <vector>

bool right_endpoint_comparator(std::pair<int, int> a, std::pair<int, int> b) {
    return a.second < b.second;
}

std::vector<int> min_points(int N, std::vector<std::pair<int, int>> intervals) {
    std::sort(intervals.begin(), intervals.end(), right_endpoint_comparator);
    int last_point = -1;
    std::vector<int> points;
    for (auto interval : intervals) {
        if (!(interval.first <= last_point && last_point <= interval.second)) {
            points.push_back(interval.second);
            last_point = interval.second;
        }
    }
    return points;
}

int main() {
    int N;
    std::cin >> N;
    std::vector<std::pair<int, int>> intervals(N);
    for (int i = 0; i < N; i++) {
        int a, b;
        std::cin >> a >> b;
        intervals[i] = std::make_pair(a, b);
    }
    std::vector<int> points = min_points(N, intervals);
    std::cout << points.size() << std::endl;
    for (int i : points) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return 0;
}
