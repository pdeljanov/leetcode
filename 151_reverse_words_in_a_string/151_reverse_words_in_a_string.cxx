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
#include <algorithm>
#include <iostream>

using namespace std;

void reverseWords(string &s) {
    // Reverse string in-place.
    reverse(s.begin(), s.end());

    auto iter = s.begin();
    auto end = s.end();

    // Reverse individual words.
    while(iter != end) {
        // Find the start of the word.
        while(iter != end && *iter == ' ') iter++;
        auto wbegin = iter;

        // Find the end of the word.
        while(iter != end && *iter != ' ') iter++;

        // Reverse word in-place.
        reverse(wbegin, iter);
    }

    // Strip leading spaces.
    iter = s.begin();
    while(iter != end && *iter == ' ') iter++;
    iter = s.erase(s.begin(), iter);

    // Strip spaces between words.
    while(iter != s.end()) {
        // Current character is a space.
        if(*iter == ' ') {
            auto next = iter + 1;

            // If the next character does not exist or is a space, delete the current space.
            if(next == s.end() || *next == ' ') {
                iter = s.erase(iter, next);
            }
            // Otherwise the next character is not a space, continue.
            else {
                iter++;
            }
        }
        // Current character is not a space, continue.
        else {
            iter++;
        }
    }
}

int main() {
	string original = "   the  sky   is blue   ";
	string reversed(original);

	reverseWords(reversed);

	cout << "'" << reversed << "'" << endl;

	return 0;
}
