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

#include <memory>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        // Trivial case.
        if(!head) { return; }

        // Traverse the 'head' list to find the middle node.
        auto* mid = head;

        for(auto* end = head; end->next && end->next->next; end = end->next->next) {
            mid = mid->next;
        }

        // Remove all nodes from the 'head' list AFTER the middle node (i.e., from mid->next onwards).
        // Push these nodes onto a new list in last-in first-out order so that they are reversed. After
        // this operation, the 'head' list is halved in length.
        auto stack = make_unique<ListNode>(0);
        stack->next = nullptr;

        while(mid->next) {
            auto next = mid->next->next;

            mid->next->next = stack->next;
            stack->next = mid->next;
            mid->next = next;
        }

        // Interlace the 'head' and 'stack' lists. The 'stack' list created from the unique elements will
        // always be less than or equal to the 'head' list in length. By using a dummy node above, the head
        // element for the stack will always exist.
        auto* iter = head;

        while(stack->next){
            auto top = stack->next->next;
            auto next = iter->next;

            iter->next = stack->next;
            iter->next->next = next;
            iter = next;

            stack->next = top;
        }

    }
};
