/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:01:27 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 16:02:31 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	create_str(t_pf *pf)
{
	pf->token = NULL;
	pf->max_y = 0;
	pf->max_x = 0;
	pf->imap = 0;
	pf->player_symb = '\0';
	pf->enemy_symb = '\0';
	pf->map = NULL;
	pf->tmax_y = 0;
	pf->tmax_x = 0;
	pf->ret_x = 0;
	pf->ret_y = 0;
	pf->sum = 10000;
}

void	fill_numbers(t_pf *pf, int x, int y, int numb)
{
	int	d;

	d = 1;
	if (x + d < pf->max_x && pf->imap[y][x + d] == -1)
		pf->imap[y][x + d] = numb;
	if (x - d >= 0 && y + d < pf->max_y && pf->imap[y + d][x - d] == -1)
		pf->imap[y + d][x - d] = numb;
	if (x >= d && y >= d && pf->imap[y - d][x - d] == -1)
		pf->imap[y - d][x - d] = numb;
	if (x + d < pf->max_x && y + d < pf->max_y && pf->imap[y + d][x + d] == -1)
		pf->imap[y + d][x + d] = numb;
	if (x + d < pf->max_x && y - d >= 0 && pf->imap[y - d][x + d] == -1)
		pf->imap[y - d][x + d] = numb;
	if (x - d >= 0 && pf->imap[y][x - d] == -1)
		pf->imap[y][x - d] = numb;
	if (y - d >= 0 && pf->imap[y - d][x] == -1)
		pf->imap[y - d][x] = numb;
	if (y + d < pf->max_y && pf->imap[y + d][x] == -1)
		pf->imap[y + d][x] = numb;
}

void	clean_map(t_pf *pf)
{
	int i;

	i = 0;
	while (i < pf->max_y)
	{
		ft_memdel((void **)&(pf->imap[i]));
		i++;
	}
	i = 0;
	while (i < pf->max_y)
	{
		ft_strdel(&(pf->map[i]));
		i++;
	}
	i = 0;
	while (i < pf->tmax_y)
	{
		ft_strdel(&(pf->token[i]));
		i++;
	}
	ft_memdel((void **)&(pf->map));
	ft_memdel((void **)&(pf->token));
	ft_memdel((void **)&(pf->imap));
}
