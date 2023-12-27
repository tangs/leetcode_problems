#include <string>
#include <vector>
#include <regex>
#include <iostream>

class Utils {
  template<class T>
  static T to(const std::string& txt) {
    if constexpr (std::is_same_v<T, char>) {
      return txt[0];
    }
    if constexpr (std::is_integral_v<T>) {
      return std::atoll(txt.c_str());
    }
    if constexpr (std::is_same_v<T, std::string>) {
      return txt;
    }
  }
public:
  template<class T>
  static std::vector<T> v1(const std::string& txt) {
    const std::regex word_regex(R"xx("?(-?\w+)"?)xx");

    std::vector<T> arr;
    std::smatch smatch_word;
    auto search_start_word(txt.cbegin());

    while (regex_search(search_start_word, txt.cend(), smatch_word, word_regex)) {
      auto word_txt = smatch_word[1].str();
      search_start_word = smatch_word.suffix().first;

      arr.push_back(to<T>(word_txt));
    }

    return arr;
  }

  template<class T>
  static std::vector<std::vector<T>> v2(const std::string& txt) {
    std::vector<std::vector<T>> ret;

    const std::regex arr_regex(R"(\[((-?"?\w+"?,?)*)\])");

    std::smatch smatch;
    auto search_start(txt.cbegin());
    while (regex_search(search_start, txt.cend(), smatch, arr_regex)) {
      auto arr_txt = smatch[0].str();
      ret.emplace_back(v1<T>(arr_txt));
      search_start = smatch.suffix().first;
    }

    return ret;
  }
};
