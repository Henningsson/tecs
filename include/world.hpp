/* @author: Timmy Henningsson 
 *
 * Container class for all entities and all systems
 * handles memory allocation and deallocation.
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <unordered_map>
#include <type_traits>

#include "entity.hpp"
#include "component.hpp"
#include "system.hpp"
#include "id.hpp"

namespace tecs
{

  class World
  {
  public:

    using EntityMap = std::unordered_map<Id, Entity*>;
    using SystemMap = std::unordered_map<Id, System*>;

    World() = default;
    virtual ~World();

    World(const World&)            = delete;
    World(World&&)                 = delete;
    World& operator=(const World&) = delete;
    World& operator=(World&&)      = delete;

    template<class T>
    T* create_entity();

    template<typename T>
    T* create_system();

    template<typename T>
    bool has_system();
    
    void remove_system(System *system);
    void remove_system(const Id& id);

    void remove_entity(Entity *entity);
    void remove_entity(const Id& id);

    System* get_system(const Id& id);

    Entity* get_entity(const Id& id);

    void populate_systems();

  private:

    EntityMap m_entities;
    SystemMap m_systems;

    void populate_systems(Entity *entity);
  };


  template<typename T>
  T* World::create_entity()
  {
    static_assert(std::is_base_of<Entity, T>::value,
		  "Template parameter is not a base of Entity");

    auto e = new T();
    m_entities[e->get_id()] = e;

    //Add the entity to the appropiate systems
    populate_systems(e);

    return e;
  }

  template<typename T>
  T* World::create_system()
  {
    static_assert(std::is_base_of<System, T>::value,
		  "Template parameter is not a base of ComponentSystem");

    if(!has_system<T>()) //Systems are unique and can only exist in one instance
      {
	auto s = new T();
	m_systems[s->get_id()] = s;;

	//Add the approipate entities to the system
	s->populate(m_entities);

	return s;
      }

    return nullptr;
  }

  template<typename T>
  bool World::has_system()
  {
    for(auto s : m_systems)
      {
	if(typeid(s) == typeid(T*))
	  return true;
      }

    return false;
  }

}

#endif //WORLD_HPP_
