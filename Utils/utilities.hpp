#ifndef UTILITIES_HPP
# define UTILITIES_HPP

namespace ft {

	template<bool Cond, class T = void>
	struct enable_if {};

	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
		/* The enable_if templates always come in pairs: one of them is empty and the 
		other one has a type typedef that forwards its second type parameter. The empty 
		structure triggers an invalid type because it contains no member. 
		When a compile-time condition is false, the empty enable_if template is chosen. 
		Appending ::type would result in an invalid instantiation, which the 
		compiler throws away due to the SFINAE principle. */


	template <class T> struct is_integral 				{ static const bool value = false;};
	template <> struct is_integral<bool>				{ static const bool value = true; };
	template <> struct is_integral<char>				{ static const bool value = true; };
	template <> struct is_integral<signed char>			{ static const bool value = true; };
	template <> struct is_integral<unsigned char>		{ static const bool value = true; };
	template <> struct is_integral<wchar_t>				{ static const bool value = true; };
	template <> struct is_integral<char16_t>			{ static const bool value = true; };
	template <> struct is_integral<char32_t>			{ static const bool value = true; };
	template <> struct is_integral<short>				{ static const bool value = true; };
	template <> struct is_integral<unsigned short>		{ static const bool value = true; };
	template <> struct is_integral<int>					{ static const bool value = true; };
	template <> struct is_integral<unsigned int>		{ static const bool value = true; };
	template <> struct is_integral<long>				{ static const bool value = true; };
	template <> struct is_integral<unsigned long>		{ static const bool value = true; };
	template <> struct is_integral<long long>			{ static const bool value = true; };
	template <> struct is_integral<unsigned long long>	{ static const bool value = true; };
	
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2){
		while (first1 != last1){
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp){
		while (first1 != last1){
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return true;
			++first1;
			++first2;
		}
		return (first2 != last2);
	}

	template <class InputIterator1, class InputIterator2>
	bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2){
		while (first1 != last1) {
			if (!(*first1 == *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}
	
	template <class InputIterator1, class InputIterator2, class BinaryPredicate>
	bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, BinaryPredicate pred){
		while (first1 != last1) {
			if (!pred(*first1, *first2))
				return false;
			++first1;
			++first2;
		}
		return true;
	}


	template <class T1, class T2>
	struct pair{
		typedef T1	first_type;
		typedef T2	second_type;

		T1			first;
		T2			second;

		pair() : first(), second() {};

		template<class t1, class t2> 
		pair(const pair<t1,t2>& original) : first(original.first), second(original.second) {};

		pair(const first_type& a, const second_type& b) : first(a), second(b) {};

		pair& operator= (const pair& original) {
			this->first = original.first;
			this->second = original.second;
			return *this;
		};
	};

	template <class T1,class T2>
	pair<T1,T2> make_pair(T1 x, T2 y) { return pair<T1,T2>(x, y); }
	
	template <class T1, class T2>
	bool operator==(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool operator<(const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second); 
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs == rhs); }

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(rhs < lhs); }

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return rhs < lhs; }

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) { return !(lhs < rhs); }
}

#endif
