#include "AutoTests.hpp"

int main() {
    AutoTests tests(50000);
    tests.GoTestRandom(8);
    return 0;
}