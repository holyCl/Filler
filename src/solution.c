/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:04:55 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 16:10:15 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void		final_check(t_pf *pf, int cx, int cy, int sum_cord)
{
	if (pf->sum > sum_cord)
	{
		pf->sum = sum_cord;
		pf->ret_x = cx;
		pf->ret_y = cy;
	}
}

void		find_best_case(int cx, int cy, t_pf *pf)
{
	int		tx;
	int		ty;
	int		sum_cord;
	int		x;
	int		y;

	y = cy;
	sum_cord = 0;
	ty = 0;
	while (ty < pf->tmax_y)
	{
		tx = 0;
		x = cx;
		while (tx < pf->tmax_x)
		{
			if (pf->token[ty][tx] == '*')
				sum_cord += pf->imap[y][x];
			tx++;
			x++;
		}
		ty++;
		y++;
	}
	final_check(pf, cx, cy, sum_cord);
}

void		check_token(t_pf *pf, int cy, int cx, int neg)
{
	int		ty;
	int		tx;
	int		count_stars;
	int		x;
	int		y;

	y = cy;
	ty = -1;
	count_stars = 0;
	while (++ty < pf->tmax_y)
	{
		tx = -1;
		x = cx;
		while (++tx < pf->tmax_x)
		{
			if (pf->imap[y][x] == -3 && pf->token[ty][tx] == '*')
				count_stars++;
			else if (pf->imap[y][x] == -2 && pf->token[ty][tx] == '*')
				neg = 1;
			x++;
		}
		y++;
	}
	if (count_stars == 1 && neg == 0)
		find_best_case(cx, cy, pf);
}
