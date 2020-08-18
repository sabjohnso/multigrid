#pragma once

//
// ... MultiGrid header files
//
#include <multigrid/details/import.hpp>

namespace Multigrid::Details
{
  /**
   * @brief A class describing the data for a multidimensional
   * vector-like value.
   */
  template<typename T, size_type NDims>
  class Vec
  {
    array<T,NDims> values;
  public:

    using value_type = T;

    template<typename T1, typename T2, typename ... Ts>
    constexpr
    Vec(T1 x1, T2 x2, Ts ... xs)
      : values{{move(x1), move(x2), move(xs) ... }}
    {}

    constexpr auto
    operator [](integer index) const { return values[index]; }

    template<size_type Index>
    constexpr auto
    operator [](Nat<Index>) const {
      return get<Index>(values);
    }

    static constexpr integer
    size(){ return NDims; }

  private:

    template<size_type Index>
    friend constexpr auto
    get(Vec const& v, Nat<Index>){ return std::get<Index>(v.values); }


    template<typename ...>
    struct IndexHelper_;

    template<size_type ... Indices>
    struct IndexHelper_<Nats<Indices ...>>
    {
      static constexpr bool
      equal( Vec const& u, Vec const& v){
        return ((u[Indices] == v[Indices]) && ... && true);
      }
    }; // end of IndexHelper_;

    using IndexHelper = IndexHelper_<decltype(generate_indices<NDims>())>;

  }; // end of class Vec

  template<typename T, typename ... Ts>
  Vec(T x, Ts ... xs) -> Vec<common_type_t<T, Ts ...>, count_types<T,Ts ...>()>;

} // end of namespace Multigrid::Details

namespace std
{

  template<size_t Index, typename T, ::Multigrid::Details::size_type N>
  constexpr auto
  get(::Multigrid::Details::Vec<T,N> const& v){
    static_assert(Index < N);
    static_assert(Index >= 0);
    return v[::Multigrid::Details::nat<Index>];
  }
} // end of namespace std
