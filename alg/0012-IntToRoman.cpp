#include <iostream>
#include <string>

/**
 * Given an integer, convert it to a roman numeral.
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
 * @since 2021-9-14 Tuesday 19:44
 */
class Solution {
public:
  std::string intToRoman(int num) {
    std::string res = "";
    while (num != 0) {
      std::string special = specialNum(&num);
      if (special.size() > 0) {
        res.append(special);
      } else {
        if (num / 1000 > 0) {
          int count = num / 1000;
          append(&res, "M", count);
          num = num % 1000;
        } else if (num / 500 > 0) {
          int count = num / 500;
          append(&res, "D", count);
          num = num % 500;
        } else if (num / 100 > 0) {
          int count = num / 100;
          append(&res, "C", count);
          num = num % 100;
        } else if (num / 50 > 0) {
          int count = num / 50;
          append(&res, "L", count);
          num = num % 50;
        } else if (num / 10 > 0) {
          int count = num / 10;
          append(&res, "X", count);
          num = num % 10;
        } else if (num / 5 > 0) {
          int count = num / 5;
          append(&res, "V", count);
          num = num % 5;
        } else if (num / 1 > 0) {
          int count = num / 1;
          append(&res, "I", count);
          num = num % 1;
        }
      }
    }
    return res;
  }

private:
  std::string specialNum(int *num) {
    if (*num >= 900 && *num < 1000) {
      *num -= 900;
      return "CM";
    } else if (*num >= 400 && *num < 500) {
      *num -= 400;
      return "CD";
    } else if (*num >= 90 && *num < 100) {
      *num -= 90;
      return "XC";
    } else if (*num >= 40 && *num < 50) {
      *num -= 40;
      return "XL";
    } else if (*num >= 9 && *num < 10) {
      *num -= 9;
      return "IX";
    } else if (*num == 4) {
      *num -= 4;
      return "IV";
    } else {
      return "";
    }
  }

  void append(std::string *res, std::string append, int count) {
    for (int i = 0; i < count; i++) {
      res->append(append);
    }
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  std::cout << s.intToRoman(1) << "\n";
  std::cout << s.intToRoman(3) << "\n";
  std::cout << s.intToRoman(4) << "\n";
  std::cout << s.intToRoman(9) << "\n";
  std::cout << s.intToRoman(58) << "\n";
  std::cout << s.intToRoman(1994) << "\n";
}
