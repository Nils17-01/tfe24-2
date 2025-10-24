#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include "point.hpp"

TEST_CASE("Point: Konstruktoren") {
    SECTION("Init mit Werten") {
        Point p{2, 3};
        REQUIRE(p.x == 2);
        REQUIRE(p.y == 3);
    }
    SECTION("Default-Konstruktor") {
        Point p;
        REQUIRE(p.x == 0);
        REQUIRE(p.y == 0);
    }
}

TEST_CASE("Point: move verschiebt relativ") {
    Point p{1, 1};
    p.move(2, -3);
    REQUIRE(p.x == 3);
    REQUIRE(p.y == -2);

    SECTION("mehrere moves sind additiv") {
        p.move(1, 1);
        REQUIRE(p.x == 4);
        REQUIRE(p.y == -1);
    }
}

TEST_CASE("Point: distance_to – euklidisch & robust") {
    Point a{0, 0};
    Point b{3, 4};
    REQUIRE( a.distance_to(b) == Catch::Approx(5.0).margin(1e-12) );
    REQUIRE( b.distance_to(a) == Catch::Approx(5.0).margin(1e-12) );
    REQUIRE( a.distance_to(a) == Catch::Approx(0.0).margin(1e-12) );
}

TEST_CASE("Point: edge cases") {
    SECTION("grosse Koordinaten") {
        Point big{1000000, -1000000};
        Point other{-1000000, 1000000};
        // Distanz berechnet ohne Overflow (double intermediate)
        auto d = big.distance_to(other);
        REQUIRE(d > 0.0);
    }
    SECTION("dreiecksungleichung (kleines sample)") {
        Point a{0,0};
        Point b{1,0};
        Point c{1,1};
    REQUIRE( a.distance_to(c) <= Catch::Approx(a.distance_to(b) + b.distance_to(c)).margin(1e-12) );
    }
}
