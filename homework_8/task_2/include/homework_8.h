#include <algorithm>
#include <cstdint>
#include <iostream>
#include <memory>
#include <png++/png.hpp>
#include <png++/rgb_pixel.hpp>
#include <stdexcept>
#include <string>
#include <vector>

namespace igg {

class IoStrategy {
public:
  virtual bool Read(const std::string &path) = 0;
  virtual bool Write(const std::string &path) = 0;
  virtual ~IoStrategy() = default;
};

class PngIoStrategy : public IoStrategy {
public:
  bool Read(const std::string &path) override;
  bool Write(const std::string &path) override;
};

class PpmIoStrategy : public IoStrategy {
public:
  bool Read(const std::string &path) override;
  bool Write(const std::string &path) override;
};

class Image {
  struct Pixel {
    int red;
    int green;
    int blue;
  };

public:
  void SetIoStrategy(std::shared_ptr<IoStrategy> strategy_ptr);
  bool ReadFromDisk(const std::string &path);
  bool WriteToDisk(const std::string &path);

  Image() = default;
  // The rule of 6.

  // 1. Move Constructor
  Image(Image &&other) {
    data_ = other.data_;
    other.data_.clear();
  }
  // 2. Move assignment operator
  Image &operator=(Image &&other) {
    this->data_ = other.data_;
    return *this;
  }

  // 2. Copy assignment operator

  Image(int rows, int cols);
  ~Image() = default;
  [[nodiscard]] Pixel at(int row, int col) const;

  Pixel &at(int row, int col);
  [[nodiscard]] std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);
  [[nodiscard]] int rows() const;
  [[nodiscard]] int cols() const;

private:
  int rows_ = 0;
  int cols_ = 0;
  Pixel default_pixel = {0, 0, 0};
  std::shared_ptr<IoStrategy> stratergy_ptr_ = nullptr;

  std::vector<Pixel> data_;
};

} // namespace igg