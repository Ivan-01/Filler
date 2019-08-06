/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 10:21:06 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/27 16:28:31 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			**create_arr(t_filler *filler)
{
	int		i;
	int		**res;
	int		j;

	res = (int **)malloc(sizeof(int *) * (filler->board_y + 1));
	i = -1;
	while (++i < filler->board_y)
	{
		res[i] = (int *)malloc(sizeof(int) * filler->board_x);
		j = -1;
		while (++j < filler->board_x)
			if (filler->board[i][j] == filler->player_2 || \
					filler->board[i][j] == filler->player_2 + 32)
				res[i][j] = 1;
			else if (filler->board[i][j] == filler->player_1 || \
					filler->board[i][j] == filler->player_1 + 32)
				res[i][j] = -2;
			else
				res[i][j] = -1;
	}
	res[filler->board_y] = NULL;
	return (res);
}

int			check_borders(int **res, t_point point, int cnt, t_filler *filler)
{
	if (point.x + 1 < filler->board_x && res[point.y][point.x + 1] == cnt)
		return (1);
	else if (point.x != 0 && res[point.y][point.x - 1] == cnt)
		return (1);
	if (point.y != 0)
	{
		if (point.x != 0 && res[point.y - 1][point.x - 1] == cnt)
			return (1);
		else if (res[point.y - 1][point.x] == cnt)
			return (1);
		else if (point.x + 1 < filler->board_x && \
				res[point.y - 1][point.x + 1] == cnt)
			return (1);
	}
	if (point.y + 1 < filler->board_y)
	{
		if (point.x != 0 && res[point.y + 1][point.x - 1] == cnt)
			return (1);
		else if (res[point.y + 1][point.x] == cnt)
			return (1);
		else if (point.x + 1 < filler->board_x && \
				res[point.y + 1][point.x + 1] == cnt)
			return (1);
	}
	return (0);
}

int			fill_distance(int **res, t_filler *filler, int cnt)
{
	t_point	point;
	int		check;

	point.y = 0;
	check = 0;
	while (point.y < filler->board_y)
	{
		point.x = 0;
		while (point.x < filler->board_x)
		{
			if (res[point.y][point.x] == -1)
				if (check_borders(res, point, cnt, filler) == 1)
				{
					res[point.y][point.x] = cnt + 1;
					check = 1;
				}
			++point.x;
		}
		++point.y;
	}
	return (check);
}

int			**distance(t_filler *filler)
{
	int		**res;
	int		cnt;

	res = create_arr(filler);
	cnt = 1;
	while (fill_distance(res, filler, cnt) == 1)
		++cnt;
	return (res);
}
