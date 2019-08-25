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

#include <algorithm>
#include <iterator>
#include <memory>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:

    TreeNode* descend(
        vector<int>::const_iterator in_begin,
        vector<int>::const_iterator in_end,
        vector<int>::const_iterator post_begin,
        vector<int>::const_iterator post_end
    )
    {
        // If the postorder slice has length of 0, then there are no more nodes.
        if(post_begin == post_end) {
            return nullptr;
        }

        // The value of this node is the last value of the postorder slice. The postorder slice is
        // represented as a half-closed range where the end is excluded. Therefore, the last value
        // in the postorder slice is end - 1.
        int pivot = *(--post_end);

        // Create a TreeNode and store it in a unique_ptr for now.
        unique_ptr<TreeNode> node = make_unique<TreeNode>(pivot);

        // Get an iterator to the pivot value by searching the inorder range.
        auto in_mid = find(in_begin, in_end, pivot);

        // Get the number of elements up-to and including the pivot value.
        auto dist = distance(in_begin, in_mid);

        // For the left child node, recurse. We slice inorder[begin..mid], and
        // postorder[begin..begin + dist]. Note the ranges are half-open whereby the end is excluded.
        // Therefore, the pivot value in inorder is excluded, and this node's value is excluded in
        // postorder.
        node->left = descend(in_begin, in_mid, post_begin, post_begin + dist);

        // Likewise, for the right child node, recurse. Slice inorder[begin..dist, end], and
        // postorder[begin + dist..end].
        node->right = descend(in_mid + 1, in_end, post_begin + dist, post_end);

        // Release ownership of the node from the unique_ptr and return it.
        return node.release();
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return descend(inorder.cbegin(), inorder.cend(), postorder.cbegin(), postorder.cend());
    }
};
