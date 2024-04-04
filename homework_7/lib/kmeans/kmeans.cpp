#include "kmeans.hpp"

#include <iostream>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/core/mat.hpp>

void ipb::HelloWorld() { std::cout << "Hello"; }

cv::Mat ipb::kMeans(const std::vector<cv::Mat> &descriptors, int k,
                    int max_iter) {
  cv::Mat concat;
  cv::vconcat(descriptors, concat);
  cv::Mat best_labels;
  cv::Mat centers;
  cv::kmeans(concat, k, best_labels, cv::TermCriteria(0, max_iter, 0.0), 1,
             cv::KMEANS_PP_CENTERS, centers);
  cv::sort(centers, centers, cv::SORT_ASCENDING + cv::SORT_EVERY_COLUMN);
  return centers;
}
