/* @author: Timmy Henningsson
 *
 * Used for filtering out entities which does
 * not fit a system
 */
#ifndef FILTER_HPP_
#define FILTER_HPP_

#include <unordered_map>
#include "typeid.hpp"
#include "component.hpp"


//TODO(Timmy): flesh out the filter.. add stuff like
//             excluded components, one of components etc

namespace tecs
{
  class Entity;


  class Filter
  {
  public:

    using ComponentMap = std::unordered_map<Id, bool>;

    Filter()  = default;
    ~Filter() = default;

    template<typename T>
    void add_required();

    template<typename T>
    void remove_required();

    bool passes_filter(const Entity* entity) const;

  private:
    
    ComponentMap m_required;
  };

  
  template<typename T>
  void Filter::add_required()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");
    
    m_required[ComponentId::get<T>()] = true;
  }

  template<typename T>
  void Filter::remove_required()
  {
    static_assert(std::is_base_of<Component<T>, T>::value,
		  "Template parameter is not a base of tecs::Component");
    
    m_required.erase(ComponentId::get<T>());
  }

}

#endif //FILTER_H_
