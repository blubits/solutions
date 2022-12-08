#include <iostream>
#include <vector>

int min_refills(int total_dist, int max_drive, std::vector<int> stations) {
    stations.insert(stations.begin(), 0);
    stations.insert(stations.end(), total_dist);
    int num_refills = 0, curr_station = 0, last_station = 0;
    while (curr_station < stations.size()) {
        last_station = curr_station;
        while (curr_station < stations.size() &&
               stations[curr_station + 1] - stations[last_station] <=
                   max_drive) {
            curr_station++;
        }
        if (curr_station == last_station) return -1;
        if (curr_station < stations.size()) num_refills++;
    }
    return num_refills;
}

int main() {
    int total_dist, max_drive, n;
    std::cin >> total_dist >> max_drive >> n;
    std::vector<int> stations(n);
    for (int i = 0; i < n; i++) std::cin >> stations[i];
    std::cout << min_refills(total_dist, max_drive, stations) << std::endl;
    return 0;
}
