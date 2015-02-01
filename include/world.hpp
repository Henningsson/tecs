/* @author: Timmy Henningsson 
 *
 * Container class for all entities and all systems
 * handles memory allocation and deallocation.
 */
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <vector>
#include "entity.hpp"
#include "componentsystem.hpp"
#include "component.hpp"

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
    //ADD(Timmy): Make sure the type is derived from Entity
    auto entity = new T();
    m_entities.push_back(entity);

    return entity;
  }

  template<class T>
  T* World::create_system()
  {
    //ADD(Timmy): Make sure the type is derived from ComponentSystem
    auto system = new T();
    m_systems.push_back(system);

    return system;
  }

}

#endif //WORLD_HPP_
