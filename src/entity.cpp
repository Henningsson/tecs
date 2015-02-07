/* @author: Timmy Henningsson  */
#include "entity.hpp"

using namespace tecs;


bool Entity::has_component(const Id& id) const
{
  return m_components.find(id) != m_components.end();
}
