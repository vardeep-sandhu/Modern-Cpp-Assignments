#include "homework_8.h"
#include "io_tools.hpp"
#include <fstream>
#include <iomanip>
#include <iostream>

namespace igg {

Image::Image(int rows, int cols)
    : rows_(rows), cols_(cols), data_(rows * cols, default_pixel) {}

int Image::rows() const { return rows_; }
int Image::cols() const { return cols_; }

Image::Pixel Image::at(int row, int col) const {
  if ((row < 0 || row > rows_) && (col < 0 || col < cols_)) {
    throw std::domain_error("Provided rows and cols are out of bounds");
  }
  int index = (row)*cols_ + col;
  return data_[index];
}

Image::Pixel &Image::at(int row, int col) {
  if ((row < 0 || row > rows_) && (col < 0 || col < cols_)) {
    throw std::domain_error("Provided rows and cols are out of bounds");
  }
  int index = (row)*cols_ + col;

  return data_[index];
}

bool Image::ReadFromDisk(const std::string &path) {
  std::ifstream f(path.c_str());
  if (!f.good()) {
    exit(1);
  }
  stratergy_ptr_->Read(path);
}
bool Image::WriteToDisk(const std::string &path) {
  std::ifstream f(path.c_str());
  if (!f.good()) {
    exit(1);
  }
  stratergy_ptr_->Write(path);
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
    int index_r = pixel.red / factor;
    int index_g = pixel.green / factor;
    int index_b = pixel.blue / factor;
    hist[index_r] += 1;
    hist[index_g] += 1;
    hist[index_b] += 1;
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
  Image temp(new_rows, new_cols);

  for (int y = 0; y < new_rows; ++y) {
    for (int x = 0; x < new_cols; ++x) {
      int srcX = x * scale;
      int srcY = y * scale;
      temp.at(srcX, srcY).red = data_[srcY * cols_ + srcX].red;
      temp.at(srcX, srcY).green = data_[srcY * cols_ + srcX].green;
      temp.at(srcX, srcY).blue = data_[srcY * cols_ + srcX].blue;
    }
  }

  *this = std::move(temp);
  rows_ = new_rows;
  cols_ = new_cols;
}

void Image::UpScale(int scale) {
  int new_rows = rows_ * scale;
  int new_cols = cols_ * scale;
  // std::vector<int> newImageData(new_rows * new_cols);
  Image temp(new_rows, new_cols);

  for (int y = 0; y < new_rows; ++y) {
    for (int x = 0; x < new_cols; ++x) {
      int srcX = x / scale;
      int srcY = y / scale;
      temp.at(srcX, srcY).red = data_[srcY * cols_ + srcX].red;
      temp.at(srcX, srcY).green = data_[srcY * cols_ + srcX].green;
      temp.at(srcX, srcY).blue = data_[srcY * cols_ + srcX].blue;
    }
  }

  *this = std::move(temp);
  rows_ = new_rows;
  cols_ = new_cols;
}

void Image::SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr) {
  stratergy_ptr_ = strategy_ptr;
}

bool PngIoStrategy::Read(const std::string &path) {
  // png::image<png::rgb_pixel> image;
  // image.read(path);
  return true;
}

bool PngIoStrategy::Write(const std::string &path) { return true; }

bool PpmIoStrategy::Read(const std::string &path) {

  igg::io_tools::ImageData img = igg::io_tools::ReadFromPgm(path);
  bool zeros = std::all_of(img.data.begin(), img.data.end(),
                           [](int i) { return i == 0; });
  if (zeros) {
    return false;
  }
  std::vector<int> data{std::begin(img.data), std::end(img.data)};
  Image temp{img.rows, img.cols};

  for (int i = 0; i < data.size(); i + 3) {
    temp.data_[i].red = i;
    temp.data_[i / 3].green = i + 1;
    temp.data_[i / 3].blue = i + 2;
  }

  *this = std::move(temp);
  rows_ = img.rows;
  cols_ = img.cols;
  return true;
}

bool PpmIoStrategy::Write(const std::string &path) {
  // std::ofstream out(path);
  // if (!out) {
  //   return false;
  // }

  // out << "P3" << std::endl
  //     << rows_ << " " << cols_ << std::endl
  //     << 255 << std::endl;
  // for (int r = 0; r < image_data.rows; ++r) {
  //   for (int c = 0; c < image_data.cols; ++c) {
  //     out << image_data.data[r * image_data.cols + c] << " ";
  //   }
  //   out << std::endl;
  // }
  return true;
}

} // namespace igg

int main() {

  igg::Image image;
  image.SetIoStrategy(std::make_shared<igg::PngIoStrategy>());
  std::cout << image.rows() << image.cols() << std::endl;
}