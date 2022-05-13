#include <iostream>
#include <map>
#include <set>
#include <string>

/**
 * Given a roman numeral, convert it to an integer.
 *
 * Symbol       Value
 * I             1
 * V             5
 * X             10
 * L             50
 * C             100
 * D             500
 * M             1000
 *
 * I can be placed before V (5) and X (10) to make 4 and 9. 
 * X can be placed before L (50) and C (100) to make 40 and 90. 
 * C can be placed before D (500) and M (1000) to make 400 and 900.
 *
 * @since 2021-9-14 Tuesday 21:38
 */
class Solution {
public:
  int romanToInt(std::string s) {
    std::map<std::string, int> mapping{{"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}};

    std::map<std::string, int> special{{"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900}};
    int res = 0;
    int len = s.size();
    int i = 0;
    while (i < len) {
      std::string prefix = s.substr(i, 2);
      auto search = special.find(prefix);
      if (search != special.end()) {
        res += special[prefix];
        i += 2;
      } else {
        res += mapping[s.substr(i, 1)];
        i++;
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.romanToInt("I") << "\n";
  std::cout << s.romanToInt("III") << "\n";
  std::cout << s.romanToInt("IX") << "\n";
  std::cout << s.romanToInt("LVIII") << "\n";
  std::cout << s.romanToInt("MCMXCIV") << "\n";
}
