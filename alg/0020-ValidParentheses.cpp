#include <iostream>
#include <stack>
#include <string>

/**
 * determine if the input string is valid
 *
 * @since 2021-7-22 Thursday 15:45
 */
class Solution {
public:
  bool isValid(std::string s) {
    std::stack<char> stack;
    int size = s.size();
    for (int i = 0; i < size; i++) {
      char c = s[i];
      if (c == '(' || c == '[' || c == '{') {
        stack.push(c);
      } else {
        if (stack.empty()) {
          return false;
        }
        char top = stack.top();
        if (c == ')' && top == '(') {
          stack.pop();
        } else if (c == ']' && top == '[') {
          stack.pop();
        } else if (c == '}' && top == '{') {
          stack.pop();
        } else {
          return false;
        }
      }
    }
    return stack.empty();
  }
};

int main(int argc, char *argv[]) {
  Solution s;
  std::cout << s.isValid("(())") << "\n";
  std::cout << s.isValid("(){{[[]]}}") << "\n";
  std::cout << s.isValid("({[]})") << "\n";
  std::cout << s.isValid(")()") << " \n";
}