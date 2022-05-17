#ifndef ITREE_HPP
# define ITREE_HPP

# include "utilities.hpp"
# include "node.hpp"
 
namespace ft {
	template<class T>
	class Itree {
	public:
		typedef T								data_type;
		typedef	size_t							size_type;
		typedef node<data_type>					node;	

	public:
		virtual node*		findSmallest() const = 0;
		virtual node*		findLargest() const = 0;

		virtual size_type	getSize() const = 0;


		virtual ~Itree(){};
	};
}
#endif
