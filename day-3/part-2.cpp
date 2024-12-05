#include <cstdint>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <map>

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

    std::map<size_t, bool, std::greater<size_t>> enable_ranges;
    enable_ranges.insert({ 0, true });

    size_t cursor = 0;
    while (cursor < input.size()) {
        size_t do_pos = input.find("do()", cursor);
        size_t dont_pos = input.find("don't()", cursor);

        if (do_pos < input.size()) {
            enable_ranges.insert({ do_pos, true });
        }

        if (dont_pos < input.size()) {
            enable_ranges.insert({ dont_pos, false });
        }

        cursor = std::min(do_pos, dont_pos);
        if (cursor >= input.size()) {
            break;
        }

        cursor += 1;
    }

    // for (auto& [pos, enable] : enable_ranges) {
    //     std::cout << pos << " " << enable << std::endl;
    // }

    cursor = 0;
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

        auto it = enable_ranges.lower_bound(pos);
        if (it == enable_ranges.end()) {
            std::cout << "WTF, no way " << pos << std::endl;
            return 0;
        }

        // std::cout << a << " * " << b << " = " << a * b << " " << (it->second) << std::endl;
        if (it->second) {
            sum += a * b;
        }

        cursor = pos + 1;
    }

    std::cout << sum << std::endl;
    return 0;
}