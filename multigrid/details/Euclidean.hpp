#pragma once

//
// ... Multigrid header files
//
#include <multigrid/details/import.hpp>
#include <multigrid/details/Vec.hpp>

namespace Multigrid::Details
{
  template<typename ...>
  class Euclidean;

  template<typename T, size_type N>
  class  Euclidean<T,Nat<N>> : public CRTP<Euclidean, T, Nat<N>>
  {
    friend constexpr bool
    operator ==(Euclidean const& u, Euclidean const& v)
    {
      return IndexHelper::equal(u, v);
    }

    friend constexpr bool
    operator !=(Euclidean const& u, Euclidean const& v){
      return !(u == v);
    }



    friend constexpr T
    operator +(Euclidean const& u, Euclidean const& v)
    {
      return IndexHelper::add(u, v);
    }

    friend constexpr T
    operator -(Euclidean const& u, Euclidean const& v)
    {
      return IndexHelper::sub(u, v);
    }

    template<typename Scalar>
    friend constexpr T
    operator *(Euclidean  const& u, Scalar s){
      return IndexHelper::scale(u, s);
    }

    template<typename Scalar>
    friend constexpr T
    operator *(Scalar s, Euclidean  const& u){
      return IndexHelper::scale(u, s);
    }

  private:

    template<typename ...>
    struct IndexHelper_;

    template<size_type ... Indices>
    struct IndexHelper_<Nats<Indices ...>>
    {
      static constexpr T
      add(T const&u, T const& v){
        return
          {u[Indices] + v[Indices] ...};
      }
      static constexpr T
      sub(T const&u, T const& v){
        return
          {u[Indices] - v[Indices] ...};
      }

      template<typename Scalar>
      static constexpr T
      scale(T const& u, Scalar s){
        return {u[Indices]*s ... };
      }

      static constexpr bool
      equal(T const& u, T const& v){
        return ((u[Indices] == v[Indices]) && ... && true);
      }
    }; // end of struct IndexHelper_

    using IndexHelper = IndexHelper_<decltype(generate_indices<N>())>;

  }; // end of class Euclidean
} // end of namespace Multigrid::Details
