#include <fmt/chrono.h>
#include <fmt/format.h>

#include "CLI/CLI.hpp"
#include "config.h"
#include <cmath>

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

    // Klasse Point definieren (kann auch in Header ausgelagert werden)
    class Point
    {
    public:
        int x;
        int y;

        // Standardkonstruktor: setzt x=0, y=0
        Point() : x(0), y(0) {}

        // Parameterisierter Konstruktor: setzt x und y explizit
        Point(int x_, int y_) : x(x_), y(y_) {}

        // Verschiebt den Punkt um dx, dy
        void move(int dx, int dy) { x += dx; y += dy; }

        // Gibt den Punkt in der Form (x, y) aus
        void print() const { fmt::print("({}, {})\n", x, y); }

        // Optional: euklidischer Abstand zu einem anderen Punkt
        double distance_to(const Point &other) const
        {
            double dx = static_cast<double>(x - other.x);
            double dy = static_cast<double>(y - other.y);
            return std::sqrt(dx * dx + dy * dy);
        }
    };

    // Beispielnutzung gemäß Readme
    Point p1(2, 3); // (2, 3)
    p1.print();     // Ausgabe: (2, 3)

    p1.move(1, -1); // verschiebe um (1, -1)
    p1.print();     // Ausgabe: (3, 2)

    Point p2;       // Default -> (0, 0)
    p2.print();     // Ausgabe: (0, 0)

    // Abstand berechnen (Zusatzaufgabe)
    fmt::print("Distance p1 -> p2 = {}\n", p1.distance_to(p2));

    return 0; /* exit gracefully*/
}
