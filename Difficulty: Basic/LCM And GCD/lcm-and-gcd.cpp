class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int x =a;
        int y =b;
        //euclid algo GCD
        while(b!=0){ //repeat untill remainder
        int rem= a%b;
        a = b;
        b= rem;
            
        }
        int gcd = a;
        int lcm=(x*y) / gcd;
        return {lcm,gcd};
    }
};