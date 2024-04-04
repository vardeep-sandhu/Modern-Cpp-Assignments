#include <iostream>

class Random {
 public:
  Random(const Random&) = delete;
  static Random& Get() { return s_Instance; }

  float Float() const { return random_float; }
  void floatt(float x) { this->random_float = x; }

 private:
  float random_float = 0.5F;
  Random() = default;
  static Random s_Instance;
};

Random Random::s_Instance;

int main() {
  Random::Get().floatt(1.23);
  std::cout << Random::Get().Float();
}