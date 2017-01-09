/**
 * @file	tracer.cpp
 * @author	Chris Vig (chris@invictus.so)
 * @date	2017/01/08
 */

/* -- Includes -- */

#include "tracer.hpp"

/* -- Namespaces -- */

using namespace learncpp;

/* -- Variables -- */

int tracer::s_next_id = 0;

/* -- Procedures -- */

void tracer::trace(const std::string& method, const std::string& file, int line) const
{
  std::cout << "[tracer id=" << m_id << " name=\"" << m_name << "\"] " << method << std::endl;
}
