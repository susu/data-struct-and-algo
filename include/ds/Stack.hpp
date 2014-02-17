#ifndef DS_STACK_HPP_INC
#define DS_STACK_HPP_INC

#include <memory>
#include <cstring>
#include <cassert>

namespace ds
{
  /**
   *  Stack implemented with array.
   *  Terms:
   *    - size: the actual size of the stack (how many element pushed)
   *    - capacity: size of its internal buffer
   */
  template<typename T>
  class Stack
  {
    public:
      const static size_t INITIAL_CAPACITY = 3;

      Stack()
        : m_data(new T[INITIAL_CAPACITY])
        , m_capacity(INITIAL_CAPACITY)
        , m_size(0)
      {}

      /**
       * Returns if a stack is empty.
       */
      bool isEmpty() const
      { return m_size == 0; }

      /**
       * Pushes an element to the stack.
       */
      void push(const T& item)
      {
        // we need at least that amount of capacity, but it is possible
        // that the capacity will be greater than m_size + 1
        ensureCapacity(m_size + 1);
        m_data[m_size] = item;
        ++m_size;
      }

      /**
       * Pops and returns an element from the stack.
       * Prereq: stack must not be empty
       */
      T pop()
      {
        assert(!isEmpty());
        return m_data[--m_size];
      }

      /**
       * Returns a const ref. of the front/top element.
       * Prereq: stack must not be empty.
       */
      const T& getFront() const
      {
        assert(!isEmpty());
        return m_data[m_size-1];
      }

    private:
      /**
       *  Post-condition: size of capacity is at least 'requiredCapacity'
       */
      void ensureCapacity(size_t requiredCapacity)
      {
        // Check if we have to resize our capacity.
        if (m_capacity < requiredCapacity)
        {
          // suppose, the capacity will be doubled
          size_t newCapacity = m_capacity * 2;
          // But, if it's not enough:
          if (requiredCapacity > m_capacity * 2)
            newCapacity = requiredCapacity;

          // Let's allocate the new buffer
          std::unique_ptr<T[]> newData(new T[newCapacity]);

          // Copy the old buffer's content.
          // memcpy can be used, since we don't need the copy constructors
          std::memcpy(newData.get(), m_data.get(), m_capacity * sizeof(T));

          // Set the new buffer.
          // We must not free the old buffer, unique_ptr takes care.
          // Both reset() and release() are noexcept functions, so exception-safety is ok.
          m_data.reset(newData.release());

          // At last, update to our new capacity.
          m_capacity = newCapacity;
        }
      }

    private:
      // the internal buffer
      std::unique_ptr<T[]> m_data;

      // size of the internal buffer
      size_t m_capacity;

      // size of the stack (number of elements)
      size_t m_size;
  };
}

#endif
