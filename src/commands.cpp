#include "commands.h"

#include <iostream>

#include "filters.h"
#include "format.h"
#include "storage.h"

int handleAdd(const std::vector<std::string>& args, const std::string& path) {
    std::string title;
    for (const std::string& a : args) title += (title.empty() ? "" : " ") + a;
    Task task = addTask(title, path);
    std::cout << "Added " << task.id << ": " << task.title << "\n";
    return 0;
}

int handleList(const std::vector<std::string>& args, const std::string& path) {
    std::vector<Task> tasks = loadTasks(path);
    for (const Task& t : applyFilter(tasks, args.empty() ? "all" : args[0])) std::cout << formatTask(t) << "\n";
    std::cout << pluralize(countRemaining(tasks), "task") << " left\n";
    return 0;
}

int handleClear(const std::vector<std::string>& args, const std::string& path) {
    (void)args;
    saveTasks({}, path);
    std::cout << "Cleared all tasks\n";
    return 0;
}

const std::map<std::string, CommandFn> COMMANDS = {
    {"add", handleAdd},
    {"list", handleList},
    {"clear", handleClear},
};
