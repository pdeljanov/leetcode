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

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {

        // Create dummy header that will automatically deallocate at the end of this function.
        unique_ptr<ListNode> list = make_unique<ListNode>(0);
        list->next = head;

        // Ptr is always one node previous to the next adjacent set. The dummy head node is used to remove
        // the initial edge case.
        auto ptr = list.get();

        while(ptr != nullptr && ptr->next != nullptr && ptr->next->next != nullptr) {
            auto p1 = ptr->next;
            auto p2 = p1->next;
            auto p3 = p2->next;

            ptr->next = p2;
            p2->next = p1;
            p1->next = p3;

            // The node pointed to by p1 is now actually the *ptr->next->next, or one node before the
            // next adjacent set.
            ptr = p1;
        }

        return list->next;
    }
};
