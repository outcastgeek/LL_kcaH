#include <iostream>
#include <absl/strings/str_format.h>
#include <absl/strings/str_join.h>

int main() {

    constexpr absl::string_view formatString = "Welcome to %s, Number %d!\n";
    std::string abslStr = absl::StrFormat(formatString, "The Village", 6);
    std::cout << "Abseil String: " << abslStr << std::endl;

    std::string fstr = absl::StrFormat("%s\n", "Hello Abseil!");
    std::cout << fstr << std::endl;

    std::vector<std::string> vStr = {"foo","bar","baz"};
    std::string str = absl::StrJoin(vStr, "-");
    std::cout << "Joined string: " << str << std::endl;

    return 0;
}
