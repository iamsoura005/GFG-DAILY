class Solution {
  public:
    int convertFive(int n) {
        // code here
        //special case
        if(n==0) 
            return 5;
        //convert to string
        string s = to_string(n);
        for(int i=0; i< s.length(); i++)
        {
            //replace 0 with 5
            if(s[i] == '0'){
                s[i]= '5';
            }
        }
        return stoi(s);
        
    }
};