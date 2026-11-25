#include <cstdio>

#include "storage.h"
#include "test.h"

TEST(add_and_load) {
    const std::string path = "build/test_tasks_1.tsv";
    std::remove(path.c_str());
    addTask("Write docs", path);
    std::vector<Task> tasks = loadTasks(path);
    CHECK_EQ(tasks.size(), 1u);
    CHECK_EQ(tasks[0].title, std::string("Write docs"));
}

TEST(toggle_and_remove) {
    const std::string path = "build/test_tasks_2.tsv";
    std::remove(path.c_str());
    Task task = addTask("A", path);
    toggleTask(task.id, path);
    CHECK(loadTasks(path)[0].done);
    removeTask(task.id, path);
    CHECK(loadTasks(path).empty());
}
