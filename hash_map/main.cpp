#include <iostream>
#include <numeric>

#include "HashMap.hpp"

auto myHash = [](const std::string& str) -> int {
  int sum = 0;
  for (auto it = str.begin(); it != str.end(); ++it) {
    sum += (*it);
  }
  return sum;
};

int myHash2(int x) { return x + 2; }

int main() {
  HashMap<std::string, int, 50> myMap(myHash);

  myMap.insert("test", 2);
  myMap.insert("test2", 5);
  std::cout << "myMap[\"test\"]: " << myMap["test"] << std::endl;
  std::cout << "myMap[\"test2\"]: " << myMap["test2"] << std::endl;
  myMap.erase("test");

  try {
    myMap["test"];
  } catch (const std::out_of_range& err) {
    std::cout << err.what() << std::endl;
  }

  HashMap<int, std::string, 50> myMap2(myHash2);

  myMap2.insert(0, "Hello");
  myMap2.insert(1, "World!");

  for (int i = 0; i < 2; ++i) {
    std::cout << "myMap2[" << i << "]: " << myMap2[i] << std::endl;
  }

  myMap2.erase(0);

  try {
    myMap2[0];
  } catch (const std::out_of_range& err) {
    std::cout << err.what() << std::endl;
  }

  auto myMap3 = myMap2;

  std::cout << "myMap3[1]: " << myMap3[1] << std::endl;

  return 0;
}
