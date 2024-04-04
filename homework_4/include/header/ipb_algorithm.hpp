#ifndef IPB_ALGORITHM_HPP_
#define IPB_ALGORITHM_HPP_

#include "named_vector.hpp"
namespace ipb {
int accumulate(named_vector<int>);
int count(named_vector<int>, int i);
bool all_even(named_vector<int>);
ipb::named_vector<int> clamp(named_vector<int>&, int min_val, int max_val);
ipb::named_vector<int> fill(named_vector<int>&, int f);
bool find(named_vector<int>, int num);
void printvector(named_vector<int>);
void print(named_vector<int>);
auto UpperCase(char& c);
ipb::named_vector<int> toupper(named_vector<int>&);
ipb::named_vector<int> sort(named_vector<int>&);
ipb::named_vector<int> rotate(named_vector<int>&, int i);
ipb::named_vector<int> reverse(named_vector<int>&);
bool all_even(int i);
}  // namespace ipb

#endif