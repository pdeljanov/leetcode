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

    int numRescueBoats(vector<int>& people, int limit) {
        // Sort people from lightest to heaviest.
        sort(people.begin(), people.end());

        int boats = 0;
        int i = 0, j = people.size() - 1;

        // Skip past individuals who are heavier than the weight limit as efficiently as possible.
        while(i < j && people[j] >= limit) {
            ++boats;
            --j;
        }

        // Pair light and heavy individuals.
        while(i <= j) {
            ++boats;

            // If the next lightest and heaviest individuals have a combined weight that is at or below
            // the limit, then the light person can be boarded on the same boat as the heavy individual.
            // Advance to the next lightest invididual for the next iteration in this case.
            if(people[i] + people[j] <= limit) {
                ++i;
            }

            // The next heaviest person will always be placed on a boat, either by themselves or with
            // the light person determined above. Thus, always advance to the next heaviest individual
            // for the next iteration.
            --j;
        }

        return boats;
    }

};
