#include <filesystem>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <ostream>

#include <opencv2/core.hpp>
#include <opencv2/core/cvstd.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "homework_5.h"
using Mode = std::ios_base::openmode;

int main() {
  std::string input_image_path =
      "/home/sandhu/cpp-homeworks/homework_5/data/lenna.png";
  std::string extension = ".bin";
  std::string binary_file = std::filesystem::path(input_image_path).stem();
  binary_file.append(extension);
  cv::Mat input_image = cv::imread(input_image_path, cv::IMREAD_GRAYSCALE);
  // ipb::serialization::Serialize(input_image, binary_file);
  // auto image = ipb::serialization::Deserialize(binary_file);
  // cv::namedWindow("Window Name", cv::WINDOW_AUTOSIZE);
  // cv::imshow("Window Name", image);
  // cv::waitKey(0);
  ipb::serialization::sifts::ConvertDataset("data/freiburg/images/");
  ipb::serialization::sifts::LoadDataset("data/freiburg/bin/");
}
