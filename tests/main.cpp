#include <exception>
#include <iostream>

#include "test.h"

int main() {
    int n = 0, failed = 0;
    for (const TestCase& t : testRegistry()) {
        ++n;
        try {
            t.fn();
            std::cout << "ok " << n << " - " << t.name << "\n";
        } catch (const CheckFailure& e) {
            ++failed;
            std::cout << "not ok " << n << " - " << t.name << ": " << e.message << "\n";
        } catch (const std::exception& e) {
            ++failed;
            std::cout << "not ok " << n << " - " << t.name << ": exception " << e.what() << "\n";
        }
    }
    std::cout << "# " << (n - failed) << "/" << n << " passed\n";
    return failed == 0 && n > 0 ? 0 : 1;
}
