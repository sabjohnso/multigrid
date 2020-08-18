#pragma once
//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Halo.hpp>

namespace Multigrid::Details
{
  template<integer ... Sizes>
  class FixedHalo
  {
    static constexpr size_type NDims = count_args(Sizes...);
  public:
    static constexpr Halo<NDims> value{Sizes ...};
  }; // end of class Halo

  template<integer ... Sizes>
  constexpr FixedHalo<Sizes ...> fixed_halo{};
} // end of namespace Multigrid::Details
