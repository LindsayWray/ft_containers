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
		
		// map (const map& original);
		~map(){
			removeSubtree(this->_root);
		};

		//map& operator= (const map& original);







		//  ------------  ITERATOR FUNCTIONS  ------------
		// iterator begin();
		// const_iterator begin() const;

		// iterator end();
		// const_iterator end() const;

		// reverse_iterator rbegin();
		// const_reverse_iterator rbegin() const;

		// reverse_iterator rend();
		// const_reverse_iterator rend() const;







		//  ------------  CAPACITY  ------------
		bool empty() const _NOEXCEPT{
			if (this->_size == 0)
				return true;
			return false;
		};
		
		size_type size() const _NOEXCEPT{
			return this->_size;
		};
		
		size_type max_size() const _NOEXCEPT{
			return _alloc.max_size() / 2;
			//return std::numeric_limits<size_type>::max() / sizeof(value_type);
		};








		//  ------------  ELEMENT ACCESS   ------------
		mapped_type& operator[] (const key_type& key) {	//look into exceptions
			addLeaf(key, this->_root);
			return findNode(key, this->_root)->pair->second;
		};






		//  ------------  MODIFIERS   ------------
		// pair<iterator,bool> insert (const value_type& val)
		bool insert(const value_type& val){  // first try without iterator
			return addLeaf(val.first, this->_root, val.second);
		};

		// iterator insert(iterator position, const value_type& val);
		// template <class InputIterator>
  		// void insert(InputIterator first, InputIterator last);

    	// void erase(iterator position);
		size_type erase (const key_type& key){
			removeNode(findNode(key, this->_root)->pair, this->_root);
			return 1000;
		};
     	// void erase(iterator first, iterator last);

		//void swap(map& x);

		//void clear();






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



	private:
		//  ------------    HELPER FUNCTIONS   ------------
		//node* CreateLeaf(const key_type& key, mapped_type value = mapped_type()){
		node* CreateLeaf(const key_type& key, mapped_type value){
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

		bool	addLeaf(const key_type& key, node* ptr, mapped_type value = mapped_type()){
			bool hasBeenAdded = true;
			if(_root == NULL)
				_root = CreateLeaf(key, value);
			else if(key < ptr->pair->first){
				if(ptr->left != NULL)
					addLeaf(key, ptr->left);
				else
					ptr->left = CreateLeaf(key, value);
			}
			else if(key > ptr->pair->first){
				if(ptr->right != NULL)
					addLeaf(key, ptr->right);
				else
					ptr->right = CreateLeaf(key, value);
			}
			else{
				hasBeenAdded= false;
				std::cout << "The key "<< key << " has already been added to the tree" << std::endl;
			}
			return hasBeenAdded;
			
		}

		node*	findNode(const key_type& key, node* ptr){
			if(ptr != NULL){
				if(ptr->pair->first == key)
					return ptr;
				else{
					if(key < ptr->pair->first)
						return findNode(key, ptr->left);
					else
						return findNode(key, ptr->right);
				}
			}
			else
				return NULL;
		}

		void	removeSubtree(node* ptr){
			if(ptr != NULL){
				if(ptr->left != NULL)
					removeSubtree(ptr->left);
			if(ptr->right != NULL)
				removeSubtree(ptr->right);

			std::cout << "Deleting the node containing the key " << ptr->pair->first << std::endl;
			this->_alloc.destroy(ptr->pair);
			_alloc.deallocate(ptr->pair, 1);
			delete ptr;
			}
		}


		void	removeNode(value_type* val, node* parent){
			if(this->_root != NULL){
				if(this->_root->pair == val)
					RemoveRootMatch();
				else{
					if(val->first < parent->pair->first && parent->left != NULL){
						parent->left->pair->first == val->first ?
						RemoveMatch(parent, parent->left, true)	:
						removeNode(val, parent->left);
					}
					else if(val->first > parent->pair->first && parent->right != NULL){
						parent->right->pair->first == val->first ?
						RemoveMatch(parent, parent->right, false)	:
						removeNode(val, parent->right);
					}
					else
						std::cout << "The key " << val->first << " was not found in this tree\n";
				}
			}
			else
				std::cout << "The tree is empty\n";
		}

		void	RemoveRootMatch(){
			if(this->_root != NULL){
				node* delPtr = this->_root;
				key_type rootKey = this->_root->pair->first;
				key_type smallestInRightSubtree;

				// case 0  - root node has zero children
				if(this->_root->left == NULL && this->_root->right == NULL){
					this->_root = NULL;
					delete delPtr;
				}

				// case 1 - root node has one child
				else if(this->_root->left == NULL && this->_root->right != NULL){
					this->_root = this->_root->right;
					delPtr->right = NULL;  // perhaps optional, but is extra save
					delete delPtr;
					std::cout	<< "The root node with key " << rootKey 
								<< " was deleted. The new root contains key "
								<< this->_root->pair->first << std::endl;
				}

				else if(this->_root->left != NULL && this->_root->right == NULL){
					this->_root = this->_root->left;
					delPtr->left = NULL;  // perhaps optional, but is extra save
					delete delPtr;
					std::cout	<< "The root node with key " << rootKey 
								<< " was deleted. The new root contains key "
								<< this->_root->pair->first << std::endl;
				}

				// Case 2 - root node has two children
				else{
					//smallestInRightSubtree = FindSmallestPrivate(this->_root->right);
					removeNode(smallestInRightSubtree, this->_root);
					this->_root->pair = smallestInRightSubtree;
					std::cout	<< "The root key containing key " << rootKey <<
								" was overwritten with key " << this->_root->pair->first << std::endl;
				}
			}
			else
				std::cout << "Can not remove root. The tree is empty\n";
		}

			void	RemoveMatch(node* parent, node* match, bool left){
				if(this->_root != NULL){
					node* delPtr;
					key_type matchKey = match->pair->first;
					key_type smallestInRightSubtree;

					//Case 0 0 children
					if(match->left == NULL && match->right == NULL){
						delPtr = match;
						left == true ? parent->left = NULL : parent->right = NULL;

						//more cleaning
						delete delPtr;
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}

					// Case 1 - 1 child
					else if(match->left == NULL && match->right != NULL){
						left == true ? parent->left = match->right : parent->right = match->right;
						match->right = NULL;
						delPtr = match;
						delete delPtr;
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}

						else if(match->left != NULL && match->right == NULL){
						left == true ? parent->left = match->left : parent->right = match->left;
						match->left = NULL;
						delPtr = match;
						delete delPtr;
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}

					// Case 2 - node has 2 children
					else{
						smallestInRightSubtree = FindSmallestPrivate(match->right);
						removeNode(smallestInRightSubtree, match);
						match->pair.first = smallestInRightSubtree;
					}
				}
				else
					std::cout << "Can not remove match. The tree is empty\n";
			}
		};
	}

#endif
