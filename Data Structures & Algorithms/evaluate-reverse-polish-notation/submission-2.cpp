#include <string>
#include <stack>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;

        for (const std::string& t : tokens) {
            if (t == "+" || t == "-" || t == "*"|| t == "/") {
                int b = numbers.top(); numbers.pop();
                int a = numbers.top(); numbers.pop();

                if (t == "+") {numbers.push(a + b);}
                else if (t == "*") {numbers.push(a * b);}
                else if (t == "/") {numbers.push(a / b);}
                else {numbers.push(a - b);}
            } else {
                numbers.push(stoi(t));
            }
        }

        return numbers.top();
    }
};
