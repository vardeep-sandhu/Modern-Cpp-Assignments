#include "homework_6.h"
#include "io_tools.hpp"
#include <iomanip>
#include <iostream>

namespace igg {

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(rows * cols, 0) {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

int Image::at(int row, int col) const {
  if ((row < 0 || row > rows_) && (col < 0 || col < cols_)) {
    throw std::domain_error("Provided rows and cols are out of bounds");
  }
  int index = (row)*cols_ + col;
  return static_cast<int>(data_[index]);
}

int &Image::at(int row, int col) {
  if ((row < 0 || row > rows_) && (col < 0 || col < cols_)) {
    throw std::domain_error("Provided rows and cols are out of bounds");
  }
  int index = (row)*cols_ + col;

  return data_[index];
}

bool Image::FillFromPgm(const std::string &file_name) {

  igg::io_tools::ImageData img = igg::io_tools::ReadFromPgm(file_name);
  bool zeros = std::all_of(img.data.begin(), img.data.end(),
                           [](int i) { return i == 0; });
  if (zeros) {
    return false;
  }
  std::vector<int> data{std::begin(img.data), std::end(img.data)};
  data_ = std::move(data);
  rows_ = img.rows;
  cols_ = img.cols;
  return true;
}

void Image::WriteToPgm(const std::string &file_name) {
  auto max_elem_it =
      std::max_element(std::begin(data_), std::end(data_)); // C++11
  std::vector<uint8_t> data{std::begin(data_), std::end(data_)};
  igg::io_tools::ImageData img{rows_, cols_, *max_elem_it, data};

  bool written = igg::io_tools::WriteToPgm(img, file_name);
  if (!written) {
    throw std::domain_error("Problem with writing");
  }
}
void Print(std::vector<float> vec) {
  std::cout << "Vec Print" << std::endl;
  for (auto i : vec) {
    std::cout << std::fixed << std::setprecision(1) << i << std::endl;
  }
  std::cout << "Vec Print End" << std::endl;
}

std::vector<float> Image::ComputeHistogram(int bins) const {
  std::vector<float> hist(bins, 0.0f);

  float total_pixels = rows_ * cols_;
  float factor = 256.0f / bins;
  for (auto pixel : data_) {
    int index = pixel / factor;
    hist[index] += 1;
  }
  std::transform(hist.begin(), hist.end(), hist.begin(),
                 [total_pixels](float &i) {
                   return static_cast<float>(i / total_pixels);
                 });
  return hist;
}

void Image::DownScale(int scale) {
  int new_rows = rows_ / scale;
  int new_cols = cols_ / scale;
  std::vector<int> newImageData(new_rows * new_cols);

  for (int y = 0; y < new_rows; ++y) {
    for (int x = 0; x < new_cols; ++x) {
      int srcX = x * scale;
      int srcY = y * scale;
      newImageData[y * new_cols + x] = data_[srcY * cols_ + srcX];
    }
  }

  data_ = std::move(newImageData);
  rows_ = new_rows;
  cols_ = new_cols;
}

void Image::UpScale(int scale) {
  int new_rows = rows_ * scale;
  int new_cols = cols_ * scale;
  std::vector<int> newImageData(new_rows * new_cols);

  for (int y = 0; y < new_rows; ++y) {
    for (int x = 0; x < new_cols; ++x) {
      int srcX = x / scale;
      int srcY = y / scale;
      newImageData[y * new_cols + x] = data_[srcY * cols_ + srcX];
    }
  }

  data_ = std::move(newImageData);
  rows_ = new_rows;
  cols_ = new_cols;
}
} // namespace igg

// int main() {

//   igg::Image image;

//   // image.at(5, 5) = 115;
//   bool yes = image.FillFromPgm("data/dummy_file.pgm");
//   // std::cout << std::boolalpha << yes << std::endl;
//   const auto &image_ref = image;
//   // auto histogram = image_ref.ComputeHistogram(1);
//   // std::cout << "Size: " << histogram.size() << std::endl;
//   // std::cout << "Front: " << histogram.front() << std::endl;

//   int size = 10;

//   auto histogram_1 = image_ref.ComputeHistogram(size);
//   std::cout << histogram_1.size() << std::endl;
//   std::cout << histogram_1[9] << std::endl;
//   std::cout << histogram_1[0] << std::endl;
// }