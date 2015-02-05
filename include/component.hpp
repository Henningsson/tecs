/* @author: Timmy Henningsson  */
#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "typeid.hpp"

namespace tecs
{
  class ComponentBase
  {
  public:
    ComponentBase()          = default;
    virtual ~ComponentBase() = default;
  };

  template<class T>
  class Component : public ComponentBase
  {
  public:
    
    using value_type  = T;
    using ComponentId = TypeId<ComponentBase>;

    Component()          = default;
    virtual ~Component() = default;

    Id get_typeid() const
    {
      return ComponentId::get<T>();
    }
  };

}

#endif //COMPONENT_HPP_
