//
// Created by kittech on 8/15/24.
//
#include "util.h"


std::expected<double, std::string_view> util::into_double(const std::string &str) {
    try {
        return std::stod(str);
    } catch (const std::exception &_) {
        return std::unexpected{"not a double"};
    }
}

std::expected<int, std::string_view> util::into_int(const std::string &str) {
    try {
        return std::stoi(str);
    } catch (const std::exception &_) {
        return std::unexpected{"not a int"};
    }
}

std::expected<char, std::string_view> util::first_char(const std::string &str) {
    if (str.empty()) {
        return std::unexpected{"empty string"};
    }
    return str.at(0);
}

std::expected<double, std::string_view> util::read_double() {
    std::string in_double;
    std::getline(std::cin, in_double);
    return into_double(in_double);
}

std::expected<char, std::string_view> util::read_first_char() {
    std::string in_char;
    std::getline(std::cin, in_char);
    return first_char(in_char);
}

std::expected<double, std::string_view> util::combine_values(
    const double x, const double z, const char operation
    ) {
    switch (operation) {
        case '+':
            return x + z;
        case '-':
            return x - z;
        case '*':
            return x * z;
        case '/':
            return x / z;
        default:
            return std::unexpected{"unknown operator"};
    }
}

void util::to_upper(std::string &str) {
    std::transform(
        str.begin(), str.end(), str.begin(), [](const unsigned char c) {
            return std::toupper(c);
        }
        );
}

std::expected<int, std::string_view> util::read_int() {
    std::string in_int;
    std::getline(std::cin, in_int);
    return into_int(in_int);
}
