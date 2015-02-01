/* @author: Timmy Henningsson
 *
 * Used for filtering out entities which does
 * not fit a system
 */
#ifndef COMPONENTFILTER_HPP_
#define COMPONENTFILTER_HPP_

namespace tecs
{
  template<class T>
  class Component;
  class Entity;

  //TODO(Timmy): Dummycode while testing..

  class ComponentFilter
  {
  public:
    ComponentFilter()  = default;
    ~ComponentFilter() = default;


    bool passes_filter(const Entity* entity) const;
  };

}

#endif //COMPONENTFILTER_H_
