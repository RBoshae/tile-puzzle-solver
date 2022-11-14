#pragma once

#include <cmath>

namespace Validate {

template <typename T>
bool IsSquare(T _value) {
  
  if (_value < 0) 
    return false;

  double quotient, remainder; 
  remainder= std::modf(static_cast<double>(_value),&quotient); 

  if (remainder == 0)
    return true;

  return false; 
}
template<int>
template<unsigned int>

}
