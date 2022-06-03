#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "Itree.hpp"
 
namespace ft {
	template<class T, class Alloc, class Compare >
	class RBtree : public Itree<T> {
	public:
		typedef Itree<T>											Itree;
		typedef typename Itree::data_type							data_type;
		typedef Alloc												allocator_type;
		typedef typename Itree::node								node;
		typedef typename Alloc::template rebind<node>::other		node_allocator_type;
		typedef	size_t												size_type;

	private:
		node*				_root;
		allocator_type		_alloc;
		node_allocator_type	_nodeAlloc;
		size_type			_size;
		Compare				_compare;		

	public:
		RBtree(allocator_type alloc, Compare compare) : _root(NULL), _alloc(alloc), _size(0), _compare(compare) {};
		RBtree() : _root(NULL), _alloc(), _size(0), _compare() {};
		~RBtree() {};

		RBtree& operator=(const RBtree& original) {
			_alloc = original._alloc;
			_nodeAlloc = original._nodeAlloc;
			_size = original._size;
			_compare = original._compare;
			return *this;
		}

		//  		**************   ADD FUNCTIONS   **************
		bool	addLeaf(data_type data) { return addLeaf(this->_root, data); }

	private:
		bool	addLeaf(node* ptr, data_type& data) {
			bool hasBeenAdded = true;
			if(_root == NULL){
				_root = createLeaf(NULL, data);
				_root->color = BLACK;
			} else if(_compare(data, *(ptr->data))) {
				if(ptr->left != NULL) {
					return addLeaf(ptr->left, data);
				} else {
					ptr->left = createLeaf(ptr, data);
					fixRedBlackPropertiesAfterInsert(ptr->left);
				}
			} else if(_compare(*(ptr->data), data)) {
				if(ptr->right != NULL) {
					return addLeaf(ptr->right, data);
				} else {
					ptr->right = createLeaf(ptr, data);
					fixRedBlackPropertiesAfterInsert(ptr->right);
				}
			} else
				hasBeenAdded = false;
			return hasBeenAdded;
		}

		node* createLeaf(node* ptr, data_type& data) {
			node* newNode = _nodeAlloc.allocate(1);
			_nodeAlloc.construct(newNode, node(ptr));
			newNode->data = _alloc.allocate(1);
			_alloc.construct(newNode->data, data);
			_size++;
			return newNode;
		}


		// 	 ************** REMOVAL FUNCTIONS **************
	public:
		void	removeTree(){
			removeSubtree(_root);
			_root = NULL;		//clearing an empty map
			_size = 0;
		}

		void	removeNode(const data_type& data) { removeNode(data, this->_root); }

	private:
		void	removeNode(const data_type& data, node* parent) {
			if(_root != NULL) {
				if(isEqual(*(_root->data), data)) {
					RemoveMatch(NULL, _root);
				} else {
					if(_compare(data, *(parent->data)) && parent->left != NULL) {
						isEqual(*(parent->left->data), data) ?
						RemoveMatch(parent, parent->left)	:
						removeNode(data, parent->left);
					} else if(_compare(*(parent->data), data) && parent->right != NULL) {
						isEqual(*(parent->right->data), data) ?
						RemoveMatch(parent, parent->right)	:
						removeNode(data, parent->right);
					}
				}
			}
		}
		
		void	removeSubtree(node* ptr) {
			if(ptr != NULL) {
				if(ptr->left != NULL)
					removeSubtree(ptr->left);
				if(ptr->right != NULL)
					removeSubtree(ptr->right);
				_alloc.destroy(ptr->data);
				_alloc.deallocate(ptr->data, 1);
				_nodeAlloc.destroy(ptr);
				_nodeAlloc.deallocate(ptr, 1);
			}
		}

		void	destroyNode(node* ptr) {
				_alloc.destroy(ptr->data);
				_alloc.deallocate(ptr->data, 1);
				_nodeAlloc.destroy(ptr);
				_nodeAlloc.deallocate(ptr, 1);
				_size--;
		}

