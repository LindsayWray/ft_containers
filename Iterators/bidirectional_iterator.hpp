#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

namespace ft{
	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	class bidirectional_iterator{
	public:
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef	Pointer							pointer;
		typedef	Reference						reference;
		typedef Category						iterator_category;
	private:
		value_type* 	_ptr;
		bidirectional_iterator() : _ptr(NULL){};
	public:
		bidirectional_iterator(value_type* ptr) : _ptr(ptr){};
		bidirectional_iterator(bidirectional_iterator const& original) : _ptr(original._ptr){};
		~bidirectional_iterator(){};

		bidirectional_iterator&	operator=(bidirectional_iterator const& original){
			this->_ptr = original._ptr;
			return *this;
		}

		inline bool operator==(const bidirectional_iterator& rhs) const{ 
			return this->_ptr == rhs._ptr;
		}
		inline bool operator!=(const bidirectional_iterator& rhs) const{ 
			return this->_ptr != rhs._ptr;
		}

		bidirectional_iterator& operator++(){
			this->_ptr++;
			return *this;
		}
		bidirectional_iterator operator++(int){
			bidirectional_iterator copy(*this);
			this->_ptr++;
			return copy;
		}
		bidirectional_iterator& operator--(){
			this->_ptr--;
			return *this;
		}
		bidirectional_iterator operator--(int){
			bidirectional_iterator copy(*this);
			this->_ptr--;
			return copy;
		}
		value_type& operator*(){
			return *_ptr;
		}
		value_type* operator->(){
			return _ptr;
		}
	};
}

#endif
