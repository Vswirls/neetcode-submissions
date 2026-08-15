#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, int> word_count;

        for (char c : s) {
            word_count[c]++;
        }

        for (char c : t) {
            word_count[c]--;
        }

        for (auto pair : word_count) {
            if (pair.second != 0) {
                return false;
            }
        }

        return true;

    }
};
