class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long left = 1, right = 1e18;
        long long ans = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long count = 0;
            
            int n = coins.size();
            for (int mask = 1; mask < (1 << n); mask++) {
                long long lcm_val = 1;
                int bits = 0;
                
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;
                        lcm_val = lcm(lcm_val, (long long)coins[i]);
                        if (lcm_val > mid) break;
                    }
                }
                
                if (lcm_val > mid) continue;
                
                if (bits % 2 == 1) {
                    count += mid / lcm_val;
                } else {
                    count -= mid / lcm_val;
                }
            }
            
            if (count >= k) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return ans;
    }
};