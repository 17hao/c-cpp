#include <deque>
#include <iostream>
#include <map>
#include <set>
#include <string>

class Solution {
   public:
    bool validParentheses(std::string str) {
        std::set<char> leftParentheses{'(', '[', '{'};
        std::map<char, char> mapping{{')', '('}, {']', '['}, {'}', '{'}};
        std::deque<char> dequeue;
        int len = str.size();
        for (int i = 0; i < len; i++) {
            char c = str[i];
            if (dequeue.size() == 0) {
                dequeue.push_back(c);
            } else {
                if (leftParentheses.find(c) != leftParentheses.end()) {
                    dequeue.push_back(c);
                } else {
                    if (dequeue.back() == mapping[c]) {
                        dequeue.pop_back();
                    } else {
                        return false;
                    }
                }
            }
        }
        return dequeue.size() == 0;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    std::cout << s.validParentheses("(({{}}))") << "\n";
    std::cout << s.validParentheses("(({{}}))") << "\n";
    std::cout << s.validParentheses("(])") << "\n";
    std::cout << s.validParentheses("))") << "\n";
}
