#ifndef RBTREE_HPP
# define RBTREE_HPP

# include "Itree.hpp"
 
namespace ft {
	template<class T, class Alloc, class Compare >
	class RBtree : public Itree<T> {
	public:
		typedef Itree<T>											Itree;
		typedef typename Itree::data_type							data_type;
		typedef typename Alloc::template rebind<data_type>::other	allocator_type;
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
		RBtree(allocator_type alloc, Compare compare) : _root(NULL), _alloc(alloc), _size(0), _compare(compare){};
		RBtree() : _root(NULL), _alloc(), _size(0), _compare(){};
		~RBtree(){};

		RBtree& operator=(const RBtree& original){
			_alloc = original._alloc;
			_nodeAlloc = original._nodeAlloc;
			_size = original._size;
			_compare = original._compare;
			return *this;
		}

		//  		************** ADD FUNCTIONS **************

		node* CreateLeaf(node* ptr, data_type& data) {
			node* newNode;
			try{
				newNode = _nodeAlloc.allocate(1);
				this->_nodeAlloc.construct(newNode, node(ptr));
				newNode->data = _alloc.allocate(1);
				this->_alloc.construct(newNode->data, data);
				this->_size++;
			}
			catch(std::bad_alloc &e){
				std::cerr << e.what() << std::endl;	
				exit(EXIT_FAILURE);
			}
			return newNode;
		}

		bool	addLeaf(data_type data) {
			return addLeaf(this->_root, data);
		}

		bool	addLeaf(node* ptr, data_type& data) {
			bool hasBeenAdded = true;
			if(_root == NULL){
				_root = CreateLeaf(NULL, data);
				_root->color = BLACK;
			}
			else if(_compare(data, *(ptr->data))){
				if(ptr->left != NULL)
					return addLeaf(ptr->left, data);
				else{
					ptr->left = CreateLeaf(ptr, data);
					fixRedBlackPropertiesAfterInsert(ptr->left);
				}
			}
			else if(_compare(*(ptr->data), data)){
				if(ptr->right != NULL)
					return addLeaf(ptr->right, data);
				else{
					ptr->right = CreateLeaf(ptr, data);
					fixRedBlackPropertiesAfterInsert(ptr->right);
				}
			}
			else
				hasBeenAdded = false;
			return hasBeenAdded;
		}

		// 	 ************** REMOVAL FUNCTIONS **************

		void	removeTree(){
			removeSubtree(this->_root);
			this->_root = NULL;			//clearing an empty map
			this->_size = 0;
		}

		void	removeSubtree(node* ptr){
			if(ptr != NULL){
				if(ptr->left != NULL)
					removeSubtree(ptr->left);
				if(ptr->right != NULL)
					removeSubtree(ptr->right);
				this->_alloc.destroy(ptr->data);
				_alloc.deallocate(ptr->data, 1);
				this->_nodeAlloc.destroy(ptr);
				_nodeAlloc.deallocate(ptr, 1);
			}
		}

		void	destroyNode(node* ptr){
				this->_alloc.destroy(ptr->data);
				_alloc.deallocate(ptr->data, 1);
				this->_nodeAlloc.destroy(ptr);
				_nodeAlloc.deallocate(ptr, 1);
				this->_size--;
		}


		void	removeNode(const data_type& data){
			removeNode(data, this->_root);
		}

		void	removeNode(const data_type& data, node* parent){
			if(this->_root != NULL){
				if(isEqual(*(_root->data), data))
					RemoveMatch(NULL, _root);
				else{
					if(_compare(data, *(parent->data)) && parent->left != NULL){
						isEqual(*(parent->left->data), data) ?
						RemoveMatch(parent, parent->left)	:
						removeNode(data, parent->left);
					}
					else if(_compare(*(parent->data), data) && parent->right != NULL){
						isEqual(*(parent->right->data), data) ?
						RemoveMatch(parent, parent->right)	:
						removeNode(data, parent->right);
					}
				}
			}
		}



