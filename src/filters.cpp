#include "filters.h"

const std::vector<std::string> FILTER_NAMES = {"all", "active", "done"};

std::vector<Task> applyFilter(const std::vector<Task>& tasks, const std::string& name) {
    std::vector<Task> out;
    for (const Task& t : tasks) {
        if (name == "active" ? !t.done : name == "done" ? t.done : true) out.push_back(t);
    }
    return out;
}

int countRemaining(const std::vector<Task>& tasks) {
    int n = 0;
    for (const Task& t : tasks) n += t.done ? 0 : 1;
    return n;
}
