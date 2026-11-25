#include "storage.h"

#include <algorithm>
#include <chrono>
#include <fstream>
#include <sstream>

const char* const STORAGE_PATH = "tasks.tsv";

std::vector<Task> loadTasks(const std::string& path) {
    std::vector<Task> tasks;
    std::ifstream in(path);
    std::string line;
    while (std::getline(in, line)) {
        if (line.empty()) continue;
        std::istringstream fields(line);
        std::string id, done, created, title;
        std::getline(fields, id, '\t');
        std::getline(fields, done, '\t');
        std::getline(fields, created, '\t');
        std::getline(fields, title);
        tasks.push_back({std::stoi(id), title, done == "1", std::stoll(created)});
    }
    return tasks;
}

void saveTasks(const std::vector<Task>& tasks, const std::string& path) {
    std::ofstream out(path, std::ios::trunc);
    for (const Task& t : tasks) {
        out << t.id << '\t' << (t.done ? "1" : "0") << '\t' << t.createdAt << '\t' << t.title << '\n';
    }
}

Task addTask(const std::string& title, const std::string& path) {
    std::vector<Task> tasks = loadTasks(path);
    int next = 1;
    for (const Task& t : tasks) next = std::max(next, t.id + 1);
    long long now = std::chrono::duration_cast<std::chrono::milliseconds>(
                        std::chrono::system_clock::now().time_since_epoch()).count();
    Task task{next, title, false, now};
    tasks.push_back(task);
    saveTasks(tasks, path);
    return task;
}

void toggleTask(int id, const std::string& path) {
    std::vector<Task> tasks = loadTasks(path);
    for (Task& t : tasks) {
        if (t.id == id) t.done = !t.done;
    }
    saveTasks(tasks, path);
}

void removeTask(int id, const std::string& path) {
    std::vector<Task> tasks = loadTasks(path);
    tasks.erase(std::remove_if(tasks.begin(), tasks.end(), [id](const Task& t) { return t.id == id; }), tasks.end());
    saveTasks(tasks, path);
}
