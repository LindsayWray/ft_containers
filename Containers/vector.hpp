#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstring>
# include <stdexcept>

# include "../Iterators/iterator.hpp"
# include "../Iterators/reverse_iterator.hpp"
# include "../Utils/utilities.hpp"

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
	public:
		typedef	T													value_type;
		typedef Alloc												allocator_type;
		typedef typename allocator_type::reference					reference;
		typedef typename allocator_type::const_reference			const_reference;
		typedef typename allocator_type::pointer					pointer;
		typedef typename allocator_type::const_pointer				const_pointer;
		typedef ft::iterator<T>										iterator;
		typedef ft::iterator<T, const_pointer, const_reference>		const_iterator;
		typedef ft::reverse_iterator<iterator>						reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;
		typedef std::ptrdiff_t										difference_type;
		typedef size_t												size_type;

	private:
		value_type*			_array;
		size_type			_size;
		size_type			_allocSize;
		allocator_type		_alloc;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _allocSize(0), _alloc(alloc){};

		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) 
					: _array(NULL), _size(0), _allocSize(0), _alloc(alloc){
			increaseCapacity(n);
			for(size_type i = 0; i < n; i++)
				push_back(val);
		};

		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, bool>::type = true)
				: _array(NULL), _size(0), _allocSize(0), _alloc(alloc) {
			increaseCapacity(rangeLength(begin, end));
			insert(this->begin(), begin, end);
		};

		vector(vector const& original) : _array(NULL), _size(0), _allocSize(0) { *this = original; }
		
		~vector(){
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_alloc.deallocate(_array, _allocSize);
		};

		vector& operator=(vector const& original){
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_alloc.deallocate(_array, _allocSize);
			_array = _alloc.allocate(original._allocSize);
			_size = original._size;
			_allocSize = original._allocSize;
			_alloc = original._alloc;
			for(size_type i = 0; i < _size; i++)
				_alloc.construct(&_array[i], original._array[i]);
			//std::memcpy(_array, original._array, _size * sizeof(value_type));
			return *this;
		}


		//  ------------  ITERATOR FUNCTIONS  ------------
		iterator begin() _NOEXCEPT { return iterator(&_array[0]); };
		const_iterator begin() const _NOEXCEPT { return const_iterator(&_array[0]); };

		iterator end() _NOEXCEPT { return iterator(&_array[_size]); };
		const_iterator end() const _NOEXCEPT { return const_iterator(&_array[_size]); };

		reverse_iterator rbegin() _NOEXCEPT { return reverse_iterator(end()); };
		const_reverse_iterator rbegin() const _NOEXCEPT { return const_reverse_iterator(end()); };

		reverse_iterator rend() _NOEXCEPT { return reverse_iterator(begin()); };
		const_reverse_iterator rend() const _NOEXCEPT { return const_reverse_iterator(begin()); };


		//  ------------  CAPACITY  ------------ 
		size_type size() const { return _size; };

		size_type max_size() const { return _alloc.max_size(); };

		void resize(size_type n, value_type val = value_type()) {
			if(n <= _size) {
				for(size_type i = n; i < _size; i++)
					_alloc.destroy(&_array[i]);
			} else {
				if(n > _allocSize)
					increaseCapacity(n);
				for(size_type i = _size; i < n; i++)
					_alloc.construct(&_array[i], val);
			}
			_size = n;
		};

		size_type capacity() const { return _allocSize; };

		bool empty() const{ return (_size == 0); };

		void reserve(size_type n) {
			if (n > _allocSize)
				increaseCapacity(n);
		};


		//  ------------  ELEMENT ACCESS   ------------
		reference operator[](size_type index) _NOEXCEPT { return _array[index]; };
		const_reference operator[](size_type index) const _NOEXCEPT { return _array[index]; };

		reference at(size_type index) {
			if (index >= _size)
				throw(std::out_of_range("vector"));
			return _array[index];
		};
		const_reference at(size_type index) const {
			if (index >= _size)
				throw(std::out_of_range("vector"));
			return _array[index];
		};

		reference front() _NOEXCEPT { return _array[0]; };
		const_reference front() const _NOEXCEPT { return _array[0]; };

		reference back() _NOEXCEPT { return _array[_size - 1]; };
		const_reference back() const _NOEXCEPT { return _array[_size - 1]; };



		//  ------------  MODIFIERS   ------------
		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value,void>::type assign (InputIterator first, InputIterator last) {
			clear();
			increaseCapacity(rangeLength(first, last));
			insert(end(), first, last);
		};

		void assign (size_type n, const value_type& val) {
			clear();
			increaseCapacity(n);
			for(size_type i = 0; i < n; i++)
				push_back(val);
		};

		void	push_back(const value_type& val) {
			if (_size == _allocSize)
				increaseCapacity();
			_alloc.construct(&_array[_size], val);
			_size++;
		};

		void pop_back() {
			_alloc.destroy(&_array[_size]);
			if (_size > 0)
				_size--;
		};

		iterator insert(iterator position, const value_type& val) {
			int start_pos = position - begin();
			if(position == end()){
				push_back(val);
			} else {
				value_type temp_val = val;
				int pos = position - begin();
				if (_size == _allocSize){
					increaseCapacity();
					position = begin() + pos;
				}
				while(position <= end()){
					value_type temp = _array[pos];
					_alloc.destroy(&_array[pos]);
					_alloc.construct(&_array[pos], temp_val);
					temp_val = temp;
					position++;
					pos++;
				}
				_size++;
			}
			return (begin() + start_pos);
		};

		void insert(iterator position, size_type n, const value_type& val) {
			for(size_type i = 0; i < n; i++) {
				position = insert(position, val);
				position++;
			}
		};

		template <class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value,void>::type insert (iterator position, InputIterator first, InputIterator last) {
			for(InputIterator it = first; it != last; it++) {
				position = insert(position, *it);
				position++;
			}
		};

		iterator erase (iterator position) {
			iterator start_position = position;
			if(position == end()) {
				pop_back();
			} else {
				int pos = position - begin();
				while(position <= end()){
					value_type temp = _array[pos + 1];
					_alloc.destroy(&_array[pos]);
					_alloc.construct(&_array[pos], temp);
					position++;
					pos++;
				}
				_size--;
			}
			return (start_position);
		};

		iterator erase (iterator first, iterator last) {
			for(iterator it = first; it != last; it++)
				erase(first);
			return first;
		};

		void swap (vector& x) {
			value_type* temp = _array;
			_array = x._array;
			x._array = temp;

			size_type tempSize = _size;
			_size = x._size;
			x._size = tempSize;

			size_type tempAllocSize = _allocSize;
			_allocSize = x._allocSize;
			x._allocSize = tempAllocSize;

			allocator_type tempAlloc= _alloc;
			_alloc = x._alloc;
			x._alloc = tempAlloc;
		};

		void clear() {
			for(size_type i = 0; i < _size; i++)
				_alloc.destroy(&_array[i]);
			_size = 0;
		};


		//  ------------  ALLOCATOR   ------------
		allocator_type get_allocator() const{ return _alloc; };


		//  ------------    HELPER FUNCTIONS   ------------
	private:
		void increaseCapacity(size_type n) {
			if (n < _allocSize)
				return;
			_allocSize = n;
			value_type* _tempArray = _alloc.allocate(_allocSize);
			for(size_type i = 0; i < _size; i++) {
				_alloc.construct(_tempArray + i, _array[i]);
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _size);
			_array = _tempArray;
		}
		
		void increaseCapacity() {
			if (_allocSize == 0)
				_allocSize += 1;
			else
				_allocSize *= 2;
			increaseCapacity(_allocSize);
		}

		template <class InputIterator>
		size_type rangeLength(InputIterator& first, InputIterator& last) {
			size_type count = 0;
			for(InputIterator it = first; it != last; it++, count++);
			return count;
		};
	};
	

	// -------------  Non-member function overloads  -----------
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) { x.swap(y); }


	// -------------- relational operators -------------------
	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(rhs < lhs); }

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return rhs < lhs; }

	template <class T, class Alloc>
	bool operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) { return !(lhs < rhs); }
}

#endif
