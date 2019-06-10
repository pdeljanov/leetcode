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

#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;

        // The first level only contains the root node if it is not null.
        if(root) { q.push(root); }

        // The current depth.
        int depth = 0;

        // Perform a breadth-first search for the first leaf node. This outer loop iterates over
        // each level of the tree.
        while(!q.empty()) {
            depth++;

            // Check each node at the current level. If a leaf is found, return the current depth,
            // otherwise queue any children to be checked next.
            size_t n = q.size();

            for(size_t i = 0; i < n; ++i) {
                auto node = q.front();
                q.pop();

                // Leaf node.
                if(node->left == node->right) {
                    return depth;
                }

                if(node->left) {
                    q.push(node->left);
                }

                if(node->right) {
                    q.push(node->right);
                }
            }
        }

        return depth;
    }

};
