/* @author: Timmy Henningsson */
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <typeinfo>
#include <algorithm>
#include <exception>


//NOTE(Timmy): Dummyclass while testing

namespace tecs
{

  template<class T>
  class Component;
  class ComponentBase;
  class World;

  class Entity
  {
  public:

    using ComponentVector = std::vector<ComponentBase*>;

    Entity()  = default;
    ~Entity() = default;

    ComponentVector get_components();

  private:
    ComponentVector m_components;
  };

}


#endif //ENTITY_HPP_
