#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

bool parse_int(const std::string& input, size_t start, size_t end, int64_t& result) {
    // std::cout << "parse '" << input.substr(start, end - start + 1) << "'" << std::endl;

    result = 0;
    for (size_t i = start; i <= end; i++) {
        if ('0' <= input[i] && input[i] <= '9') {
            result = result * 10 + (input[i] - '0');
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    std::ifstream file("input.txt");

    std::stringstream buffer;
    buffer << file.rdbuf();
    std::string input = buffer.str();

    size_t cursor = 0;
    int64_t sum = 0;
    while (cursor < input.size()) {
        size_t pos = input.find("mul(", cursor);
        if (pos > input.size()) {
            break;
        }

        cursor = pos + 4;
        pos = input.find(",", cursor);
        if (pos > input.size()) {
            break;
        }

        int64_t a = 0;
        if (!parse_int(input, cursor, pos - 1, a)) {
            continue;
        }

        cursor = pos + 1;
        pos = input.find(")", cursor);
        if (pos > input.size()) {
            break;
        }

        int64_t b = 0;
        if (!parse_int(input, cursor, pos - 1, b)) {
            continue;
        }

        cursor = pos + 1;
        // std::cout << a << " * " << b << " = " << a * b << std::endl;
        sum += a * b;
    }

    std::cout << sum << std::endl;
    return 0;
}