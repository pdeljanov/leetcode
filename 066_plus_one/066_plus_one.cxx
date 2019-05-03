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
    vector<int> plusOne(vector<int>& digits) {
        // The carry value is set to 1 initially to add 1 to the least significant digit.
        int carry = 1;

        // From the end of the list (least significant digit), to the front (most significant
        // digit), add the carry value to the digit. Then then get the new digit value by mod 10,
        // and the new carry value by div 10.
        for(auto digit = digits.rbegin(); digit != digits.rend(); ++digit) {
            *digit += carry;
            carry = *digit / 10;
            if(*digit > 9) {
                *digit = *digit % 10;
            }
        }

        // If there is a remaining carry value, append it to the front of the vector.
        if(carry > 0) {
            digits.insert(digits.begin(), carry);
        }

        return digits;
    }
};
