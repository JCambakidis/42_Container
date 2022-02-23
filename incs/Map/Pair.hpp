#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{

	/**
	 * Pair is a struct template that provides a way to store two heterogeneous objects as a single unit.
	 * 
	 * @tparam T1 - first type stored
	 * @tparam T2 - second type stored
	 */

	template <class T1, class T2> 
	struct pair
	{

	/**
	 * Typedef
	 */

		typedef T1 first_type;
		typedef T2 second_type;

	/**
	 * Variables
	 */

		first_type first;
		second_type second;

	/**
	 * Constructors
	 */

		/**
		 * Construct new empty pair.
		 */
		pair() : first(), second() {}
		
		/**
		 * Construct new pair with values of pair "pr".
		 * 
		 * @param pr - pair reference
		 */
		template<class U, class V> 
		pair (const ft::pair<U,V>& pr) : first(pr.first), second(pr.second) {}

		/**
		 * Construct new pair with "a" and "b" values.
		 * 
		 * @param a - first value reference
		 * @param b - second value reference
		 */
		pair (const first_type& a, const second_type& b) : first(a) ,second(b) {}

		/**
		 * Destruct pair.
		 */
		~pair () {}

	/**
	 * Members functions
	 */

		/**
		 * Swap pair elements with a pair "pr".
		 * 
		 * @param pr - pair reference
		 * @return void
		 */
		void swap (pair& pr)
		{
			swap(first, pr.first);
			swap(second, pr.second);
		}

	/**
	 * Operators
	 */

		/**
		 * Copy pair "pr".
		 * 
		 * @param pr - pair reference
		 * @return pointer of this
		 */
		pair& operator= (const pair& pr)
		{
			first = pr.first;
			second = pr.second;
			return *this;
		}

		/**
		 * Overload of "==" operator
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if the two pairs are equal
		 */
		friend bool operator== (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }

		/**
		 * Overload of "!=" operator
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if the two pairs are not equal
		 */
		friend bool operator!= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs==rhs); }

		/**
		 * Overload of "<" operator.
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if "lhs" are smaller than "rhs"
		 */
		friend bool operator<  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

		/**
		 * Overload of "<=" operator.
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if "lhs" are smaller than "rhs" or equal
		 */
		friend bool operator<= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(rhs<lhs); }

		/**
		 * Overload of ">" operator.
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if "lhs" are bigger than "rhs"
		 */
		friend bool operator>  (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return rhs<lhs; }

		/**
		 * Overload of ">=" operator.
		 * 
		 * @param lhs - pair reference
		 * @param rhs - pair reference
		 * @return true if "lhs" are bigger than "rhs" or equal
		 */
		friend bool operator>= (const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs) { return !(lhs<rhs); }

	};

	/**
	 * Create new pair.
	 * 
	 * @param first - first element
	 * @param second - second element
	 * @return pair created
	 */
	template <class T1, class T2>
	pair<T1, T2> make_pair(T1 first, T2 second) {
		return pair<T1, T2>(first, second);
	}
}

#endif