#pragma once

//
// ... Standard header files
//
#include <cstdint>
#include <utility>
#include <type_traits>
#include <array>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>


namespace Multigrid::Details
{
  using integer = std::ptrdiff_t;
  using size_type = std::size_t;

  using std::common_type_t;

  using std::forward;
  using std::move;
  using std::get;
  using std::array;

  using TypeUtility::nat;
  using TypeUtility::Nat;
  using TypeUtility::CRTP;
  using TypeUtility::count_types;
  using TypeUtility::count_args;
  using TypeUtility::generate_indices;

  template<size_t ... Indices>
  using Nats = std::index_sequence<Indices ...>;

} // end of namespace Multigrid::Details
