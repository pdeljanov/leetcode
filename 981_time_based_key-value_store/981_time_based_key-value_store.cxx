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
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

class TimeMap {
private:
    using Entry = pair<int, string>;

    unordered_map<string, vector<Entry>> map_;

    static bool compare_entry(const Entry& lhs, const Entry& rhs) {
        return lhs.first > rhs.first;
    }

public:

    TimeMap() { }

    void set(string key, string value, int timestamp) {
        map_[key].emplace_back(make_pair(timestamp, value));
    }

    string get(string key, int timestamp) {
        auto iter = map_.find(key);

        if(iter != map_.end()) {
            // Use lower_bound to perform a binary search on the entry vector for the given key.
            //
            // Normally, lower_bound would return an iterator to the first entry where
            // timestamp_prev >= timestamp if and only if all entries are sorted in ascending order.
            //
            // However, the problems requires the first entry with timestamp_prev <= timestamp to be
            // returned. The logic can be reversed however. Since the entry vector is sorted in ascending
            // order, if we pass the reverse iterator to lower_bound, the entry vector will appear to
            // be in descending order. Then we use a compare function that checks timestamp < timestamp_prev.
            // Now instead of returning the first entry with a timestamp_prev >= timestamp, we return the
            // first entry where timestamp_prev <= timestamp.
            auto entry_iter = lower_bound(
                iter->second.rbegin(),
                iter->second.rend(),
                make_pair(timestamp, string{}),
                compare_entry);

            // If an entry was found, return it's value.
            if(entry_iter != iter->second.rend()) {
                return entry_iter->second;
            }
        }

        return "";
    }

};
