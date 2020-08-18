//
// ... Testing header files
//
#include <gtest/gtest.h>
#include <multigrid_testing/test_macros.hpp>

//
// ... Multigrid header files
//
#include <multigrid/details/Root.hpp>
#include <multigrid/details/Origin.hpp>
#include <multigrid/details/Spacing.hpp>
#include <multigrid/details/Offset.hpp>
#include <multigrid/details/FixedShape.hpp>
#include <multigrid/details/FixedHalo.hpp>
#include <multigrid/details/FixedSubgrid.hpp>


namespace Multigrid::Testing
{
  namespace
  {
    using ::Multigrid::Details::Origin;
    using ::Multigrid::Details::Spacing;
    using ::Multigrid::Details::Root;
    using ::Multigrid::Details::Offset;
    using ::Multigrid::Details::fixed_shape;
    using ::Multigrid::Details::fixed_halo;
    using ::Multigrid::Details::FixedShape;
    using ::Multigrid::Details::FixedHalo;
    using ::Multigrid::Details::FixedSubgrid;
  }
  TEST(FixedSubgrid, Construction){
    FixedSubgrid  sgrid(
      Root(Origin(0.0, 0.0), Spacing(1.0, 1.0)),
      Offset(0, 0),
      fixed_shape<16,16>,
      fixed_halo<1,1>,
      0);
  }

  TEST(FixedSubgrid, Access){
    ASSERT_TRUE(false);
  }
} // end of namespace Multigrid::Testing
