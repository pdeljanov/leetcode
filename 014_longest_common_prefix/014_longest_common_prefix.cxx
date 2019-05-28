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
    string longestCommonPrefix(vector<string>& strs) {
        // If there are no strings, the prefix has to be empty.
        if(strs.size() == 0) {
            return "";
        }
        // If there is one string, the prefix is simply the first and only string.
        if(strs.size() == 1) {
            return strs[0];
        }
        // If there is more than one string...
        else {
            // Sort the strings in ascending order, such that the shortest strings come first 
            // and the longest strings are last, and a comes before z.
            sort(strs.begin(), strs.end());
    
            // Find the length of common prefix of the now sorted first and last strings.
            string::size_type i = 0;
            
            while(i < strs.front().size() && strs.front()[i] == strs.back()[i]) {
                ++i;
            }
            
            // Return the common prefix.
            return strs.front().substr(0, i);
        }
    }
};