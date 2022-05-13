#include <iostream>
#include <string>
#include <vector>

/**
 * paypalishiring
 *
 * p   a   h   n
 * a p l s i i g
 * y   i   r
 *
 * P     I     N
 * A   L S   I G
 * Y A   H R
 * P     I
 *
 * @since 2021-9-13 Monday 9:00
 */
class Solution {
public:
  std::string convert(std::string s, int numRows) {
    int len = s.size();
    std::vector<char> res(len);
    int index = 0;
    int gap = 2 * (numRows - 1);
    if (numRows == 1) {
      return s;
    }
    for (int level = 0; level < numRows; level++) {
      if (level >= len) {
        break;
      }
      int gap1 = (numRows - level - 1) * 2;
      int gap2 = gap - gap1;
      int i = level, j = 0;
      res[index++] = s[level];
      while (true) {
        if (j % 2 == 0 && gap1 != 0) {
          i += gap1;
        } else if (j % 2 == 1 && gap2 != 0) {
          i += gap2;
        } else {
          j++;
          continue;
        }
        if (i < len) {
          res[index++] = s[i];
          j++;
        } else {
          break;
        }
      }
    }
    return std::string(res.begin(), res.end());
  }
};

int main(int argc, char const *argv[]) {
  Solution s;
  // std::string str = "A";
  // std::cout << s.convert(str, 1) << "\n";
  // std::cout << s.convert(str, 2) << "\n";
  // std::cout << s.convert(str, 3) << "\n";

  std::string str = "paypalishiring";
  std::cout << s.convert(str, 3) << "\n";
  std::cout << s.convert(str, 4) << "\n";
  std::cout << s.convert(str, 5) << "\n";
  std::cout << s.convert(str, 1000) << "\n";
}
