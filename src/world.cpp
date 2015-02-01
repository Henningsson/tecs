/* @author: Timmy Henningsson */

#include "world.hpp"
#include <algorithm>

using namespace tecs;
using namespace std;


World::~World()
{
  //Deallocate entities
  for(auto it = m_entities.begin(); it != m_entities.end(); ++it)
    delete *it;

  //Deallocate systems
  for(auto it = m_systems.begin(); it != m_systems.end(); ++it)
    delete *it;
}

Entity* World::create_entity()
{
  auto entity = new Entity();
  m_entities.push_back(entity);
  
  return entity;
}

void World::remove_entity(Entity *entity)
{
  auto it = find(m_entities.begin(), m_entities.end(), entity);
  
  if(it != m_entities.end())
    {
      m_entities.erase(it);
      delete entity;
    }    
}


ComponentSystem* World::create_system()
{
  auto system = new ComponentSystem();
  m_systems.push_back(system);

  return system;
}

void World::remove_system(ComponentSystem *system)
{
  auto it = find(m_systems.begin(), m_systems.end(), system);

  if(it != m_systems.end())
    {
      m_systems.erase(it);
      delete system;
    }
}
