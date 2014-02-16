#include <ds/Stack.hpp>

#include <igloo/igloo.h>
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

    It(should_return_the_front_element)
    {
      // Arrange
      ds::Stack<int> stack;
      stack.push(15);

      // Act && Assert
      AssertThat(stack.getFront(), Equals(15));
      stack.push(66);
      AssertThat(stack.getFront(), Equals(66));
    }

    Spec(pushes_and_pops_can_be_mixed)
    {
      ds::Stack<int> stack;

      stack.push(42);
      // ->[ 42 ]
      AssertThat(stack.isEmpty(), Equals(false));
      AssertThat(stack.getFront(), Equals(42));
      AssertThat(stack.pop(), Equals(42));
      // ->[ ]
      AssertThat(stack.isEmpty(), Equals(true));

      stack.push(99);
      // ->[ 99 ]
      stack.push(64);
      // ->[ 64, 99 ]
      AssertThat(stack.getFront(), Equals(64));

      stack.push(95);
      // ->[ 95, 64, 99 ]
      AssertThat(stack.getFront(), Equals(95));

      stack.push(44);
      // ->[ 44, 95, 64, 99 ]
      AssertThat(stack.getFront(), Equals(44));

      AssertThat(stack.pop(), Equals(44));
      // ->[ 95, 64, 99 ]
      AssertThat(stack.pop(), Equals(95));
      // ->[ 64, 99 ]

      stack.push(1000);
      // ->[ 1000, 64, 99 ]
      AssertThat(stack.getFront(), Equals(1000));

      AssertThat(stack.pop(), Equals(1000));
      // ->[ 64, 99 ]
      AssertThat(stack.pop(), Equals(64));
      // ->[ 99 ]
      AssertThat(stack.pop(), Equals(99));
      // ->[ ]

      AssertThat(stack.isEmpty(), Equals(true));
    }
  };
}
