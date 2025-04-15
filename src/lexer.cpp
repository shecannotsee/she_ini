#include "lexer.h"

#include <tuple>
#include <unordered_map>

namespace {
namespace pre_tokenization {
enum class states : int;
enum class alphabet : int;
}  // namespace pre_tokenization
namespace tokenization {
enum class states : int;
enum class alphabet : int;
}  // namespace tokenization
}  // unnamed namespace
template <>
struct std::hash<std::tuple<pre_tokenization::states, pre_tokenization::alphabet>> {
  std::size_t operator()(const std::tuple<pre_tokenization::states, pre_tokenization::alphabet>& key) const noexcept {
    using std::hash;
    return hash<int>()(static_cast<int>(std::get<0>(key))) ^ (hash<int>()(static_cast<int>(std::get<1>(key))) << 1);
  }
};
template <>
struct std::hash<std::tuple<tokenization::states, tokenization::alphabet>> {
  std::size_t operator()(const std::tuple<pre_tokenization::states, pre_tokenization::alphabet>& key) const noexcept {
    using std::hash;
    return hash<int>()(static_cast<int>(std::get<0>(key))) ^ (hash<int>()(static_cast<int>(std::get<1>(key))) << 1);
  }
};

namespace {

namespace pre_tokenization {
enum class states : int {
  S1,     ///< Non-escape state, normal character state
  S2,     ///< In escape state
  S3,     ///< Accept one line
  S4,     ///< space
  S5,     ///< new line
  REFUSE  ///< refuse
};

enum class alphabet : int {
  Q1,  ///< '\n'
  Q2,  ///< '\'
  Q3,  ///< ' '
  Q4   ///< means other character
};

constexpr auto start_state = states::S1;  ///< init state

constexpr auto accept_state = states::S3;  ///< accept state

std::unordered_map<char, alphabet> cher_table = {
    {'\n', alphabet::Q1},  //
    {'\\', alphabet::Q2},  //
    {' ', alphabet::Q3},   //
};
// convert Character to State
template <typename char_type>
auto get_alphabet(char_type input) -> alphabet {
  if (cher_table.find(input) != cher_table.end()) {
    return cher_table[input];
  } else {
    return alphabet::Q4;
  }
}

/********** Transition Function ***************************************************************************************/
std::unordered_map<std::tuple<states, alphabet>, states> transfer_function = {
    // S1
    {{states::S1, /* + */ alphabet::Q1}, /* -> */ states::S3},
    {{states::S1, /* + */ alphabet::Q2}, /* -> */ states::S2},
    {{states::S1, /* + */ alphabet::Q3}, /* -> */ states::S4},
    {{states::S1, /* + */ alphabet::Q4}, /* -> */ states::S1},
    // S2
    {{states::S2, /* + */ alphabet::Q1}, /* -> */ states::S5},
    {{states::S2, /* + */ alphabet::Q2}, /* -> */ states::S1},
    {{states::S2, /* + */ alphabet::Q3}, /* -> */ states::S2},
    {{states::S2, /* + */ alphabet::Q4}, /* -> */ states::S1},
    // S4
    {{states::S4, /* + */ alphabet::Q1}, /* -> */ states::S3},
    {{states::S4, /* + */ alphabet::Q2}, /* -> */ states::S2},
    {{states::S4, /* + */ alphabet::Q3}, /* -> */ states::S4},
    {{states::S4, /* + */ alphabet::Q4}, /* -> */ states::S1},
    // S5
    {{states::S5, /* + */ alphabet::Q1}, /* -> */ states::S3},
    {{states::S5, /* + */ alphabet::Q2}, /* -> */ states::S2},
    {{states::S5, /* + */ alphabet::Q3}, /* -> */ states::S5},
    {{states::S5, /* + */ alphabet::Q4}, /* -> */ states::S1},
};

template <typename char_type>
auto transition_status(const states now, char_type input) -> states {
  auto input_S = static_cast<states>(now);
  auto input_Q = static_cast<alphabet>(get_alphabet(input));
  auto key     = std::make_tuple(input_S, input_Q);
  if (transfer_function.find(key) != transfer_function.end())
    return transfer_function[key];
  else {
    return states::REFUSE;
  }
}
}  // namespace pre_tokenization

namespace tokenization {
enum class states : int {
  S1,  ///<
  S2,
  S3,
  S4,
  S5,
  S6,
  REFUSE,
};

enum class alphabet : int {
  Q1,  ///< '['
  Q2,  ///< ']'
  Q3,  ///< ';'
  Q4,  ///< '#'
  Q5,  ///< '='
  Q6,  ///< means other character
};

constexpr auto start_state = states::S1;  ///< init state

constexpr auto accept_state = states::S6;  ///< accept state

std::unordered_map<char, alphabet> cher_table = {
    {'[', alphabet::Q1},  //
    {']', alphabet::Q2},  //
    {';', alphabet::Q3},  //
    {'#', alphabet::Q4},  //
    {'=', alphabet::Q5},  //
};
// convert Character to State
template <typename char_type>
auto get_alphabet(char_type input) -> alphabet {
  if (cher_table.find(input) != cher_table.end()) {
    return cher_table[input];
  } else {
    return alphabet::Q6;
  }
}

/********** Transition Function ***************************************************************************************/
std::unordered_map<std::tuple<states, alphabet>, states> transfer_function = {
    // S1
    {{states::S1, /* + */ alphabet::Q1}, /* -> */ states::S3},
};

template <typename char_type>
auto transition_status(const states now, char_type input) -> states {
  auto input_S = static_cast<states>(now);
  auto input_Q = static_cast<alphabet>(get_alphabet(input));
  auto key     = std::make_tuple(input_S, input_Q);
  if (transfer_function.find(key) != transfer_function.end())
    return transfer_function[key];
  else {
    return states::REFUSE;
  }
}
}  // namespace tokenization

}  // unnamed namespace

using namespace ini::detail;

lexer::lexer(const std::string& file_path) : loader_(file_path) {
}

auto lexer::get_token() -> std::vector<token> {
  std::vector<token> token_list;
  std::string single_line;
  // Pre-tokenization
  {
    using namespace pre_tokenization;
    auto now_states = start_state;
    // Get one line
    while (auto ch = loader_.read_char()) {
      now_states = pre_tokenization::transition_status<char>(now_states, (*ch));
      if (now_states == states::S1) {
        single_line.push_back(*ch);
      }
      if (now_states == accept_state) {
        break;
      }
    }
  }

  // Single-line Tokenization
  {
    using namespace tokenization;
  }

  return token_list;
}