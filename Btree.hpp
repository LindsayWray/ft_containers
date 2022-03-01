#ifndef BTREE_HPP
# define BTREE_HPP

#include "map.hpp"

class MAP

namespace ft {
	template<class T>
	class Btree {
	public:
		typedef T 	value_type;

		struct node{
			value_type*		pair;
			node*			left;
			node*			right;
			node*			parent;
		};

		node*		_root;

		Btree() : _root(NULL) {};


		node* CreateLeaf(const key_type& key, mapped_type value, node* ptr){
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

		bool	addLeaf(const key_type& key, node* ptr, mapped_type value = mapped_type()){
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

		node*		FindSmallest(node* ptr){
			if(ptr->left != NULL)
				return FindSmallest(ptr->left);
			else
				return ptr;
		}

		// node*	findParent(node* ptr, node* begin){
		// 	if(begin->left != ptr)
		// 		findParent(ptr, begin->left);
		// 	return ptr;
		// }

		void	removeSubtree(){
			removeSubtree(this_root);
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

			void	destroyNode(node* ptr){
				std::cout << "Deleting the node containing the key " << ptr->pair->first << std::endl;
				this->_alloc.destroy(ptr->pair);
				_alloc.deallocate(ptr->pair, 1);
				delete ptr;
				this->_size--;
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
