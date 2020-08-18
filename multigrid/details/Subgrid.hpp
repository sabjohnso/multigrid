#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Root.hpp>
#include <multigrid/details/Offset.hpp>
#include <multigrid/details/Shape.hpp>
#include <multigrid/details/Halo.hpp>


namespace Multigrid::Details
{
  template<typename T, size_type NDims>
  class Subgrid
  {
    using root_type = Root<T,NDims>;
    using offset_type = Offset<NDims>;

    root_type root_;
    offset_type offset_;
    shape_type shape_;
    halo_type halo_;
    integer level_;

  public:

    constexpr
    Subgrid(root_type root, offset_type offset, shape_type shape, halo_type halo, integer level)
      : root_(move(root))
      , offset_(move(offset))
      , shape_(move(shape))
      , halo_(move(halo))
      , level_(level)
    {}

    constexpr root_type
    root(){ return root_; }

    constexpr offset_type
    offset(){ return offset_; }

    constexpr shape_type
    shape(){ return shape_; }

    constexpr halo_type
    halo(){ return halo_; }

    constexpr integer
    level(){ return level_; }

  }; // end of class Subgrid;
} // end of namespace Multigrid::Details
