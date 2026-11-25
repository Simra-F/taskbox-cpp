# Contributing to Taskbox

Thanks for helping! Small, focused pull requests are easiest to review.

## Rules
- No third-party libraries: C++17 and the standard library only.
- All task persistence goes through the functions declared in include/storage.h (loadTasks, saveTasks, addTask, toggleTask, removeTask). Never read or write the tasks file anywhere else.
- Every CLI command must be registered in COMMANDS in src/commands.cpp.
- Declare public functions in a header in include/ and define them in a matching .cpp file in src/; `./run-tests.sh` compiles every file in src/ and tests/.
- Tests live in tests/ as *_test.cpp files using `TEST(name)` and `CHECK(...)` / `CHECK_EQ(a, b)` from tests/test.h.
- Add new tests in a new test file; never delete or rewrite existing functions or tests.

## Workflow
1. Open or pick an issue (look for `good first issue`).
2. Branch from `main`, keep the change focused, update docs/ if you change an API.
3. Run `./run-tests.sh` and open a pull request using the template.
4. A maintainer reviews; CI must be green before merge.
