// Copyright (c) 2018-2019 Philip Deljanov
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include <pair>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    bool isSymmetric(TreeNode* left, TreeNode* right) {
        // Both left and right nodes are null, this is symmetric.
        if(!left && !right) {
            return true;
        }

        // If left XOR right is null, or left and right both exist but have
        // different values, then the tree is not symmetric.
        if(!left || !right || left->val != right->val) {
            return false;
        }

        return isSymmetric(left->left, right->right) &&
               isSymmetric(left->right, right->left);
    }

    // Method 1: Recursive
    bool isSymmetric(TreeNode* root) {
        if(!root || root->left == root->right) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }

    // Method 2: Iterative
    bool isSymmetric2(TreeNode* root) {
        if(!root || root->left == root->right) {
            return true;
        }

        vector<pair<TreeNode*, TreeNode*>> stack { make_pair(root->left, root->right) };

        while(!stack.empty()) {
            auto node = stack.back();
            stack.pop_back();

            if(!node.first && !node.second) {
                continue;
            }

            if(!node.first || !node.second || node.first->val != node.second->val) {
                return false;
            }

            stack.emplace_back(make_pair(node.first->left, node.second->right));
            stack.emplace_back(make_pair(node.first->right, node.second->left));
        }

        return true;
    }

};
