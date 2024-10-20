class Solution {
public:
    vector<string> stringSequence(string target) {

       vector<string> result;
    string screen = "";  // Start with an empty screen

    // Loop through each character of the target
    for (char c : target) {
        // Step 1: Always append 'a' using Key 1
        screen += 'a';  
        result.push_back(screen);  // Store the current screen state

        // Step 2: If the target character is after 'a', use Key 2 to change it
        while (screen.back() != c) {
            screen.back()++;  // Change the last character to the next in the alphabet
            result.push_back(screen);  // Store each step
        }
    }

    return result;
        
    }
};