class Solution {
  public:
    bool isStrong(int n) {
        // code here.
        int original = n; //storing original
        int sum = 0;
        while(n>0) {
            int digit = n%10;
            int fact =1; //starts from 1 not 0
            for(int i=1; i<=digit; i++) {
                fact= fact * i; // 5!= 1 x 2 x 3 4 x 5 
            }
            sum = sum+ fact;
            n= n/10; //remove last digit
        }
        return (sum== original);
    }
};
