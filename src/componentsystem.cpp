/* @author: Timmy Henningsson */

#include "componentsystem.hpp"
#include "componentfilter.hpp"
#include "entity.hpp"
#include <algorithm>

using namespace tecs;
using namespace std;


ComponentSystem::ComponentSystem(const ComponentFilter& filter)
  : m_filter(filter)
{}

vector<Entity*> ComponentSystem::get_entities()
{
  return m_entities;
}

ComponentFilter ComponentSystem::get_filter() const
{
  return m_filter;
}

void ComponentSystem::clear()
{
  m_entities.clear();
}
