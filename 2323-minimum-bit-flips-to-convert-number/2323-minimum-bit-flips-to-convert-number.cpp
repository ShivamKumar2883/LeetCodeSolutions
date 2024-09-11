class Solution {
public:
    int minBitFlips(int start, int goal) {
        int count = 0;
        int num = start^goal;

        while(num){
            int x = num%2;
            if(x && 1) count++;
            num /= 2;
        }
        return count;
    }
};