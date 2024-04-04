#include <algorithm>
#include <iostream>
#include <new>
#include <numeric>
#include <vector>

#include "homework_4.h"

using namespace ipb;
// #include "lib.hpp"
void vector1(named_vector<int> obj) {
  for (auto&& element_of_vec : obj.vector()) {
    std::cout << element_of_vec << std::endl;
  }
}
// auto UpperCase1(char& c) { return std ::toupper(c); }
int main() {
  named_vector<int> v{"name", {1, 2, 3, 4}};

  // std::cout << count(v, 1);
  print(toupper(v));

  // ipb::clamp(v, 1, 2);
  // vector1(v);
  // ipb::find(v);
  // ipb::print(ipb::sort(v));
  // ipb::print(ipb::reverse(v));
  // std::cout << ipb::count(v, 1);
  return 0;
}