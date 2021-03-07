/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   break_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdodre <tdodre@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:50:13 by tdodre            #+#    #+#             */
/*   Updated: 2020/07/17 14:23:17 by tdodre           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cube.h"

void		break_error2(int wa)
{
	if (wa == -11)
		write(1, "[resolution is missing]", 24);
	if (wa == -12)
		write(1, "[color for the floor or the ceiling is invalid]", 47);
	if (wa == -13)
		write(1, "[backlines are not accepted in the map]", 39);
	if (wa == -14)
		write(1, "[malloc]", 8);
	if (wa == -15)
		write(1, "[texture not find]", 18);
	if (wa == -16)
		write(1, "[map needs only one position or accepts only 5 chars]", 53);
	if (wa == -17)
		write(1, "[map is not closed]", 19);
}

int			break_error(int wa)
{
	write(1, "ERROR ", 6);
	if (wa == -1)
		write(1, "[need map.cub]", 14);
	if (wa == -2)
		write(1, "[too many argument]", 19);
	if (wa == -3)
		write(1, "[the 2nd argument need .cub extension]", 38);
	if (wa == -4)
		write(1, "[the 3rd argument isn't --save]", 32);
	if (wa == -5)
		write(1, "[invalid file]", 14);
	if (wa == -6)
		write(1, "[invalid resolution]", 20);
	if (wa == -7)
		write(1, "[invalid texture or color]", 26);
	if (wa == -8)
		write(1, "[texture is missing for the wall]", 33);
	if (wa == -9)
		write(1, "[texture is missing for the sprite]", 35);
	if (wa == -10)
		write(1, "[color is missing for the ceiling or the floor]", 47);
	break_error2(wa);
	return (-1);
}
