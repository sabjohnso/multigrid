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
  class Spacing
    : Vec<T,NDims>
    , public Euclidean<Spacing<T,NDims>, Nat<NDims>>
  {
    using base = Vec<T,NDims>;
  public:
    using base::base;
    using base::operator[];
    using base::size;
  }; // end of class Spacing

  template<typename T1, typename T2, typename ... Ts>
  Spacing(T1 x1, T2 x2, Ts ... xs) -> Spacing<common_type_t<T1,T2,Ts...>, count_types<T1,T2,Ts ...>()>;

} // end of namespace Multigrid::Details
