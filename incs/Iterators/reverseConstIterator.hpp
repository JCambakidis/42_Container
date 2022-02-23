#ifndef REVERSECONSTITERATOR_HPP
# define REVERSECONSTITERATOR_HPP

# include <memory>
template <class T, class A = std::allocator<T> >
class reverseConstIterator
{
	public:

		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

		reverseConstIterator(void) : _ptr(nullptr) {}
		reverseConstIterator(reverseConstIterator const &instance) : _ptr(instance._ptr) {}
		reverseConstIterator(pointer pt) : _ptr(pt) {}
		~reverseConstIterator(void){}

		reverseConstIterator& operator=(const reverseConstIterator &it)
		{
			_ptr = it._ptr;
			return *this;
		}

		bool operator==(const reverseConstIterator &it) const
		{
			return _ptr == it._ptr;
		}

		bool operator!=(const reverseConstIterator &it) const
		{
			return _ptr != it._ptr;
		}

		bool operator<(const reverseConstIterator &it) const
		{
			return _ptr > it._ptr;
		} 

		bool operator>(const reverseConstIterator &it) const
		{
			return _ptr < it._ptr;
		} 

		bool operator<=(const reverseConstIterator &it) const
		{
			return _ptr >= it._ptr;
		}

		bool operator>=(const reverseConstIterator &it) const
		{
			return _ptr <= it._ptr;
		}

		reverseConstIterator& operator++()
		{
			--_ptr;
			return *this;
		}

		reverseConstIterator operator++(int)
		{
			reverseConstIterator tmp(*this);
			--_ptr;
			return tmp;
		}

		reverseConstIterator& operator--()
		{
			++_ptr;
			return *this;
		}

		reverseConstIterator operator--(int)
		{
			reverseConstIterator tmp(*this);
			++(*_ptr);
			return tmp;
		}

		reverseConstIterator& operator+=(size_type rhs)
		{
			movePtr(_ptr, rhs, 1);
			return *this;
		}

		reverseConstIterator operator+(size_type rhs) const
		{
			reverseConstIterator it(*this);
			movePtr(it._ptr, rhs, 1);
			return it;
		}

		friend reverseConstIterator operator+(size_type lhs, const reverseConstIterator &rhs)
		{
			reverseConstIterator it(rhs);
			return it += lhs;
		}

		reverseConstIterator& operator-=(size_type rhs)
		{
			movePtr(_ptr, rhs, 0);
			return *this;
		}   

		reverseConstIterator operator-(size_type rhs) const
		{
			reverseConstIterator it(*this);
			movePtr(it._ptr, rhs, 0);
			return 0;
		}

		difference_type operator-(reverseConstIterator it) const
		{
			return it._ptr - _ptr;
		}

		friend reverseConstIterator operator-(size_type lhs, const reverseConstIterator &rhs)
		{
			reverseConstIterator it(rhs);
			return it -= lhs;
		}

		reference operator*() const
		{
			return *--_ptr;
		}

		pointer operator->() const
		{
			return _ptr;
		}

		reference operator[](size_type rhs) const
		{
			value_type *tmp(_ptr);
			movePtr(tmp, rhs, 1);
			return *tmp;
		}

	private:
		T *_ptr;

		void movePtr(T &val, size_type nb, bool sign) const
		{
			int mov;

			if (sign == 1)
				mov = nb > 0 ? mov = -1: mov = 1;
			else
				mov = nb > 0 ? mov = 1: mov = -1;

			if (nb < 0)
				nb *= -1;
			for (; nb > 0; --nb)
				val += mov;
		}

};

#endif