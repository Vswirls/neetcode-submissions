#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> seen_s;
        std::unordered_map<char, int> seen_t;

        for (char c : s) {
            seen_s[c]++;
        }

        for (char c : t) {
            seen_t[c]++;
        }

        if (seen_s == seen_t) {
            return true;
        } else {
            return false;
        }
    }
};
