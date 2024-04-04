#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

#include "homework_7.h"

int main() {
  // ipb::serialization::sifts::ConvertDataset("data/freiburg/images");
  std::vector<cv::Mat> discriptor =
      ipb::serialization::sifts::LoadDataset("data/freiburg/bin");

  // cv::Mat temp = ipb::kMeans(discriptor, 10, 10);
  // std::cout << temp.rows;
  ipb::BowDictionary::GetInstance().set_params(10, 100, discriptor);
  std::cout << ipb::BowDictionary::GetInstance().empty();
}