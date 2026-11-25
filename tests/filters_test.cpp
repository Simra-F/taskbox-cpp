#include "filters.h"
#include "test.h"

static const std::vector<Task> TASKS = {{1, "a", false, 0}, {2, "b", true, 0}};

TEST(apply_filter) {
    CHECK_EQ(applyFilter(TASKS, "active")[0].id, 1);
    CHECK_EQ(applyFilter(TASKS, "done")[0].id, 2);
}

TEST(count_remaining) { CHECK_EQ(countRemaining(TASKS), 1); }
