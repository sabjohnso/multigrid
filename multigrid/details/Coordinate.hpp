#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Vec.hpp>
#include <multigrid/details/Euclidean.hpp>


namespace Multigrid::Details
{

  template<typename T, size_type NDims>
  class Coordinate
    : Vec<T,NDims>
    , public Euclidean<Coordinate<T,NDims>, Nat<NDims>>
  {
    using base = Vec<T,NDims>;
  public:
    using base::base;
    using base::operator[];
    using base::size;
  }; // end of class Coordinate

  template<typename T, typename ... Ts>
  Coordinate(T x, Ts ... xs) -> Coordinate<common_type_t<T, Ts ...>, count_types<T, Ts ...>()>;

} // end of namespace Multigrid::Details
