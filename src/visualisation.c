/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualisation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivoloshi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 16:31:57 by ivoloshi          #+#    #+#             */
/*   Updated: 2018/06/13 16:32:57 by ivoloshi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <stdio.h>
#include <locale.h>
#include "../inc/filler.h"

void	emodgi_use(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == 'O')
			printf("%C ", L'🐼');
		else if (str[i] == 'X')
			printf("%C ", L'🐸');
		else if (str[i] == 'x')
			printf("%C ", L'🐸');
		else if (str[i] == 'o')
			printf("%C ", L'🐼');
		else if (str[i] == '.')
			printf("%C ", L'👣');
		else
			printf("%c", str[i]);
		i++;
	}
	printf("\n");
}

int		main(void)
{
	char	*line;

	setlocale(LC_ALL, "");
	while (get_next_line(0, &line) > 0)
	{
		if (*line >= '0' && *line <= '9')
			emodgi_use(line);
		else
			printf("%s\n", line);
		free(line);
	}
}
