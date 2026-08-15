#include <iostream>
#include <string>
using namespace std;

//string
//two pointer


class Solution {
public:
    bool isPalindrome(string s) {
        int left = s.size() - 1;
        int right = 0;

        while (left > right) {
            while (left > right && !isalnum(s[left])) {
                left--;
            }
            while (left > right && !isalnum(s[right])) {
                right++;
            }
            if (tolower(s[right]) != tolower(s[left])) {
                return false;
            }

            left--;
            right++;
        }

        return true;
    }
};
