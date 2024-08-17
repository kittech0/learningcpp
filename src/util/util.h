//
// Created by kittech on 8/15/24.
//

#ifndef UTIL_H
#define UTIL_H
#include <expected>
#include <iostream>
#include <print>

namespace util {
#define RED "\033[0;31m"

    template<typename T, typename E> T unwrap(const std::expected<T, E> &expected) {
        if (!expected.has_value()) {
            std::cerr << "error: " << expected.error() << std::endl;
            exit(EXIT_FAILURE);
        }
        return expected.value();
    }

    std::expected<double, std::string_view> combine_values(double x, double z, char operation);
    std::expected<double, std::string_view> into_double(const std::string &str);
    std::expected<int, std::string_view> into_int(const std::string &str);
    std::expected<char, std::string_view> first_char(const std::string &str);
    std::expected<double, std::string_view> read_double();
    std::expected<int, std::string_view> read_int();
    std::expected<char, std::string_view> read_first_char();
    void to_upper(std::string &str);
    void to_upper(std::string::pointer data);
}
#endif //UTIL_H
