#include <iostream>
#include <vector>

void doubleVec(std::vector<int> *v) {
  v->insert(v->begin(), v->begin(), v->end());
}

int main() {
  std::vector<int> v{1, 2, 3};
  doubleVec(&v);
  for (int i : v) {
    std::cout << i << " ";
  }
}