		void	RemoveMatch(node* parent, node* match) {
			node* movedUpNode = match;
			color deletedNodeColor = match->color;
			bool isNILnode = false;
			node* nilNode = NULL;
			
			if(match->left == NULL && match->right == NULL)	{				//Case 0 - 0 children
				isNILnode = true;
				nilNode = match;
			} else if (match->left == NULL || match->right == NULL ) {		// Case 1 - 1 child
				if(match->right != NULL)
					movedUpNode = match->right;
				else
					movedUpNode = match->left;
				replaceParentsChild(parent, match, movedUpNode);
				movedUpNode->parent = match->parent;
				destroyNode(match);
			} else {														// Case 2 - node has 2 children
				node* smallestInRightSubtree = findSmallest(match->right);
				if (smallestInRightSubtree->right) {
					movedUpNode = smallestInRightSubtree->right;
				} else {
					isNILnode = true;
					data_type nilData = data_type();
					nilNode = createLeaf(NULL, nilData);
					nilNode->color = BLACK;
					replaceParentsChild(smallestInRightSubtree->parent, smallestInRightSubtree, nilNode);
					movedUpNode = nilNode;
				}
								
				if(smallestInRightSubtree->parent == match) {
					replaceParentsChild(match->parent, match, smallestInRightSubtree);
					smallestInRightSubtree->left = match->left;
					match->left->parent = smallestInRightSubtree;
					if (!smallestInRightSubtree->right) {
						smallestInRightSubtree->right = nilNode;
						nilNode->parent = smallestInRightSubtree;
					}
				} else {
					if (smallestInRightSubtree->right) {
						smallestInRightSubtree->right->parent = smallestInRightSubtree->parent;
						smallestInRightSubtree->parent->left = smallestInRightSubtree->right;
					}
					replaceParentsChild(match->parent, match, smallestInRightSubtree);
					smallestInRightSubtree->left = match->left;
					match->left->parent = smallestInRightSubtree;
					smallestInRightSubtree->right = match->right;
					match->right->parent = smallestInRightSubtree;
				}
				deletedNodeColor = smallestInRightSubtree->color;
				smallestInRightSubtree->color = match->color;
				destroyNode(match);
			}
			if (deletedNodeColor == BLACK)
				fixRedBlackPropertiesAfterDelete(movedUpNode);
			if(isNILnode) {
				replaceParentsChild(nilNode->parent, nilNode, NULL);
				destroyNode(nilNode);
			}
		}


		//  ************** FAMILY HANDLERS **************
		void handleRedSibling(node* ptr, node* sibling) {
			sibling->color = BLACK;
			ptr->parent->color = RED;
			if (ptr == ptr->parent->left)
				rotateLeft(ptr->parent);
			else
				rotateRight(ptr->parent);
		}

		void handleBlackSiblingWithAtLeastOneRedChild(node* ptr, node* sibling) {
			bool nodeIsLeftChild = (ptr == ptr->parent->left);

			// Case 5: Black sibling with at least one red child + "outer nephew" is black
			// --> Recolor sibling and its child, and rotate around sibling
			if (nodeIsLeftChild && isBlack(sibling->right)) {
				sibling->left->color = BLACK;
				sibling->color = RED;
				rotateRight(sibling);
				sibling = ptr->parent->right;
			} else if (!nodeIsLeftChild && isBlack(sibling->left)) {
				sibling->right->color = BLACK;
				sibling->color = RED;
				rotateLeft(sibling);
				sibling = ptr->parent->left;
			}
			// Case 6: Black sibling with at least one red child + "outer nephew" is red
			// --> Recolor sibling + parent + sibling's child, and rotate around parent
			sibling->color = ptr->parent->color;
			ptr->parent->color = BLACK;
			if (nodeIsLeftChild) {
				sibling->right->color = BLACK;
				rotateLeft(ptr->parent);
			} else {
				sibling->left->color = BLACK;
				rotateRight(ptr->parent);
			}
		}

