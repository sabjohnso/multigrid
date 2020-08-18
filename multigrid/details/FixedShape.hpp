#pragma once
//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Shape.hpp>

namespace Multigrid::Details
{
  template<integer ... Sizes>
  class FixedShape
  {
    static constexpr size_type NDims = count_args(Sizes...);
  public:
    static constexpr Shape<NDims> value{Sizes ...};
  }; // end of class Shape

  template<integer ... Sizes>
  constexpr FixedShape<Sizes...> fixed_shape{};

} // end of namespace Multigrid::Details
