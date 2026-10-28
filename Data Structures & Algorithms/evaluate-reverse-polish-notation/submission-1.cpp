// Stack -> if token != num, pop number and do appropriate function
// First number is set as total -> total +-*/ = the number

#include <stack>
#include <string>


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        int holder_top = 0;
        int holder = 0;

        for (const std::string& t : tokens) {
            if (t == "+") {
                holder_top = numbers.top();
                numbers.pop();
                holder_top += numbers.top();
                numbers.pop();
                numbers.push(holder_top);
            } else if (t == "-") { 
                holder_top = numbers.top();
                holder = holder_top;
                numbers.pop();
                holder_top = numbers.top();
                holder_top -= holder;
                numbers.pop();
                numbers.push(holder_top);
            } else if (t == "/") {
                holder_top = numbers.top();
                holder = holder_top;
                numbers.pop();
                holder_top = numbers.top();
                holder_top /= holder;
                numbers.pop();
                numbers.push(holder_top);
            } else if (t == "*") {
                holder_top = numbers.top();
                numbers.pop();
                holder_top *= numbers.top();
                numbers.pop();
                numbers.push(holder_top);
            } else {
                numbers.push(stoi(t));
            }
        }

        return numbers.top();
    }
};
