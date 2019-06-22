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
    int removeDuplicates(vector<int>& nums) {
        size_t i = 0, j = i + 1;

        for(; j < nums.size(); ++j) {
            // The number indexed by the lagging index, i, is the same value as the number
            // indexed by the leading index, j. Therefore the j-th number is a equal to (and
            // duplicate of) the i-th number so increment the leading index.
            if(nums[i] == nums[j]) {
                continue;
            }

            // Since the array is sorted, every number after the i-th, lagging, index will either
            // be greater than or equal to the i-th number. Since the equals/duplicate case was
            // handled earlier that means the j-th number is larger than the i-th number. So we must
            // therefore copy the j-th number after the i-th number.
            nums[++i] = nums[j];
        }

        return nums.size() - (j - i - 1);
    }
};
