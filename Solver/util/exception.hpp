/**
* @author Tim Luchterhand
* @date 28.11.24
* @brief Not implemented exception
*/

#ifndef EXCEPTION_HPP
#define EXCEPTION_HPP

#include <stdexcept>
#include <string>

struct NotImplementedException : std::logic_error {
    NotImplementedException(const std::string &methodName = {});
};

#define NOT_IMPLEMENTED NotImplementedException(__PRETTY_FUNCTION__)


#endif //EXCEPTION_HPP
