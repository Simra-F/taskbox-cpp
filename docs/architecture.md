# Architecture

```
app/main.cpp        parses arguments, looks the command up in COMMANDS, runs it
src/commands.cpp    one handler per command, and the COMMANDS registry
src/storage.cpp     the only file that reads or writes the tasks file
src/filters.cpp     pure functions over task lists
src/format.cpp      pure formatting helpers
include/task.h      struct Task { id, title, done, createdAt }
```
Every public function is declared in a header in include/ and defined in the matching file in src/.
