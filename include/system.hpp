/* @author: Timmy Henningsson  */
#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include <unordered_map>
#include <vector>
#include <string>

#include "filter.hpp"
#include "typeid.hpp"

namespace tecs
{
  class World;
  class Entity;

  class SystemBase
  {
  public:

    //Systems should be unique
    SystemBase(const SystemBase&)            = delete;
    SystemBase(SystemBase&&)                 = delete;
    SystemBase& operator=(const SystemBase&) = delete;
    SystemBase& operator=(SystemBase&&)      = delete;

    using EntityMap    = std::unordered_map<Id, Entity*>;
    using EntityVector = std::vector<Entity*>;

    EntityVector get_entities();
    Filter       get_filter() const;

    void set_filter(const Filter& filter);

    void populate(const EntityMap& entities);
    void populate(Entity *entity);

    void clear();

  protected:

    SystemBase() = default;
    SystemBase(const Filter& filter);
    virtual ~SystemBase() = default;

    Filter    m_filter;
    EntityMap m_entities;

    friend class World;
  };


  using SystemId = TypeId<SystemBase>;


  template<typename T>
  class System : public SystemBase
  {
  public:
    using value_type = T;

    virtual ~System() = default;

    Id get_typeid() const
    {
      return SystemId::get<T>();
    }

  protected:

    System() = default;
    System(const Filter& filter) : SystemBase(filter)
    {}

  };

}


#endif //SYSTEM_HPP_
