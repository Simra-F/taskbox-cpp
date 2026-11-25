#include "format.h"

#include <ctime>

std::string formatDate(long long epochMillis) {
    std::time_t seconds = static_cast<std::time_t>(epochMillis / 1000);
    char buf[16];
    std::strftime(buf, sizeof buf, "%Y-%m-%d", std::gmtime(&seconds));
    return buf;
}

std::string pluralize(int n, const std::string& word) {
    return std::to_string(n) + " " + word + (n == 1 ? "" : "s");
}

std::string formatTask(const Task& task) {
    return std::string(task.done ? "[x] " : "[ ] ") + std::to_string(task.id) + ": " + task.title;
}
