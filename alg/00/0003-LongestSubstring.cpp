#include <algorithm>
#include <iostream>
#include <set>
#include <string>

/**
 * Given a string s, find the length of the longest substring without
 * repeating characters.
 *
 * @since 2021-9-23 Thursday 16:50
 */
class Solution {
   public:
    int lengthOfLongestSubstring(std::string s) {
        std::set<char> slidingWindow;
        int len = s.size();
        int left, right = 0;
        int res = 0;
        while (right < len) {
            char r = s[right++];
            while (slidingWindow.find(r) != slidingWindow.end()) {
                char l = s[left++];
                slidingWindow.erase(l);
            }
            slidingWindow.insert(r);
            res = std::max(res, (int)slidingWindow.size());
        }
        return res;
    }
};

int main(int argc, char const *argv[]) {
    Solution s;
    std::string s0 = "pwwkew";
    std::cout << s.lengthOfLongestSubstring(s0) << "\n";

    std::string s1 = "aaa";
    std::cout << s.lengthOfLongestSubstring(s1) << "\n";

    std::string s2 = "abcabcbb";
    std::cout << s.lengthOfLongestSubstring(s2) << "\n";
}
