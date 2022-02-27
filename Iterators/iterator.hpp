#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "bidirectional_iterator.hpp"

namespace ft{
	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	class iterator {
	public:
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef	Pointer							pointer;
		typedef	Reference						reference;
		typedef Category						iterator_category;

	private:
		value_type* 	_ptr;
		iterator() : _ptr(NULL){};
	public:
		iterator(value_type* ptr) : _ptr(ptr){};
		iterator(iterator const& original) : _ptr(original._ptr){};
		~iterator(){};

		iterator&	operator=(iterator const& original){
			this->_ptr = original._ptr;
			return *this;
		}

		inline bool operator==(const iterator& rhs) const{ 
			return this->_ptr == rhs._ptr;
		}
		inline bool operator!=(const iterator& rhs) const{ 
			return this->_ptr != rhs._ptr;
		}
		bool operator<(const iterator& rhs) const{
			return this->_ptr < rhs._ptr;
		}
		bool operator>(const iterator& rhs) const{
			return this->_ptr > rhs._ptr;
		}
		bool operator<=(const iterator& rhs) const{
			return this->_ptr <= rhs._ptr;
		}
		bool operator>=(const iterator& rhs) const{
			return this->_ptr >= rhs._ptr;
		}

		iterator& operator++(){
			this->_ptr++;
			return *this;
		}
		iterator operator++(int){
			iterator copy(*this);
			this->_ptr++;
			return copy;
		}
		iterator& operator--(){
			this->_ptr--;
			return *this;
		}
		iterator operator--(int){
			iterator copy(*this);
			this->_ptr--;
			return copy;
		}
		value_type& operator*(){
			return *(this->_ptr);
		}
		value_type* operator->(){
			return this->_ptr;
		}
		value_type& operator[](difference_type index) const{
			iterator copy(*this);
			copy._ptr += index;
			return *copy._ptr;
		}
		iterator operator+(const int& n) const{
			iterator copy(*this);
			copy._ptr += n;
			return copy;
		}
		friend iterator operator+(const int &n, const iterator& b){ //friend gives acces, even though no instance is calling this function
			return b + n;
		}
		iterator operator-(const int& b) const{
			iterator copy(*this);
			copy._ptr -= b;
			return copy;
		}
		difference_type operator-(const iterator& b) const{
			return this->_ptr - b._ptr;
		}
		iterator& operator+=(const int &b){
			this->_ptr += b;
			return *this;
		}
		iterator& operator-=(const int &b){
			this->_ptr -= b;
			return *this;
		}
	};
}

#endif
