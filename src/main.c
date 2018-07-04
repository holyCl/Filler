/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:44:27 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 16:19:00 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/filler.h"

void	create_token_int_map(t_pf *pf, int i, int j, char *line)
{
	ft_strdel(&line);
	while (++i < pf->tmax_y)
	{
		get_next_line(0, &line);
		pf->token[i] = ft_strdup(line);
		ft_strdel(&line);
	}
	i = -1;
	while (++i < pf->max_y)
	{
		j = -1;
		pf->imap[i] = (int *)malloc(sizeof(int) * pf->max_x + 1);
		while (++j < pf->max_x)
		{
			if (pf->map[i][j] == pf->enemy_symb ||
				pf->map[i][j] == pf->enemy_symb + 32)
				pf->imap[i][j] = -2;
			else if (pf->map[i][j] == pf->player_symb ||
				pf->map[i][j] == pf->player_symb + 32)
				pf->imap[i][j] = -3;
			else
				pf->imap[i][j] = -1;
		}
	}
	check_free_pos(pf);
}

void	create_map(t_pf *pf, char *line)
{
	int	i;

	i = 0;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (i < pf->max_y)
	{
		get_next_line(0, &line);
		pf->map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	get_next_line(0, &line);
	i = 0;
	pf->tmax_y = ft_atoi(line + 6);
	while (ft_isdigit(*(line + 6 + i)))
		i++;
	pf->tmax_x = ft_atoi(line + 6 + ++i);
	pf->token = (char **)malloc(sizeof(char *) * pf->tmax_y + 1);
	pf->token[pf->tmax_y] = NULL;
	create_token_int_map(pf, -1, -1, line);
}

int		main(void)
{
	t_pf	*pf;
	char	*line;

	get_next_line(0, &line);
	pf = (t_pf *)malloc(sizeof(*pf));
	create_str(pf);
	pf->player_symb = 'O';
	pf->enemy_symb = 'X';
	line[10] != '1' ? pf->player_symb = 'X' : 1;
	line[10] != '1' ? pf->enemy_symb = 'O' : 1;
	ft_strdel(&line);
	while (get_next_line(0, &line) > 0)
	{
		pf->max_y = ft_atoi(&line[8]);
		pf->max_x = ft_atoi(&line[11]);
		pf->map = (char **)malloc(sizeof(char *) * pf->max_y + 1);
		pf->imap = (int **)malloc(sizeof(int *) * pf->max_y + 1);
		pf->map[pf->max_y] = 0;
		ft_strdel(&line);
		create_map(pf, line);
		ft_strdel(&line);
		ft_printf("%i %i\n", pf->ret_y, pf->ret_x);
		clean_map(pf);
	}
	free(pf);
}
