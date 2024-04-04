
#include "bow_dictionary.hpp"

#include <iostream>
#include <utility>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

#include "homework_7.h"

// namespace ipb {
ipb::BowDictionary ipb::BowDictionary::s_Ins;

// Singleton requrirement

ipb::BowDictionary& ipb::BowDictionary::GetInstance() { return s_Ins; }
// setting all parameters
void ipb::BowDictionary::set_params(int max_itr, int size,
                                    const std::vector<cv::Mat>& discriptor) {
  this->max_itr_ = max_itr;
  this->size_ = size;
  this->discriptor_ = discriptor;
}

// normal funcitons
// =getter methods
int ipb::BowDictionary::max_iterations() const { return max_itr_; }

int ipb::BowDictionary::size() const {
  return size_;
}  // number of centroids / codewords
std::vector<cv::Mat> ipb::BowDictionary::descriptors() { return discriptor_; }

// cv::Mat ipb::BowDictionary::vocabulary() { return discriptor_; }

int ipb::BowDictionary::total_features() const {
  int total_features = 0;
  for (const auto& descriptor : discriptor_) {
    total_features += descriptor.rows;
  }
  return total_features;
}  // number of input features
bool ipb::BowDictionary::empty() const { return discriptor_.empty(); }

// Setters methods

void ipb::BowDictionary::set_max_iterations(int kNewIterations) {
  this->max_itr_ = kNewIterations;
}

void ipb::BowDictionary::set_size(int kNewSize) { this->size_ = kNewSize; }

void ipb::BowDictionary::set_descriptors(std::vector<cv::Mat> new_descriptors) {
  this->discriptor_ = std::move(new_descriptors);
}
// }  // namespace ipb