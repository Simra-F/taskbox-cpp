#pragma once
#include <map>
#include <string>
#include <vector>

using CommandFn = int (*)(const std::vector<std::string>& args, const std::string& path);

int handleAdd(const std::vector<std::string>& args, const std::string& path);
int handleList(const std::vector<std::string>& args, const std::string& path);
int handleClear(const std::vector<std::string>& args, const std::string& path);

extern const std::map<std::string, CommandFn> COMMANDS;
