#ifndef DS_STACK_HPP_INC
#define DS_STACK_HPP_INC

#include <memory>
#include <cstring>
#include <cassert>

namespace ds
{
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

      bool isEmpty() const
      { return true; }

      void push(const T& item)
      {
        ensureCapacity(m_size + 1);
        m_data[m_size] = item;
        ++m_size;
      }

      T pop()
      {
        assert(m_size > 0);
        return m_data[--m_size];
      }
    private:
      void ensureCapacity(size_t requiredCapacity)
      {
        if (m_capacity < requiredCapacity)
        {
          std::unique_ptr<T[]> newData(new T[m_capacity * 2]);
          std::memcpy(newData.get(), m_data.get(), m_capacity * sizeof(T));

          m_data.reset(newData.release());
          m_capacity *= 2;
        }
      }

    private:
      std::unique_ptr<T[]> m_data;
      size_t m_capacity;
      size_t m_size;
  };
}

#endif
