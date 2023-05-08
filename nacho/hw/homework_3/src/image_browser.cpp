#include "image_browser.hpp"
// #include <fmt>
#include <iostream>

using ScoredImage = std::tuple<std::string, float>;
using ImageRow = std::array<ScoredImage, 3>;

void image_browser::AddFullRow(const ImageRow &row, bool first_row) {}

void CreateImageBrowser(const std::string &title, const std::string &stylesheet,
                        const std::vector<ImageRow> &rows) {}