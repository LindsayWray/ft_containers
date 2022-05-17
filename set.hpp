#ifndef SET_HPP
# define SET_HPP

# include "Iterators/bidirectional_iterator.hpp"
# include "Iterators/reverse_iterator.hpp"
# include "RBtree.hpp"

# include "Aordered.hpp"

namespace ft {
	template <
		class T,
		class Compare = std::less<T>,
		class Alloc = std::allocator<T>
		>
	class set : public Aordered<T, T, Compare, Alloc> {
	public:
		typedef	T																			key_type;
		typedef	T																			value_type;
		typedef	Compare																		key_compare;
		typedef Compare																		value_compare;
		typedef	Alloc																		allocator_type;
		typedef	value_type&																	reference;
		typedef	const value_type&															const_reference;
		typedef	value_type*																	pointer;
		typedef	const value_type*															const_pointer;
		typedef	ft::bidirectional_iterator<value_type>										iterator;
		typedef	ft::bidirectional_iterator<value_type, const_pointer, const_reference>		const_iterator;
		typedef	ft::reverse_iterator<iterator>												reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>										const_reverse_iterator;
		typedef	size_t																		size_type;
		typedef	ptrdiff_t																	difference_type;
		typedef RBtree<value_type, Alloc, Compare>											tree_type;

	private:
		tree_type			_tree;
		allocator_type		_alloc;
		key_compare			_comp_func;
		
	public:
		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
			: _tree(alloc, comp), _alloc(alloc), _comp_func(comp){};

		template <class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
				:  _tree(alloc, comp), _alloc(alloc), _comp_func(comp){
			insert(first, last);
		};


		set(const set& original){
			*this = original;
		};

		~set(){
			_tree.removeTree();
		};

		set& operator=(const set& original){
			this->_tree = original._tree;
			this->_comp_func = original._comp_func;
			this->_tree.removeTree();
			insert(original.begin(), original.end());
			return *this;
		};
		
		size_type max_size() const _NOEXCEPT{
			return _alloc.max_size() / 8;
		};


		//  ------------  MODIFIERS   ------------
		pair<iterator,bool> insert (const value_type& val){
			bool inserted = _tree.addLeaf(val);
			return ft::make_pair(iterator(_tree.findNode(val), &_tree), inserted);
		};

		iterator insert(iterator position, const value_type& val){
			if(*position == val)
				return position;
			return insert(val).first;
		};

		template <class InputIterator>
  		void insert(InputIterator first, InputIterator last){
			for(InputIterator it = first; it != last; it++)
				insert(*it);
		};

    	void erase(iterator position) _NOEXCEPT{
			iterator it = find(*position);
			if (it == position)
				erase(*position);
		};

		size_type erase(const key_type& key) _NOEXCEPT{
			size_t size = _tree.getSize();
			_tree.removeNode(key);
			return size - _tree.getSize();
		};

     	void erase(iterator first, iterator last) _NOEXCEPT{
			 for(iterator it = first; it != last; ){
				iterator temp = it;
				temp++;
				erase(*it);
				it = temp;
			 }
		 };


		void swap(set& x){
			_tree.swapTrees(x._tree);

			key_compare tempCompare = this->_comp_func;
			this->_comp_func = x._comp_func;
			x._comp_func = tempCompare;

			allocator_type tempAlloc= this->_alloc;
			this->_alloc = x._alloc;
			x._alloc = tempAlloc;
		};

		void clear(){
			_tree.removeTree();
		};

		// //  ------------  OBSERVERS   ------------

		value_compare value_comp() const{
			return _comp_func;
		};
	
		// //  ------------  OPERATIONS   ------------
		iterator find(const key_type& k){
			return iterator(_tree.findNode(k), &_tree);
		};
		const_iterator find(const key_type& k) const{
			return const_iterator(_tree.findNode(k), &_tree);
		};

		 size_type count(const key_type& k) const{
			if (_tree.findNode(k))
				return 1;
			return 0;
		};

		private:
		const Itree<value_type>& getTree() const{
			return _tree;
		}

	};

	// -------------  Non-member function overloads  -----------

	template< class Key, class Compare, class Alloc >
	void swap( set<Key,Compare,Alloc>& lhs, set<Key,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	};

	// -------------- relational operators -------------------

	template< class Key, class Compare, class Alloc >
	bool operator==( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template< class Key, class Compare, class Alloc >
	bool operator!=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		return !(lhs == rhs);
	};

	template< class Key, class Compare, class Alloc >
	bool operator<( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template< class Key, class Compare, class Alloc > 
	bool operator<=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		return !(rhs < lhs);
	};

	template< class Key, class Compare, class Alloc >
	bool operator>( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		return rhs < lhs;
	};

	template< class Key, class Compare, class Alloc >
	bool operator>=( const set<Key,Compare,Alloc>& lhs, const set<Key,Compare,Alloc>& rhs ){
		return !(lhs < rhs);
	};
}

#endif
