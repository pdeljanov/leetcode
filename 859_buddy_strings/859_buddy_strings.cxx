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
    bool buddyStrings(string A, string B) {

        if(A.size() != B.size()) {
            return false;
        }

        int seen[26] = { 0 };
        int pos[2] = { 0 };

        int mismatches = 0;

        // Loop through both strings at the same time and find mismatched characters. Also do a
        // tally of each character in the string.
        for(int i = 0; i < A.size(); ++i) {
            // Tally the characters. The tally is only used when both strings are equal so we can
            // just tally from A.
            seen[A[i] - 97]++;

            // Check if the characters are mismatched.
            if(A[i] != B[i]) {
                // If there were less than 2 mismatches previosuly, record the position
                // of the new mismatch.
                if(mismatches < 2) {
                    pos[mismatches++] = i;
                }
                // If there were 2 or more mismatches previously, this will be atleast the 3rd,
                // and therefore the strings are impossible to fix with only a single swap.
                else {
                    return false;
                }
            }
        }

        // If there are two mismatched characters, there is a possibility they can be swapped.
        if(mismatches == 2) {
            // See if the two mismatched characters can be swapped.
            return (A[pos[0]] == B[pos[1]]) && (A[pos[1]] == B[pos[0]]);
        }
        // If there are no mismatched characters, the strings are identical. Therefore, we can only
        // "swap" two characters in A if they're the same character. Check if we've seen any character
        // twice in A.
        else if(mismatches == 0) {
            for(int i = 0; i < 26; ++i) {
                if(seen[i] > 1) {
                    return true;
                }
            }
        }

        return false;
    }
};
