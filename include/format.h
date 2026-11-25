#pragma once
#include <string>

#include "task.h"

std::string formatDate(long long epochMillis);
std::string pluralize(int n, const std::string& word);
std::string formatTask(const Task& task);
