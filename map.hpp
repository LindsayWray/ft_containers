#ifndef MAP_HPP
# define MAP_HPP

# include "Iterators/reverse_iterator.hpp"
# include "Iterators/bidirectional_iterator.hpp"
# include "vector.hpp"

# include "Btree.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> >
		>
	class map {
	public:
		typedef	Key																				key_type;
		typedef	T																				mapped_type;
		typedef	ft::pair<const Key, T>															value_type;
		typedef	size_t																			size_type;
		typedef	long																			difference_type;
		typedef	Compare																			key_compare;
		typedef	Alloc																			allocator_type;
		typedef	value_type&																		reference;
		typedef	const value_type&																const_reference;
		typedef	ft::bidirectional_iterator<std::bidirectional_iterator_tag, value_type>			iterator;
		typedef	ft::bidirectional_iterator<std::bidirectional_iterator_tag, const value_type>	const_iterator;
		typedef	ft::reverse_iterator<iterator>													reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>											const_reverse_iterator;
	private:

		Btree<value_type, Alloc>	_tree;
		allocator_type				_alloc;
		key_compare					_comp_func;


	public:
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(alloc), _alloc(alloc), _comp_func(comp){};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());
		
		// map (const map& original);
		~map(){
			_tree.removeTree();
		};

		//map& operator= (const map& original);







		//  ------------  ITERATOR FUNCTIONS  ------------
		iterator begin(){
			return iterator(_tree.FindSmallest());
		};
		// const_iterator begin() const;

		iterator end(){
			return NULL;
		}
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;






		//  ------------  CAPACITY  ------------
		bool empty() const _NOEXCEPT{
			if (_tree.getSize() == 0)
				return true;
			return false;
		};
		
		size_type size() const _NOEXCEPT{
			return _tree.getSize();
		};
		
		size_type max_size() const _NOEXCEPT{
			return _alloc.max_size() / 2;
		};








		//  ------------  ELEMENT ACCESS   ------------
		mapped_type& operator[] (const key_type& key) {	//look into exceptions
			_tree.addLeaf(key);
			return _tree.findNode(key)->pair->second;
		};






		//  ------------  MODIFIERS   ------------
		// pair<iterator,bool> insert (const value_type& val)
		bool insert(const value_type& val){  // first try without iterator
			return _tree.addLeaf(val.first, val.second);
		};

		// iterator insert(iterator position, const value_type& val);
		// template <class InputIterator>
  		// void insert(InputIterator first, InputIterator last);

    	// void erase(iterator position);
		size_type erase (const key_type& key){
			size_t size = _tree.getSize();
			_tree.removeNode(key);
			return size - _tree.getSize();
		};
     	// void erase(iterator first, iterator last);

		//void swap(map& x);

		void clear(){
			_tree.removeTree();
			_tree.setSize(0);
		};






		//  ------------  OBSERVERS   ------------
		//key_compare key_comp() const;
		
		//value_compare value_comp() const;
	






		//  ------------  OPERATIONS   ------------
		// iterator find(const key_type& k);
		// const_iterator find(const key_type& k) const;

		// size_type count(const key_type& k) const;

		// iterator lower_bound(const key_type& k);
		// const_iterator lower_bound(const key_type& k) const;

		// iterator upper_bound(const key_type& k);
		// const_iterator upper_bound(const key_type& k) const

		// pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
		// pair<iterator,iterator>             equal_range(const key_type& k);







		//  ------------  ALLOCATOR   ------------
		// allocator_type get_allocator() const;



		};
	}

#endif
