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
    vector<vector<int>> imageSmoother(vector<vector<int>>& M) {

        int h = M.size();
        int w = M[0].size();

        // [#]
        if(w == 1 && h == 1) {
            return M;
        }

        vector<vector<int>> ans(h, vector<int>(w, 0));

        if(h == 1) {
            // [#][#]
            if(w == 2) {
                ans[0][0] = (M[0][0] + M[0][1]) / 2;
                ans[0][1] = (M[0][0] + M[0][1]) / 2;
                return ans;
            }
            // [#]...[#]
            else {
                ans[0][  0] = (M[0][  0] + M[0][  1]) / 2;
                ans[0][w-1] = (M[0][w-1] + M[0][w-2]) / 2;

                for(int x = 1; x < w-1; ++x) {
                    ans[0][x] = (M[0][x-1] + M[0][x] + M[0][x+1]) / 3;
                }

                return ans;
            }
        }
        else {
            // [#]
            //  .
            //  .
            // [#]
            if(w == 1) {
                ans[  0][0] = (M[  0][0] + M[  1][0]) / 2;
                ans[h-1][0] = (M[h-1][0] + M[h-2][0]) / 2;

                for(int y = 1; y < h-1; ++y) {
                    ans[y][0] = (M[y-1][0] + M[y][0] + M[y+1][0]) / 3;
                }

                return ans;
            }
            // [#]...[#]
            //  . ... .
            //  . ... .
            // [#]...[#]
            else {
                ans[  0][  0] = (M[  0][  0] + M[  0][  1] + M[  1][  0] + M[  1][  1]) / 4;
                ans[  0][w-1] = (M[  0][w-1] + M[  0][w-2] + M[  1][w-1] + M[  1][w-2]) / 4;
                ans[h-1][  0] = (M[h-1][  0] + M[h-1][  1] + M[h-2][  0] + M[h-2][  1]) / 4;
                ans[h-1][w-1] = (M[h-1][w-1] + M[h-1][w-2] + M[h-2][w-1] + M[h-2][w-2]) / 4;
            }
        }

        // [ ][#]...[#][ ]
        //  .  . ... .  .
        //  .  . ... .  .
        for(int x = 1; x < w-1; ++x) {
            ans[0][x] = (M[0][x-1] + M[0][x] + M[0][x+1] +
                         M[1][x-1] + M[1][x] + M[1][x+1]) / 6;
        }

        //  .  . ... .  .
        //  .  . ... .  .
        // [ ][#]...[#][ ]
        for(int x = 1; x < w-1; ++x) {
            ans[h-1][x] = (M[h-1][x-1] + M[h-1][x] + M[h-1][x+1] +
                           M[h-2][x-1] + M[h-2][x] + M[h-2][x+1]) / 6;
        }

        // [ ]...
        // [#]...
        //  . ...
        //  . ...
        // [#]...
        // [ ]...
        for(int y = 1; y < h-1; ++y) {
            ans[y][0] = (M[y-1][0] + M[y][0] + M[y+1][0] +
                         M[y-1][1] + M[y][1] + M[y+1][1]) / 6;
        }

        // ...[ ]
        // ...[#]
        // ... .
        // ... .
        // ...[#]
        // ...[ ]
        for(int y = 1; y < h-1; ++y) {
            ans[y][w-1] = (M[y-1][w-1] + M[y][w-1] + M[y+1][w-1] +
                           M[y-1][w-2] + M[y][w-2] + M[y+1][w-2]) / 6;
        }

        // [ ][ ]...[ ][ ]
        // [ ][#]...[#][ ]
        //  .  . ... .  .
        //  .  . ... .  .
        // [ ][#]...[#][ ]
        // [ ][ ]...[ ][ ]
        for(int y = 1; y < h-1; ++y) {
            auto y0 = M[y-1].data() + 1;
            auto y1 = M[y  ].data() + 1;
            auto y2 = M[y+1].data() + 1;

            for(int x = 1; x < w-1; ++x) {
                // Pointer arithmetic equivalent to:
                //
                // ans[y][x] = (M[y-1][x-1] + M[y-1][x] + M[y-1][x+1] +
                //              M[y  ][x-1] + M[y  ][x] + M[y  ][x+1] +
                //              M[y+1][x-1] + M[y+1][x] + M[y+1][x+1]) / 9;
                ans[y][x] = (*(--y0) + *(++y0) + *(++y0) +
                             *(--y1) + *(++y1) + *(++y1) +
                             *(--y2) + *(++y2) + *(++y2)) / 9;
            }
        }

        return ans;
    }
};
