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
  std::string entry{};
  int number = 0;

  while (true) {

    std::cin >> entry;
    number = std::stoi(entry);
    std::cout << "Did you enter: " << number << std::endl;

    if (random_number == number) {
      std::cout << "You have won" << std::endl;
      return EXIT_SUCCESS;
    }

    else if (random_number > number) {
      std::cout << "My number is larger, guess again" << std::endl;
      continue;
    }

    else if (random_number < number) {
      std::cout << "My number is smaller, guess again" << std::endl;
      continue;
    }

    else {
      std::cerr << "Something weird happened!" << std::endl;
      return EXIT_FAILURE;
    }
  }
  return 0;
}