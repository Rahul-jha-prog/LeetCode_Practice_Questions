#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
    // Helper structure to maintain sliding window median and cost
    struct MedianFinder {
        multiset<long long> left, right;
        long long sum_left = 0, sum_right = 0;
        int max_left_size;

        MedianFinder(int k) {
            max_left_size = (k + 1) / 2;
        }

        void add(long long val) {
            if (left.empty() || val <= *left.rbegin()) {
                left.insert(val);
                sum_left += val;
            } else {
                right.insert(val);
                sum_right += val;
            }
            balance();
        }

        void remove(long long val) {
            auto it = left.find(val);
            if (it != left.end()) {
                sum_left -= val;
                left.erase(it);
            } else {
                it = right.find(val);
                sum_right -= val;
                right.erase(it);
            }
            balance();
        }

        void balance() {
            while (left.size() > max_left_size) {
                long long val = *left.rbegin();
                left.erase(prev(left.end()));
                sum_left -= val;
                right.insert(val);
                sum_right += val;
            }
            while (left.size() < max_left_size && !right.empty()) {
                long long val = *right.begin();
                right.erase(right.begin());
                sum_right -= val;
                left.insert(val);
                sum_left += val;
            }
        }

        long long getCost() {
            long long median = *left.rbegin();
            long long cost_left = (long long)left.size() * median - sum_left;
            long long cost_right = sum_right - (long long)right.size() * median;
            return cost_left + cost_right;
        }
    };

public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        if (k == 0) return 0;
        if (n < (long long)k * x) return -1; // Edge case: not enough elements

        // Step 1: Precompute the cost for every subarray of length x
        vector<long long> window_cost(n, 0);
        MedianFinder mf(x);

        for (int i = 0; i < n; ++i) {
            mf.add(nums[i]);
            if (i >= x) {
                mf.remove(nums[i - x]);
            }
            if (i >= x - 1) {
                window_cost[i] = mf.getCost();
            }
        }

        // Step 2: DP to find minimum cost for k non-overlapping intervals
        // dp[j][i]: min cost to pick j subarrays from the first i elements
        const long long INF = 1e18; // Large sentinel value
        vector<long long> dp(n + 1, 0);

        for (int j = 1; j <= k; ++j) {
            vector<long long> next_dp(n + 1, INF);
            for (int i = j * x; i <= n; ++i) {
                // Option 1: Do not take a subarray ending at i - 1
                next_dp[i] = next_dp[i - 1];
                // Option 2: Take a subarray of length x ending at i - 1
                if (dp[i - x] != INF) {
                    next_dp[i] = min(next_dp[i], dp[i - x] + window_cost[i - 1]);
                }
            }
            dp = move(next_dp);
        }

        return dp[n];
    }
};