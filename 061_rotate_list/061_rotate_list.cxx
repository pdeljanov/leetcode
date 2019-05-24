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
    ListNode* rotateRight(ListNode* head, int k) {

        // Trivial cases, simply return the head if there are 0 or 1 elements.
        if(head == nullptr || head->next == nullptr) {
            return head;
        }

        // Use a dummy head node to remove edge-cases during traversals and list
        // modifications.
        unique_ptr<ListNode> dummy = make_unique<ListNode>(0);
        dummy->next = head;

        // Find the length of the list and the last node. Time complexity = O(N).
        size_t len = 0;

        ListNode* end = dummy.get();

        while(end->next != nullptr) {
            end = end->next;
            ++len;
        }

        // Find the split-point in the list. The split-point is the node where next points
        // to the node that should be the new head. All nodes preceeding split->next (head
        // to split inclusive) should be appended to end->next. Finally split->next is the
        // new end and should be null. Time complexity = O(N).
        ListNode* split = dummy.get();

        size_t i = len - (k % len);

        while(i-- > 0) {
            split = split->next;
        }

        // Perform the swap described above.
        end->next = dummy->next;
        dummy->next = split->next;
        split->next = nullptr;

        return dummy->next;
    }
};
