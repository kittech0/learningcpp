//
// Created by kittech on 8/16/24.
//
#include "games.h"
void test_for_char(long unsigned word_size, std::string_view guess, std::string_view letters);
bool guesser(long unsigned word_size, int guess_limit, std::string_view letters);

int games::lorem_world() {
    constexpr std::string_view letters{"ABCDE"};
    std::println("LoremWorld!");
    std::print("Guess a word (5 letters): ");

    if (guesser(5, 5, letters)) {
        return EXIT_SUCCESS;
    }

    std::cerr << "You lost!" << std::endl;
    return EXIT_FAILURE;
}

bool guesser(const long unsigned word_size, const int guess_limit, const std::string_view letters) {
    for (int i = guess_limit; i > 0; i--) {
        std::string in_guess;
        std::getline(std::cin, in_guess);
        util::to_upper(in_guess);
        constexpr std::string_view guess = in_guess;
        if (guess.size() != word_size) {
            std::cerr << "required 5 letters word" << std::endl;
            i++;
            continue;
        }

        test_for_char(word_size, guess, letters);
        std::cout << std::endl;
        if (guess == letters) {
            std::println("Won on try: {}", i);
            return true;
        }
        std::println("Remaining tries: {}", i - 1);
    }
    return false;
}

void test_for_char(const long unsigned word_size, const std::string_view guess, const std::string_view letters) {
    for (long unsigned j = 0; j < word_size; j++) {
        if (const char guess_at = guess[j]; guess_at == letters[j]) {
            std::print("\033[0;32m{}\033[0m", guess_at);
        } else if (letters.find(guess_at) != std::string::npos) {
            std::print("\033[0;33m{}\033[0m", guess_at);
        } else {
            std::print("\033[0;31m{}\033[0m", guess_at);
        }
    }
}
