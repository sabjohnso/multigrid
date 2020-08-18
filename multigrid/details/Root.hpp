#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Origin.hpp>
#include <multigrid/details/Spacing.hpp>


namespace Multigrid::Details
{
  template<typename T, size_type NDims>
  class Root
  {
    using origin_type = Origin<T,NDims>;
    using spacing_type = Spacing<T,NDims>;

    origin_type origin_;
    spacing_type spacing_;

  public:
    constexpr
    Root(origin_type origin, spacing_type spacing)
      : origin_(move(origin))
      , spacing_(move(spacing))
    {}

    constexpr spacing_type
    spacing() const { return spacing_; }

    constexpr origin_type
    origin() const { return origin_; }

  }; // end of class Root

  template<typename T, size_type N>
  Root(Origin<T,N> origin, Spacing<T,N> spacing) -> Root<T,N>;

} // end of namespace Multigrid::Details
