#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

auto main(int argc, char **argv) -> int
{

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", tfe24::PROJECT_NAME);

    /* INSERT YOUR CODE HERE */
    int x = 10;
    int* p = &x;
    fmt::print("dein lümmel ist {} cm lang!\n", *p);

    return 0; /* exit gracefully*/
}
