#ifndef TECS_HPP_
#define TECS_HPP_

// TODO(Timmy):
// ifall man tar bort en komponent på entities måste systemen om populeras..
// behöver nog lösas genom att ha en pekare till världen i alla entities..
//
// Göra System och Entity till friend klasser till World?? och enbart tillåta
// dom att konstrueras av World? ( sätta alla konstruktorer som private )


#include "world.hpp"
#include "entity.hpp"
#include "system.hpp"
#include "component.hpp"

#endif //TECS_HPP_
