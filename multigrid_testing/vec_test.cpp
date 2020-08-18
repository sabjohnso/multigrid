//
// ... Standard header files
//
#include <type_traits>

//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>

//
// ... External header files
//
#include <type_utility/type_utility.hpp>

//
// ... Multigrid header files
//
#include <multigrid/details/Vec.hpp>

namespace Multigrid::Testing
{
  namespace
  {
    using std::decay_t;
    using std::is_same_v;

    using TypeUtility::nat;

    using Multigrid::Details::Vec;
  }

  TEST(Vec2, Construction){
    constexpr auto a = 1.0;
    constexpr auto b = 2.0;
    constexpr Vec v(1.0, 2.0);

    STATIC_EXPECT_TRUE(is_same_v<decltype(v), const Vec<double,2>>);

    STATIC_EXPECT_EQ(v[0], a);
    STATIC_EXPECT_EQ(v[1], b);

    STATIC_EXPECT_EQ(v[nat<0>], a);
    STATIC_EXPECT_EQ(v[nat<1>], b);

    STATIC_EXPECT_EQ(std::get<0>(v), a);
    STATIC_EXPECT_EQ(std::get<1>(v), b);
  }

  TEST(Vec3, Size){
    constexpr auto a = 1.0;
    constexpr auto b = 2.0;
    constexpr auto c = 3.0;
    constexpr Vec v(1.0, 2.0, 3.0);

    STATIC_EXPECT_TRUE(is_same_v<decltype(v), const Vec<double,3>>);

    STATIC_EXPECT_EQ(v.size(), 3);
  }


} // end of namespace Multigrid::Testing
