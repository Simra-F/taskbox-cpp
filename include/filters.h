#pragma once
#include <string>
#include <vector>

#include "task.h"

extern const std::vector<std::string> FILTER_NAMES;

std::vector<Task> applyFilter(const std::vector<Task>& tasks, const std::string& name);
int countRemaining(const std::vector<Task>& tasks);
