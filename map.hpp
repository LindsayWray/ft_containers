#ifndef MAP_HPP
# define MAP_HPP

# include "Aordered.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<ft::pair<const Key, T> >
		>
	class map : public Aordered<Key, ft::pair<const Key, T>, Compare, Alloc> {	
	public:
		typedef	Key																			key_type;
		typedef	T																			mapped_type;
		typedef	ft::pair<const Key, T>														value_type;
		typedef	size_t																		size_type;
		typedef	ptrdiff_t																	difference_type;
		typedef	Compare																		key_compare;
		typedef	Alloc																		allocator_type;
		typedef	value_type&																	reference;
		typedef	const value_type&															const_reference;
		typedef	value_type*																	pointer;
		typedef	const value_type*															const_pointer;
		typedef	ft::bidirectional_iterator<value_type>										iterator;
		typedef	ft::bidirectional_iterator<value_type, const_pointer, const_reference>		const_iterator;
		typedef	ft::reverse_iterator<iterator>												reverse_iterator;
		typedef	ft::reverse_iterator<const_iterator>										const_reverse_iterator;

	private:
		class value_compare{
			friend class map;
			protected:
				key_compare _comp;
				value_compare (key_compare c) : _comp(c) {}  // constructed with map's comparison object
			public:
				typedef bool 			result_type;
				typedef value_type 		first_argument_type;
				typedef value_type 		second_argument_type;

				bool operator() (const value_type& x, const value_type& y) const{
					return _comp(x.first, y.first);
				}
		};

	public:
		typedef RBtree<value_type, Alloc, value_compare>									tree_type;

	private:
		tree_type							_tree;
		allocator_type						_alloc;
		key_compare							_comp_func;

	public:


		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
			: _tree(alloc, value_compare(comp)), _alloc(alloc), _comp_func(comp){};

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) 
				:  _tree(alloc, value_compare(comp)), _alloc(alloc), _comp_func(comp){
			insert(first, last);
		};

		map(const map& original) : _tree(original._alloc, value_compare(original._comp_func)) { *this = original; };

		~map(){ _tree.removeTree(); };

		map& operator= (const map& original){
			this->_tree = original._tree;
			this->_comp_func = original._comp_func;
			this->_tree.removeTree();
			insert(original.begin(), original.end());
			return *this;
		};

		
		size_type max_size() const _NOEXCEPT{
			return _alloc.max_size() / 2;
		};


		//  ------------  ELEMENT ACCESS   ------------x
		mapped_type& operator[] (const key_type& key) {
			value_type data = ft::make_pair(key, mapped_type());
			_tree.addLeaf(data);
			return _tree.findNode(data)->data->second;		
		};


		//  ------------  MODIFIERS   ------------
		pair<iterator,bool> insert (const value_type& val){
			bool inserted = _tree.addLeaf(val);
			return ft::make_pair(iterator(_tree.findNode(val), &_tree), inserted);
		};

		iterator insert(iterator position, const value_type& val){
			if(position->first == val.first)
				return position;
			return insert(val).first;
		};

		template <class InputIterator>
  		void insert(InputIterator first, InputIterator last){
			for(InputIterator it = first; it != last; it++)
				insert(*it);
		};

    	void erase(iterator position) _NOEXCEPT{
			iterator it = find(position->first);
			if (it == position)
				erase(position->first);
		};

		size_type erase(const key_type& key) _NOEXCEPT{
			size_t size = _tree.getSize();
			_tree.removeNode(ft::make_pair(key, mapped_type()));
			return size - _tree.getSize();
		};

     	void erase(iterator first, iterator last) _NOEXCEPT{
			 for(iterator it = first; it != last; ){
				iterator temp = it;
				temp++;
				erase(it->first);
				it = temp;
			 }
		 };

		void swap(map& x){
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

		//  ------------  OBSERVERS   ------------
		value_compare value_comp() const{
			return value_compare(_comp_func);
		};
	
		//  ------------  OPERATIONS   ------------
		iterator find(const key_type& k){
			return iterator(_tree.findNode(ft::make_pair(k, mapped_type())), &_tree);
		};
		const_iterator find(const key_type& k) const{
			return const_iterator(_tree.findNode(ft::make_pair(k, mapped_type())), &_tree);
		};

		 size_type count(const key_type& k) const{
			if (_tree.findNode(ft::make_pair(k, mapped_type())))
				return 1;
			return 0;
		};

		private:
		const Itree<value_type>& getTree() const{
			return _tree;
		}
	};


	// -------------  Non-member function overloads  -----------

	template< class Key, class T, class Compare, class Alloc >
	void swap( map<Key,T,Compare,Alloc>& lhs, map<Key,T,Compare,Alloc>& rhs ){
		lhs.swap(rhs);
	};

	// -------------- relational operators -------------------

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs == rhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template< class Key, class T, class Compare, class Alloc > 
	bool operator<=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(rhs < lhs);
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return rhs < lhs;
	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs ){
		return !(lhs < rhs);
	};
}

#endif
