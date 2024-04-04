#ifndef BOW_DICTIONARY_HPP_
#define BOW_DICTIONARY_HPP_
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

namespace ipb {
class BowDictionary {
  int max_itr_ = 0;
  int size_ = 0;
  std::vector<cv::Mat> discriptor_;
  // cv::Mat dictionary_;
  BowDictionary() = default;
  static BowDictionary s_Ins;

 public:
  // Siingleton requirement

  BowDictionary(const BowDictionary&) = delete;
  static BowDictionary& GetInstance();

  void set_params(int max_itr, int size,
                  const std::vector<cv::Mat>& discriptor);

  // getter methods

  int max_iterations() const;
  int size() const;  // number of centroids / codewords
  std::vector<cv::Mat> descriptors();
  cv::Mat vocabulary();
  int total_features() const;  // number of input features
  bool empty() const;

  // Setters methods
  void set_max_iterations(int kNewIterations);
  void set_size(int kNewSize);
  void set_descriptors(std::vector<cv::Mat> new_descriptors);
};
}  // namespace ipb
#endif