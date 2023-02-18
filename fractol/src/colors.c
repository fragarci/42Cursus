/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fragarci <fragarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:53:02 by fragarci          #+#    #+#             */
/*   Updated: 2023/02/18 15:33:01 by fragarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_fractal_color(double n, t_data *data)
{
	double	hue;
	double	sat;
	double	value;

	hue = 255 * n / data->max_iter;
	sat = 255;
	if (n == (double)data->max_iter)
		value = 0;
	else
		value = 255;
	hue = (int)((hue / 255.) * 360. + data->hue_off) % 360;
	sat /= 255.;
	value /= 255.;
	return (hsv2rgb((t_hsv){hue, sat, value}));
}

/*
La función hsv2rgb2 convierte un color del espacio de color HSV (Hue, Saturation,
Value) al espacio de color RGB (Red, Green, Blue). La conversión se realiza
mediante el cálculo de los valores de rojo (R), verde (G) y azul (B) de la imagen
RGB a partir de los valores de matiz (H), saturación (S) y brillo (V) del espacio
de color HSV. Esto implica los siguientes pasos:

1.- Convertir el ángulo del matiz en el rango de 0 a 360 grados a un valor en el
rango de 0 a 5, ya que los valores de matiz en el espacio de color HSV se miden
en grados, mientras que los valores necesarios para la conversión a RGB están en
el rango de 0 a 5.

2.- Calcular los valores de rojo (R), verde (G) y azul (B) en función del valor
de matiz (H), saturación (S) y brillo (V) en el espacio de color HSV. Este
cálculo se realiza mediante la siguiente fórmula:

    Si 0 <= H < 1: R = V, G = T, B = P
    Si 1 <= H < 2: R = Q, G = V, B = P
    Si 2 <= H < 3: R = P, G = V, B = T
    Si 3 <= H < 4: R = P, G = Q, B = V
    Si 4 <= H < 5: R = T, G = P, B = V
    Si 5 <= H < 6: R = V, G = P, B = Q

Donde:

    P = V * (1 - S)
    Q = V * (1 - S * f)
    T = V * (1 - S * (1 - f))
    f = fracción de H dentro de su intervalo de 60 grados

3.- Finalmente, se devuelve el valor de rojo, verde y azul como una estructura
t_rgb
*/

static t_rgb	hsv2rgb2(t_hsv hsv, t_pqt pqt)
{
	t_rgb	rgb;

	if (0. <= hsv.h && hsv.h < 1.)
		rgb = (t_rgb){.r = hsv.v, .g = pqt.t, .b = pqt.p};
	else if (1. <= hsv.h && hsv.h < 2.)
		rgb = (t_rgb){.r = pqt.q, .g = hsv.v, .b = pqt.p};
	else if (2. <= hsv.h && hsv.h < 3.)
		rgb = (t_rgb){.r = pqt.p, .g = hsv.v, .b = pqt.t};
	else if (3. <= hsv.h && hsv.h < 4.)
		rgb = (t_rgb){.r = pqt.p, .g = pqt.q, .b = hsv.v};
	else if (4. <= hsv.h && hsv.h < 5.)
		rgb = (t_rgb){.r = pqt.t, .g = pqt.p, .b = hsv.v};
	else if (5. <= hsv.h && hsv.h < 6.)
		rgb = (t_rgb){.r = hsv.v, .g = pqt.p, .b = pqt.q};
	else
		rgb = (t_rgb){.r = 0., .g = 0., .b = 0.};
	return (rgb);
}

/*
La función hsv2rgb es la función principal que realiza la conversión de un valor
de color en el espacio de color HSV (Hue, Saturation, Value) a un valor de color
en el espacio de color RGB (Red, Green, Blue). Funciona de la siguiente manera:

1.- Si el valor de matiz (H) es igual a 360 grados, se establece en 0, ya que los
valores de matiz en el espacio de color HSV están en el rango de 0 a 360 grados.

2.- Se calculan los valores de P, Q y T usando las fórmulas:

·	P = V * (1 - S)
·	Q = V * (1 - S * f)
·	T = V * (1 - S * (1 - f))

Donde f es la fracción de H dentro de su intervalo de 60 grados.

3.- Se llama a la función hsv2rgb2 con los valores de color HSV y PQT calculados.
La función hsv2rgb2 devuelve un valor de color en el espacio de color RGB como
una estructura t_rgb.

4.- Los valores de rojo, verde y azul de la estructura t_rgb se escalan en el
rango de 0 a 255 y se colocan en los bits superiores del número de 32 bits
devuelto por la función. Los bits inferiores se establecen en 255, lo que
significa que el color es completamente opaco.

5.- La función devuelve el número de 32 bits que representa el valor de color
en el espacio de color RGB.
*/
uint32_t	hsv2rgb(t_hsv hsv)
{
	t_rgb	rgb;
	t_pqt	pqt;
	double	fract;

	if (hsv.h == 360.)
		hsv.h = 0.;
	else
		hsv.h /= 60.;
	fract = hsv.h - floor(hsv.h);
	pqt = (t_pqt){hsv.v * (1. - hsv.s), hsv.v * (1. - hsv.s * fract), hsv.v
		* (1. - hsv.s * (1. - fract))};
	rgb = hsv2rgb2(hsv, pqt);
	return ((int)(rgb.r * 255) << 24 | (int)(rgb.g * 255) << 16 | (int)(rgb.b
			* 255) << 8 | 255);
}

void	ft_color_shift(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (data->rainbow)
	{
		data->hue_off += 10.;
		ft_draw_fractal(data);
	}
}
