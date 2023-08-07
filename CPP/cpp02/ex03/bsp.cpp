/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 11:20:41 by fragarci          #+#    #+#             */
/*   Updated: 2023/08/07 12:19:17 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Se toma un triangulo con vertices a, b y c y un punto point.
// realizamos el producto vectorial entre los vectores formados por los puntos
// del triangulo y el punto "point" y comparamos su signo.
// Si los signos de los productos vectoriales son iguales para todos los lados
// del triangulo, el punto "point" se encuentra dentro de este.

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
    bool check[3];

    check[0] = ((a.get_X() - point.get_X()) * (b.get_Y() - a.get_Y()) -
                (b.get_X() - a.get_X()) * (point.get_Y() - a.get_Y())) > 0;
    check[1] = ((b.get_X() - point.get_X()) * (c.get_Y() - b.get_Y()) -
                (c.get_X() - b.get_X()) * (point.get_Y() - b.get_Y())) > 0;
    check[2] = ((c.get_X() - point.get_X()) * (a.get_Y() - c.get_Y()) -
                (a.get_X() - c.get_X()) * (point.get_Y() - c.get_Y())) > 0;
    return (check[0] == check[1] && check[1] == check[2]);
}
