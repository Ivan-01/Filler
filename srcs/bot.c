/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 08:36:33 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/27 15:35:52 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			check_contact(t_filler *filler, int i, int j, int *count)
{
	if (i < filler->board_y && j < filler->board_x)
	{
		if (filler->board[i][j])
		{
			if (filler->board[i][j] == filler->player_1 || \
				filler->board[i][j] == filler->player_1 + 32)
				(*count)++;
			if (filler->board[i][j] == filler->player_2 || \
				filler->board[i][j] == filler->player_2 + 32)
				return (0);
		}
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

int			check_fit(t_filler *filler, int i, int j)
{
	int		i_token;
	int		j_token;
	int		count;

	i_token = 0;
	j_token = 0;
	count = 0;
	while (filler->token[i_token])
	{
		j_token = 0;
		while (filler->token[i_token][j_token])
		{
			if (filler->token[i_token][j_token] == '*')
				if (check_contact(filler, i_token + i, j_token + j, &count) \
						== 0)
					return (0);
			++j_token;
		}
		++i_token;
	}
	return (count);
}

int			check_dist(int **map, t_filler *filler, int i, int j)
{
	int i_token;
	int j_token;
	int total;

	i_token = 0;
	j_token = 0;
	total = 0;
	while (filler->token[i_token])
	{
		j_token = 0;
		while (filler->token[i_token][j_token])
		{
			if (filler->token[i_token][j_token] == '*')
				total += map[i_token + i][j_token + j];
			++j_token;
		}
		++i_token;
	}
	return (total);
}

void		check_place(t_filler *filler, t_point *answer)
{
	int		**map;
	int		min_sum;
	int		tmp;
	int		i;
	int		j;

	i = -1;
	min_sum = 1000000;
	map = distance(filler);
	while (filler->board[++i])
	{
		j = -1;
		while (filler->board[i][++j])
			if (check_fit(filler, i, j) == 1)
			{
				tmp = check_dist(map, filler, i, j);
				if (min_sum > tmp)
				{
					min_sum = tmp;
					answer->y = i;
					answer->x = j;
				}
			}
	}
	ft_clean_int_arr(&map);
}

int			bot(t_filler *filler)
{
	t_point *answer;

	answer = malloc(sizeof(t_point *));
	answer->y = 0;
	answer->x = 0;
	check_place(filler, answer);
	ft_printf("%d %d\n", answer->y, answer->x);
	free(answer);
	return (0);
}
