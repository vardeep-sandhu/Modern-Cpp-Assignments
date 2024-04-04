#include "convert_dataset.hpp"

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <string>
#include <tuple>
#include <vector>

#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "homework_5.h"
using cv::xfeatures2d::SiftDescriptorExtractor;
using cv::xfeatures2d::SiftFeatureDetector;

std::tuple<cv::Mat, cv::Mat> ipb::serialization::sifts::ComputeSifts(
    const std::string& file_path) {
  const cv::Mat kInput = cv::imread(file_path, cv::IMREAD_GRAYSCALE);
  auto detector = SiftFeatureDetector::create();
  std::vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);
  cv::Mat image_with_keypoints;
  drawKeypoints(kInput, keypoints, image_with_keypoints);
  cv::Mat descriptors;
  auto extractor = SiftDescriptorExtractor::create();
  extractor->compute(kInput, keypoints, descriptors);
  return std::make_tuple(descriptors, image_with_keypoints);
}
void ipb::serialization::sifts::ConvertDataset(
    const std::filesystem::path& img_path) {
  std::string binary_path =
      img_path.parent_path().parent_path().u8string() + "/bin/";
  if (!std::filesystem::is_directory(binary_path)) {
    std::filesystem::create_directory(binary_path);
  }
  for (const auto& image : std::filesystem::directory_iterator(img_path)) {
    std::string binary_file = image.path().stem();
    if (image.path().extension() == ".png") {
      const std::string SIFT_filename = binary_path + binary_file + ".bin";

      if (!std::filesystem::exists(SIFT_filename)) {
        cv::Mat SIFT =
            std::get<0>(ipb::serialization::sifts::ComputeSifts(image.path()));

        if (!SIFT.empty()) {
          ipb::serialization::Serialize(SIFT, SIFT_filename);
        }
      }
    }
  }
}
std::vector<cv::Mat> ipb::serialization::sifts::LoadDataset(
    const std::filesystem::path& bin_path) {
  std::vector<cv::Mat> Image_vector;
  for (const auto& binary : std::filesystem::directory_iterator(bin_path)) {
    if (std::filesystem::path(binary.path()).extension() != ".bin") {
      continue;
    }
    cv::Mat Deserial_SIFT =
        ipb::serialization::Deserialize(std::filesystem::path(binary));
    Image_vector.push_back(Deserial_SIFT);
  }
  return Image_vector;
}
