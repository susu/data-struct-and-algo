#include <igloo/igloo_alt.h>
#include <ds/Stack.hpp>

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

    // Act
    stack.push(42);

    // Assert
    AssertThat(stack.pop(), 42);
  }
};
