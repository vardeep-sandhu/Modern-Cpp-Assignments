#include <cstdlib>
#include <fstream>
#include <ios>
#include <iostream>
#include <ostream>
#include <string>

#include <opencv2/core/mat.hpp>

#include "homework_5.h"

void ipb::serialization::Serialize(const cv::Mat& m,
                                   const std::string& filename) {
  std::ofstream file(filename, std::ios_base::out | std::ios_base::binary);
  int rows = m.rows;
  int cols = m.cols;
  int type = m.type();
  file.write(reinterpret_cast<char*>(&type), sizeof(type));
  file.write(reinterpret_cast<char*>(&rows), sizeof(rows));
  file.write(reinterpret_cast<char*>(&cols), sizeof(cols));
  file.write(reinterpret_cast<char*>(m.data),
             rows * cols * sizeof(m.elemSize()));
  // file.write(reinterpret_cast<char*>(&m), sizeof(m));
}

void ipb::serialization::HelloWorld() { std::cout << "Hello World"; }

cv::Mat ipb::serialization::Deserialize(const std::string& filename) {
  int rows = 0;
  int cols = 0;
  int type = 0;
  cv::Mat m;
  std::ifstream in(filename, std::ios_base::in | std::ios_base::binary);
  in.read(reinterpret_cast<char*>(&type), sizeof(type));
  in.read(reinterpret_cast<char*>(&rows), sizeof(rows));
  in.read(reinterpret_cast<char*>(&cols), sizeof(cols));
  std::cout << "DIM:" << rows << "x" << cols << type << std::endl;
  m.create(rows, cols, type);
  in.read(reinterpret_cast<char*>(m.data), m.total() * m.elemSize());
  return m;
}