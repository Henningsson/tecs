#include "tecs.hpp"

using namespace tecs;

struct Character : public Entity
{
};

struct Health : public Component<Health>
{
  int amount;
};

struct Mana : public Component<Mana>
{
  int amount;
};


int main()
{
  World world;

  auto character = world.create_entity<Character>();

  auto health = c->add_component<Health>();
  health->amount = 100;
  
  auto mana = c->add_component<Mana>();
  mana->amount = 100;

  
  


  return 0;
}

