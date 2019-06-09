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

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    
    // Branch will return the longest continuous count of edges where each node connected
    // by those edges have the same value as node. In other words, branch returns the number
    // nodes with the same value as node minus one.
    int branch(TreeNode* node, int* longest) {
        // Node doesn't exist, return an invalid edge count.
        if(node == nullptr) {
            return -1;
        }
        
        int l = branch(node->left, longest);
        int r = branch(node->right, longest);
        
        // The parent, left child, and right child nodes all have the same value.
        // A path exists as a bridge between the two children and through the parent,
        // as well as from the parent to the longest child. However, the longest path
        // will always be the bridged path.
        if(node->left  && node->left->val  == node->val &&
           node->right && node->right->val == node->val) 
        {
            *longest = max(*longest, l + r + 2);
            return max(l, r) + 1;
        }
        // The parent and left child have the same value, increment the edges in this path.
        else if(node->left && node->left->val == node->val) {
            *longest = max(*longest, l + 1);
            return l + 1;
        }
        // The parent and right child have the same value, increment the edges in this path.
        else if(node->right && node->right->val == node->val) {
            *longest = max(*longest, r + 1);
            return r + 1;
        }
        
        // The parent node does not have the same value as any children, or the children
        // don't exist. Therefore no path between parent and child exists. Start a new path
        // at the parent.
        return 0;
    }
    
    int longestUnivaluePath(TreeNode* root) {
        // Improvement: Make `longest` a class variable to reduce stack size.
        int longest = 0;
        branch(root, &longest);
        return longest;
    }
};