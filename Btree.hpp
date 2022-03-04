#ifndef BTREE_HPP
# define BTREE_HPP

# include "utilities.hpp"

namespace ft {
	template<class T, class Alloc = std::allocator<T>, class Compare = std::less<typename T::first_type> >
	class Btree {
	public:
		typedef T								pair_type;
		typedef typename pair_type::first_type	key_type;
		typedef typename pair_type::second_type	mapped_type;
		typedef	Alloc							allocator_type;
		typedef	size_t							size_type;


		struct node{
			pair_type*		pair;
			node*			left;
			node*			right;
			node*			parent;
		};

		node*				_root;
		allocator_type		_alloc;
		size_type			_size;
		Compare				_compare;

		Btree(allocator_type alloc) : _root(NULL), _alloc(alloc), _size(0), _compare() {};

		size_type	getSize() const {
			return this->_size;
		}
		void	setSize(size_type newSize) {
			this->_size = newSize;
		}



		// void previous() {
		// if (this->_node->left) {
		// 	this->_node = this->_node->left;
		// 	while (this->_node->right)
		// 		this->_node = this->_node->right;-

		// }
		// else
		// 	this->_node = this->_node->parent;
		// }

		// void next() {
		// 	printf("test\n");
		// 	if (this->_node->right) {
		// 		printf("testing if\n");
		// 		this->_node = this->_node->right;
		// 		while (this->_node->left)
		// 			this->_node = this->_node->left;
		// 	}
		// 	else {
		// 		printf("testing else\n");
		// 		node* tmp = this->_node;
		// 		this->_node = this->_node->parent;
		// 		while (this->_node->left != tmp) {
		// 			tmp = this->_node;
		// 			this->_node = this->_node->parent;
		// 		}
		// 	}
		// }


		// void previous(node *ptr) {
		// if (ptr->left) {
		// 	ptr = ptr->left;
		// 	while (ptr->right)
		// 		ptr = ptr->right;
		// }
		// else
		// 	ptr = ptr->parent;
		// }

		// void next(node *ptr) {
		// 	//printf("test\n");
		// 	if (ptr->right) {
		// 		printf("testing if\n");
		// 		ptr = ptr->right;
		// 		while (ptr->left)
		// 			ptr = ptr->left;
		// 	}
		// 	else {
		// 		//printf("testing else\n");
		// 		node* tmp = ptr;
		// 		ptr = ptr->parent;
		// 		while (ptr->left != tmp) {
		// 			tmp = ptr;
		// 			ptr = ptr->parent;
		// 		}
		// 	}
		// }




		node* CreateLeaf(const key_type& key, mapped_type value, node* ptr) {
			node* newNode = new node;
			try{
				newNode->pair = _alloc.allocate(1);
				this->_alloc.construct(newNode->pair, ft::make_pair(key, value));
			}
			catch(std::bad_alloc &e){
				std::cerr << e.what() << std::endl;
				exit(EXIT_FAILURE);
			}
			newNode->left = NULL;
			newNode->right = NULL;
			newNode->parent = ptr;

			this->_size++;
			return newNode;
		}

		bool	addLeaf(const key_type& key, mapped_type value = mapped_type()) {
			return addLeaf(key, this->_root, value);
		}

		bool	addLeaf(const key_type& key, node* ptr, mapped_type value) {
			bool hasBeenAdded = true;
			if(_root == NULL)
				_root = CreateLeaf(key, value, NULL);
			else if(key < ptr->pair->first){
				if(ptr->left != NULL)
					return addLeaf(key, ptr->left, value);
				else
					ptr->left = CreateLeaf(key, value, ptr);
			}
			else if(key > ptr->pair->first){
				if(ptr->right != NULL)
					return addLeaf(key, ptr->right, value);
				else
					ptr->right = CreateLeaf(key, value, ptr);
			}
			else
				hasBeenAdded= false;
			return hasBeenAdded;
		}

		node*	findNode(const key_type& key) {
			return findNode(key, this->_root);
		}

		node*	findNode(const key_type& key, node* ptr) {
			if(ptr != NULL){
				if(ptr->pair->first == key)
					return ptr;
				else{
					if(key < ptr->pair->first)
						return findNode(key, ptr->left);
					else
						return findNode(key, ptr->right);
				}
				// else{
				// 	if(bool comp = _compare_func(key, ptr->pair->first))
				// 		return findNode(key, ptr->left);
				// 	else
				// 		return findNode(key, ptr->right);
				// }
			}
			else
				return NULL;
		}


		node*		FindSmallest() {
			return FindSmallest(this->_root);
		}

		node*		FindSmallest(node* ptr) {
			if(ptr->left != NULL)
				return FindSmallest(ptr->left);
			else
				return ptr;
		}

		node*		FindLargest() {
			return FindSmallest(this->_root);
		}

		node*		FindLargest(node* ptr) {
			if(ptr->right != NULL)
				return FindSmallest(ptr->right);
			else
				return ptr;
		}

		// node*	findParent(node* ptr, node* begin){
		// 	if(begin->left != ptr)
		// 		findParent(ptr, begin->left);
		// 	return ptr;
		// }

		void	removeTree(){
			removeSubtree(this->_root);
			this->_root = NULL;			//clearing an empty map
		}

