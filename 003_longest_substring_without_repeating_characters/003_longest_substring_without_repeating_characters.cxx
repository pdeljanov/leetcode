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
#include <array>

using namespace std;

class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        int longest = 0;

        // Mapping of seen characters (the character value used as an index for the array)
        // to the index of that character in the string.
        array<int, 255> seen;

        // Fill the array with -1 to indicate no characters have been seen.
        fill(seen.begin(), seen.end(), -1);

        int substr_start = 0;
        int substr_len = 0;

        for(int i = 0; i < s.size(); ++i) {
            // Get the last seen index, and then update the current character's
            // last seen index to the current index.
            int last_seen_idx = seen[s[i]];
            seen[s[i]] = i;

            // Character was never seen before (last_seen_idx=-1) or it was seen
            // before the starting index of the current substr. Increment the substr
            // length.
            if(last_seen_idx < substr_start) {
                substr_len++;
            }
            // Character was seen before. A new substr must be defined starting at the
            // index after the original instance of the seen character, up to the current
            // character.
            else {
                // Update longest length.
                longest = max(substr_len, longest);

                substr_start = last_seen_idx + 1;
                substr_len = i - last_seen_idx;
            }
        }

        // Final update of longest substr length. This handles the case when there
        // are no repeated characters so longest is never updated.
        longest = max(substr_len, longest);

        return longest;
    }
};
