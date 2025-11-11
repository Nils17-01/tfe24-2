#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

static void print_vector(const std::vector<int> &v)
{
    for (const auto &x : v)
    {
        fmt::print("{} ", x);
    }
    fmt::print("\n");
}

auto main(int argc, char **argv) -> int
{
    /**
     * CLI11 is a command line parser to add command line options
     * More info at https://github.com/CLIUtils/CLI11#usage
     */
    CLI::App app{PROJECT_NAME};
    try
    {
        app.set_version_flag("-V,--version", fmt::format("{} {}", PROJECT_VER, PROJECT_BUILD_DATE));
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", app.get_name());

    // CLI option: -c / --count
    int count = 20;
    app.add_option("-c,--count", count, "Number of random elements to generate")->check(CLI::PositiveNumber);
    try
    {
        app.parse(argc, argv);
    }
    catch (const CLI::ParseError &e)
    {
        return app.exit(e);
    }

    // create and fill vector with random numbers 1..100
    std::vector<int> values;
    values.reserve(count);
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100);
    for (int i = 0; i < count; ++i)
        values.push_back(dist(gen));

    fmt::print("Generated (unsorted) vector ({} elements):\n", count);
    print_vector(values);

    // sort and measure time
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(values.begin(), values.end());
    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);

    fmt::print("Sorted vector:\n");
    print_vector(values);
    fmt::print("Sorting took {} ms\n", elapsed.count());

    return 0; /* exit gracefully*/
}
