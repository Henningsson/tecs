/* @author: Timmy Henningsson */
#include "world.hpp"

using namespace tecs;
using namespace std;


World::~World()
{
  for(auto it = m_entities.begin(); it != m_entities.end(); ++it)
    delete it->second;

  for(auto it = m_systems.begin(); it != m_systems.end(); ++it)
    delete it->second;
}

void World::remove_system(const Id& id)
{
  auto it = m_systems.find(id);

  if(it != m_systems.end())
    {
      delete it->second;
      m_systems.erase(it);
    }
}

void World::remove_entity(Entity *entity)
{
  remove_entity(entity->get_id());
}

void World::remove_entity(const Id& id)
{
  auto it = m_entities.find(id);

  if(it != m_entities.end())
    {
      delete it->second;
      m_entities.erase(it);
    }
}

SystemBase* World::get_system(const Id& id)
{
  if(m_systems.find(id) != m_systems.end())
    return m_systems[id];

  return nullptr;
}

Entity* World::get_entity(const Id& id)
{
 if(m_entities.find(id) != m_entities.end())
    return m_entities[id];

  return nullptr;
}

World::EntityVector
World::get_entities()
{
  EntityVector entities;
  for(auto it = m_entities.cbegin(); it != m_entities.cend(); ++it)
    entities.push_back(it->second);

  return entities;
}


void World::populate_systems()
{
  for(auto s : m_systems)
    {
      s.second->populate(m_entities);
    }
}

void World::populate_systems(Entity *entity)
{
  for(auto s : m_systems)
    {
      s.second->populate(entity);
    }
}
