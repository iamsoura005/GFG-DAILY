class Solution {
  public:
    int sumOfAP(int n, int a, int d) {
        // Code here.
        //store final result
        int sum = 0;
        int current = a;
        //loop
        for(int i=1; i<=n; i++) {
            sum=sum+current;
            current=current+d;
        }
        return sum;
    }
};