#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "../Itree.hpp"

namespace ft{
	template <class T, class Pointer = T*, class Reference = T&,
				class Distance = std::ptrdiff_t, class Category = std::bidirectional_iterator_tag>
	class bidirectional_iterator{
	public:
		typedef T									value_type;
		typedef Distance							difference_type;
		typedef	Pointer								pointer;
		typedef	Reference							reference;
		typedef Category							iterator_category;
		typedef node<value_type>					node;

	private:
		node*	_node;
		const Itree<value_type>*	_tree;

		node* previous(node *ptr) {
			if(ptr == NULL){	//end node
				return _tree->findLargest();
			}
			if (ptr->left) {
				ptr = ptr->left;
				while (ptr->right)
					ptr = ptr->right;
			}
			else {
				node* tmp = ptr;
				ptr = ptr->parent;
				while (ptr && ptr->right != tmp){
					tmp = ptr;
					ptr = ptr->parent;
				}
			}
			return ptr;
		}

		node* next(node *ptr) {
			if(ptr == NULL){	//rend node
				return _tree->findSmallest();
			}
			if (ptr->right) {;
				ptr = ptr->right;
				while (ptr->left)
					ptr = ptr->left;
			}
			else {
				node* tmp = ptr;
				ptr = ptr->parent;
				while (ptr && ptr->left != tmp) {
					tmp = ptr;
					ptr = ptr->parent;
				}
			}
			return ptr;
		}

	public:
		bidirectional_iterator(node* ptr, const Itree<value_type>* tree) : _node(ptr), _tree(tree) {};
		bidirectional_iterator() : _node(NULL), _tree(NULL){};

		template <class ptr, class ref>
		bidirectional_iterator(bidirectional_iterator<T, ptr, ref> const& original) : _node( original.getNode() ), _tree( original.getTree() ){};

		// template <class U>
		// bidirectional_iterator(bidirectional_iterator<U, U*, U&> const& original) : _node( original.getNode() ), _tree( original.getTree() ){};



		~bidirectional_iterator(){};

		bidirectional_iterator&	operator=(bidirectional_iterator const& original){
			this->_node = original._node;
			return *this;
		}

		inline bool operator==(const bidirectional_iterator& rhs) const{ 
			return this->_node == rhs._node;
		}
		inline bool operator!=(const bidirectional_iterator& rhs) const{ 
			return this->_node != rhs._node;
		}

		bidirectional_iterator& operator++(){
			this->_node = next(this->_node);
			return *this;
		}
		bidirectional_iterator operator++(int){
			bidirectional_iterator copy(*this);
			this->_node = next(this->_node);
			return copy;
		}
		bidirectional_iterator& operator--(){
			this->_node = previous(this->_node);
			return *this;
		}
		bidirectional_iterator operator--(int){
			bidirectional_iterator copy(*this);
			this->_node = previous(this->_node);
			return copy;
		}
		reference operator*(){
			return *this->_node->data;
		}
		pointer operator->(){
			return this->_node->data;
		}
		pointer operator->() const{
			return this->_node->data;
		}
		node*	getNode() const{
			return this->_node;
		}
		const Itree<value_type>*	getTree() const{
			return this->_tree;
		}
	};
}

#endif
