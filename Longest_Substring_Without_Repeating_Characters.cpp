class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
        unordered_map<char, int> chars;
        int max_length = 0;
        int left = 0; 
        for (int right = 0; right < n; right++) { 
            if (chars.find(s[right]) != chars.end()) {
                left = max(chars[s[right]] + 1, left);
            }
            chars[s[right]] = right;
            max_length = max(max_length, right - left + 1);
        }

        return max_length;
    }
};