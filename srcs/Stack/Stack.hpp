#ifndef STACK_HPP
# define STACK_HPP

#include "../Vector/Vector.hpp"

namespace ft
{

	/**
	 * Stacks are sequence containers representing arrays that can use some interaction of it.
	 * 
	 * @tparam T - type of objects who can be use in this vector
	 * @tparam Container - container of vector with type value "T"
	 */

	template <class T, class Container = ft::vector<T> >
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

		/**
		 * Create stack with default container.
		 * 
		 * @param cont - address of container
		 */
			explicit stack(const container_type& cont = container_type()) : _c(cont) {}

		/**
		 * Assign other stack to this stack
		 * 
		 * @param rhs - address of stack
		 * @return - address of this stack
		 */
			stack &operator=(stack const &rhs)
			{
				_c = rhs._c;

				return *this;
			}

		/**
		 * Destroy stack, clear all elements and memory.
		 */
			~stack(void)
			{
				_c.clear();
			}

	/**
	 * Member functions
	 */

		/**
		 * Get a reference to the first element of the stack.
		 * 
		 * @return reference to the first element of the stack
		 */
			reference top()
			{
				return _c.back();
			}

		/**
		 * Get a constant reference to the first element of the stack.
		 * 
		 * @return constant reference to the first element of the stack
		 */
			const_reference top() const
			{
				return _c.back();
			}

		/**
		 * Check if stack is empty.
		 * 
		 * @return true if stack is empty
		 */
			bool empty() const
			{
				return _c.empty();
			}

		/**
		 * Get stack size.
		 * 
		 * @return stack size
		 */
			size_type size() const
			{
				return _c.size();
			}

		/**
		 * Add element on top of a stack.
		 * 
		 * @param value - value added
		 * @return void
		 */
			void push( const value_type& value )
			{
				_c.push_back(value);
			}

		/**
		 * Delete the last stack's element.
		 * 
		 * @return void
		 */
			void pop()
			{
				_c.pop_back();
			}

	/**
	 * Non-member functions
	 */

		/**
		 * Overload of "==" operator
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if the two stacks are equal
		 */
			friend bool operator==( const stack& lhs, const stack& rhs ) 
			{
				return lhs._c == rhs._c;
			}

		/**
		 * Overload of "!=" operator
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if the two stacks are not equal
		 */
			friend bool operator!=( const stack& lhs, const stack& rhs )
			{
				return lhs._c != rhs._c;
			}


		/**
		 * Overload of "<" operator.
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if "lhs" are smaller than "rhs"
		 */
			friend bool operator<( const stack& lhs, const stack& rhs )
			{
				return lhs._c < rhs._c;
			}

		/**
		 * Overload of "<=" operator.
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if "lhs" are smaller than "rhs" or equal
		 */
			friend bool operator<=( const stack& lhs, const stack& rhs )
			{
				return lhs._c <= rhs._c;
			}

		/**
		 * Overload of ">" operator.
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if "lhs" are bigger than "rhs"
		 */
			friend bool operator>( const stack& lhs, const stack& rhs )
			{
				return lhs._c > rhs._c;
			}

		/**
		 * Overload of ">=" operator.
		 * 
		 * @param lhs - stack's address
		 * @param rhs - stack's address
		 * @return true if "lhs" are bigger than "rhs" or equal
		 */
			friend bool operator>=( const stack& lhs, const stack& rhs )
			{
				return lhs._c >= rhs._c;
			}

		protected:
			container_type _c;

	};
}

#endif