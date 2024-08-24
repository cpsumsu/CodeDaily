#include <cstdint>
#include <iostream>
using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container,
          typename = enable_if_t<!is_same_v<string, T_container>,
                                 typename T_container::value_type>>
ostream &operator<<(ostream &os, const T_container &arg) {
  for (const auto &x : arg)
    os << x << ' ';
  return os;
}

template <typename> struct is_tuple : std::false_type {};
template <typename... T> struct is_tuple<std::tuple<T...>> : std::true_type {};
template <typename T> void tuple_out(T &&t) {
  apply([](auto &&...arg) { ((cout << arg << ' '), ...) << '\n'; }, t);
}

template <typename T> void _deduce(T arg) {
  if constexpr (is_tuple<T>::value) {
    tuple_out(arg);
  } else {
    cerr << arg << ' ';
  }
}
template <typename... Arg> void println(Arg &&...args) {
  (_deduce(args), ...);
  cerr << '\n';
}

void run_case() {
  int64_t N;
  cin >> N;

  const int64_t MOD = 1e9 + 7;

  auto quick_pow = [&](int64_t a, int64_t n) -> int64_t {
    int64_t ret = 1;

    while (n) {
      if (n & 1)
        ret = ret * a % MOD;

      a = a * a % MOD;
      n >>= 1;
    }

    return ret;
  };

  cout << quick_pow(2, N) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  run_case();

  return 0;
}
