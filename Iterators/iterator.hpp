#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft{
	template<typename value_type>
	class iterator{
	public:
		typedef size_t	size_type;
		typedef long	difference_type;
	private:
		value_type* 	_ptr;
	public:
		iterator() : _ptr(NULL){};
		iterator(value_type* ptr) : _ptr(ptr){};
		iterator(iterator const& original) : _ptr(original._ptr){};
		~iterator(){};

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
			return *_ptr;
		}
		value_type* operator->(){
			return _ptr;
		}
		value_type& operator[](size_type index) const{
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
