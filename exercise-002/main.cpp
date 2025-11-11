#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"

/* Globale Variable im Data-Segment */
int globalVar = 1;

void foo() { fmt::print("Hello from foo!\n"); }

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
        app.parse(argc, argv);
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

    /* Ausgabe von Wert und Adresse der globalen Variable */
    fmt::print("globalVar = {} at address {}\n", globalVar, fmt::ptr(&globalVar));

    int localVar = 2;
    fmt::print("localVar = {} at address {}\n", localVar, fmt::ptr(&localVar));

    int* heapVar = new int(3);
    fmt::print("heapVar (value) = {} at address {}\n", *heapVar, fmt::ptr(heapVar));
    fmt::print("address of pointer variable heapVar (where the pointer itself is stored) = {}\n", fmt::ptr(&heapVar));

    /* free heap memory */
    delete heapVar;

    /* Funktion: Adresse im Code-Segment und Aufruf */
    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));
    foo();

    return 0; /* exit gracefully*/
}
