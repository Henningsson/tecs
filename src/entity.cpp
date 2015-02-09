/* @author: Timmy Henningsson  */
#include "entity.hpp"

using namespace tecs;


Entity::~Entity()
{
  remove_all_components();
}


bool Entity::has_component(const Id& id) const
{
  return m_components.find(id) != m_components.end();
}

void Entity::remove_all_components()
{
  for(auto c : m_components)
    {
      delete c.second;
    }

  m_components.clear();
}
