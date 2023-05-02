#include <cstdlib>
#include <iostream>
#include <random>
int main() {
  //   Genrate random number
  std::random_device device;
  std::mt19937 generator(device());
  std::uniform_int_distribution<int> distribution(0, 99);
  int random_number = distribution(generator);

  std::cout << "The random generated number is: " << random_number << std::endl;
  std::cout << "Now please enter a number: " << std::endl;

  int number = 0;
  std::cin >> number;
  std::cout << "Did you enter: " << number << std::endl;

  if (random_number == number) {
    std::cout << "Exiting now!" << std::endl;
    return EXIT_SUCCESS;
  }
  return 0;
}