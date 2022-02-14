#ifndef PAIR_HPP
# define PAIR_HPP

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
 * Constructor
 */

	/**
	 * Construct new empty pair.
	 */
	pair() : first(), second() {}
	
	/**
	 * Construct new pair with values of pair "pr".
	 * 
	 * @param pr - pair address
	 */
	template<class U, class V> 
	pair (const pair<U,V>& pr) : first(pr.first), second(pr.second) {}

	/**
	 * Construct new pair with "a" and "b" values.
	 * 
	 * @param a - first value
	 * @param b - second value
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
	 * Swap first and second pair elements with a pair "pr".
	 * 
	 * @param pr - pair to swap
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
	 * Assign first and second pair elements with a pair "pr" values.
	 * 
	 * @param pr - pair' address
	 * @return Address of this
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
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if the two pairs are equal
	 */
	friend bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first==rhs.first && lhs.second==rhs.second; }

	/**
	 * Overload of "!=" operator
	 * 
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if the two pairs are not equal
	 */
	friend bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs==rhs); }

	/**
	 * Overload of "<" operator.
	 * 
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if "lhs" are smaller than "rhs"
	 */
	friend bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

	/**
	 * Overload of "<=" operator.
	 * 
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if "lhs" are smaller than "rhs" or equal
	 */
	friend bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs<lhs); }

	/**
	 * Overload of ">" operator.
	 * 
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if "lhs" are bigger than "rhs"
	 */
	friend bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs<lhs; }

	/**
	 * Overload of ">=" operator.
	 * 
	 * @param lhs - pair's address
	 * @param rhs - pair's address
	 * @return true if "lhs" are bigger than "rhs" or equal
	 */
	friend bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs<rhs); }

};

#endif