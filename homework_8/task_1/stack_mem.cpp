#include <cstddef>
#include <iostream>
#include <memory>

void crash_system() {
  for (int i = 0; i < 1000; ++i) {
    const int num_elements = i * 100 * 1024;
    std::byte OneKbArray[num_elements];

    for (int i = 0; i < num_elements; ++i) {
      OneKbArray[i] = static_cast<std::byte>(i);
    }

    std::cerr << (i) * 100 << "[KiB] Allocated in the stack\n";
  }
}

int main() { crash_system(); }