		void	removeSubtree(node* ptr){
			if(ptr != NULL){
				if(ptr->left != NULL)
					removeSubtree(ptr->left);
				if(ptr->right != NULL)
					removeSubtree(ptr->right);
				//std::cout << "Deleting the node containing the key " << ptr->pair->first << std::endl;
				this->_alloc.destroy(ptr->pair);
				_alloc.deallocate(ptr->pair, 1);
				delete ptr;
			}
		}

		void	destroyNode(node* ptr){
				std::cout << "Deleting the node containing the key " << ptr->pair->first << std::endl;
				this->_alloc.destroy(ptr->pair);
				_alloc.deallocate(ptr->pair, 1);
				delete ptr;
				this->_size--;
		}

		void	removeNode(const key_type& key){
			removeNode(key, this->_root);
		}

		void	removeNode(key_type key, node* parent){
			if(this->_root != NULL){
				if(this->_root->pair->first == key)
					RemoveRootMatch();
				else{
					if(key < parent->pair->first && parent->left != NULL){
						parent->left->pair->first == key ?
						RemoveMatch(parent, parent->left, true)	:
						removeNode(key, parent->left);
					}
					else if(key > parent->pair->first && parent->right != NULL){
						parent->right->pair->first == key ?
						RemoveMatch(parent, parent->right, false)	:
						removeNode(key, parent->right);
					}
					else
						std::cout << "The key " << key << " was not found in this tree\n";
				}
			}
			else
				std::cout << "The tree is empty\n";
		}

		void	RemoveRootMatch(){
			if(this->_root != NULL){
				node* delPtr = this->_root;
				key_type rootKey = this->_root->pair->first;
				node* smallestInRightSubtree;

				// case 0  - root node has zero children
				if(this->_root->left == NULL && this->_root->right == NULL){
					this->_root = NULL;
					destroyNode(delPtr);
				}

				// case 1 - root node has one child
				else if(this->_root->left == NULL && this->_root->right != NULL){
					this->_root = this->_root->right;
					destroyNode(delPtr);
					std::cout	<< "The root node with key " << rootKey 
								<< " was deleted. The new root contains key "
								<< this->_root->pair->first << std::endl;
				}

				else if(this->_root->left != NULL && this->_root->right == NULL){
					this->_root = this->_root->left;
					destroyNode(delPtr);
					std::cout	<< "The root node with key " << rootKey 
								<< " was deleted. The new root contains key "
								<< this->_root->pair->first << std::endl;
				}

				// Case 2 - root node has two children
				else{
					smallestInRightSubtree = FindSmallest(this->_root->right);
					//node* parent = findParent(smallestInRightSubtree, this->_root);
					if(smallestInRightSubtree->parent == this->_root)
						smallestInRightSubtree->parent->right = smallestInRightSubtree->right;
					else
						smallestInRightSubtree->parent->left = smallestInRightSubtree->right;
					smallestInRightSubtree->left = this->_root->left;
					smallestInRightSubtree->right = this->_root->right;
					smallestInRightSubtree->parent = NULL;

					this->_root = smallestInRightSubtree;
					destroyNode(delPtr);
					std::cout	<< "The root key containing key " << rootKey <<
								" was overwritten with key " << this->_root->pair->first << std::endl;
				}
			}
			else
				std::cout << "Can not remove root. The tree is empty\n";
			}

			void	RemoveMatch(node* parent, node* match, bool left){
				if(this->_root != NULL){
					key_type matchKey = match->pair->first;
					node* smallestInRightSubtree;

					//Case 0 0 children
					if(match->left == NULL && match->right == NULL){
						left == true ? parent->left = NULL : parent->right = NULL;

						//more cleaning
						destroyNode(match);
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}

					// Case 1 - 1 child
					else if(match->left == NULL && match->right != NULL){
						left == true ? parent->left = match->right : parent->right = match->right;
						match->right = NULL;
						destroyNode(match);	
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}
					else if(match->left != NULL && match->right == NULL){
						left == true ? parent->left = match->left : parent->right = match->left;
						match->left = NULL;
						destroyNode(match);		
						std::cout << "the node containing key " << matchKey << " was removed\n";
					}

					// Case 2 - node has 2 children
					else{
						smallestInRightSubtree = FindSmallest(match->right);
						//node* parent = findParent(smallestInRightSubtree, this->_root);
						if (smallestInRightSubtree->left != NULL)
							smallestInRightSubtree->parent->left = smallestInRightSubtree->left;
						else
							smallestInRightSubtree->parent->left = NULL;
						smallestInRightSubtree->left = match->left;
						smallestInRightSubtree->right = match->right;
						smallestInRightSubtree->parent = match->parent;

						destroyNode(match);
						std::cout	<< "The root key containing key " << matchKey <<
									" was overwritten with key " << match->pair->first << std::endl;
					}
				}
				else
					std::cout << "Can not remove match. The tree is empty\n";
			}

			void	printInOrder(node* ptr){
				if(this->_root != NULL){
					if(ptr->left != NULL)
						printInOrder(ptr->left);
					std::cout << "key: " << ptr->pair->first << "  with value: " << ptr->pair->second << std::endl;
					if(ptr->right != NULL)
						printInOrder(ptr->right);
				}
				else
					std::cout << "The tree is empty\n" << std::endl;
			}

			void	printInOrder(){
				printInOrder(this->_root);
			}
	};
}

#endif
