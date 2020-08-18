//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>

//
// ... Multigrid header files
//
#include <multigrid/details/Origin.hpp>


namespace Multigrid::Testing
{
  namespace
  {
    using ::Multigrid::Details::Origin;
    using ::Multigrid::Details::Coordinate;
  }

  TEST(Origin, Construction)
  {
    constexpr Origin x(0.0, 1.0, 2.0);
    STATIC_EXPECT_EQ(x[0], 0.0);
    STATIC_EXPECT_EQ(x[1], 1.0);
    STATIC_EXPECT_EQ(x[2], 2.0);
  }

  TEST(Origin, ToCoordinate)
  {
    constexpr Origin x(0.0, 1.0, 2.0);
    constexpr Coordinate<double,3> y = x;
    STATIC_EXPECT_EQ(x[0], y[0]);
    STATIC_EXPECT_EQ(x[1], y[1]);
    STATIC_EXPECT_EQ(x[2], y[2]);
  }

  TEST(Origin, FromCoordinate)
  {
    constexpr Coordinate x(0.0, 1.0, 2.0);
    constexpr Origin<double,3> y = x;

    STATIC_EXPECT_EQ(x[0], y[0]);
    STATIC_EXPECT_EQ(x[1], y[1]);
    STATIC_EXPECT_EQ(x[2], y[2]);
  }


} // end of namespace Multigrid::Testing
