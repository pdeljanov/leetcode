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

    int numDecodings(string s) {
        if (s.empty()) {
            return 0;
        }

        if(s.length() == 1) {
            return ('0' == s[0] ? 0 : 1);
        }

        int prev[2] = {0, 0};

        prev[1] = s[0] != '0' ? 1 : 0;
        prev[0] = s[1] != '0' ? prev[1]: 0;

        for(int i = 2; i <= s.length(); i++) {
            int one = stoi(s.substr(i-1, 1));
            int two = stoi(s.substr(i-2, 2));

            // If the single digit number is not 0, the number of "branches" are remain
            // the same. Ohterwise, reset to match expected behaviour.
            int count = (one > 0 ? prev[0] : 0);

            // Only double digit numbers cause a "branch" in the decode. If there is a
            // branch, simply add all the previous possibilities prior to the double
            // digit number.
            if(two >= 10 && two <= 26) {
                count += prev[1];
            }

            // Shift window.
            prev[1] = prev[0];
            prev[0] = count;
        }

        return prev[0];
    }

};
