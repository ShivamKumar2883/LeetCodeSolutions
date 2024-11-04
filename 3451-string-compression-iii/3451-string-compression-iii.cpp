class Solution {
public:
    string compressedString(string word) {
        int count = 1;  // Start counting the first character
        string Output = "";
        
        for (int i = 1; i <= word.length(); i++) {
            // Condition to check if the character changes or the count reaches 9
            if (i == word.length() || word[i] != word[i - 1] || count == 9) {
                Output += to_string(count) + word[i - 1];  // Append count and character
                count = 1;  // Reset count for the new character
            } else {
                count++;  // Increment count for consecutive characters
            }
        }
        
        return Output;
    }
};
