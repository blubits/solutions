#include <bits/stdc++.h>
using namespace std;

void postorder(string &preorder, string &inorder) {

    if (preorder.size() == 0 && inorder.size() == 0) {
        return;
    }

    if (preorder.size() == 1 && inorder.size() == 1) {
        cout << preorder;
        return;
    }
    
    char root = preorder[0];
    int root_inorder = inorder.find(root);

    string inorder_left = inorder.substr(0, root_inorder);
    string inorder_right = inorder.substr(root_inorder + 1, inorder.size() - root_inorder + 1);

    string preorder_left = preorder.substr(1, inorder_left.size());
    string preorder_right = preorder.substr(inorder_left.size() + 1, inorder_right.size());

    postorder(preorder_left, inorder_left);
    postorder(preorder_right, inorder_right);
    cout << root;
    return;
}

int main() {
    string preorder, inorder;
    while (cin >> preorder >> inorder) {
        postorder(preorder, inorder);
        cout << endl;
    }
}