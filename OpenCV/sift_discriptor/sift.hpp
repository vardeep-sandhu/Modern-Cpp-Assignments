#ifndef SIFT_HPP_
#define SIFT_HPP_

#include <string>
#include <tuple>

#include <opencv2/core/mat.hpp>

std::tuple<cv::Mat, cv::Mat> ComputeSifts(const std::string& fileName);

#endif  // SIFT_COMPUTE_SIFTS_HPP_