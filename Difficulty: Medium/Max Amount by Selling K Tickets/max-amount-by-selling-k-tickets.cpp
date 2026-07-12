class Solution {
public:
    int maxAmount(vector<int>& arr, int k) {
        long long MOD = 1e9 + 7;
        
        // Find the maximum value in arr to define the binary search range
        int low = 0, high = 0;
        for (int x : arr) {
            high = max(high, x);
        }
        
        int target_price = 0;
        
        // Binary search to find the minimum ticket price threshold
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            long long current_k = 0;
            for (int x : arr) {
                if (x >= mid) {
                    current_k += (x - mid + 1);
                }
            }
            
            if (current_k >= k) {
                target_price = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        long long total_earnings = 0;
        long long tickets_sold = 0;
        
        // Collect earnings for all tickets sold strictly above target_price
        for (int x : arr) {
            if (x > target_price) {
                long long count = x - target_price;
                tickets_sold += count;
                
                // Sum of arithmetic progression from (target_price + 1) to x
                long long sum = (count * (x + target_price + 1)) / 2;
                total_earnings = (total_earnings + sum) % MOD;
            }
        }
        
        // The remaining tickets needed are sold exactly at target_price
        long long remaining_tickets = k - tickets_sold;
        if (remaining_tickets > 0) {
            total_earnings = (total_earnings + (remaining_tickets * target_price) % MOD) % MOD;
        }
        
        return total_earnings;
    }
};