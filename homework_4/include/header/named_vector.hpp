#ifndef FILE_HPP_
#define FILE_HPP_
#include <iostream>
#include <utility>
#include <vector>

namespace ipb {
template <typename T>
struct named_vector {
 public:
  std::string name_of_vector;
  std::vector<T> great_vector;
  named_vector<T>() = default;
  named_vector<T>(std::string a_name, std::vector<T> a_vector) {
    name_of_vector = std::move(a_name);
    great_vector = a_vector;
  }
  std::string name() { return name_of_vector; }
  std::vector<T> vector() { return great_vector; }
  void reserve(int capacity) { great_vector.reserve(capacity); }
  bool empty() { return (name_of_vector.empty() || great_vector.empty()); }
  unsigned long size() { return great_vector.size() + name_of_vector.size(); }
  void resize(int value) { great_vector.resize(value); }
  int capacity() { return great_vector.capacity(); }
};
}  // namespace ipb
#endif