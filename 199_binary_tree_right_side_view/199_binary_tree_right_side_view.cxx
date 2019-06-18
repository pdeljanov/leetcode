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

    // Method 1: Breadth-first traversal
    vector<int> rightSideViewBFS(TreeNode* root) {
        vector<int> ans;

        vector<TreeNode*> visit;
        vector<TreeNode*> next;

        if(root) {
            visit.emplace_back(root);
        }

        while(!visit.empty()) {
            ans.emplace_back(visit.back()->val);

            for(auto node : visit) {
                if(node->left) {
                    next.emplace_back(node->left);
                }
                if(node->right) {
                    next.emplace_back(node->right);
                }
            }

            visit.clear();
            next.swap(visit);
        }

        return ans;
    }

    void descend(vector<int>& ans, TreeNode* node, size_t level) {
        if(!node) {
            return;
        }

        if(ans.size() <= level) {
            ans.emplace_back(node->val);
        }
        else {
            ans[level] = node->val;
        }

        // Pre-order traversal
        descend(ans, node->left, level + 1);
        descend(ans, node->right, level + 1);
    }

    // Method 2: Depth-first traversal
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        descend(ans, root, 0);
        return ans;
    }

};
