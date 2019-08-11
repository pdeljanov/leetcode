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

#include <stack>
#include <string>
#include <vector>

class Solution {
public:
    bool isValid(string s) {

        stack<char> brackets;

        for(auto b : s) {
            // If the current character is an opening bracket, push it
            // onto the stack of opening brackets.
            if(b == '(' || b == '[' || b == '{') {
                brackets.push(b);
            }
            // Otherwise, the character is a closing bracket. A closing
            // bracket must match with an opening bracket, therefore
            // the opening bracket stack should have atleast 1 bracket
            // pushed onto it.
            else if(brackets.size() > 0) {
                char t = brackets.top();

                // The top of the bracket stack must have an appropriate opening
                // bracket for the closing bracket. If it does, pop it off the
                // stack.
                if(
                    (b == ')' && t == '(') ||
                    (b == '}' && t == '{') ||
                    (b == ']' && t == '['))
                {
                    brackets.pop();
                }
                // The top of the opening bracket stack does not match appropriately
                // with the closing bracket. The string is invalid.
                else {
                    return false;
                }
            }
            // Otherwise, there is no matching opening bracket, and the string
            // is invalid.
            else {
                return false;
            }
        }

        // The string is only valid if the bracket stack has been emptied (all opening
        // brackets have been closed with a closing bracket).
        return brackets.empty();
    }
};
