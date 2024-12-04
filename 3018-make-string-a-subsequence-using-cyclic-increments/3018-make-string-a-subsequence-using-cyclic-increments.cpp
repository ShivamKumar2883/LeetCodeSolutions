class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        int i = 0, j = 0;
        
        for(i = 0, j = 0; i<str1.size() && j<str2.size();){
            char ch = (str1[i] == 'z') ? 'a' : str1[i]+1;
            
            if(str1[i] == str2[j] || ch == str2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        
        return j == str2.size();
    }
};