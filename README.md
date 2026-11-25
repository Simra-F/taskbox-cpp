# Taskbox (C++)

<!-- tagline -->A tiny task list for your terminal.<!-- /tagline -->

Plain C++17 and the standard library, tasks stored in a local tab-separated file, no dependencies.

**Last change:** <!-- last-change -->initial import<!-- /last-change -->

## Features
- Add, complete, list and clear tasks
- Filters: all / active / done

## Project layout
| Path | What it is |
|---|---|
| `include/storage.h`, `src/storage.cpp` | storage API (all task persistence goes here) - see `docs/storage-api.md` |
| `include/commands.h`, `src/commands.cpp` | command handlers and the `COMMANDS` registry |
| `include/filters.h`, `include/format.h` | filters and formatting helpers |
| `app/main.cpp` | the `taskbox` executable |
| `tests/` | tests (`tests/test.h` is a tiny test framework) |

## Development
```bash
./run-tests.sh                                   # build and run the tests
c++ -std=c++17 -Iinclude src/*.cpp app/main.cpp -o taskbox && ./taskbox add "Write the README"
# or: cmake -B build && cmake --build build && ctest --test-dir build
```

## Contributing
See [CONTRIBUTING.md](CONTRIBUTING.md). Please follow the [Code of Conduct](CODE_OF_CONDUCT.md).
