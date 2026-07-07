class Solution {
  public:
    vector<int> minAnd2ndMin(vector<int> &arr) {
        int n = arr.size();
        
        // If there are fewer than 2 elements, a second smallest cannot exist
        if (n < 2) {
            return {-1};
        }
        
        // Step 1: Sort the array
        sort(arr.begin(), arr.end());
        
        int smallest = arr[0];
        int secondSmallest = -1;
        
        // Step 2: Find the first element strictly greater than the smallest
        for (int i = 1; i < n; i++) {
            if (arr[i] > smallest) {
                secondSmallest = arr[i];
                break;
            }
        }
        
        // Step 3: If a valid second smallest was found, return the pair; otherwise return -1
        if (secondSmallest != -1) {
            return {smallest, secondSmallest};
        } else {
            return {-1};
        }
    }
};