		void replaceParentsChild(node* parent, node* oldChild, node* newChild) {
			if (parent == NULL)
				_root = newChild;
			else if (parent->left == oldChild)
				parent->left = newChild;
			else if (parent->right == oldChild) 
				parent->right = newChild;
			if (newChild != NULL) 
				newChild->parent = parent;
		}

		node* getAunt(node* parent) {
			node* grandparent = parent->parent;
			if (grandparent->left == parent)
				return grandparent->right;
			else
				return grandparent->left;
		}

		node* getSibling(node* ptr) {
			node* parent = ptr->parent;
			if (ptr == parent->left)
				return parent->right;
			else
				return parent->left;
		}

		// 			 ************** ROTATIONS **************
		void rotateRight(node* ptr) {
			node* parent = ptr->parent;
			node* leftChild = ptr->left;

			ptr->left = leftChild->right;
			if (leftChild->right != NULL)
				leftChild->right->parent = ptr;
			leftChild->right = ptr;
			ptr->parent = leftChild;
			replaceParentsChild(parent, ptr, leftChild);
		}

		void rotateLeft(node* ptr) {
			node* parent = ptr->parent;
			node* rightChild = ptr->right;

			ptr->right = rightChild->left;
			if (rightChild->left != NULL)
				rightChild->left->parent = ptr;
			rightChild->left = ptr;
			ptr->parent = rightChild;
			replaceParentsChild(parent, ptr, rightChild);
		}


		// 			 ************** FIXER FUNCTIONS **************
		void fixRedBlackPropertiesAfterInsert(node* newNode) {
			node* parent = newNode->parent;

			// Case 1: Parent is null, we've reached the root, the end of the recursion
			if (parent == NULL) {
				newNode->color = BLACK;
				return;
			}
			// Parent is black --> nothing to do
			if (parent->color == BLACK)
				return;
				
			// From here on, parent is red
			node* grandparent = parent->parent;
			node* aunt = getAunt(parent);
			// Case 2: aunt is red -> recolor parent, grandparent and aunt
			if (aunt != NULL && aunt->color == RED) {
				parent->color = BLACK;
				grandparent->color = RED;
				aunt->color = BLACK;
				// Call recursively for grandparent, which is now red.
				// It might be root or have a red parent, in which case we need to fix more...
				fixRedBlackPropertiesAfterInsert(grandparent);
			} else if (parent == grandparent->left) {	// Parent is left child of grandparent
				// Case 3a: aunt is black and node is left->right "inner child" of its grandparent
				if (newNode == parent->right) {
					rotateLeft(parent);
					parent = newNode;
				}
				// Case 4a: aunt is black and node is left->left "outer child" of its grandparent
				rotateRight(grandparent);
				parent->color = BLACK;
				grandparent->color = RED;
			} else {	// Parent is right child of grandparent
				// Case 3b: aunt is black and node is right->left "inner child" of its grandparent
				if (newNode == parent->left) {
					rotateRight(parent);
					parent = newNode;
				}
				// Case 5b: aunt is black and node is right->right "outer child" of its grandparent
				rotateLeft(grandparent);
				parent->color = BLACK;
				grandparent->color = RED;
			}
		}

		void fixRedBlackPropertiesAfterDelete(node* movedNode) {
			if (movedNode == _root) {	// Case 1: Examined node is root, end of recursion
				movedNode->color = BLACK;
				return;
			}
			node* sibling = getSibling(movedNode);
			// Case 2: Red sibling
			if (sibling->color == RED) {
				handleRedSibling(movedNode, sibling);
				sibling = getSibling(movedNode); // Get new sibling for fall-through to cases 3-6
			}
			// Cases 3+4: Black sibling with two black children
			if (isBlack(sibling->left) && isBlack(sibling->right)) {
				sibling->color = RED;
				// Case 3: Black sibling with two black children + red parent
				if (movedNode->parent->color == RED)
					movedNode->parent->color = BLACK;
				// Case 4: Black sibling with two black children + black parent
				else
					fixRedBlackPropertiesAfterDelete(movedNode->parent);
			}
			// Case 5+6: Black sibling with at least one red child
			else
				handleBlackSiblingWithAtLeastOneRedChild(movedNode, sibling);
		}


