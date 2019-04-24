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

#include <set>
#include <string>

using namespace std;

class Solution {
public:

    string simplify_email(const string& email) {
        string unique;
        unique.reserve(email.size());

        auto iter = email.cbegin();

        while(iter != email.cend()) {
            if(*iter == '@') {
                break;
            }
            else if(*iter == '+') {
                break;
            }
            else if(*iter != '.') {
                unique.push_back(*iter);
            }
            ++iter;
        }

        while(iter != email.cend()) {
            if(*iter == '@') {
                break;
            }
            ++iter;
        }

        while(iter != email.cend()) {
            unique.push_back(*iter);
            ++iter;
        }

        return unique;
    }

    int numUniqueEmails(vector<string>& emails) {
        set<string> unique;

        for(auto email : emails) {
            string unique_email = simplify_email(email);

            if(unique.find(unique_email) == unique.end()) {
                unique.insert(unique_email);
            }
        }

        return unique.size();
    }

};
