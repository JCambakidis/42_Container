#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/Vector.hpp"

template <class T, class Container = vector<T> >
class stack
{
	public:

	/**
	 * Typedef
	 */

		typedef Container container_type;
		typedef typename Container::value_type value_type;
		typedef typename Container::size_type size_type;
		typedef typename Container::reference reference;
		typedef typename Container::const_reference const_reference;

	/**
	 * Constructor
	 */

		explicit stack(const container_type& cont = container_type()) : _c(cont) {}

		stack &operator=(stack const &rhs)
		{
			_c = rhs._c;
		}

		~stack(void)
		{
			_c.clear();
		}

	/**
	 * Member functions
	 */

		reference top()
		{
			return _c.back();
		}

		const_reference top() const
		{
			return _c.back();
		}

		bool empty() const
		{
			return _c.empty();
		}

		size_type size() const
		{
			return _c.size();
		}

		void push( const value_type& value )
		{
			_c.push_back(value);
		}

		void pop()
		{
			_c.pop_back();
		}

	/**
	 * Non-member functions
	 */

		friend bool operator==( const stack& lhs, const stack& rhs ) 
		{
			return lhs._c == rhs._c;
		}

		friend bool operator!=( const stack& lhs, const stack& rhs )
		{
			return lhs._c != rhs._c;
		}

		friend bool operator<( const stack& lhs, const stack& rhs )
		{
			return lhs._c < rhs._c;
		}

		friend bool operator<=( const stack& lhs, const stack& rhs )
		{
			return lhs._c <= rhs._c;
		}

		friend bool operator>( const stack& lhs, const stack& rhs )
		{
			return lhs._c > rhs._c;
		}

		friend bool operator>=( const stack& lhs, const stack& rhs )
		{
			return lhs._c >= rhs._c;
		}

	protected:
		container_type _c;

};

#endif