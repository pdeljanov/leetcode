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

    void fill_right(int iter, int &x, int &y, Matrix& matrix, int& i) {
        int len = matrix[y].size() - iter;
        for(++x; x < len; ++x) {
            matrix[y][x] = i++;
        }
        --x;
    }

    void fill_down(int iter, int &x, int &y, Matrix& matrix, int& i) {
        int len = matrix.size() - iter;
        for(++y; y < len; ++y) {
            matrix[y][x] = i++;
        }
        --y;
    }

    void fill_left(int iter, int &x, int &y, Matrix& matrix, int& i) {
        for(--x; x >= iter; --x) {
            matrix[y][x] = i++;
        }
        ++x;
    }

    void fill_up(int iter, int &x, int &y, Matrix& matrix, int& i) {
        for(--y; y > iter; --y) {
            matrix[y][x] = i++;
        }
        ++y;
    }

    vector<vector<int>> generateMatrix(int n) {
        if(n < 1) {
            return Matrix();
        }

        Matrix matrix(n, vector<int>(static_cast<size_t>(n), 0));

        int x = -1, y = 0, iter = 0, i = 1, oi = i;

        for(;; ++iter) {
            fill_right(iter, x, y, matrix, i);
            if(i == oi) break; else oi = i;
            fill_down(iter, x, y, matrix, i);
            if(i == oi) break; else oi = i;
            fill_left(iter, x, y, matrix, i);
            if(i == oi) break; else oi = i;
            fill_up(iter, x, y, matrix, i);
            if(i == oi) break; else oi = i;
        }

        return matrix;
    }
};
