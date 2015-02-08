/* @author: Timmy Henningsson  */
#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <unordered_map>
#include <vector>
#include <string>

#include "filter.hpp"
#include "instanceid.hpp"

namespace tecs
{
  class World;
  class Entity;

  class System : public InstanceId<System>
  {
  public:

    using EntityMap    = std::unordered_map<Id, Entity*>;
    using EntityVector = std::vector<Entity*>;

    System() = default;
    System(const Filter& filter);

    virtual ~System() = default;

    EntityVector get_entities();
    Filter       get_filter() const;

    void set_filter(const Filter& filter);

    void populate(const EntityMap& entities);
    void populate(Entity *entity);

    void clear();

  private:
    Filter    m_filter;
    EntityMap m_entities;
  };

}


#endif //SYSTEM_HPP_
