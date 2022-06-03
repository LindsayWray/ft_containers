#ifndef NODE_HPP
# define NODE_HPP

#include <stdlib.h>

namespace ft {

	enum color{
		RED,
		BLACK
	};

	template<class data_type>
	struct node {
		node(node* parent) : color(RED), left(NULL), right(NULL), parent(parent) {};

		data_type*		data;
		color 			color; 
		node*			left;
		node*			right;
		node*			parent;
	};
}

#endif
