/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 11:13:30 by fragarci          #+#    #+#             */
/*   Updated: 2024/02/13 11:34:50 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

int	main(void)
{
	Base *p = generate();

	identify(p);
	identify(*p);
	return (0);
}
