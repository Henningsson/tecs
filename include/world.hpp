/* @author: Timmy Henningsson 
 *
 * Container class for all entities and all systems
 * handles memory allocation and deallocation.
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <unordered_map>
#include <type_traits>

#include "component.hpp"
#include "entity.hpp"
#include "system.hpp"
#include "id.hpp"

namespace tecs
{

  class World
  {
  public:

    using EntityMap = std::unordered_map<Id, Entity*>;
    using SystemMap = std::unordered_map<Id, SystemBase*>;

    World() = default;
    virtual ~World();

    World(const World&)            = delete;
    World(World&&)                 = delete;
    World& operator=(const World&) = delete;
    World& operator=(World&&)      = delete;

    template<typename T = Entity>
    T* create_entity();

    template<typename T>
    T* create_system();

    template<typename T>
    bool has_system();
    
    template<typename T>
    void remove_system();
    void remove_system(const Id& id);

    void remove_entity(Entity *entity);
    void remove_entity(const Id& id);

    template<typename T>
    SystemBase* get_system();
    SystemBase* get_system(const Id& id);

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
    e->set_world(this);
    m_entities[e->get_id()] = e;

    populate_systems(e);

    return e;
  }

  template<typename T>
  T* World::create_system()
  {
    static_assert(std::is_base_of<SystemBase, T>::value,
		  "Template parameter is not a base of System");

    if(!has_system<T>()) //Systems are unique and can only exist in one instance
      {
	auto s = new T();
	m_systems[s->get_typeid()] = s;;

	s->populate(m_entities);

	return s;
      }

    return nullptr;
  }

  template<typename T>
  bool World::has_system()
  {
    return m_systems.find(SystemId::get<T>()) != m_systems.end();
  }

  template<typename T>
  void World::remove_system()
  {
    remove_system(SystemId::get<T>());
  }

  template<typename T>
  SystemBase* World::get_system()
  {
    return get_system(SystemId::get<T>());
  }


}

#endif //WORLD_HPP_
