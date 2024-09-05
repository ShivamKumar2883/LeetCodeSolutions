class Solution {
public:
    bool isPalindrome(int x) {
        long long u=0,pali=0,n=x;
        if(x>=0)
        {
            while(x!=0)
            {
                u=x%10;
                pali= (pali*10)+u;
                x=x/10;
            }
            if(pali==n)
            return true;
            else 
            return false;
        }
        else
        {
            return false;
        }
    }
};