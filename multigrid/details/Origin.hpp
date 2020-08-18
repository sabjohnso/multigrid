#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Vec.hpp>
#include <multigrid/details/Euclidean.hpp>
#include <multigrid/details/Coordinate.hpp>

namespace Multigrid::Details
{

  template<typename T, size_type NDims>
  class Origin
    : Vec<T,NDims>
    , public Euclidean<Origin<T,NDims>, Nat<NDims>>
  {
    using base = Vec<T,NDims>;
  public:
    using coordinate_type = Coordinate<T,NDims>;
    using base::base;
    using base::operator[];
    using base::size;

    constexpr
    Origin(coordinate_type const& x)
      : Origin(coordinate_to_origin(generate_indices<NDims>(), x))
    {}

    constexpr
    operator coordinate_type() const {
      return origin_to_coordinate(generate_indices<NDims>(), *this);
    }

  private:

    template<size_type ... Indices>
    static constexpr coordinate_type
    origin_to_coordinate(Nats<Indices ...>, Origin const& x){
      return {x[Indices] ... };
    }

    template<size_type ... Indices>
    static constexpr Origin
    coordinate_to_origin(Nats<Indices ...>, coordinate_type const& x){
      return {x[Indices] ...};
    }

  }; // end of class Origin


  template<typename T1, typename T2, typename ... Ts>
  Origin(T1 x1, T2 x2, Ts ... xs) -> Origin<common_type_t<T1,T2,Ts...>, count_types<T1,T2,Ts...>()>;


} // end of namespace Multigrid::Details
