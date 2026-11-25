// A tiny test framework: TEST(name) { CHECK(cond); CHECK_EQ(a, b); }
#pragma once
#include <functional>
#include <string>
#include <vector>

struct TestCase {
    std::string name;
    std::function<void()> fn;
};

inline std::vector<TestCase>& testRegistry() {
    static std::vector<TestCase> tests;
    return tests;
}

struct TestRegistrar {
    TestRegistrar(const std::string& name, std::function<void()> fn) { testRegistry().push_back({name, fn}); }
};

struct CheckFailure {
    std::string message;
};

#define TEST(name)                                          \
    static void name();                                     \
    static TestRegistrar name##_registrar(#name, name);     \
    static void name()

#define CHECK(cond)                                                                                     \
    do {                                                                                                \
        if (!(cond))                                                                                    \
            throw CheckFailure{std::string(__FILE__) + ":" + std::to_string(__LINE__) + ": CHECK(" #cond ")"}; \
    } while (0)

#define CHECK_EQ(a, b) CHECK((a) == (b))
