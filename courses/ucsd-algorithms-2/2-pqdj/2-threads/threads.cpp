#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct Process {
    long long int start;
    long long int end;
    int thread;

    Process(long long int start, long long int end, long long int thread)
        : start(start), end(end), thread(thread) {}
};

void printer(Process p) {
    std::cout << p.thread << ": [" << p.start << ", " << p.end << "]"
              << std::endl;
}

class process_comparator {
   public:
    // true if lhs is above rhs in the heap
    bool operator()(const Process& lhs, const Process& rhs) const {
        if (lhs.end == rhs.end) {
            return lhs.thread > rhs.thread;
        }
        return lhs.end > rhs.end;
    }
};

int main() {
    int cap, nthreads;
    std::cin >> cap >> nthreads;
    std::priority_queue<Process, std::vector<Process>, process_comparator>
        processor;
    std::vector<long long int> threads(nthreads);
    for (int i = 0; i < nthreads; i++) {
        std::cin >> threads[i];
    }

    // push in the initial threads
    int curr_process = 0, curr_thread = 0;
    while (curr_process < nthreads && processor.size() != cap) {
        if (threads[curr_process] == 0) {
            // If the current thread takes time 0 to complete, it finishes
            // immediately; never put it in the queue, to simulate immediate
            // pop in-pop out.
            std::cout << curr_thread << " 0" << std::endl;
            curr_process++;
            continue;
        }
        // Else, the thread takes some time to complete; queue it in, occupying
        // the smallest available free thread.
        processor.push(Process(0, threads[curr_process], curr_thread));
        std::cout << curr_thread << " 0" << std::endl;
        curr_thread++;
        curr_process++;
    }

    while (processor.size() > 0) {
        // Get a finished thread.
        // If multiple threads are done, take the one with the least thread
        // number first.
        long long int time = processor.top().end;
        int free_thread = processor.top().thread;
        processor.pop();
        // Process all the zero-length threads up until the next non-trivial
        // thread. They process immediately; if it were to be pushed in, they
        // would be popped out immediately anyway. This improves efficiency.
        while (curr_process < nthreads && threads[curr_process] == 0) {
            std::cout << free_thread << " " << time << std::endl;
            curr_process++;
        }
        // If there is still a thread to push, process it.
        if (curr_process < nthreads) {
            processor.push(
                Process(time, time + threads[curr_process], free_thread));
            std::cout << free_thread << " " << time << std::endl;
            curr_process++;
        }
    }
    return 0;
}