		void	RemoveMatch(node* parent, node* match){
			node* movedUpNode = match;
			color deletedNodeColor = match->color;
			bool isNILnode = false;

			node* nilNode = NULL;
			
			if(match->left == NULL && match->right == NULL)	{				//Case 0 - 0 children
				isNILnode = true;
				nilNode = match;
			}
			else if (match->left == NULL || match->right == NULL ){			// Case 1 - 1 child
				if(match->right != NULL)
					movedUpNode = match->right;
				else
					movedUpNode = match->left;
				replaceParentsChild(parent, match, movedUpNode);
				movedUpNode->parent = match->parent;
				destroyNode(match);
			}
			else{															// Case 2 - node has 2 children
				node* smallestInRightSubtree = findSmallest(match->right);
				if (smallestInRightSubtree->right)
					movedUpNode = smallestInRightSubtree->right;
				else {
					isNILnode = true;

					data_type nilData = data_type();
					nilNode = CreateLeaf(NULL, nilData);
					nilNode->color = BLACK;
					replaceParentsChild(smallestInRightSubtree->parent, smallestInRightSubtree, nilNode);
					movedUpNode = nilNode;
				}
				if(smallestInRightSubtree->parent == match){
					replaceParentsChild(match->parent, match, smallestInRightSubtree);
					smallestInRightSubtree->left = match->left;
					match->left->parent = smallestInRightSubtree;
				}
				else{
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
			if (deletedNodeColor == BLACK){
				fixRedBlackPropertiesAfterDelete(movedUpNode);
			}
				
			if(isNILnode){
				replaceParentsChild(nilNode->parent, nilNode, NULL);
				destroyNode(nilNode);
			}
		}


		//  ************** FAMILY HANDLERS **************

		void handleRedSibling(node* ptr, node* sibling) {
			sibling->color = BLACK;
			ptr->parent->color = RED;

			if (ptr == ptr->parent->left) {
				rotateLeft(ptr->parent);
			} else
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
			if (parent == NULL){
				_root = newChild;
			}
				
			else if (parent->left == oldChild)
				parent->left = newChild;
			else if (parent->right == oldChild) 
				parent->right = newChild;
			if (newChild != NULL) 
				newChild->parent = parent;
		}

		node* getAunt(node* parent) {
			node* grandparent = parent->parent;
			if (grandparent->left == parent) {
				return grandparent->right;
			} else
				return grandparent->left;
		}

		node* getSibling(node* ptr) {
			node* parent = ptr->parent;
			if (ptr == parent->left) {
				return parent->right;
			} else
				return parent->left;
		}

		// 			 ************** ROTATIONS **************

		void rotateRight(node* ptr) {
			node* parent = ptr->parent;
			node* leftChild = ptr->left;

			ptr->left = leftChild->right;
			if (leftChild->right != NULL) {
				leftChild->right->parent = ptr;
			}

			leftChild->right = ptr;
			ptr->parent = leftChild;

			replaceParentsChild(parent, ptr, leftChild);
		}

		void rotateLeft(node* ptr) {
			node* parent = ptr->parent;
			node* rightChild = ptr->right;

			ptr->right = rightChild->left;
			if (rightChild->left != NULL) {
				rightChild->left->parent = ptr;
			}

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
			}

			// Parent is left child of grandparent
			else if (parent == grandparent->left) {
				// Case 3a: aunt is black and node is left->right "inner child" of its grandparent
				if (newNode == parent->right) {
					rotateLeft(parent);
					parent = newNode;
				}

				// Case 4a: aunt is black and node is left->left "outer child" of its grandparent
				rotateRight(grandparent);
				// Recolor original parent and grandparent
				parent->color = BLACK;
				grandparent->color = RED;
			}

			// Parent is right child of grandparent
			else {
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
			// Case 1: Examined node is root, end of recursion
			if (movedNode == _root) {
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

		node*	findNode(const data_type& data) const{
			return findNode(data, this->_root);
		}

		node*	findNode(const data_type& data, node* ptr) const{
			if(ptr != NULL){
				if(isEqual(*(ptr->data), data))
					return ptr;
				else{
					if(_compare(data, *(ptr->data)))
						return findNode(data, ptr->left);
					else
						return findNode(data, ptr->right);
				}
			}
			else
				return NULL;
		}

		node*		findSmallest() const{
			return findSmallest(this->_root);
		}

		node*		findSmallest(node* ptr) const{
			if(ptr && ptr->left != NULL)
				return findSmallest(ptr->left);
			else
				return ptr;
		}

		node*		findLargest() const{
			return findLargest(this->_root);
		}

		node*		findLargest(node* ptr) const{
			if(ptr && ptr->right != NULL)
				return findLargest(ptr->right);
			else
				return ptr;
		}


		// 			************** UTILS **************

		bool isBlack(node* ptr) {
			return ptr == NULL || ptr->color == BLACK;
		}

		void swapTrees(RBtree& tree){
			node* tempRoot = this->_root;
			this->_root = tree._root;
			tree._root = tempRoot;

			size_type tempSize = this->_size;
			this->_size = tree._size;
			tree._size = tempSize;
		}

		bool	isEqual(const data_type& x, const data_type& y) const{
			if(_compare(x, y))
				return false;
			if(_compare(y,x))
				return false;
			return true;
		}

		size_type	getSize() const {
			return this->_size;
		}


		//   *******  PRINT FUNCTIONS *******

		void	printInOrder(node* ptr, int depth = 0){
			if(this->_root != NULL){
				if(ptr->left != NULL)
					printInOrder(ptr->left, depth + 1);
				for (int i = 0; i < depth; i++)
					std::cout << "- ";
				std::cout << "key: " << ptr->data->first << "	value: " << ptr->data->second << "	color: " << (ptr->color == RED ? "RED" : "BLACK") << std::endl;
				if(ptr->right != NULL)
					printInOrder(ptr->right, depth + 1);
			}
			else
				std::cout << "The tree is empty\n" << std::endl;
		}

		void	printInOrder(){
			std::cout << "Root is: " << *(this->_root->data) << std::endl;
			printInOrder(this->_root);
		}
	};
}

#endif
