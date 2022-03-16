#ifndef ALGORITHME_HPP
# define ALGORITHME_HPP

namespace ft
{
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
}

#endif