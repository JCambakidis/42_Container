#ifndef RANDOMACCESSCONSTITERATOR_HPP
# define RANDOMACCESSCONSTITERATOR_HPP

# include <memory>

template <class T, class A = std::allocator<T> >
class const_iterator {
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::random_access_iterator_tag iterator_category;

		const_iterator() : _ptr(nullptr) {}
		const_iterator(const const_iterator &it) : _ptr(it._ptr) {}
		const_iterator(pointer pt) : _ptr(pt) {}
		~const_iterator() {}

		const_iterator& operator=(const const_iterator &it)
		{
			_ptr = it._ptr;
			return *this;
		}

		bool operator==(const const_iterator &it) const
		{
			return _ptr == it._ptr;
		}

		bool operator!=(const const_iterator &it) const
		{
			return _ptr != it._ptr;
		}

		bool operator<(const const_iterator &it) const
		{
			return _ptr < it._ptr;
		} 

		bool operator>(const const_iterator &it) const
		{
			return _ptr > it._ptr;
		} 

		bool operator<=(const const_iterator &it) const
		{
			return _ptr <= it._ptr;
		}

		bool operator>=(const const_iterator &it) const
		{
			return _ptr >= it._ptr;
		}

		const_iterator& operator++()
		{
			++_ptr;
			return *this;
		}

		const_iterator operator++(int)
		{
			const_iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		const_iterator& operator--()
		{
			--_ptr;
			return *this;
		}

		const_iterator operator--(int)
		{
			const_iterator tmp(*this);
			--_ptr;
			return tmp;
		}

		const_iterator& operator+=(size_type rhs)
		{
			_ptr += rhs;
			return *this;
		}

		const_iterator operator+(size_type rhs) const
		{
			return const_iterator(_ptr + rhs);
		}

		friend const_iterator operator+(size_type lhs, const const_iterator &rhs)
		{
			return const_iterator(lhs + rhs._ptr);
		}

		const_iterator& operator-=(size_type rhs)
		{
			_ptr -= rhs;
			return *this;
		}   

		const_iterator operator-(size_type rhs) const
		{
			return const_iterator(_ptr - rhs);
		}

		difference_type operator-(const_iterator it) const
		{
			return _ptr - it._ptr;
		}


		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->() const
		{
			return _ptr;
		}

		reference operator[](size_type rhs) const
		{
			return _ptr[rhs];
		}

	private:
		T *_ptr;
};

#endif