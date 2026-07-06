class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        if(n == 0)                           // 0th Fibonacci number
        return 0;

    if(n == 1)                           // 1st Fibonacci number
        return 1;

    int a = 0;                           // First Fibonacci number
    int b = 1;                           // Second Fibonacci number
    int next;                            // Store next Fibonacci number

    for(int i = 2; i <= n; i++)          // Generate Fibonacci numbers
    {
        next = a + b;                    // Current Fibonacci number

        a = b;                           // Move first pointer
        b = next;                        // Move second pointer
    }

    return b;
    }
};