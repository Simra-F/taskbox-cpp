# Storage API (`include/storage.h`)

| Function | Does |
|---|---|
| `loadTasks(path)` | returns the tasks (empty if the file does not exist) |
| `saveTasks(tasks, path)` | writes the tasks |
| `addTask(title, path)` | appends a task and returns it |
| `toggleTask(id, path)` | flips `done` |
| `removeTask(id, path)` | deletes a task |

File format: one task per line, `id<TAB>done<TAB>createdAt<TAB>title`. Nothing outside src/storage.cpp may open the file.
