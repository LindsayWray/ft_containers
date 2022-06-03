#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft {
	template <class T, class Container = vector<T> >
	class stack {
		template <class T2, class Alloc>
		friend bool operator==(const stack<T2,Alloc>& lhs, const stack<T2,Alloc>& rhs);

		template <class T2, class Alloc>
		friend bool operator<(const stack<T2,Alloc>& lhs, const stack<T2,Alloc>& rhs);
		
	public:
		typedef 			Container					container_type;
		typedef typename 	Container::value_type		value_type;
		typedef typename	Container::size_type		size_type;

	protected:
		Container c;

	public:
		stack(const Container& cont = Container()) : c(cont) {};

		stack(const stack& original) { *this = original; };
		~stack() {};

		stack& operator=(const stack& original) {
			this->c = original.c;
			return *this;
		}

		bool empty() const { return c.empty(); };
		
		size_type size() const { return c.size(); };
		
		value_type& top() { return c.back(); };

		const value_type& top() const { return c.back(); };

		void push (const value_type& val) { c.push_back(val); };

		void pop() { c.pop_back(); };
	};

	// -------------- relational operators -------------------

	template <class T, class Alloc>
	bool operator==(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return lhs.c == rhs.c; }

	template <class T, class Alloc>
	bool operator!=(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return !(lhs == rhs); }

	template <class T, class Alloc>
	bool operator<(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return lhs.c < rhs.c; }

	template <class T, class Alloc>
	bool operator<= (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return !(rhs < lhs); }

	template <class T, class Alloc>
	bool operator>(const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return rhs < lhs; }

	template <class T, class Alloc>
	bool operator>= (const stack<T,Alloc>& lhs, const stack<T,Alloc>& rhs) { return !(lhs < rhs); }
}

#endif
