class Solution {
public:
    int maxPathSum(vector<int>& a, vector<int>& b) {
        int m = a.size();
        int n = b.size();
        
        int i = 0, j = 0;
        int sum1 = 0, sum2 = 0;
        int result = 0;
        
        // Traverse both arrays simultaneously
        while (i < m && j < n) {
            // If element in array a is smaller, add to sum1 and move pointer i
            if (a[i] < b[j]) {
                sum1 += a[i++];
            } 
            // If element in array b is smaller, add to sum2 and move pointer j
            else if (a[i] > b[j]) {
                sum2 += b[j++];
            } 
            // If we found a common element
            else {
                // Add the maximum of the two sums + the common element to the result
                result += max(sum1, sum2) + a[i];
                
                // Reset sums for the next segment
                sum1 = 0;
                sum2 = 0;
                
                // Move both pointers
                i++;
                j++;
            }
        }
        
        // Add remaining elements of array a (if any)
        while (i < m) {
            sum1 += a[i++];
        }
        
        // Add remaining elements of array b (if any)
        while (j < n) {
            sum2 += b[j++];
        }
        
        // Add the maximum of the final sums
        result += max(sum1, sum2);
        
        return result;
    }
};