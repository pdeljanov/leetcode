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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    pair<TreeNode*, int> descend(TreeNode* node, int level) {
        // Node is null if the root is null, or the parent was a leaf node. If the parent was
        // a leaf node, then the deepest level is level-1. If the root was null, and therefore
        // level=0, then -1 is returned.
        if(nullptr == node) {
            return { nullptr, level - 1 };
        }

        // Recurse into the left and right sub-trees.
        auto left = descend(node->left, level + 1);
        auto right = descend(node->right, level + 1);

        // If the left and right sub-trees have nodes at the same depth, then node is the common
        // ancestor containing both of the deepest nodes.
        if(left.second == right.second) {
            return { node, left.second };
        }
        // If the left sub-tree is deeper than the right, then the deepest node is given by left.
        else if(left.second > right.second) {
            return left;
        }
        // Likewise, if the right sub-tree is deeper than the left, then the deepest node is given by
        // right.
        else {
            return right;
        }
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return descend(root, 0).first;
    }
};
