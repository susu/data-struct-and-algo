#ifndef DS_TEST_COMMON_HPP_INC
#define DS_TEST_COMMON_HPP_INC

#include <random>


std::vector<int> generateRandomVector(int numberOfElements)
{
  std::vector<int> ret(numberOfElements);
  std::random_device dev;
  std::uniform_int_distribution<> distribution(0, 1000);
  for (auto & i : ret)
  {
    i = distribution(dev);
  }
  return std::move(ret);
}


#endif
