//
// Created by kittech on 8/16/24.
//
#include "games.h"

int games::calculator() {
    std::println("Calculator!");

    std::print("X: ");
    const double num_x{util::unwrap(util::read_double())};

    std::print("Z: ");
    const double num_z = util::unwrap(util::read_double());

    std::print("Operation (+-*/): ");
    const char operation = util::unwrap(util::read_first_char());

    const double value = util::unwrap(util::combine_values(num_x, num_z, operation));
    std::println("({} {} {}): {}", num_x, operation, num_z, value);

    return EXIT_SUCCESS;
}
