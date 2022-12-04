#include <algorithm>
#include <deque>
#include <iostream>
#include <vector>

struct Request {
    int start;
    int length;
};

int main() {
    int buf, n;
    std::cin >> buf >> n;
    std::vector<Request> requests(n);
    for (int i = 0; i < n; i++) {
        std::cin >> requests[i].start >> requests[i].length;
    }
    std::deque<int> finish_times;
    for (int i = 0; i < n; i++) {
        // std::cout << "*curr-packet: " << requests[i].start << ","
        //           << requests[i].length << std::endl;
        // std::cout << "*finish-times: ";
        // for (auto i : finish_times) {
        //     std::cout << i << " ";
        // }
        // std::cout << std::endl;
        // let (t, l) be the current packet processed
        // (1) pop everything already proceesed by time t, advancing the current
        //      time as we process nodes
        while (!finish_times.empty() &&
               finish_times.front() <= requests[i].start) {
            finish_times.pop_front();
        }
        // (2) calculate the possible finish time of the current packet
        int possible_finish_time;
        if (!finish_times.empty()) {
            possible_finish_time = finish_times.back() + requests[i].length;
        } else {
            possible_finish_time = requests[i].start + requests[i].length;
        }
        // (2) push the current packet, checking if the buffer is full
        //      and rejecting the request if needed
        if (finish_times.size() >= buf) {
            // request dropped
            std::cout << -1 << std::endl;
        } else {
            finish_times.push_back(possible_finish_time);
            std::cout << possible_finish_time - requests[i].length << std::endl;
        }
    }
}
