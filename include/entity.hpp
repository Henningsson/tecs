/* @author: Timmy Henningsson */
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <type_traits>
#include <typeinfo>

#include "typeid.hpp"



namespace tecs
{

  template<typename T>
  class Component;
  class ComponentBase;
  class World;

  class Entity
  {
  public:

    using ComponentVector = std::vector<ComponentBase*>;

    Entity()  = default;
    ~Entity() = default;

    template<typename T>
    T* add_component();

    template<typename T>
    void remove_component();

    template<typename T>
    T* get_component();

    ComponentVector get_components();

  private:
    ComponentVector m_components;
  };


  template<typename T>
  T* Entity::add_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value, 
		  "Template parameter is not a base of tecs::Component");

    auto c = new T();
    m_components.push_back(c);

    return c;
  }

  template<typename T>
  void Entity::remove_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");

    auto it = m_components.begin();
    for( ; it != m_components.end(); ++it)
      {
	if(typeid(*it) == typeid(T*))
	  break;
      }

    if(it != m_components.end())
      {
	delete *it;
	m_components.erase(it);
      }
  }

  template<typename T>
  T* Entity::get_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");

    for(auto it = m_components.begin(); it != m_components.end(); ++it)
      {
	if(typeid(*it) == typeid(T*))
	  return *it;
      }
    
    return nullptr;
  }

}


#endif //ENTITY_HPP_
