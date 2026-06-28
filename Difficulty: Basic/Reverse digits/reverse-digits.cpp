class Solution {
  public:
    int reverseDigits(int n) {
        // Code here
        //store here the rev no
        int reverse = 0;
        while(n>0) {
            int digit = n%10; //extract last digit
            reverse = reverse * 10 + digit; //add the digit to rev
            n = n/10;
            
        }
        return reverse;
    }
    
    
};