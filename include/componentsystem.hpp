/* @author: Timmy Henningsson
 *
 * Base class for all ComponentSystems
 */
#ifndef COMPONENTSYSTEM_HPP_
#define COMPONENTSYSTEM_HPP_

#include "componentfilter.hpp"
#include <vector>
#include <string>

namespace tecs
{
  class World;
  class Entity;

  class ComponentSystem
  {
  public:

    ComponentSystem() = default;
    ComponentSystem(const ComponentFilter& filter);

    virtual ~ComponentSystem() = default;

    std::vector<Entity*>  get_entities();
    ComponentFilter       get_filter() const;

    void clear();

  private:
    ComponentFilter      m_filter;
    std::vector<Entity*> m_entities;
  };

}


#endif //COMPONENTSYSTEM_H_
