#include <iostream>
#include <stack>
#include <unordered_map>
#include <string>


class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> brackets;
        std::unordered_map<char, char> mapping = {{')', '('}, {']', '['}, {'}', '{'}};
        
        for (char bracket : s) {
            if (mapping.find(bracket) != mapping.end()) {
                // Current character is a closing bracket
                char topElement = brackets.empty() ? '#' : brackets.top();
                brackets.pop();
                if (topElement != mapping[bracket]) {
                    // If the corresponding opening bracket is not at the top of the stack
                    return false;
                }
            } else {
                // Current character is an opening bracket, push it onto the stack
                brackets.push(bracket);
            }
        }
        
        // If the stack is empty, all opening brackets were matched and removed
        return brackets.empty();
    }
};

int main(){
    std::string str1 = "()";
    std::string str2 = "()[]{}";
    std::string str3 = "(]";
    std::string str4 = "(}{)";


    Solution s = Solution();

    // std::cout << s.isValid(str1) << std::endl;
    // std::cout << s.isValid(str2) << std::endl;
    // std::cout << s.isValid(str3) << std::endl;
    std::cout << s.isValid(str4) << std::endl;

}


/**
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
 

Constraints:

1 <= s.length <= 104
s consists of parentheses only '()[]{}'.
*/