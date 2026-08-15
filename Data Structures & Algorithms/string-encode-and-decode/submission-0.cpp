// When encoding into one long string, add seperator and number
// of chars in str
// Use number to iterate through string -> stop when you finish iterating
// through that number
// Seperator is used to split iterating number from the actual string
// -> Won't merge numbers from string with iterating number

#include <vector>
#include <string>

class Solution {
public:

    string encode(vector<string>& strs) {
        std::string output;

        for (const string& str : strs) {
            int count = str.size();

            output += std::to_string(count);
            output += '#';
            output += str;
        }

        return output;
    }

    vector<string> decode(string s) {
        std::vector<string> output;
        int i = 0;

        while(i < s.size()) {
            std::string holder_str;
            std::string scan_length;

            while(s[i] != '#') {
                scan_length.push_back(s[i]);
                i++;
            }

            i++; 

            for (int n = 0; n < std::stoi(scan_length); n++) {
                holder_str.push_back(s[i]);
                i++;
            }

            output.push_back(holder_str);
        }

        return output;

    }
};
