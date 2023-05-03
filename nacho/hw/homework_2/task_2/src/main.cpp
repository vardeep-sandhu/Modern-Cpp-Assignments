// #include <cstdlib>
#include <iostream>
#include <sstream>
#include <vector>

int main(int argc, char *argv[]) {
  std::cout << "The input args are: " << argc << std::endl;

  // Checking the number of args
  if (argc != 3) {
    std::cerr << "Error occured. Exiting!" << std::endl;
    return EXIT_FAILURE;
  }
  std::vector<int> names;
  for (int i = 1; i < argc; i++) {
    std::cout << argv[i] << std::endl;
    std::stringstream filename{argv[i]};
    int name = 0;
    std::string ext;
    filename >> name >> ext;

    if ((ext == ".png") || (ext == ".txt")) {
      //  Find average
      names.push_back(name);
    }

    else {
      std::cerr << "Error occured";
      return EXIT_FAILURE;
    }
  }
  // Seprating the extensions the filename

  return 0;
}