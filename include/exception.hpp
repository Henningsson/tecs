/* @author: Timmy Henningsson
 *
 * All exception thrown by the library
 * will be of this type
 */
#ifndef EXCEPTION_H_
#define EXCEPTION_H_

#include <exception>

namespace tecs
{

  class Exception : public std::exception
  {
  public:
    Exception(std::string msg) : m_msg()
    {}

    virtual const char *what() const throw()
    { return m_msg.c_str();  }

  private:
    std::string m_msg;
  };

}

#endif //ENGINEEXCEPTION_H_
