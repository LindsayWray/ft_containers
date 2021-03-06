#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft {
	template<class Iter>
	class reverse_iterator {
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;

	private:
		Iter 	_iter;

	public:
		reverse_iterator() : _iter() {};
		explicit reverse_iterator (iterator_type it) : _iter(it) {};

		template <class Iterator>
		reverse_iterator (const reverse_iterator<Iterator>& original) : _iter(original.getIter()) {};

		iterator_type base() const { return _iter; }

		reverse_iterator operator+(difference_type b) const {
			reverse_iterator copy(*this);
			copy._iter -= b;
			return copy;
		}

		reverse_iterator& operator++() {
			_iter--;
			return *this;
		}

		reverse_iterator operator++(int) {
			reverse_iterator copy(*this);
			_iter--;
			return copy;
		}

		reverse_iterator& operator+=(difference_type b) {
			_iter -= b;
			return *this;
		}

		reverse_iterator operator-(difference_type b) const {
			reverse_iterator copy(*this);
			copy._iter += b;
			return copy;
		}

		reverse_iterator& operator--() {
			_iter++;
			return *this;
		}
		reverse_iterator operator--(int) {
			reverse_iterator copy(*this);
			_iter++;
			return copy;
		}

		reverse_iterator& operator-=(difference_type b) {
			_iter += b;
			return *this;
		}

		reference operator*() {
			iterator_type copy(_iter);
			return *(--copy);
		}

		reference operator*() const{
			iterator_type copy(_iter);
			return *(--copy);
		}

		pointer operator->(){
			iterator_type copy(_iter);
			return &(*--copy);
		}
		pointer operator->() const{
			iterator_type copy(_iter);
			return &(*--copy);
		}

		reference operator[](difference_type index) const{
			iterator_type copy(_iter);
			copy -= index;
			return *(--copy);
		}

		Iter	getIter() const { return _iter; }
	};

		//	*********** relational operators (reverse_iterator) ***********
		template <class Iterator1, class Iterator2>
		bool operator==(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) 
			{ return lhs.getIter() == rhs.getIter(); }

		template <class Iterator1, class Iterator2>
		bool operator!=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs) 
			{ return !(lhs == rhs); }

		template <class Iterator1, class Iterator2>
		bool operator<(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
			{ return lhs.getIter() > rhs.getIter(); }

		template <class Iterator1, class Iterator2>
		bool operator>(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
			{ return rhs < lhs; }

		template <class Iterator1, class Iterator2>
		bool operator<=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
			{ return !(rhs < lhs); }

		template <class Iterator1, class Iterator2>
		bool operator>=(const reverse_iterator<Iterator1>& lhs, const reverse_iterator<Iterator2>& rhs)
			{ return !(lhs < rhs); }

		template <class Iterator>
		reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n,
					const reverse_iterator<Iterator>& rev_it) { return rev_it + n; }

		template <class Iterator1, class Iterator2>
		typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& lhs,
				const reverse_iterator<Iterator2>& rhs) { return rhs.getIter().get_pos() - lhs.getIter().get_pos(); }
}

#endif
