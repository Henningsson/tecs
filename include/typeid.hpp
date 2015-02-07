/* @author: Timmy Henningsson
 *
 * Returns a unique id for each type of class
 */
#ifndef TYPEID_HPP_
#define TYPEID_HPP_

#include "id.hpp"

namespace tecs
{

  template<typename Base>
  class TypeId
  {
  public:
  
    template<class T>
    static Id get()
    {
      static const Id id = m_nextId++;
      return id;
    }

  private:
    static Id m_nextId;
  };

  template<typename Base>
  Id TypeId<Base>::m_nextId = 0;
}



#endif //TYPEID_HPP_
