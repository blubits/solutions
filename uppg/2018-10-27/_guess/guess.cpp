#include <algorithm>
#include <cstdio>
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int t;
    while (scanf("%d", &t) != EOF) {
        int command, item;
        bool is_stack = true, is_queue = true, is_pq = true;
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;
        while (t--) {
            scanf("%d %d", &command, &item);
            if (command == 1) {
                s.push(item);
                q.push(item);
                pq.push(item);
            } else {
                if (s.size() == 0) {
                    is_stack = false;
                    is_queue = false;
                    is_pq = false;
                    continue;
                }
                int sp = s.top();
                s.pop();
                int qp = q.front();
                q.pop();
                int pqp = pq.top();
                pq.pop();
                if (sp != item) is_stack = false;
                if (qp != item) is_queue = false;
                if (pqp != item) is_pq = false;
            }
        }
        if ((is_stack && is_queue) || (is_queue && is_pq) ||
            (is_stack && is_pq)) {
            cout << "not sure" << endl;
        } else if (!is_stack && !is_queue && !is_pq) {
            cout << "impossible" << endl;
        } else if (is_stack) {
            cout << "stack" << endl;
        } else if (is_queue) {
            cout << "queue" << endl;
        } else if (is_pq) {
            cout << "priority queue" << endl;
        }
    }
}
