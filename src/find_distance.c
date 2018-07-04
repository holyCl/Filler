/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_distance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:03:08 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 16:04:24 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		check_on_map(t_pf *pf)
{
	int		x;
	int		y;

	y = 0;
	while (y < pf->max_y)
	{
		x = 0;
		while (x < pf->max_x)
		{
			if (pf->tmax_y + y < pf->max_y && pf->tmax_x + x < pf->max_x)
				check_token(pf, y, x, 0);
			x++;
		}
		y++;
	}
}

void		go_next(t_pf *pf, int numb, int *flag)
{
	int		x;
	int		y;

	y = 0;
	while (y < pf->max_y)
	{
		x = 0;
		while (x < pf->max_x)
		{
			if (pf->imap[y][x] == -2)
			{
				fill_numbers(pf, x, y, numb);
				*flag = 1;
			}
			else if (pf->imap[y][x] == numb - 1)
				fill_numbers(pf, x, y, numb);
			x++;
		}
		y++;
	}
}

void		check_free_pos(t_pf *pf)
{
	int		x;
	int		y;
	int		numb;
	int		flag;

	flag = 0;
	numb = 1;
	y = 0;
	while (y < pf->max_y)
	{
		x = 0;
		while (x < pf->max_x)
		{
			if (pf->imap[y][x] == -1)
			{
				go_next(pf, numb, &flag);
				numb++;
			}
			x++;
		}
		y++;
	}
	pf->sum = 10000;
	check_on_map(pf);
}
