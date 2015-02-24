#include <tecs/tecs.hpp>


struct DerivedEntity : public tecs::Entity
{

};

struct DerivedSystem : public tecs::System<DerivedSystem>
{

};

struct DerivedComponent : public tecs::Component<DerivedComponent>
{
  int value;
};

int main()
{
  tecs::World   world;

  auto e = world.create_entity<DerivedEntity>();

  auto c = e->get_component<DerivedComponent>();

  // e->remove_component<Health>();
  
}
