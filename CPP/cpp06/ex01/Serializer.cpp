/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:39:47 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 10:42:06 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t	Serializer::serialize(Data *ptr) { return ((uintptr_t)ptr); }

Data	*Serializer::deserialize(uintptr_t raw) { return ((Data *)raw); }
