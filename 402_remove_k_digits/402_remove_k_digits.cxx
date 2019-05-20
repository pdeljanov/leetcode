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

#include <string>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {

        string ans;
        ans.push_back(num[0]);

        // Digits in the final answer should be increasing in value from the most
        // significant digit to the least significant digit. Treat the answer string,
        // ans, as a stack. If the next digit in num, num[i], is less-than the last digit
        // in ans, pop off the last digit in ans and repeat the check. Once num[i] is
        // greater-than the last digit in ans, push that digit onto ans and continue
        // moving forward.
        for(int i = 1; i < num.size(); ++i) {
            if(num[i] < ans.back() && k > 0) {
                ans.pop_back();
                --i;
                --k;
            }
            // Do not append leading zeros.
            else if(num[i] != '0' || ans.size() > 0) {
                ans.push_back(num[i]);
            }
        }

        // If we can still remove k digits, pop digits off since the next largest digit will
        // always be in the least significant digit (last) position.
        while(!ans.empty() && k-- > 0) {
            ans.pop_back();
        }

        // If there are no digits left append a '0'.
        if(ans.empty()) {
            ans.push_back('0');
        }

        return ans;
    }
};

