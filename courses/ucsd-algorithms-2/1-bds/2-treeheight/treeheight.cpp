#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct TreeNode {
    int node;
    std::vector<TreeNode*> children;
    TreeNode(int n) : node(n) {}
    TreeNode() : node(-1) {}
};

int height(TreeNode* root) {
    std::queue<std::pair<TreeNode*, int>> q;
    q.push(std::make_pair(root, 1));
    TreeNode* curr_node;
    int ht;
    while (!q.empty()) {
        auto k = q.front();
        curr_node = k.first;
        ht = k.second;
        q.pop();
        for (auto c : curr_node->children) {
            q.push(std::make_pair(c, ht + 1));
        }
    }
    return ht;
}

int main() {
    int n;
    std::cin >> n;
    TreeNode* nodes[n];
    TreeNode* root;
    for (int i = 0; i < n; i++) {
        nodes[i] = new TreeNode(i);
    }
    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;
        if (k == -1)
            root = nodes[i];
        else {
            (nodes[k]->children).push_back(nodes[i]);
        }
    }
    std::cout << height(root) << std::endl;
}