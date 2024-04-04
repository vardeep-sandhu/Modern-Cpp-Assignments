#ifndef KMEANS_HPP_
#define KMEANS_HPP_

#include <iostream>
#include <string>
#include <vector>

#include <opencv2/core/mat.hpp>

// #include "io_tools.hpp"
namespace ipb {

void HelloWorld();
cv::Mat kMeans(const std::vector<cv::Mat> &descriptors, int k, int max_iter);
}  // namespace ipb
#endif