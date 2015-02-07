/* @author: Timmy Henningsson */

#include "system.hpp"
#include "filter.hpp"
#include "entity.hpp"
#include <algorithm>

using namespace tecs;
using namespace std;


System::System(const Filter& filter)
  : m_filter(filter)
{}


System::EntityMap System::get_entities()
{
  return m_entities;
}

Filter System::get_filter() const
{
  return m_filter;
}

void System::set_filter(const Filter& filter)
{
  m_filter = filter;
}

void System::populate(const EntityMap& entities)
{
  clear();

  for(auto p : entities)
    {
      if(m_filter.passes_filter(p.second))
	m_entities.insert(p);
    }
}

void System::populate(Entity *entity)
{
  if(m_filter.passes_filter(entity))
     m_entities[entity->get_id()] = entity;
}


void System::clear()
{
  m_entities.clear();
}