		// 			************** FINDERS **************
	public:
		node*	findNode(const data_type& data) const { return findNode(data, this->_root); }

		node*	findSmallest() const { return findSmallest(this->_root); }
		
		node*	findLargest() const { return findLargest(this->_root); }

	private:
		node*	findNode(const data_type& data, node* ptr) const {
			if(ptr != NULL) {
				if(isEqual(*(ptr->data), data)) {
					return ptr;
				} else {
					if(_compare(data, *(ptr->data)))
						return findNode(data, ptr->left);
					else
						return findNode(data, ptr->right);
				}
			} else
				return NULL;
		}

		node*	findSmallest(node* ptr) const {
			if(ptr && ptr->left != NULL)
				return findSmallest(ptr->left);
			else
				return ptr;
		}

		node*	findLargest(node* ptr) const {
			if(ptr && ptr->right != NULL)
				return findLargest(ptr->right);
			else
				return ptr;
		}


		// 			************** UTILS **************
		bool isBlack(node* ptr) { return ptr == NULL || ptr->color == BLACK; }

		bool	isEqual(const data_type& x, const data_type& y) const {
			if(_compare(x, y))
				return false;
			if(_compare(y,x))
				return false;
			return true;
		}

	public:
		size_type	getSize() const { return _size; }
		
		void swapTrees(RBtree& tree) {
			node* tempRoot = _root;
			_root = tree._root;
			tree._root = tempRoot;

			size_type tempSize = _size;
			_size = tree._size;
			tree._size = tempSize;

			Compare tempComp = _compare;
			_compare = tree._compare;
			tree._compare = tempComp;

			allocator_type tempAlloc= _alloc;
			_alloc = tree._alloc;
			tree._alloc = tempAlloc;
			
			node_allocator_type tempNodeAlloc= _nodeAlloc;
			_nodeAlloc = tree._nodeAlloc;
			tree._nodeAlloc = tempNodeAlloc;
		}

		const node*	getRoot() const { return _root; }


		//   *******  PRINT FUNCTIONS *******
		void	printMapStructure() { printMapStructure(_root); }

		void	printSetStructure() { printSetStructure(_root); }

	private:
		void	printMapStructure(node* ptr, int depth = 0) {
			if(_root != NULL){
				std::cout << "Root is: " << _root->data->first << std::endl;
				if(ptr->left != NULL)
					printMapStructure(ptr->left, depth + 1);
				for (int i = 0; i < depth; i++)
					std::cout << "- ";
				std::cout << "key: " << ptr->data->first << "	value: " << ptr->data->second << "	color: " << (ptr->color == RED ? "RED" : "BLACK") << std::endl;
				if(ptr->right != NULL)
					printMapStructure(ptr->right, depth + 1);
			}
			else
				std::cout << "The tree is empty\n" << std::endl;
		}

		void	printSetStructure(node* ptr, int depth = 0) {
			if(_root != NULL){
				std::cout << "Root is: " << *(_root->data) << std::endl;
				if(ptr->left != NULL)
					printSetStructure(ptr->left, depth + 1);
				for (int i = 0; i < depth; i++)
					std::cout << "+ ";
				std::cout << "	value: " << *(ptr->data) << "	color: " << (ptr->color == RED ? "RED" : "BLACK") << std::endl;
				if(ptr->right != NULL)
					printSetStructure(ptr->right, depth + 1);
			}
			else
				std::cout << "The tree is empty\n" << std::endl;
		}
	};
}

#endif
