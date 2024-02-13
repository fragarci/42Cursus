/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:28:41 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 10:50:38 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include "Data.hpp"
# include <stdint.h>

class Serializer
{
	public:
		virtual ~Serializer() = 0;
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};

#endif
