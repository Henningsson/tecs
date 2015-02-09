/* @author: Timmy Henningsson */
#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <unordered_map>
#include <type_traits>
#include <typeinfo>

#include "typeid.hpp"
#include "component.hpp"
#include "instanceid.hpp"



namespace tecs
{
  class World;

  class Entity : public InstanceId<Entity>
  {
  public:

    using ComponentMap  = std::unordered_map<Id, ComponentBase*>;

    Entity() = default;
    ~Entity();

    template<typename T>
    T* add_component();

    template<typename T>
    void remove_component();

    void remove_all_components();

    template<typename T>
    T* get_component();

    template<typename T>
    bool has_component() const;

    bool has_component(const Id& id) const;

    ComponentMap get_components();

  private:
    ComponentMap m_components;
  };


  template<typename T>
  T* Entity::add_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value, 
		  "Template parameter is not a base of tecs::Component");

    auto c = new T();
    m_components[c->get_typeid()] = c;

    return c;
  }

  template<typename T>
  void Entity::remove_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");

    Id id = ComponentId::get<T>();
    auto component = m_components[id];
    
    m_components.erase(id);
    delete component;
  }

  template<typename T>
  T* Entity::get_component()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");

    Id id   = ComponentId::get<T>();
    auto it = m_components.find(id);

    if(it == m_components.end())
      return nullptr;
    else
      return *it;
  }

  template<typename T>
  bool Entity::has_component() const
  {
    return get_component<T>() != nullptr;
  }

}


#endif //ENTITY_HPP_
