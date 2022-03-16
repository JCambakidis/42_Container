#ifndef RANDOMACCESSITERATOR_HPP
# define RANDOMACCESSITERATOR_HPP

# include <memory>

namespace ft
{
	template <class T, class A = std::allocator<T> >
	class iterator { 
		public:
			typedef typename A::difference_type difference_type;
			typedef typename A::reference reference;
			typedef typename A::pointer pointer;
			typedef typename A::size_type size_type;
			typedef std::random_access_iterator_tag iterator_category;

			iterator() : _ptr(nullptr) {}
			iterator(const iterator &it) : _ptr(it._ptr) {}
			iterator(pointer pt) : _ptr(pt) {}
			~iterator(){}

			iterator& operator=(const iterator &it)
			{
				_ptr = it._ptr;
				return *this;
			}

			bool operator==(const iterator &it) const
			{
				return _ptr == it._ptr;
			}

			bool operator!=(const iterator &it) const
			{
				return _ptr != it._ptr;
			}

			bool operator<(const iterator &it) const
			{
				return _ptr < it._ptr;
			} 

			bool operator>(const iterator &it) const
			{
				return _ptr > it._ptr;
			} 

			bool operator<=(const iterator &it) const
			{
				return _ptr <= it._ptr;
			}

			bool operator>=(const iterator &it) const
			{
				return _ptr >= it._ptr;
			}

			iterator& operator++()
			{
				++_ptr;
				return *this;
			}

			iterator operator++(int)
			{
				iterator tmp(*this);
				++_ptr;
				return tmp;
			}

			iterator& operator--()
			{
				--_ptr;
				return *this;
			}

			iterator operator--(int)
			{
				iterator tmp(*this);
				--_ptr;
				return tmp;
			}

			iterator& operator+=(size_type rhs)
			{
				_ptr += rhs;
				return *this;
			}

			iterator operator+(size_type rhs) const
			{
				return iterator(_ptr + rhs);
			}

			friend iterator operator+(size_type lhs, const iterator &rhs)
			{
				return iterator(lhs + rhs._ptr);
			}

			iterator& operator-=(size_type rhs)
			{
				_ptr -= rhs;
				return *this;
			}   

			iterator operator-(size_type rhs) const
			{
				return iterator(_ptr - rhs);
			}

			difference_type operator-(iterator it) const
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
}

#endif