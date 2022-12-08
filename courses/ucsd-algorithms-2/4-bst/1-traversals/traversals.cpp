#include <iostream>
#include <stack>
#include <vector>

class BST {
   private:
    std::vector<int> key, left, right;
    int sz;

   public:
    BST(int i) : sz(0) {
        key.resize(i);
        left.resize(i);
        right.resize(i);
    }

    void insert(int k, int l, int r) {
        key[sz] = k;
        left[sz] = l;
        right[sz] = r;
        sz++;
    }

    void preorder() {
        std::stack<int> nodes;
        nodes.push(0);
        while (!nodes.empty()) {
            int n = nodes.top();
            std::cout << n << " ";
            // C
            nodes.pop();
            // R (second)
            if (right[n] != -1) nodes.push(right[n]);
            // L (first)
            if (left[n] != -1) nodes.push(left[n]);
        }
        std::cout << std::endl;
    }

    void inorder() {
        std::stack<int> nodes;
        int curr = 0;
        while (curr != -1 || !nodes.empty()) {
            // L
            while (curr != -1) {
                nodes.push(curr);
                curr = left[curr];
            }
            // C
            curr = nodes.top();
            std::cout << curr << " ";
            nodes.pop();
            // R
            curr = right[curr];
        }
        std::cout << std::endl;
    }

    void postorder() {
        std::stack<int> nodes;
        int curr = 0, last = -1;
        while (curr != -1 || !nodes.empty()) {
            // L
            if (curr != -1) {
                nodes.push(curr);
                curr = left[curr];
            } else {
                int top = nodes.top();
                // check if we can traverse right && we just came from left
                if (right[top] != -1 && last != right[top]) {
                    // R
                    curr = right[top];
                } else {
                    // C
                    std::cout << top << " ";
                    last = top;
                    nodes.pop();
                }
            }
        }
        std::cout << std::endl;
    }
};

int main() {
    int n;
    std::cin >> n;
    BST tree(n);
    while (n--) {
        int k, l, r;
        std::cin >> k >> l >> r;
        tree.insert(k, l, r);
    }
    tree.inorder();
    tree.preorder();
    tree.postorder();
    return 0;
}
