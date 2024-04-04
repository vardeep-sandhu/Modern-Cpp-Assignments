#include <cstdlib>
#include <fstream>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/xfeatures2d.hpp>

using cv::xfeatures2d::SiftDescriptorExtractor;
using cv::xfeatures2d::SiftFeatureDetector;
using namespace std;
int main() {
  const cv::Mat kInput = cv::imread("../lenna.png", cv::IMREAD_GRAYSCALE);

  // detect key points
  auto detector = SiftFeatureDetector::create();
  vector<cv::KeyPoint> keypoints;
  detector->detect(kInput, keypoints);

  cv::Mat image_with_keypoints;
  drawKeypoints(kInput, keypoints, image_with_keypoints);

  cv::Mat descriptors;
  auto extractor = SiftDescriptorExtractor::create();
  extractor->compute(kInput, keypoints, descriptors);

  cv::namedWindow("SIFT detections", cv::WINDOW_AUTOSIZE);
  cv::imshow("SIFT detections", image_with_keypoints);

  //   cv::namedWindow("SIFT vector as image", cv::WINDOW_AUTOSIZE);
  //   cv::imshow("SIFT vector as image", descriptors);

  std::cout << "Number of SIFTs: " << descriptors.rows << "\n"
            << "Size of each SIFT: " << descriptors.cols << "\n";
  cv::waitKey(0);
  string binary_image = "binaryImage.bin";
  ofstream file(binary_image, ios_base::out | ios_base::binary);
  int rows = descriptors.rows;
  int cols = descriptors.cols;
  //   vector<> vec(rows * cols);
  file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
  file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
  file.write(reinterpret_cast<char*>(&kInput), sizeof(kInput));
}
