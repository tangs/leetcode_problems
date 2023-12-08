#include <string>
#include <vector>
#include <regex>
#include <iostream>

class Utils {
  template<class T>
  static T to(const std::string& txt) {
    if constexpr (std::is_integral_v<T>) {
      return std::atoll(txt.c_str());
    }
    if constexpr (std::is_same_v<T, std::string>) {
      return txt;
    }
  }
public:
  template<class T>
  static std::vector<std::vector<T>> v2(const std::string& txt) {
    std::vector<std::vector<T>> ret;

    const std::regex arr_regex(R"(\[((\w+,?)*)\])");
    const std::regex word_regex(R"(\w+)");

    std::smatch smatch;
    auto search_start(txt.cbegin());
    while (regex_search(search_start, txt.cend(), smatch, arr_regex)) {
      std::vector<T> arr;
      auto arr_txt = smatch[0].str();
      std::smatch smatch_word;
      auto search_start_word(arr_txt.cbegin());

      while (regex_search(search_start_word, arr_txt.cend(), smatch_word, word_regex)) {
        auto word_txt = smatch_word[0].str();
        search_start_word = smatch_word.suffix().first;

        arr.push_back(to<T>(word_txt));
      }

      ret.push_back(arr);
      search_start = smatch.suffix().first;
    }

    return ret;
  }
};
