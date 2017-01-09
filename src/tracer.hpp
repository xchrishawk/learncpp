/**
 * @file	tracer.hpp
 * @author	Chris Vig (chris@invictus.so)
 * @date	2017/01/08
 */

#pragma once

/* -- Includes -- */

#include <iostream>
#include <string>

/* -- Types -- */

namespace learncpp
{

  /**
   * Class for tracing object lifecycle.
   */
  class tracer
  {
  public:

#define TRACE() this->trace(__PRETTY_FUNCTION__, __FILE__, __LINE__)

    /** Standard class constructor. */
    tracer(const std::string& name)
      : m_id(s_next_id++),
        m_name(name)
    {
      TRACE();
    }

    /** Copy constructor. */
    tracer(const tracer& other)
      : m_id(s_next_id++),
        m_name(other.m_name)
    {
      TRACE();
    }

    /** Assignment operator. */
    tracer& operator =(const tracer& other)
    {
      m_name = other.m_name;
      TRACE();
      return *this;
    }

    /** Move constructor. */
    tracer(tracer&& other)
      : m_id(s_next_id++),
        m_name(std::move(other.m_name))
    {
      TRACE();
    }

    /** Move assignment operator. */
    tracer& operator =(tracer&& other)
    {
      m_name = std::move(other.m_name);
      TRACE();
      return *this;
    }

    /** Destructor. */
    ~tracer()
    {
      TRACE();
    }

    /** Prints a trace. */
    void trace() const
    {
      TRACE();
    }

#undef TRACE

  private:

    static int s_next_id;
    const int m_id;
    std::string m_name;

    void trace(const std::string& method, const std::string& file, int line) const;

  };

}
