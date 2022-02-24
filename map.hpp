#ifndef MAP_HPP
# define MAP_HPP


# include "vector.hpp"

namespace ft {
	template <
		class Key,
		class T,
		class Compare = std::less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> >
		>
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
		//typedef	std::reverse_iterator<iterator>				reverse_iterator;
		//typedef	std::reverse_iterator<const_iterator>		const_reverse_iterator;
	private:
		struct node{
			// key_type	key;
			// mapped_type	value;
			value_type*	pair;
			node*		left;
			node*		right;
		};

		size_type			_size;
		node*				_root;
		allocator_type		_alloc;
		key_compare			_comp_func;


	public:
		explicit map (const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _size(0), _root(NULL), _alloc(alloc), _comp_func(comp){};

		// template <class InputIterator>
		// map (InputIterator first, InputIterator last,
		// const key_compare& comp = key_compare(),
		// const allocator_type& alloc = allocator_type());
		
		// map (const map& x);


		//  ------------  ELEMENT ACCESS   ------------
		mapped_type& operator[] (const key_type& key) {	//look into exceptions
			addLeaf(key, this->_root);
			return findNode(key, this->_root)->pair->second;
		};




	private:
		//  ------------    HELPER FUNCTIONS   ------------
		node* CreateLeaf(const key_type& key, mapped_type value = mapped_type()){
			node* newNode = new node;
			try{
				newNode->pair = _alloc.allocate(1);
				this->_alloc.construct(newNode->pair, std::make_pair(key, value));
				// newNode->pair->first = key;
				// newNode->pair->second = value;
			}
			catch(std::bad_alloc &e){
				std::cerr << e.what() << std::endl;
				exit(EXIT_FAILURE);
			}
			// newNode->key = key;
			// newNode->value = value;
			newNode->left = NULL;
			newNode->right = NULL;

			this->_size++;
			return newNode;
		}

		void	addLeaf(const key_type& key, node* ptr){
			if(_root == NULL)
				_root = CreateLeaf(key);
			else if(key < ptr->pair->first){
				if(ptr->left != NULL)
					addLeaf(key, ptr->left);
				else
					ptr->left = CreateLeaf(key);
			}
			else if(key > ptr->pair->first){
				if(ptr->right != NULL)
					addLeaf(key, ptr->right);
				else
					ptr->right = CreateLeaf(key);
			}
		// 	else
		// 		std::cout << "The key "<< key << " has already been added to the tree" << std::endl;
		}

		node*	findNode(const key_type& key, node* Ptr){
			if(Ptr != NULL){
				if(Ptr->pair->first == key)
					return Ptr;
				else{
					if(key < Ptr->pair->first)
						return findNode(key, Ptr->left);
					else
						return findNode(key, Ptr->right);
				}
			}
			else
				return NULL;
		}
	};
}

#endif
