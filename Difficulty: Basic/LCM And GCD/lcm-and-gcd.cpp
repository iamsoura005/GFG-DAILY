class Solution {
  public:
    vector<int> lcmAndGcd(int a, int b) {
        // code here
        int x =a;
        int y = b; //storing the number
        //euclid to find gcd
        while (b!=0) {  //repeat untill second number becomes 0
        int rem= a%b; //rem
        a=b; //move smaller to a 
        b= rem;
        
    }
    int gcd =a; 
    int lcm= (x*y) / gcd;
    return {lcm,gcd};
    }
};