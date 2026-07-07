class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        int n = arr.size();
        
        // Step 1: Sort the array in descending order
        sort(arr.begin(), arr.end(), greater<int>());
        
        // Step 2: Find the first element that is different from the largest
        for (int i = 1; i < n; i++) {
            if (arr[i] != arr[0]) {
                return arr[i]; // Found the second largest
            }
        }
        
        // If no such element exists (e.g., [10, 10, 10])
        return -1;
    }
};