#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

class BST {
   private:
    std::vector<int> key, left, right, pre_order;
    int sz;

   public:
    BST(int i) : sz(0) {
        key.resize(i);
        left.resize(i);
        right.resize(i);
        pre_order.resize(i);
    }

    void insert(int k, int l, int r) {
        key[sz] = k;
        left[sz] = l;
        right[sz] = r;
        sz++;
    }

    bool is_bst() {
        preprocess_preorder();
        std::stack<int> nodes;
        int curr = 0;
        int prev_idx = -1, prev_item = -1, in_tree = 0;
        while (curr != -1 || !nodes.empty()) {
            // L
            while (curr != -1) {
                nodes.push(curr);
                curr = left[curr];
            }
            // C
            curr = nodes.top();
            if (in_tree) {
                if (prev_item > key[curr]) {
                    return false;
                }
                if (prev_item == key[curr] &&
                    pre_order[prev_idx] > pre_order[curr]) {
                    return false;
                }
            } else {
                in_tree = 1;
            }
            prev_idx = curr;
            prev_item = key[curr];
            nodes.pop();
            // R
            curr = right[curr];
        }
        return true;
    }

   private:
    void preprocess_preorder() {
        std::stack<int> nodes;
        int k = 0;
        nodes.push(0);
        while (!nodes.empty()) {
            int n = nodes.top();
            pre_order[n] = k++;
            // C
            nodes.pop();
            // R (second)
            if (right[n] != -1) nodes.push(right[n]);
            // L (first)
            if (left[n] != -1) nodes.push(left[n]);
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    BST tree(n);
    if (n == 0) {
        std::cout << "CORRECT" << std::endl;
        return 0;
    }
    while (n--) {
        int k, l, r;
        std::cin >> k >> l >> r;
        tree.insert(k, l, r);
    }
    if (!tree.is_bst()) {
        std::cout << "IN";
    }
    std::cout << "CORRECT" << std::endl;
    return 0;
}
