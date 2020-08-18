//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>

//
// ... Multigrid header files
//
#include <multigrid/details/Coordinate.hpp>

namespace Multigrid::Testing
{
  namespace
  {
    using Multigrid::Details::Coordinate;
  }

  TEST(Coordinate, Construction){
    constexpr Coordinate x(1.0, 2.0, 3.0);
    STATIC_EXPECT_EQ(x[0], 1.0);
    STATIC_EXPECT_EQ(x[1], 2.0);
    STATIC_EXPECT_EQ(x[2], 3.0);
  }

  TEST(Coordinate, Addition){
    constexpr Coordinate x1(1.0, 2.0, 3.0);
    constexpr Coordinate x2(4.0, 5.0, 6.0);
    constexpr auto x3 = x1 + x2;
    STATIC_EXPECT_EQ(x3, Coordinate(x1[0]+x2[0], x1[1]+x2[1], x1[2]+x2[2]));
  }

  TEST(Coordinate, Subtraction){
    constexpr Coordinate x1(1.0, 2.0, 3.0);
    constexpr Coordinate x2(4.0, 5.0, 6.0);
    constexpr auto x3 = x1 - x2;
    STATIC_EXPECT_EQ(x3, Coordinate(x1[0]-x2[0], x1[1]-x2[1], x1[2]-x2[2]));
  }

  TEST(Coordinate, LeftScale){
    constexpr Coordinate x1(1.0, 2.0);
    constexpr auto x2 = 3.0*x1;
    STATIC_EXPECT_EQ(x2, Coordinate(3.0*x1[0], 3.0*x1[1]));
  }

  TEST(Coordinate, RightScale){
    constexpr Coordinate x1(1.0, 2.0);
    constexpr auto x2 = x1*3.0;
    STATIC_EXPECT_EQ(x2, Coordinate(3.0*x1[0], 3.0*x1[1]));
  }



} // end of namespace Multigrid::Testing
