#pragma once

#define MG_QUOTE_AUX(...) #__VA_ARGS__
#define MG_QUOTE(...) MG_QUOTE_AUX(__VA_ARGS__)

#define MG_EXPECT_TRUE_MSG(...) "Expected the expression " MG_QUOTE(__VA_ARGS__) " to be true."
#define MG_EXPECT_FALSE_MSG(...) "Expected the expression "  MG_QUOTE(__VA_ARGS__) " to be false."
#define MG_EXPECT_EQUAL_MSG(a, b) "Expected the expressions " MG_QUOTE(a) " and " MG_QUOTE(b) " equal."

#define STATIC_EXPECT_TRUE(...)                 \
  [=]{                                          \
    static_assert(                              \
      bool(__VA_ARGS__),                        \
      MG_EXPECT_TRUE_MSG(__VA_ARGS__));         \
    EXPECT_TRUE((__VA_ARGS__));                 \
  }()

#define STATIC_EXPECT_FALSE(...)                   \
  [=]{                                             \
    static_assert(                                 \
      ! bool(__VA_ARGS__),                         \
      MG_EXPECT_FALSE_MSG(__VA_ARGS__));           \
    EXPECT_FALSE((__VA_ARGS__));                   \
  }()

#define STATIC_EXPECT_EQ(a, b)                    \
  [=]{                                               \
    static_assert(                                   \
      (a) == (b),                                    \
      MG_EXPECT_EQUAL_MSG(a, b));                    \
    EXPECT_EQ((a), (b));                             \
  }()
