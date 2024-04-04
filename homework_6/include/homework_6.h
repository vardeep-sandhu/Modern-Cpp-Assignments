#include <algorithm>
#include <cstdint>
#include <stdexcept>
#include <string>
#include <vector>
namespace igg {
class Image {
public:
  Image() = default;
  Image(int rows, int cols);
  ~Image() = default;
  int at(int row, int col) const;
  bool FillFromPgm(const std::string &file_name);
  void WriteToPgm(const std::string &file_name);
  int &at(int row, int col);
  std::vector<float> ComputeHistogram(int bins) const;
  void DownScale(int scale);
  void UpScale(int scale);
  int rows() const;
  int cols() const;

private:
  int rows_ = 0;
  int cols_ = 0;
  std::vector<int> data_;
};
} // namespace igg