class Solution {
  private:
    long long countLessEqual(const vector<int>& arr, long long target) {
        long long count = 0;
        long long sum = 0;
        int left = 0;

        for (int right = 0; right < arr.size(); right++) {
            sum += arr[right];
            while (left <= right && sum > target) {
                sum -= arr[left];
                left++;
            }
            count += (right - left + 1);
        }

        return count;
    }

  public:
    long long countSubarray(vector<int>& arr, int l, int r) {
        return countLessEqual(arr, r) - countLessEqual(arr, l - 1);
    }
};