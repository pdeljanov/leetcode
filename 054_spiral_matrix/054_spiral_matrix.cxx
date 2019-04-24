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

    using Matrix = vector<vector<int>>;

    void move_right(int iter, int &x, int &y, Matrix& matrix, vector<int>& out) {
        int len = matrix[y].size() - iter;
        for(++x; x < len; ++x) {
            out.push_back(matrix[y][x]);
        }
        --x;
    }

    void move_down(int iter, int &x, int &y, Matrix& matrix, vector<int>& out) {
        int len = matrix.size() - iter;
        for(++y; y < len; ++y) {
            out.push_back(matrix[y][x]);
        }
        --y;
    }

    void move_left(int iter, int &x, int &y, Matrix& matrix, vector<int>& out) {
        for(--x; x >= iter; --x) {
            out.push_back(matrix[y][x]);
        }
        ++x;
    }

    void move_up(int iter, int &x, int &y, Matrix& matrix, vector<int>& out) {
        for(--y; y > iter; --y) {
            out.push_back(matrix[y][x]);
        }
        ++y;
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> out;
        int x = -1, y = 0, ox = x, oy = y, iter = 0;

        if ((matrix.size() == 0) || (matrix[0].size() == 0)) {
            return out;
        }

        for(;; ++iter)
        {
            move_right(iter, x, y, matrix, out);
            if(x == ox) break; else ox = x;
            move_down(iter, x, y, matrix, out);
            if(y == oy) break; else oy = y;
            move_left(iter, x, y, matrix, out);
            if(x == ox) break; else ox = x;
            move_up(iter, x, y, matrix, out);
            if(y == oy) break; else oy = y;
        }

        return out;
    }
};
