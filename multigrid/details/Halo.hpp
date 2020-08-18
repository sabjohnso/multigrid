#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Vec.hpp>

namespace Multigrid::Details
{

  template<size_type NDims>
  class Halo
    : Vec<integer,NDims>
  {
    using base = Vec<integer, NDims>;
  public:
    using base::base;
    using base::operator[];
    using base::size;

  }; // end of class Halo

  template<typename T1, typename T2, typename ... Ts>
  Halo(T1 n1, T2 n2, Ts ... ns) -> Halo<count_types<T1, T2, Ts...>()>;

} // end of namespace Multigrid::Details
