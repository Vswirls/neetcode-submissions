// Valid string s and they need to be closed properly
// Stack is last in first out
// Therefore, keep adding opening brackets onto the stack until you reach a closing bracket
// Once a closing bracket is reached, if it matches, pop the top of the stack and keep checking

// How do I match these?

#include <stack>
#include <string>
#include <unordered_map>

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> check;
        
        std::unordered_map<char, char> parentheses_pairs {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for (char c : s) {
            if (parentheses_pairs.contains(c)) {
                check.push(c);
            } else {
                if (check.empty() || parentheses_pairs[check.top()] != c) {
                   return false; 
                }

                check.pop();
            }
        }

        return check.empty();
    }

};
