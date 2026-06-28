class Solution {
  public:
    int countFactors(int n) {
        // code here
        int count =0 ; //initially 0
        //loop
        for (int i =1; i<=n; i++) {
            if(n%i == 0) {
                count++;
            }
        }
        return count;
        
    }
};