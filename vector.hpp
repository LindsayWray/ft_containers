#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstring>
# include <stdexcept>

# include "Iterators/iterator.hpp"
# include "Iterators/reverse_iterator.hpp"
# include "utilities.hpp"

namespace ft{
	template<class T, class Alloc = std::allocator<T> >
	class vector{
	public:
		typedef size_t							size_type;
		typedef Alloc							allocator_type;
		typedef ft::iterator<T>					iterator;
		typedef ft::reverse_iterator<T>			reverse_iterator;
		typedef const ft::iterator<T>			const_iterator;
		typedef	T								value_type;
		typedef long							difference_type;

	private:
		value_type*					_array;
		size_type					_size;
		size_type					_allocSize;
		allocator_type				_alloc;

	public:
		explicit vector(const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _allocSize(0), _alloc(alloc){};
		explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : _array(NULL), _size(0), _allocSize(0), _alloc(alloc){
			increaseCapacity(n);					// to emulate the exact capacity like the real vector
			for(size_type i = 0; i < n; i++){
				push_back(val);
			}
		};
		template <class InputIterator>
		vector(InputIterator begin, InputIterator end, const allocator_type& alloc = allocator_type(),
				typename std::enable_if<!std::is_integral<InputIterator>::value, bool>::type = true)
				: _array(NULL), _size(0), _allocSize(0), _alloc(alloc){
		// vector(InputIterator begin, InputIterator end, const allocator_type& alloc = allocator_type())
		// 		: _array(NULL), _size(0), _allocSize(0), _alloc(alloc){
			increaseCapacity(end - begin);
			insert(this->begin(), begin, end);
		};
		vector(vector const& original) : _array(NULL), _size(0), _allocSize(0){
			*this = original;
		}
		~vector(){
			for(size_type i = 0; i < _size; i++){
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _allocSize);
		};

		vector& operator=(vector const& original){
			for(size_type i = 0; i < _size; i++){
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _allocSize);
			try{
				_array = _alloc.allocate(original._allocSize);
			}
			catch(std::bad_alloc &e){
				std::cerr << e.what() << std::endl;
				exit(EXIT_FAILURE);
			}
			_size = original._size;
			_allocSize = original._allocSize;
			_alloc = original._alloc;
			std::memcpy(_array, original._array, _size * sizeof(value_type));
			return *this;
		}



		//  ------------  ITERATOR FUNCTIONS  ------------
		iterator begin() _NOEXCEPT {
			return iterator(&_array[0]);
		};
		const_iterator begin() const _NOEXCEPT {
			return const_iterator(&_array[0]);
		};
		iterator end(){
			return iterator(&_array[_size]);
		};
		const_iterator end() const{
			return const_iterator(&_array[_size]);
		};
		reverse_iterator rbegin() _NOEXCEPT {
			return reverse_iterator(&_array[_size - 1]);
		};
		// const_iterator rbegin() const _NOEXCEPT {
			
		// };
		reverse_iterator rend(){
			return reverse_iterator(&_array[0] - 1);
		};
		// const_iterator rend() const{

		// };




		//  ------------  CAPACITY  ------------ 
		size_type size() const {
			return _size;
		};
		size_type max_size() const {
			return _alloc.max_size();
		};
		void resize(size_type n, value_type val = value_type()) {
			if(n <= _size){
				for(size_type i = n; i < _size; i++){
					_alloc.destroy(&_array[i]);
				}
			}
			else {
				if(n > _allocSize)
					increaseCapacity(n);
				for(size_type i = _size; i < n; i++) {
					_alloc.construct(&_array[i], val);
				}
			}
			_size = n;
		};
		size_type capacity() const {
			return _allocSize;
		};
		bool empty() const{
			if(_size == 0)
				return true;
			return false;
		};
		void reserve(size_type n) {
			if (n > _allocSize)
				increaseCapacity(n);
		};



		//  ------------  ELEMENT ACCESS   ------------
		value_type& operator[](size_type index) _NOEXCEPT {  //Array subscript operator
			return _array[index];
		};
		value_type const& operator[](size_type index) const _NOEXCEPT {
			return _array[index];
		};
		value_type& at(size_type index) {
			if (index >= _size)
				throw(std::out_of_range("1vector")); // look into text / or make exception
			return _array[index];
		};
		value_type const& at(size_type index) const {
			if (index >= _size)
				throw(std::out_of_range("vector"));
			return _array[index];
		};
		value_type& front() _NOEXCEPT {
			return _array[0];
		};
		value_type const& front() const _NOEXCEPT {
			return _array[0];
		};
		value_type& back() _NOEXCEPT {
			return _array[_size - 1];
		};
		value_type const& back() const _NOEXCEPT {
			return _array[_size - 1];
		};




		//  ------------  MODIFIERS   ------------

		template <class InputIterator>
		typename enable_if<!is_integral<InputIterator>::value,void>::type assign (InputIterator first, InputIterator last){
			this->clear();
			increaseCapacity(last - first);
			this->insert(this->end(), first, last);
		};
		void assign (size_type n, const value_type& val){
			this->clear();
			increaseCapacity(n);
				//printf("SIZE is: %d", static_cast<int>(_size));
			for(size_type i = 0; i < n; i++){
				push_back(val);
			}
		};

		void	push_back(const value_type& val) {
			if (_size == _allocSize){
				increaseCapacity();
				//printf("size is: %d", static_cast<int>(_size));
			}
			_alloc.construct(&_array[_size], val);
			_size++;
		};

		void pop_back(){
			_alloc.destroy(&_array[_size]);
			_size--;
		};

		iterator insert(iterator position, const value_type& val){
			int start_pos = position - this->begin();
			if(position == this->end()){
				push_back(val);
			}
			else{
				value_type temp_val = val;
				int pos = position - this->begin();
				if (_size == _allocSize){
					increaseCapacity();
				}
				while(position <= this->end()){
					value_type temp = _array[pos];
					_alloc.destroy(&_array[pos]);
					_alloc.construct(&_array[pos], temp_val);
					temp_val = temp;
					position++;
					pos++;
				}
				_size++;
			}
			return (this->begin() + start_pos);
		};
		void insert(iterator position, size_type n, const value_type& val){
			for(size_type i = 0; i < n; i++){
				position = insert(position, val);
				position++;
			}
		};
		template <class InputIterator>
		typename enable_if<!is_integral<InputIterator>::value,void>::type insert (iterator position, InputIterator first, InputIterator last){
			for(InputIterator it = first; it != last; ++it){
				position = insert(position, *it);
				position++;
			}
		};


		iterator erase (iterator position){
			iterator start_position = position;
			if(position == this->end()){
				pop_back();
			}
			else{
				int pos = position - this->begin();
				while(position <= this->end()){
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
		iterator erase (iterator first, iterator last){
			for(iterator it = first; it != last; it++){
				erase(first);
			}
			return first;
		};

		void swap (vector& x){
			ft::vector<value_type> temp;
			temp = *this;
			*this = x;
			x = temp;
		};

		void clear(){
			for(size_type i = 0; i < _size; i++){
				_alloc.destroy(&_array[i]);
			}
			_size = 0;
		};


		//  ------------  ALLOCATOR   ------------
		allocator_type get_allocator() const{
			return _alloc;
		};

	private:
		//  ------------    HELPER FUNCTIONS   ------------
		void increaseCapacity(size_type n){
			if (n < _allocSize)
				return;
			_allocSize = n;
			try{
				value_type* _tempArray = _alloc.allocate(_allocSize);
				for(size_type i = 0; i < _size; i++){
					_alloc.construct(_tempArray + i, _array[i]);
					_alloc.destroy(&_array[i]);
				}
				_alloc.deallocate(_array, _size);
				_array = _tempArray;
			}
			catch(std::bad_alloc &e){
				std::cerr << e.what() << std::endl;
				exit(EXIT_FAILURE);
			}
		}
		void increaseCapacity(){
			if (_allocSize == 0)
				_allocSize += 1;
			else
				_allocSize *= 2;
			increaseCapacity(_allocSize);
		}
	};
	
	// -------------  Non-member function overloads  -----------

	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
		x.swap(y);
	}

	// -------------- relational operators -------------------


	template <class T, class Alloc>
	bool operator==(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class T, class Alloc>
	bool operator!=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs == rhs);
	}

	template <class T, class Alloc>
	bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}

	template <class T, class Alloc>
	bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(rhs < lhs);
	}

	template <class T, class Alloc>
	bool operator>(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return rhs < lhs;
	}

	template <class T, class Alloc>
	bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
		return !(lhs < rhs);
	}

}

#endif
