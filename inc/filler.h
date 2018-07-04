/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 16:42:07 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 18:18:16 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libftprintf/inc/ft_printf.h"

typedef	struct		s_playerinfo
{
	char			**map;
	int				**imap;
	char			**token;
	char			player_symb;
	char			enemy_symb;
	int				max_y;
	int				max_x;
	int				tmax_y;
	int				tmax_x;
	int				ret_x;
	int				ret_y;
	int				sum;
}					t_pf;

void				check_free_pos(t_pf *pf);
void				check_token(t_pf *pf, int cy, int cx, int neg);
void				fill_numbers(t_pf *pf, int x, int y, int numb);
void				create_str(t_pf *pf);
void				clean_map(t_pf *pf);

#endif
