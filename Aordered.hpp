#ifndef AORDERED_HPP
# define AORDERED_HPP

# include "Iterators/bidirectional_iterator.hpp"
# include "Iterators/reverse_iterator.hpp"
# include "RBtree.hpp" 

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<T>,
		class Alloc = std::allocator<T>
		>
	class Aordered {
	public:
		typedef	Key																			key_type;
		typedef	T																			value_type;
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
		typedef Itree<value_type>															tree_type;

	protected:
		allocator_type		_alloc;
		key_compare			_comp_func;
		
	public:
		virtual ~Aordered(){};

		//  ------------  ITERATOR FUNCTIONS  ------------
		iterator begin() _NOEXCEPT{
			return iterator(getTree().findSmallest(), &getTree());
		};
		const_iterator begin() const _NOEXCEPT{
			return const_iterator(getTree().findSmallest(), &getTree());
		}

		iterator end() _NOEXCEPT{
			return iterator(NULL, &getTree());
		}
		const_iterator end() const _NOEXCEPT{
			return const_iterator(NULL, &getTree());
		}

		reverse_iterator rbegin() _NOEXCEPT{
			return reverse_iterator(iterator(getTree().findLargest(), &getTree()));
		}
		const_reverse_iterator rbegin() const _NOEXCEPT{
			return const_reverse_iterator(const_iterator(getTree().findLargest(), &getTree()));
		}

		reverse_iterator rend() _NOEXCEPT{
			return reverse_iterator(iterator(NULL, &getTree()));
		}
		const_reverse_iterator rend() const _NOEXCEPT{
			return const_reverse_iterator(const_iterator(NULL, &getTree()));
		}


		// //  ------------  CAPACITY  ------------
		bool empty() const _NOEXCEPT{
			if (getTree().getSize() == 0)
				return true;
			return false;
		};
		
		size_type size() const _NOEXCEPT{
			return getTree().getSize();
		};
	

		// //  ------------  OBSERVERS   ------------
		key_compare key_comp() const{
			return _comp_func;
		};
	

		// //  ------------  OPERATIONS   ------------
		iterator lower_bound(const key_type& k){
			for(iterator it = begin(); it != end(); it++){
				if(!_comp_func(it->first, k))
					return it;
			}
			return end();
		};
		
		const_iterator lower_bound(const key_type& k) const{
			for(const_iterator it = begin(); it != end(); it++){
				if(!_comp_func(it->first, k))
					return it;
			}
			return end();
		};

		iterator upper_bound(const key_type& k){
			iterator it = lower_bound(k);
			if (it != end() && k == it->first)
				return ++it;
			return it;
		};
		const_iterator upper_bound(const key_type& k) const{
			const_iterator it = lower_bound(k);
			if (it != end() && k == it->first)
				return ++it;
			return it;
		};

		pair<iterator,iterator>	equal_range(const key_type& k){
			return ft::make_pair(lower_bound(k), upper_bound(k));
		};
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const{
			return ft::make_pair<const_iterator, const_iterator>(lower_bound(k), upper_bound(k));
		};
		
		//  ------------  ALLOCATOR   ------------
		allocator_type get_allocator() const{
			return _alloc;
		};

		protected:
		virtual const Itree<value_type>& getTree() const = 0;
	};
}

#endif
