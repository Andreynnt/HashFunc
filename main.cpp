#include "AutoTests.hpp"

int main() {
    AutoTests tests(1000);
    tests.GoTestRandom(5);
    return 0;
}