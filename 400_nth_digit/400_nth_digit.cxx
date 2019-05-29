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

class Solution {
public:
    int findNthDigit(int n) {
        int mn = 1, mx = 10, digits = 1;

        // Attempt to subtract the total number of digits for all numbers in the
        // range [mn, mx] while n is large enough. Each iteration advances the
        // each bound by a factor of 10, and therefore increases the number of digits
        // for each number in the range by 1 each time.
        //
        // If digits is >= 9, then the total number of digits exceeds the maximum value
        // of n (a 32-bit signed integer) so it is not possible to have more than 9 digits.
        // Do not continue iteration past this point.
        while(digits < 9 && n > digits * (mx - mn)) {
            n -= digits * (mx - mn);
            mn *= 10;
            mx *= 10;
            digits += 1;
        }

        // Calculate the number of skipped numbers before n is too small to have enough
        // digits for a number in the [mn, mx] range.
        int n_skipped_nums = (n - 1) / digits;

        // Subtract the digits of all the skipped numbers.
        n -= digits * n_skipped_nums;

        // Calculate the next number. N is only big enough to index into
        // this number now.
        int num = mn + n_skipped_nums;

        // Return the n-th most sigificant digit.
        int r = digits - n;
        while(r-- > 0) num /= 10;
        return num % 10;
    }
};
