#ifndef ALGORITHME_HPP
# define ALGORITHME_HPP

namespace ft
{

/**
 * LEXICOGRAPHICAL_COMPARE
 */

	/**
	 * A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries.
	 * 
	 * @param first1 - initial position of the first sequence
	 * @param last1 - final position of the first sequence
	 * @param first2 - initial position of the second sequence
	 * @param last2 - final position of the second sequence
	 * @return true if the first range compares lexicographically less than the second.
	 */
	template < class InputIterator1, class InputIterator2 >
	bool	exicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

	/**
	 * A lexicographical comparison is the kind of comparison generally used to sort words alphabetically in dictionaries.
	 * 
	 * @param first1 - initial position of the first sequence
	 * @param last1 - final position of the first sequence
	 * @param first2 - initial position of the second sequence
	 * @param last2 - final position of the second sequence
	 * @param comp - binary function that accepts two arguments of the types pointed by the iterators, and returns a value convertible to bool
	 * @return true if the first range compares lexicographically less than the second.
	 */
	template < class InputIterator1, class InputIterator2, class Compare >
	bool	lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}

/**
 * ENABLE IF
 */

	/**
	 * This metafunction is a convenient way to leverage SFINAE prior to C++20's concepts, 
	 * in particular for conditionally removing functions from the candidate set based on type traits, 
	 * allowing separate function overloads or specializations based on those different type traits.
	 * 
	 * @tparam B - If true, there is a member typedef type
	 * @tparam T - either T or no such member, depending on the value of B
	 */
	template<bool B, class T = void>
	struct enable_if {};

	/**
	 * This metafunction is a convenient way to leverage SFINAE prior to C++20's concepts, 
	 * in particular for conditionally removing functions from the candidate set based on type traits, 
	 * allowing separate function overloads or specializations based on those different type traits.
	 * 
	 * @tparam T - either T or no such member
	 */
	template<class T>
	struct enable_if<true, T> 
	{ 
		typedef T type; 
	};

/**
 * IS_INTEGRAL
 */

    template <bool is_integral, typename T>
    struct is_integral_res {
	typedef T   type;
	static const bool value = is_integral;
    };

    template<typename>
    struct is_integral_type : public is_integral_res<false, bool> {};

    template<>
    struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    template<>
    struct is_integral_type<char> : public is_integral_res<true, char> {};

    template<>
    struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    template<>
    struct is_integral_type<short int> : public is_integral_res<true, short int> {};

    template<>
    struct is_integral_type<int> : public is_integral_res<true, int> {};

    template<>
    struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    template<>
    struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    template<>
    struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
    
    template<>
    struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    template<>
    struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    template<>
    struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};

    template<>
    struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	/**
	 * Checks whether T is an integral type. 
	 * Provides the member constant value which is equal to true, 
	 * if T is the type bool, char, char16_t, char32_t, wchar_t, short, int, long, long long, 
	 * or any implementation-defined extended integer types, including any signed, unsigned, and cv-qualified variants. 
	 * Otherwise, value is equal to false.
	 * 
	 * @tparam T - type to check
	 */
    template <typename T>
    struct is_integral : public is_integral_type<T> {};

}

#endif