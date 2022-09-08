#include <type_traits>

template <unsigned i, unsigned n, typename Enable = void>
struct is_prime_impl { static constexpr bool value = true; };

template <unsigned i, unsigned n>
struct is_prime_impl<i, n, typename std::enable_if<(i* i <= n)>::type> { 
    static constexpr bool value = (n % i == 0 || n % (i + 2) == 0) ? false : is_prime_impl<i + 6, n>::value; 
};

template <unsigned n, typename Enable = void>
struct is_prime { static constexpr bool value = is_prime_impl<5, n>::value; };

template <unsigned n>
struct is_prime<n, typename std::enable_if<(n % 2 == 0)>::type> { static constexpr bool value = false; };

template <unsigned n>struct is_prime<n, typename std::enable_if<(n % 3 == 0) && (n % 2 != 0)>::type> { static constexpr bool value = false; };

template <> struct is_prime<1> { static constexpr bool value = false; };
template <> struct is_prime<2> { static constexpr bool value = true; };
template <> struct is_prime<3> { static constexpr bool value = true; };

int main() {


    static_assert(is_prime<2>::value, "");
    static_assert(is_prime<3>::value, "");
    static_assert(is_prime<5>::value, "");
    static_assert(is_prime<7>::value, "");
    static_assert(is_prime<11>::value, "");

    static_assert(is_prime<63727>::value, "");

    static_assert(!is_prime<1>::value, "");
    static_assert(!is_prime<4>::value, "");
    static_assert(!is_prime<6>::value, "");
    static_assert(!is_prime<8>::value, "");
    static_assert(!is_prime<9>::value, "");
    static_assert(!is_prime<10>::value, "");




	return 0;
}