#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft{
	template <	class T, class Pointer = T*, class Reference = T&,
				class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t>
		
	class iterator {
		// template <class T2, class ptr, class ref>
		// friend inline bool operator==(const iterator<T2, ptr, ref>& lhs, const iterator<T2, ptr, ref>& rhs) ;

		// template <class T2, class ptr, class ref>
		// friend bool operator<(const iterator<T2, ptr, ref>& lhs, const iterator<T2, ptr, ref>& rhs);

	public:
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef	Pointer							pointer;
		typedef	Reference						reference;
		typedef Category						iterator_category;
		typedef iterator<T, const T*, const T&>						const_iterator_type;

	private:
		value_type* 	_ptr;
	public:
		iterator() : _ptr(NULL){};
		iterator(value_type* ptr) : _ptr(ptr){};

		template <class U>
		iterator(iterator<U, U*, U&> const& original) : _ptr(original.get_pos()){};

		// template <class ptr, class ref>
		// iterator(iterator<T, ptr, ref> const& original) : _ptr(original.get_pos()){};
		~iterator(){};

		// type conversion operator
		operator const_iterator_type() const {
			return const_iterator_type(_ptr);
		}

		iterator&	operator=(iterator const& original){
			this->_ptr = original._ptr;
			return *this;
		}

		// inline bool operator==(const iterator& rhs) const{ 
		// 	//return this->_ptr == rhs._ptr;
		// 	return this->get_pos() == rhs.get_pos();
		// }
		// inline bool operator!=(const iterator& rhs) const{ 
		// 	return this->get_pos() != rhs.get_pos();
		// }
		// bool operator<(const iterator& rhs) const{
		// 	return this->get_pos() < rhs.get_pos();
		// }
		// bool operator>(const iterator& rhs) const{
		// 	return this->get_pos() > rhs.get_pos();
		// }
		// bool operator<=(const iterator& rhs) const{
		// 	return this->get_pos() <= rhs.get_pos();
		// }
		// bool operator>=(const iterator& rhs) const{
		// 	return this->get_pos() >= rhs.get_pos();
		// }




		friend inline bool operator==(const iterator& lhs, const iterator& rhs) { 
			return lhs.get_pos() == rhs.get_pos();
		}
		friend inline bool operator!=(const iterator& lhs, const iterator& rhs) { 
			return !(lhs.get_pos() == rhs.get_pos());
		}
		friend bool operator<(const iterator& lhs, const iterator& rhs) {
			return lhs.get_pos() < rhs.get_pos();
		}
		friend bool operator>(const iterator& lhs, const iterator& rhs) {
			return rhs.get_pos() < lhs.get_pos();
		}
		friend bool operator<=(const iterator& lhs, const iterator& rhs) {
			//return this->get_pos() <= rhs.get_pos();
			return !(rhs.get_pos() < lhs.get_pos());
		}
		friend bool operator>=(const iterator& lhs, const iterator& rhs) {
			//return this->get_pos() >= rhs.get_pos();
			return !(lhs.get_pos() < rhs.get_pos());
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
		reference operator*(){
			return *(this->_ptr);
		}
		pointer operator->(){
			return this->_ptr;
		}
		reference operator[](difference_type index) const{
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

		value_type* get_pos() const{
			return this->_ptr;
		}
	};

	// template <class T, class ptr, class ref>
	// inline bool operator==(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) { 
	// 	return lhs.get_pos() == rhs.get_pos();
	// }
	// template <class T, class ptr, class ref>
	// inline bool operator!=(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) { 
	// 	return !(lhs.get_pos() == rhs.get_pos());
	// }
	// template <class T, class ptr, class ref>
	// bool operator<(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) {
	// 	return lhs.get_pos() < rhs.get_pos();
	// }
	// template <class T, class ptr, class ref>
	// bool operator>(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) {
	// 	return rhs.get_pos() < lhs.get_pos();
	// }
	// template <class T, class ptr, class ref>
	// bool operator<=(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) {
	// 	//return this->get_pos() <= rhs.get_pos();
	// 	return !(rhs.get_pos() < lhs.get_pos());
	// }
	// template <class T, class ptr, class ref>
	// bool operator>=(const iterator<T, ptr, ref>& lhs, const iterator<T, ptr, ref>& rhs) {
	// 	//return this->get_pos() >= rhs.get_pos();
	// 	return !(lhs.get_pos() < rhs.get_pos());
	// }
}

#endif
