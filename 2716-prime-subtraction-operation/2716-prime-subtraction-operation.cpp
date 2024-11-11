class Solution {
public:
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        //Step1)
        int element = INT_MIN;
        for(int i = 0; i < n; i++) element = max(element,nums[i]);

        //Step2)
        vector<int> prime(element,1);

        for(int i=2; i < element; i++){
            if(prime[i] == 1){
                for(int j = i+i; j < element; j += i){
                    prime[j] = 0;
                }
            }
        }

        //Step3)
        int i = n-2;
        int prev = nums[n-1];
        while(i >= 0){
            if(nums[i] >= prev){

                int flag = 0;
                for(int j = 2; j < nums[i]; j++){

                    if(prime[j] == 1){
                        if(nums[i] - j < prev){
                            nums[i] = nums[i] - j;
                            flag = 1;
                            break;
                        }
                    }
                }
                if(flag == 0) return false;
            }
            prev = nums[i];
            i--;
        }

        return true;
    }
};