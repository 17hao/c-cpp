#include <iostream>
#include <string>
#include <vector>

using namespace ::std;

/**
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * @since 2021-11-10 Wednesday 16:56 - 17:16
 */
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s;
        generate(res, s, 0, 0, 0, n);
        return res;
    }

   private:
    char leftParenthes = '(';
    char rightParenthes = ')';

    /**
     * 如果左括号多余右括号或者左括号剩余0个，添加右括号
     * 如果左括号剩余数大于0，添加左括号
     */
    void generate(vector<string>& res, string& s, int left, int right, int cur, int n) {
        if (left == n && right == n) {
            res.push_back(s);
            return;
        }

        if (left == n || left > right) {
            s.push_back(rightParenthes);
            generate(res, s, left, right + 1, cur + 1, n);
            s.pop_back();
        }
        if (left < n) {
            s.push_back(leftParenthes);
            generate(res, s, left + 1, right, cur + 1, n);
            s.pop_back();
        }
    }
};

int main(int argc, char const* argv[]) {
    Solution s;
    auto res = s.generateParenthesis(3);
    for (string s : res) {
        cout << s << "\n";
    }
}
