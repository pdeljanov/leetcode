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

#include <limits>
#include <vector>

using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // Largest will contain the three largest values in descending order.
        // Initially fill largest with with a sentinel value that will always
        // be less than the minimum of an int.
        array<long, 3> largest {
            numeric_limits<long>::min(),
            numeric_limits<long>::min(),
            numeric_limits<long>::min()
        };

        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];

            // If the current number is greater than an existing value in the
            // largest array, but is NOT a duplicate, insert it into the array
            // and shift off the last element.
            if(num > largest[0]) {
                largest[2] = largest[1];
                largest[1] = largest[0];
                largest[0] = num;
            }
            else if(num > largest[1] && num < largest[0]) {
                largest[2] = largest[1];
                largest[1] = num;
            }
            else if(num > largest[2] && num < largest[1]) {
                largest[2] = num;
            }
        }

        // Return the last element in the largest array (the third maximum), or if
        // that element contains the sentinel value, return the first element (the
        // maximum).
        return largest[2] > numeric_limits<long>::min() ? largest[2] : largest[0];
    }
};
