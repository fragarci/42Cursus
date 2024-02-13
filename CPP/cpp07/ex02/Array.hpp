/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 19:47:52 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 20:24:32 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>
# include <cstddef>

template <typename T> class Array
{
	private:
		T			*_arr;
		std::size_t	_size;
	public:
		Array(void);
		Array(std::size_t size);
		Array(Array const &src);
		~Array(void);
		Array &operator=(Array const &src);
		T &operator[](int i);
		std::size_t size(void) const;
};

template <typename T> Array<T>::Array(void): _arr(new T[0]), _size(0) {}
template <typename T> Array<T>::Array(std::size_t size): _arr(new T[size]), _size(size) {}

template <typename T> Array<T>::Array(Array const &src): _arr(new T[src._size]), _size(src._size)
{
	for (std::size_t i = 0; i < src._size; i++)
		this->_arr[i] = src._arr[i];
}

template <typename T> Array<T>::~Array(void) { delete [] this->_arr; }

template <typename T> Array<T> &Array<T>::operator=(Array const &src)
{
	if (this != &src)
	{
		delete [] this->_arr;
		this->_arr = new T[src._size];
		this->_size = src._size;
		for (int i = 0; i < src._size; i++)
			this->_arr[i] = src._arr[i];
	}
	return (*this);
}

template <typename T> T &Array<T>::operator[](int i)
{
	if (i < 0 || (std::size_t)i > this->_size)
		throw std::exception();
	return (this->_arr[i]);
}

template <typename T> std::size_t Array<T>::size(void) const { return (this->_size); }
#endif
