#pragma once
#include <string>
#include <vector>

#include "task.h"

extern const char* const STORAGE_PATH;

std::vector<Task> loadTasks(const std::string& path);
void saveTasks(const std::vector<Task>& tasks, const std::string& path);
Task addTask(const std::string& title, const std::string& path);
void toggleTask(int id, const std::string& path);
void removeTask(int id, const std::string& path);
