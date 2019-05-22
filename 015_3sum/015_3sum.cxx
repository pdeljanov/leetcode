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

#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
    
    vector<vector<int>> threeSum(vector<int>& nums) {
     
        vector<vector<int>> result;
        
        // If there are less than 3 numbers then there can't be any triplets.
        if(nums.size() < 3) {
            return result;
        }
        
        // Sort the numbers in ascending order. O(N log N)
        sort(nums.begin(), nums.end(), less<int>());
        
        int n = nums.size();
        
        // For each unique (duplicates are skipped) number A, iterate through each unique 
        // number B, following A. These two numbers (A, B), form the first two numbers of 
        // the triplet. Since B is always after A, A should terminate iteration at index 
        // N - 2 (the second last number).
        for(int a = 0; a < n - 2;) {
            // For each new value of A, start the search for C at the end of the list.
            int c = n - 1;
            
            // Given A, for each number B, find a C, such that A + B + C = 0. To have 
            // unique triplets, C must not include B or any values previous to it.
            for(int b = a + 1; b < c;) {
            
                int sum = nums[a] + nums[b] + nums[c];

                // If A + B + C = 0, record the result, and advance to the next 
                // unique value of B.
                if(sum == 0) {
                    // Record the result with the triplet values in ascending order.
                    result.push_back({ nums[a], nums[b], nums[c] });
                    
                    // Advance the value of B to the next unique number. To have unique
                    // triplets, duplicates must be skipped.
                    for(++b; b < c && nums[b] == nums[b - 1]; ++b);
                }
                // If sum is less than zero, then increment b to advance B to a larger value. If 
                // the new value of B is the same as the previous, this condition will repeat or
                // the iteration will terminate.
                else if(sum < 0) {
                    ++b;
                }
                // If the sum is greater than zero, then decrement c to advance C to a smaller
                // value. If the new value of C is the same as the previous, this condition will
                // repeat or the iteration will terminate.
                else if(sum > 0) {
                    --c;
                }
            }
            
            // Advance the value of A to the next unique number. To have unique triplets, duplicates 
            /// must be skipped.
            for(++a; a < n && nums[a] == nums[a - 1]; ++a);
        }
        
        return result;
    }

};
