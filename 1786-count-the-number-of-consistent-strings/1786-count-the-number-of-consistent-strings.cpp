class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int consistentCount = 0;
        
        // Loop through each word in the array
        for (int i = 0; i < words.size(); i++) {
            string currentWord = words[i];
            bool isConsistent = true;

            // Check each character of the current word
            for (int j = 0; j < currentWord.size(); j++) {
                bool found = false;

                // Manually check if the current character exists in the allowed string
                for (int k = 0; k < allowed.size(); k++) {
                    if (currentWord[j] == allowed[k]) {
                        found = true;
                        break;  // No need to check further if it's found
                    }
                }

                // If the character is not found in allowed, mark the word as inconsistent
                if (!found) {
                    isConsistent = false;
                    break;
                }
            }

            // If the word is consistent, increment the count
            if (isConsistent) {
                consistentCount++;
            }
        }

        return consistentCount;
    }
};
