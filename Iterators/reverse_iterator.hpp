#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

namespace ft{
	template<typename value_type>
	class reverse_iterator{
	public:
		typedef size_t	size_type;
		typedef long	difference_type;
	private:
		value_type* 	_ptr;
	public:
		reverse_iterator() : _ptr(NULL){};
		reverse_iterator(value_type* ptr) : _ptr(ptr){};
		reverse_iterator(reverse_iterator const& original) : _ptr(original._ptr){};
		~reverse_iterator(){};

		inline bool operator==(const reverse_iterator& rhs) const{ 
			return this->_ptr == rhs._ptr;
		}
		inline bool operator!=(const reverse_iterator& rhs) const{ 
			return this->_ptr != rhs._ptr;
		}
		bool operator<(const reverse_iterator& rhs) const{
			return this->_ptr > rhs._ptr;
		}
		bool operator>(const reverse_iterator& rhs) const{
			return this->_ptr < rhs._ptr;
		}
		bool operator<=(const reverse_iterator& rhs) const{
			return this->_ptr >= rhs._ptr;
		}
		bool operator>=(const reverse_iterator& rhs) const{
			return this->_ptr <= rhs._ptr;
		}

		reverse_iterator& operator++(){
			this->_ptr--;
			return *this;
		}
		reverse_iterator operator++(int){
			reverse_iterator copy(*this);
			this->_ptr--;
			return copy;
		}
		reverse_iterator& operator--(){
			this->_ptr++;
			return *this;
		}
		reverse_iterator operator--(int){
			reverse_iterator copy(*this);
			this->_ptr++;
			return copy;
		}
		value_type& operator*(){
			return *_ptr;	
		}
		value_type* operator->(){
			return _ptr;
		}
		value_type& operator[](size_type index) const{
			reverse_iterator copy(*this);
			copy._ptr += index;
			return *copy._ptr;
		}
		reverse_iterator operator+(const int &b) const{
			reverse_iterator copy(*this);
			copy._ptr -= b;
			return copy;
		}
		friend reverse_iterator operator+(const int &n, const reverse_iterator& b){ //friend gives acces, even though no instance is calling this function
			return b + n;
		}
		reverse_iterator operator-(const int &b) const{
			reverse_iterator copy(*this);
			copy._ptr += b;
			return copy;
		}
		difference_type operator-(const reverse_iterator& b) const{
			return b._ptr - this->_ptr;
		}
		reverse_iterator& operator+=(const int &b){
			this->_ptr -= b;
			return *this;
		}
		reverse_iterator& operator-=(const int &b){
			this->_ptr += b;
			return *this;
		}
	};
}

#endif
