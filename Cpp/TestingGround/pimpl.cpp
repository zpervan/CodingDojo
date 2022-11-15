#include <fmt/format.h>
#include <iostream>
#include <memory>

class Helper {
public:
  void PrintText() { fmt::print("Helper stuff"); }
};

class SomeImplementation {
public:
  void PrintText() { helper_->PrintText(); }

private:
  std::unique_ptr<Helper> helper_{std::make_unique<Helper>()};
};

int main() {
  SomeImplementation some_implementation;
  some_implementation.PrintText();

  return EXIT_SUCCESS;
}