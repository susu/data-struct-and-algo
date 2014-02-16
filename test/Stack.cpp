#include <ds/Stack.hpp>

#include <igloo/igloo_alt.h>
#include "common.hpp"

namespace
{
  using namespace igloo;

  Describe(AStack)
  {
    It(should_be_instantiated)
    {
      ds::Stack<int> stack;
    }

    It(should_be_empty_on_creation)
    {
      // Arrange
      ds::Stack<int> stack;

      // Act && Assert
      AssertThat(stack.isEmpty(), Equals(true));
    }

    It(should_return_the_pushed_element)
    {
      // Arrange
      ds::Stack<int> stack;
      stack.push(42);

      // Act
      int poppedItem = stack.pop();

      // Assert
      AssertThat(poppedItem, Equals(42));
    }

    It(should_return_multiple_pushed_elements_in_reversed_order)
    {
      // Arrange
      ds::Stack<int> stack;
      stack.push(42);
      stack.push(76);
      stack.push(4);

      // Act && Assert
      AssertThat(stack.pop(), Equals(4));
      AssertThat(stack.pop(), Equals(76));
      AssertThat(stack.pop(), Equals(42));
      AssertThat(stack.isEmpty(), Equals(true));
    }

    It(should_return_lot_of_pushed_elements_in_reversed_order)
    {
      // Arrange
      ds::Stack<int> stack;
      std::vector<int> numbers = generateRandomVector(100);

      for (const auto & i : numbers)
        stack.push(i);

      // Act && Assert
      std::for_each(numbers.rbegin(), numbers.rend(),
      [&stack](int i)
      {
        AssertThat(stack.pop(), Equals(i));
      });
    }
  };
}
