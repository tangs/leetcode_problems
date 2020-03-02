#include <vector>
#include <unordered_set>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if (!tokens.size()) return 0;
        stack<int> numStack;
        for (auto& str: tokens) {
            char ch = str[0];
            bool isSign = ch == '+' || ch == '*' || ch == '/' || 
            (ch == '-' && str.size() == 1);
            if (isSign) {
                int num2 = numStack.top();
                numStack.pop();
                int num1 = numStack.top();
                numStack.pop();
                int num3 = 0;
                switch(ch) {
                    case '+':
                        num3 = num1 + num2;
                        break;
                    case '-':
                        num3 = num1 - num2;
                        break;
                    case '*':
                        num3 = num1 * num2;
                        break;
                    case '/':
                        num3 = num1 / num2;
                        break;
                }
                numStack.push(num3);
            } else numStack.push(atoi(str.c_str()));
        }
        return numStack.top();
    }
};

int main() {
    vector<string> tokens = {
        "10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"
    };
    Solution solution;
    solution.evalRPN(tokens);
}