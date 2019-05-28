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
    inline int maxPerms(int p) {
        int perms = 1;
        while(p > 0) {
            perms *= p--;
        }
        return perms;
    }
    
    string getPermutation(int n, int k) {
        stringstream ss;
        
        // Fill a vector of integers with digits 1 through N.
        vector<int> nums;
        
        for(int i = 1; i <= n; ++i) {
            nums.push_back(i);
        }

        // K needs to be 0 indexed.
        k -= 1;
        
        // There are N digits, and therefore N placeholders/positions in the answer string.
        // For each placeholder, calculate the number of permutations, perms, in the lower 
        // positions. If the number of permutations is < K, then push the next smallest digit
        // in nums (index 0) onto the answer string. If the number of permutations is >= K, 
        // then find an integer multiple of perms that is <= K. Use that integer multiple to 
        // select the next digit from nums. Dividing K by perms yields the index in both cases.
        //
        // For example, if the multiple is 2, then choose the third smallest digit (index 2)
        // in nums. When a number if picked from nums, remove it.
        for(int p = n; p > 0; --p) {
            int perms = maxPerms(p - 1);
            int multiple = k / perms;
            k -= multiple * perms;
            ss << nums[multiple];
            nums.erase(nums.begin() + multiple); 
        }
        
        return ss.str();
    }
};