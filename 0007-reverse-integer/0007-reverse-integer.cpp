class Solution {
public:
    int reverse(int x) {
        int u,rev=0;
        while(x!=0)
        {
            u=x%10;

            // Check for overflow/underflow before updating `rev`
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && u > 7)) {
                return 0; // Overflow for positive numbers
            }
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && u < -8)) {
                return 0; // Underflow for negative numbers
            }
            
            rev=(rev*10)+u;
            x=x/10;
        }
        return rev;
    }
};