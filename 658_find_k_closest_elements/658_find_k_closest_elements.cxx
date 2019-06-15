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

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // Bound the binary search from 0 to N-k so that if the closest range starts
        // at the right bound, then there are k elements left. Otherwise a solution
        // would be impossible.
        size_t left = 0;
        size_t right = arr.size() - k;

        // Binary search for the closest range.
        while(left < right) {
            size_t mid = (left + right) / 2;

            // The closest range is ideally where there is equal distance between the
            // values of the start and end elements of the range, and x. Therefore, use
            // the distance between x and mid (the start of the range) vs. mid+k (the
            // end of the range) and x as the binary search criteria.
            //
            // Another way to think of it is if the difference between the start element
            // and x is greater than the difference between the end element and x, then
            // the range should be shifted right, and vice-versa.
            //
            // It may be tempting to take the absolute value here, but that is incorrect
            // since it is not guaranteed that the end element is greater than x. In that
            // case, you want to always move right. Vice-versa for when the element at
            // the start of the range is greater than x.
            if(x - arr[mid] > arr[mid + k] - x) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }

        // Copy the range into the result.
        return vector(arr.cbegin() + left, arr.cbegin() + left + k);
    }
};
