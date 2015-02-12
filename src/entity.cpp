/* @author: Timmy Henningsson  */
#include "entity.hpp"
#include "world.hpp"

using namespace tecs;


Entity::~Entity()
{
  remove_all_components();
}

World* Entity::get_world()
{
  return m_world;
}

void Entity::set_world(World *world)
{
  m_world = world;
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

  notify_world();
}

void Entity::notify_world()
{
  //NOTE(Timmy): Inefficient testcode
  if(m_world)
    {
      m_world->populate_systems();
    }
}
