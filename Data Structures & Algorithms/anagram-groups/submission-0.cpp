#include <vector>
#include <unordered_map>

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups;

        for (string word : strs) {
            vector<int> count(26, 0);

            for (char c : word) {
                count[c - 'a']++;
            }

            string key;

            for(int i : count) {
                key += to_string(i) + '#';
            }

            groups[key].push_back(word);
        }

        vector<vector<string>> result;
        for (auto const& [key, val] : groups) {
            result.push_back(val);
        }
        return result;
    }

};