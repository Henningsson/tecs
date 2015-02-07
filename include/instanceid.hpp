/* @author: Timmy Henningsson
 *
 * Unique id for each instance of a class
 */
#ifndef INSTANCEID_HPP_
#define INSTANCEID_HPP_

#include "id.hpp"

namespace tecs
{
  //NOTE(Timmy): Ids may theoretically run out (altough there are about 4294967295 of them..
  //             a better idea would be to assign id's from a pool or something, maybe use boost uuid

  template<typename T>
  class InstanceId
  {
  public:

    InstanceId()
    {
      static Id id = 0;
      m_id = id++;
    }
    
    virtual ~InstanceId() = default;

    Id get_id() const
    { return m_id; }

  private:
    Id m_id;
  };

}

#endif //INSTANEID_HPP_
