#ifndef STACK_HPP
# define STACK_HPP


# include "vector.hpp"

namespace ft{
	template <class value_type, class Container = vector<value_type> >
	class stack{
	public:
		typedef Container					container_type;
		typedef Container::value_type		value_type;
		typedef Container::size_type		size_type;

	protected:
		Container c;
	public:
		stack(const Container& cont = Container()) : c(cont){};
		stack(const stack& original){
			*this = original;
		};
		~stack(){};

		stack& operator=(const stack& original){
			this->c = original.c;
			return *this;
		}

		bool empty() const{
			return c.empty();
		};
		size_type size() const{
			return c.size();
		};
		value_type& top(){
			return c.back();
		};
		const value_type& top() const{
			return c.back();
		};
		void push (const value_type& val){
			c.push_back(val);
		};
		void pop(){
			c.pop_back();
		};
	};
}

#endif
