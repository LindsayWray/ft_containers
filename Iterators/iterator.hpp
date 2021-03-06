#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft {
	template <	class T, class Pointer = T*, class Reference = T&,
				class Category = std::random_access_iterator_tag, class Distance = std::ptrdiff_t>
	class iterator {
	public:
		typedef T								value_type;
		typedef Distance						difference_type;
		typedef	Pointer							pointer;
		typedef	Reference						reference;
		typedef Category						iterator_category;
		typedef iterator<T, const T*, const T&>	const_iterator_type;

	private:
		value_type* 	_ptr;
	public:
		iterator() : _ptr(NULL) {};
		iterator(value_type* ptr) : _ptr(ptr) {};

		iterator(iterator const& original) : _ptr(original.get_pos()) {};

		~iterator() {};

		iterator&	operator=(iterator const& original) {
			_ptr = original._ptr;
			return *this;
		}

		operator const_iterator_type() const { return const_iterator_type(_ptr); }	// ********* type conversion operator *********

		// ********* Non member operator overloads *********
		friend inline bool operator==(const iterator& lhs, const iterator& rhs) { return lhs.get_pos() == rhs.get_pos(); }

		friend inline bool operator!=(const iterator& lhs, const iterator& rhs) { return !(lhs.get_pos() == rhs.get_pos()); }

		friend bool operator<(const iterator& lhs, const iterator& rhs) { return lhs.get_pos() < rhs.get_pos(); }

		friend bool operator>(const iterator& lhs, const iterator& rhs) { return rhs.get_pos() < lhs.get_pos(); }

		friend bool operator<=(const iterator& lhs, const iterator& rhs) { return !(rhs.get_pos() < lhs.get_pos()); }

		friend bool operator>=(const iterator& lhs, const iterator& rhs) { return !(lhs.get_pos() < rhs.get_pos()); }

		iterator& operator++() {
			_ptr++;
			return *this;
		}
		iterator operator++(int) {
			iterator copy(*this);
			_ptr++;
			return copy;
		}

		iterator& operator--() {
			_ptr--;
			return *this;
		}
		iterator operator--(int) {
			iterator copy(*this);
			_ptr--;
			return copy;
		}

		reference operator*() { return *(_ptr); }
		reference operator*() const { return *(_ptr); }

		pointer operator->() { return _ptr; }
		pointer operator->() const { return _ptr; }

		reference operator[](difference_type index) const {
			iterator copy(*this);
			copy._ptr += index;
			return *copy._ptr;
		}

		iterator operator+(const int& n) const {
			iterator copy(*this);
			copy._ptr += n;
			return copy;
		}
		friend iterator operator+(const int &n, const iterator& b){ return b + n; }

		iterator operator-(const int& b) const {
			iterator copy(*this);
			copy._ptr -= b;
			return copy;
		}
		difference_type operator-(const const_iterator_type& b) const { return _ptr - b.get_pos(); }

		iterator& operator+=(const int &b) {
			_ptr += b;
			return *this;
		}

		iterator& operator-=(const int &b) {
			_ptr -= b;
			return *this;
		}

		// helper to give const_iterator access to position of iterator for copying/conversion
		value_type* get_pos() const{ return _ptr; }
	};
}

#endif
