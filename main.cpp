#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


#include "../utils/VectorUtils.hpp"
#include "../utils/PrintUtils.hpp"

// https://leetcode.com/problems/find-pivot-index/

// #include "../utils/HeapUtils.hpp"
// #include "../utils/BinarySearch.hpp"
// #include "../utils/TreeUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto __ __attribute__((unused)) = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();


class Solution {
public:

    int pivotIndex(vector<int> &nums) {
        int sum = 0;
        for (auto i : nums) sum += i;
        int leftsum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (leftsum == sum - leftsum - nums[i])
                return i;
            leftsum += nums[i];
        }
        return -1;
    }

    // works for positive numbers only
    int pivotIndexPositive(vector<int> &nums) {
        if (nums.size() < 3) return -1;
        int lefti = 0;
        int righti = nums.size() - 1;
        int leftsum = nums[lefti];
        int rightsum = nums[righti];
        while (righti - lefti > 2) {
            if (leftsum < rightsum) {
                leftsum += nums[++lefti];
            } else {
                rightsum += nums[--righti];
            }
        }
        if (leftsum == rightsum)
            return lefti + 1;
        return -1;
    }
};

void test1() {
    vector<int> v1{1, 7, 3, 6, 5, 6};

    cout << "3 ? " << Solution().pivotIndex(v1) << endl;

    vector<int> v2{1, 2, 3};

    cout << "-1 ? " << Solution().pivotIndex(v2) << endl;

    // [-1,-1,-1,-1,-1,0]
    vector<int> v3{-1, -1, -1, -1, -1, 0};

    cout << "-1 ? " << Solution().pivotIndex(v2) << endl;
}

void test2() {

}

void test3() {

}