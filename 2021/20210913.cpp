#include <iostream>
#include <string>

int main(int argc, char *argv[]) {
  char chars[3] = {};
  for (int i = 0; i < 3; i++) {
    chars[i] = '0' + i;
  }
  std::string res = std::string(chars);
  std::cout << "str: " << res << "\n";
}