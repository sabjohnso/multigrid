//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>


//
// ... Multigrid header files
//
#include <multigrid/details/Origin.hpp>
#include <multigrid/details/Spacing.hpp>
#include <multigrid/details/Root.hpp>

namespace Multigrid::Testing
{
  namespace
  {
    using ::Multigrid::Details::Origin;
    using ::Multigrid::Details::Spacing;
    using ::Multigrid::Details::Root;
  }

  TEST(Root, Construction){
    constexpr Root grid(Origin(0.0, 0.0), Spacing(0.1, 0.2));
    STATIC_EXPECT_EQ(grid.origin(), Origin(0.0, 0.0));
    STATIC_EXPECT_EQ(grid.spacing(), Spacing(0.1, 0.2));
  }

} // end of namespace Multigrid::Testing
