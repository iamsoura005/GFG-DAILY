class Solution {
  public:
    string isAutomorphic(int n) {
        // code here
         long long square = 1LL * n * n;   // Find square

    string num = to_string(n);        // Convert number into string
    string sq = to_string(square);    // Convert square into string

    // Check whether square ends with original number
    if(sq.size() >= num.size() &&
       sq.substr(sq.size() - num.size()) == num)
    {
        return "Automorphic";
    }

    return "Not Automorphic";
        
    }
};