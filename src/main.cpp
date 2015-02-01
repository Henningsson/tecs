#include "tecs.hpp"

using namespace tecs;

struct DerivedEntity : Entity
{
};

struct DerivedSystem : ComponentSystem
{
};

int main()
{

  World world;
  
  auto e = world.create_entity<DerivedEntity>();
  auto s = world.create_system<DerivedSystem>();


  return 0;
}

