#include "format.h"
#include "test.h"

TEST(pluralize_words) {
    CHECK_EQ(pluralize(1, "task"), std::string("1 task"));
    CHECK_EQ(pluralize(3, "task"), std::string("3 tasks"));
}

TEST(format_task_line) { CHECK_EQ(formatTask({2, "b", true, 0}), std::string("[x] 2: b")); }
