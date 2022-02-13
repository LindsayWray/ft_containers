#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstring>
# include <stdexcept>

namespace ft{
	template<typename value_type>
	class vector{
	public:
		typedef size_t						size_type;
		typedef std::allocator<value_type>	allocator_type;
		//typedef ft::vector<int>::iterator it
	private:
		value_type*					_array;
		size_type					_size;
		size_type					_allocSize;
		std::allocator<value_type>	_alloc;
	public:
		vector() : _array(NULL), _size(0), _allocSize(0){
		};
		vector(vector const& original){
			*this = original;
		}
		~vector(){
			for(unsigned long i = 0; i < _size; i++){
				_alloc.destroy(&_array[i]);
			}
			_alloc.deallocate(_array, _allocSize);
		};

		vector& operator=(vector const& original){
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


		//  ------------    HELPER FUNCTIONS   ------------
		void increaseCapacity(size_type n){
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
				_allocSize +=1;
			else
				_allocSize *= 2;
			increaseCapacity(_allocSize);
		}

		


		//  ------------  ITERATORS  ------------
		class iterator{
		private:
			value_type* 	_ptr;
		public:
			typedef size_t	difference_type;
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
			iterator operator+(const int &b) const{
				iterator copy(*this);
				copy._ptr += b;
				return copy;
			}
			// iterator operator+(const int &b) const{   //the int plus iter problem
			// 	iterator copy(*this);
			// 	copy._ptr += b;
			// 	return copy;
			// }
			iterator operator-(const int &b) const{
				iterator copy(*this);
				copy._ptr -= b;
				return copy;
			}
			// difference_type operator-(iterator &b) const{  //subtracting iters problem
			// 	iterator copy(*this);
			// 	copy._ptr -= b;
			// 	return copy;
			// }
			iterator& operator+=(const int &b){
				this->_ptr += b;
				return *this;
			}
			iterator& operator-=(const int &b){
				this->_ptr -= b;
				return *this;
			}
		};

		class reverse_iterator{
		private:
			value_type* 	_ptr;
		public:
			typedef size_t	difference_type;
			reverse_iterator() : _ptr(NULL){};
			reverse_iterator(value_type* ptr) : _ptr(ptr){};
			reverse_iterator(reverse_iterator const& original) : _ptr(original._ptr){};
			~reverse_iterator(){};

		// 	inline bool operator==(const reverse_iterator& rhs) const{ 
		// 		return this->_ptr == rhs._ptr;
		// 	}
		// 	inline bool operator!=(const reverse_iterator& rhs) const{ 
		// 		return this->_ptr != rhs._ptr;
		// 	}
		// 	bool operator<(const reverse_iterator& rhs) const{
		// 		return this->_ptr < rhs._ptr;
		// 	}
		// 	bool operator>(const reverse_iterator& rhs) const{
		// 		return this->_ptr > rhs._ptr;
		// 	}
		// 	bool operator<=(const reverse_iterator& rhs) const{
		// 		return this->_ptr <= rhs._ptr;
		// 	}
		// 	bool operator>=(const reverse_iterator& rhs) const{
		// 		return this->_ptr >= rhs._ptr;
		// 	}

		// 	reverse_iterator& operator++(){
		// 		this->_ptr++;
		// 		return *this;
		// 	}
		// 	reverse_iterator operator++(int){
		// 		iterator copy(*this);
		// 		this->_ptr++;
		// 		return copy;
		// 	}
		// 	reverse_iterator& operator--(){
		// 		this->_ptr--;
		// 		return *this;
		// 	}
		// 	reverse_iterator operator--(int){
		// 		iterator copy(*this);
		// 		this->_ptr--;
		// 		return copy;
		// 	}
			value_type& operator*(){
				return *_ptr;
			}
		// 	value_type* operator->(){
		// 		return _ptr;
		// 	}
		// 	value_type& operator[](size_type index) const{
		// 		reverse_iterator copy(*this);
		// 		copy._ptr += index;
		// 		return *copy._ptr;
		// 	}
		// 	reverse_iterator operator+(const int &b) const{
		// 		iterator copy(*this);
		// 		copy._ptr += b;
		// 		return copy;
		// 	}
		// 	// reverse_iterator operator+(const int &b) const{   //the int plus iter problem
		// 	// 	reverse_iterator copy(*this);
		// 	// 	copy._ptr += b;
		// 	// 	return copy;
		// 	// }
		// 	reverse_iterator operator-(const int &b) const{
		// 		reverse_iterator copy(*this);
		// 		copy._ptr -= b;
		// 		return copy;
		// 	}
		// 	// difference_type operator-(iterator &b) const{  //subtracting iters problem
		// 	// 	reverse_iterator copy(*this);
		// 	// 	copy._ptr -= b;
		// 	// 	return copy;
		// 	// }
		// 	reverse_iterator& operator+=(const int &b){
		// 		this->_ptr += b;
		// 		return *this;
		// 	}
		// 	reverse_iterator& operator-=(const int &b){
		// 		this->_ptr -= b;
		// 		return *this;
		// 	}
		};


		iterator begin() _NOEXCEPT {
			return iterator(_array);
		};
		// const_iterator begin() const _NOEXCEPT {
			
		// };
		iterator end(){
			return iterator(&_array[_size]);
		};
		// const_iterator end() const{

		// };
		reverse_iterator rbegin() _NOEXCEPT {
			return reverse_iterator(&_array[_size]);
		};
		// const_iterator begin() const _NOEXCEPT {
			
		// };
			// iterator rend(){
			// 	return iterator(&_array[_size]);
			// };
		// const_iterator end() const{

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
				while(n > _allocSize)
					increaseCapacity();
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
				throw(std::out_of_range("test")); // look into text / or make exception
			return _array[index];
		};
		value_type const& at(size_type index) const {
			if (index >= _size)
				throw(std::out_of_range("test"));
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
		void	push_back(const value_type& val) {
			if (_size == _allocSize){
				increaseCapacity();
			}
			_alloc.construct(&_array[_size], val);
			_size++;
		};

		void pop_back(){

		};


		// iterator erase (iterator position);
		// iterator erase (iterator first, iterator last);

		// void swap (vector& x);

		// void clear();


		//  ------------  ALLOCATOR   ------------
		allocator_type get_allocator() const{
			return _alloc;
		};

		// -------------  Non-member function overloads  -----------

	};

}

#endif
