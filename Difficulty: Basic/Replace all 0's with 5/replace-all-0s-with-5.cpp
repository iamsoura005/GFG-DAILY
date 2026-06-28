class Solution {
  public:
    int convertFive(int n) {
        // code here
        //special case
        if(n == 0) 
            return 5;
        int newNum=0;
        //build reversed modified no
        while(n>0) {
            int digit= n%10; //extract last digit
            if(digit == 0) 
            digit =5;
            newNum= newNum*10 + digit;
            n=n/10;
        }
        //reverse again
        int answer = 0;
        while(newNum > 0) {
            int digit = newNum %10;
            answer = answer *10 +digit;
            newNum = newNum /10;
        }
        return answer;
    }
};