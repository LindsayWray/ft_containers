#ifndef MAP_HPP
# define MAP_HPP


# include "vector.hpp"

namespace ft {
	template < class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> > >
	class map {
	public:
		typedef	Key												key_type;
		typedef	T												mapped_type;
		typedef	std::pair<const Key, T>							value_type;
		typedef	size_t											size_type;
		typedef	long											difference_type;
		typedef	Compare											key_compare;
		typedef	Alloc											allocator_type;
		typedef	value_type&										reference;
		typedef	const value_type&								const_reference;
		//typedef	BidirectionalIterator to value_type			iterator;
		//typedef	BidirectionalIterator to const value_type	const_iterator;
		//typedef	std::reverse_iterator<iterator>					reverse_iterator;
		//typedef	std::reverse_iterator<const_iterator>			const_reverse_iterator;
	private:
		struct node{
			key_type	key;
			mapped_type	value;
			node*		left;
			node*		right;
		};

		size_type			_size;
		node*				_root;
		allocator_type		_alloc;
		key_compare			_comp_func;


		//  ------------    HELPER FUNCTIONS   ------------
		node* CreateLeaf(key_type key){
			node* n = new node;
			n->key = key;
			n->left = NULL;
			n->right = NULL;

			return n;
		}

		void	AddLeaf(int key, node* ptr){
			if(root == NULL){
				root = CreateLeaf(key);
			}
			else if(key < ptr->key){
				if(ptr->left != NULL){
					AddLeaf(key, ptr->left);
				}
				else{
					ptr->left = CreateLeaf(key);
				}
			}
			else if(key < ptr->key){
				if(ptr->right != NULL){
					AddLeaf(key, ptr->right);
				}
				else{
					ptr->right = CreateLeaf(key);
				}
			}
			else{
				std::cout << "The key "<< key << "has already been added to the tree" << std::endl;
			}
		}


	public:
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _size(0), _root(NULL), _alloc(alloc), _comp_func(comp){};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());
		
		// map (const map& x);
	};

}

#endif
