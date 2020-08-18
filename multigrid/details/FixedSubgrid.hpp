#pragma once

//
// ...  Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Root.hpp>
#include <multigrid/details/Offset.hpp>
#include <multigrid/details/FixedShape.hpp>
#include <multigrid/details/FixedHalo.hpp>

namespace Multigrid::Details
{
  template<typename ...>
  class FixedSubgrid;

  template<typename T, integer ... Ns, integer ... NHs>
  class FixedSubgrid<T, FixedShape<Ns...>, FixedHalo<NHs...>>
  {
    static_assert(count_args(Ns...) == count_args(NHs...));

    static constexpr size_type NDims = count_args(Ns ...);

    using root_type = Root<T,NDims>;
    using offset_type = Offset<NDims>;
    using fixed_shape = FixedShape<Ns...>;
    using shape_type = Shape<NDims>;
    using fixed_halo = FixedHalo<NHs...>;
    using halo_type = Halo<NDims>;

    root_type root_;
    offset_type offset_;
    integer level_;

  public:

    constexpr
    FixedSubgrid(root_type root, offset_type offset, integer level)
      : root_(move(root))
      , offset_(move(offset))
      , level_(level)
    {}

    constexpr
    FixedSubgrid(root_type root, offset_type offset, fixed_shape, fixed_halo, integer level)
      : FixedSubgrid(root, offset, level)
    {}

    constexpr root_type
    root(){ return root_; }

    constexpr offset_type
    offset(){ return offset_; }

    constexpr shape_type
    shape(){ return fixed_shape::value; }

    constexpr halo_type
    halo(){ return fixed_halo::value; }

  }; // end of class FixedSubgrid

  template<typename T, size_type NDims, integer ... Ns, integer ... NHs>
  FixedSubgrid(
    Root<T,NDims> root,
    Offset<NDims> offset,
    FixedShape<Ns ...> shape,
    FixedHalo<NHs ...> halo,
    integer level)
    -> FixedSubgrid<T, FixedShape<Ns ...>, FixedHalo<NHs ...> >;

} // end of namespace Multigrid::Details
