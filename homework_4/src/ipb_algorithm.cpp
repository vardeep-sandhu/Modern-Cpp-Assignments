// #include "header/ipb_algorithm.hpp"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <iterator>
#include <numeric>

// #include "header/file.hpp"
#include "homework_4.h"

int ipb::accumulate(ipb::named_vector<int> v) {
  return std::accumulate(v.great_vector.begin(), v.great_vector.end(), 0);
}

int ipb::count(ipb::named_vector<int> v, int i) {
  int var_count = std::count(v.great_vector.begin(), v.great_vector.end(), i);
  return var_count;
}
bool even(int i) { return i % 2 == 0; }
bool ipb::all_even(ipb::named_vector<int> v) {
  return std::all_of(v.vector().cbegin(), v.vector().cend(), even);
}
ipb::named_vector<int> ipb::clamp(ipb::named_vector<int>& v, int min_val,
                                  int max_val) {
  for (int& i : v.great_vector) {
    i = std::clamp(i, min_val, max_val);
  }
  return v;
}
ipb::named_vector<int> ipb::fill(ipb::named_vector<int>& v, int f) {
  std::fill(v.great_vector.begin(), v.great_vector.end(), f);
  return v;
}
bool ipb::find(ipb::named_vector<int> v, int num) {
  return std::find(v.vector().begin(), v.vector().end(), num) !=
         v.vector().end();
}

void ipb::printvector(ipb::named_vector<int> v) {
  std::vector vec = v.vector();
  for (int i : vec) {
    std::cout << i << ", ";
  }
}
void ipb::print(ipb::named_vector<int> v) {
  std::string str = v.name();
  std::cout << str << ": ";
  printvector(v);
}
auto ipb::UpperCase(char& c) { return std::toupper(c); }

ipb::named_vector<int> ipb::toupper(ipb::named_vector<int>& v) {
  //   std::string s = v.name_of_vector;
  std::transform(v.name_of_vector.begin(), v.name_of_vector.end(),
                 v.name_of_vector.begin(), UpperCase);
  return v;
}
ipb::named_vector<int> ipb::sort(ipb::named_vector<int>& v) {
  std::sort(v.great_vector.begin(), v.great_vector.end());
  return v;
}
ipb::named_vector<int> ipb::rotate(named_vector<int>& v, int i) {
  std::rotate(v.great_vector.begin(), v.great_vector.begin() + i,
              v.great_vector.end());
  return v;
}
ipb::named_vector<int> ipb::reverse(named_vector<int>& v) {
  std::reverse(v.great_vector.begin(), v.great_vector.end());
  return v;
}