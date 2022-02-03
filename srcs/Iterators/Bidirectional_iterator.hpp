#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <memory>

template <class T, class A = std::allocator<T> >
class bidirectional_iterator { 
	public:
		typedef typename A::difference_type difference_type;
		typedef typename A::value_type value_type;
		typedef typename A::reference reference;
		typedef typename A::pointer pointer;
		typedef typename A::size_type size_type;
		typedef std::bidirectional_iterator_tag iterator_category;

		bidirectional_iterator() : _ptr(nullptr) {}
		bidirectional_iterator(const bidirectional_iterator &it) : _ptr(it._ptr) {}
		bidirectional_iterator(pointer pt) : _ptr(pt) {}
		~bidirectional_iterator(){}

		bidirectional_iterator& operator=(const bidirectional_iterator &it)
		{
			_ptr = it._ptr;
			return *this;
		}

		bool operator==(const bidirectional_iterator &it) const
		{
			return _ptr == it._ptr;
		}

		bool operator!=(const bidirectional_iterator &it) const
		{
			return _ptr != it._ptr;
		}

		bidirectional_iterator& operator++()
		{
			++_ptr;
			return *this;
		}

		bidirectional_iterator operator++(int)
		{
			bidirectional_iterator tmp(*this);
			++_ptr;
			return tmp;
		}

		bidirectional_iterator& operator--()
		{
			--_ptr;
			return *this;
		}

		bidirectional_iterator operator--(int)
		{
			bidirectional_iterator tmp(*this);
			--_ptr;
			return tmp;
		}

		reference operator*() const
		{
			return *_ptr;
		}

		pointer operator->() const
		{
			return _ptr;
		}

	private:
		T *_ptr;
};

#endif