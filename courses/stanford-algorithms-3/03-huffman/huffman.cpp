#include <algorithm>
#include <fstream>
#include <iostream>
#include <queue>

struct Character {
    long long int wt;
    Character* left;
    Character* right;
};

std::pair<int, int> calculate_bitlengths(Character* root) {
    if (root->left == nullptr) {
        // std::cout << root->wt << " 0 0" << std::endl;
        return std::make_pair(0, 0);
    }
    auto lpair = calculate_bitlengths(root->left),
         rpair = calculate_bitlengths(root->right);
    // std::cout << root->wt << " " << 1 + std::min(lpair.first, rpair.first)
    //          << " " << 1 + std::max(lpair.second, rpair.second) << std::endl;
    return std::make_pair(1 + std::min(lpair.first, rpair.first),
                          1 + std::max(lpair.second, rpair.second));
}

std::pair<int, int> huffman(std::vector<long long int>& weights) {
    std::queue<Character*> leaves, merges;
    for (int w : weights) {
        Character* c = new Character;
        c->wt = w;
        c->left = c->right = nullptr;
        leaves.push(c);
    }
    while (leaves.size() + merges.size() > 1) {
        Character *first, *second;
        // Pop first and second smallest character
        if (merges.empty()) {
            first = leaves.front();
            leaves.pop();
            second = leaves.front();
            leaves.pop();
        } else if (leaves.empty()) {
            first = merges.front();
            merges.pop();
            second = merges.front();
            merges.pop();
        } else {
            if (leaves.front()->wt < merges.front()->wt) {
                first = leaves.front();
                leaves.pop();
                // std::cout << "a" << std::endl;
            } else {
                first = merges.front();
                merges.pop();
                // std::cout << "b" << std::endl;
            }
            if (merges.empty() ||
                (!leaves.empty() && leaves.front()->wt < merges.front()->wt)) {
                second = leaves.front();
                leaves.pop();
                // std::cout << "c" << std::endl;
            } else {
                second = merges.front();
                merges.pop();
                // std::cout << "d" << std::endl;
            }
        }
        // std::cout << first->wt << " " << second->wt << std::endl;
        // Merge
        Character* n = new Character;
        n->wt = first->wt + second->wt;
        n->left = first;
        n->right = second;
        // Pop into merges queue
        merges.push(n);
    }
    Character* hroot = merges.front();
    return calculate_bitlengths(hroot);
}

int main() {
    std::ifstream infile;
    infile.open("huffman.txt");

    int N;
    infile >> N;
    std::vector<long long int> weights(N);
    for (int i = 0; i < N; i++) {
        infile >> weights[i];
    }
    std::sort(weights.begin(), weights.end());
    auto ans = huffman(weights);
    std::cout << ans.second << " " << ans.first << std::endl;
    return 0;
}