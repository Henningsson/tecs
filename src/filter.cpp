/* @author: Timmy Henningsson */

#include "filter.hpp"
#include "entity.hpp"

using namespace tecs;

//
// Checks if a given entity passes the filter 
// (i.e if it has all the required components)
//
bool Filter::passes_filter(const Entity* entity) const
{
  //NOTE(Timmy): inefficient testcode.. needs to be implemented properly
  for(auto c : m_required)
    {
      if(entity->has_component(c.first) == false)
	return false;
    }

  return true;
}
