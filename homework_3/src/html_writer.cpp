#include "html_writer.hpp"
// #include <fmt>
#include <iostream>

void html_writer::OpenDocument() {}

void html_writer::CloseDocument() {}

void html_writer::AddCSSStyle(const std::string &stylesheet) {}
void html_writer::AddTitle(const std::string &title) {}
void html_writer::OpenBody() {}
void html_writer::CloseBody() {}
void html_writer::CloseRow() {}
void html_writer::AddImage(const std::string &img_path, float score,
                           bool highlight) {}