#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include "../Btree.hpp"

namespace ft{
	template <class Category, class T, class Distance = std::ptrdiff_t,
		class Pointer = T*, class Reference = T& >
	class bidirectional_iterator{
	public:
		typedef T									pair_type;
		typedef typename pair_type::first_type		key_type;
		typedef typename pair_type::second_type		mapped_type;
		typedef Distance							difference_type;
		typedef	Pointer								pointer;
		typedef	Reference							reference;
		typedef Category							iterator_category;
		typedef typename Btree<pair_type>::node			node;
	private:
		node*	_node;
		bidirectional_iterator() : _node(NULL){};


		void previous(node *ptr) {
			if (ptr->left) {
				ptr = ptr->left;
				while (ptr->right)
					ptr = ptr->right;
			}
			else
				ptr = ptr->parent;
			}

		node* next(node *ptr) {
			if (ptr->right) {;
				ptr = ptr->right;
				while (ptr->left)
					ptr = ptr->left;
			}
			else {
				node* tmp = ptr;
				ptr = ptr->parent;
				while (ptr->left != tmp) {
					tmp = ptr;
					ptr = ptr->parent;
				}
			}
			return ptr;
		}


	public:
		bidirectional_iterator(node* node) : _node(node){};
		bidirectional_iterator(bidirectional_iterator const& original) : _node(original._node){};
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
			this->_node--;
			return *this;
		}
		bidirectional_iterator operator--(int){
			bidirectional_iterator copy(*this);
			this->_node--;
			return copy;
		}
		reference operator*(){
			return *this->_node->pair;
		}
		pointer operator->(){
			return this->_node->pair;
		}
		pointer operator->() const{
			return this->_node->pair;
		}
	};
}

#endif
