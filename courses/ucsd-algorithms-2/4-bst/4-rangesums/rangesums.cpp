#include <algorithm>
#include <iostream>

using namespace std;

struct SplayNode {
    long long int sum;
    long long int key;

    SplayNode* parent;
    SplayNode* left;
    SplayNode* right;

    SplayNode(int n)
        : sum(n), key(n), parent(nullptr), left(nullptr), right(nullptr) {}
};

class SplayTree {
    SplayNode* root;

   public:
    SplayTree() {}

    void insert(int k) {}

    bool find() {}

    void remove(int k) {}

    long long int range_sum(int lo, int hi) {}

   private:
    void splay(SplayNode* s) {}

    std::pair<SplayNode*, SplayNode*> split(SplayNode* root, int key) {}
};

int main() { return 0; }
