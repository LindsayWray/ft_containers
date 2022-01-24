#ifndef VECTOR_HPP
# define VECTOR_HPP
# include <memory>
# include <cstring>
# include <stdexcept> 

namespace ft{
	template<typename value_type>
	class vector{
	private:
		value_type*					_array;
		unsigned long				_size;
		unsigned long				_allocSize;
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

		
		//CAPACITY
		unsigned long size() const{
			return _size;
		};
		unsigned long capacity() const{
			return _allocSize;
		};
		void	push_back(const value_type& val){
			if (_size == _allocSize){
				if (_allocSize == 0)
					_allocSize +=1;
				else
					_allocSize *= 2;
				try{
					value_type* _tempArray = _alloc.allocate(_allocSize);
					// std::memcpy(_tempArray, _array, _size * sizeof(value_type));   is there a way to use this only for basic types?;
					for(unsigned long i = 0; i < _size; i++){
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
			_alloc.construct(&_array[_size], val);
			_size++;
		};
		bool empty() const{
			if (_size == 0)
				return true;
			return false;
		};
		void resize(size_type n, value_type val = value_type()){
			if (n < _size){
				for (i = n; i < _size; i++){
					_alloc.destroy(&_array[i]);
				}
			}
		};

		//ELEMENT ACCESS
		value_type& operator[](unsigned int index) _NOEXCEPT{  //Array subscript operator
			return _array[index];
		};
		value_type const& operator[](unsigned int index) const _NOEXCEPT{
			return _array[index];
		};
		value_type& at(unsigned int index){
			if (index >= _size)
				throw(std::out_of_range("test")); // look into text / or make exception
			return _array[index];
		};
		value_type const& at(unsigned int index) const{
			if (index >= _size)
				throw(std::out_of_range("test"));
			return _array[index];
		};
		value_type& front() _NOEXCEPT{
			return _array[0];
		};
		value_type const& front() const _NOEXCEPT{
			return _array[0];
		};
		value_type& back() _NOEXCEPT{
			return _array[_size - 1];
		};
		value_type const& back() const _NOEXCEPT{
			return _array[_size - 1];
		};
	};
}

#endif
