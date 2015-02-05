/* @author: Timmy Henningsson 
 *
 * Container class for all entities and all systems
 * handles memory allocation and deallocation.
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <vector>
#include <type_traits>

#include "entity.hpp"
#include "component.hpp"
#include "componentsystem.hpp"

namespace tecs
{

  class World
  {
  public:

    World() = default;
    virtual ~World();

    World(const World&)            = delete;
    World(World&&)                 = delete;
    World& operator=(const World&) = delete;
    World& operator=(World&&)      = delete;

    template<class T>
    T* create_entity();
    
    void remove_entity(Entity *entity);

    template<class T>
    T* create_system();
    
    void remove_system(ComponentSystem *system);

  private:

    std::vector<Entity*>          m_entities;
    std::vector<ComponentSystem*> m_systems;
  };


  template<class T>
  T* World::create_entity()
  {
    static_assert(std::is_base_of<Entity, T>::value,
		  "Template parameter is not a base of Entity");

    auto e = new T();
    m_entities.push_back(e);

    return e;
  }

  template<class T>
  T* World::create_system()
  {
    static_assert(std::is_base_of<ComponentSystem, T>::value,
		  "Template parameter is not a base of ComponentSystem");

    //ADD(Timmy): Only one instance of each system type allowed

    auto system = new T();
    m_systems.push_back(system);

    return system;
  }

}

#endif //WORLD_HPP_
