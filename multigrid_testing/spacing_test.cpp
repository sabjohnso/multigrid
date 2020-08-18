//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>

//
// ... Multigrid header files
//
#include <multigrid/details/Spacing.hpp>
#include <multigrid/details/Coordinate.hpp>


namespace Multigrid::Testing
{
  namespace
  {
    using ::Multigrid::Details::Spacing;
  }

  TEST(Spacing, Construction)
  {
    constexpr Spacing dx(0.1, 0.2, 0.3);
    STATIC_EXPECT_EQ(dx[0], 0.1);
    STATIC_EXPECT_EQ(dx[1], 0.2);
    STATIC_EXPECT_EQ(dx[2], 0.3);
  }

} // end of namespace Multigrid::Testing
