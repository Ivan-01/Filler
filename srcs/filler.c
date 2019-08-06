/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 19:12:17 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/27 15:34:52 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			define_board(t_filler *filler, char *line)
{
	int			i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->board_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->board_x = ft_atoi(&line[i]);
	filler->board = ft_create_mtrx(filler->board_y, filler->board_x);
}

void			define_token(t_filler *filler, char *line)
{
	int			i;

	i = 0;
	while (ft_isdigit(line[i]) == 0)
		++i;
	filler->token_y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]) == 1)
		++i;
	++i;
	filler->token_x = ft_atoi(&line[i]);
	filler->token = ft_create_mtrx(filler->token_y, filler->token_x);
}

void			define_players(t_filler *filler, char *line)
{
	if (ft_strstr(line, "p1") && ft_strstr(line, "ititkov"))
	{
		filler->player_1 = 'O';
		filler->player_2 = 'X';
	}
	else if (ft_strstr(line, "p2") && ft_strstr(line, "ititkov"))
	{
		filler->player_1 = 'X';
		filler->player_2 = 'O';
	}
	else if (!ft_strstr(line, "p1") || !ft_strstr(line, "p2") || \
			!ft_strstr(line, "ititkov"))
		ft_printf("ERROR");
}

void			read_all(t_filler *filler, char *line, int *index)
{
	if (!filler->player_2)
		define_players(filler, line);
	if (!filler->board_x && !filler->board_y && ft_strstr(line, "Plateau"))
		define_board(filler, line);
	if (ft_isdigit(line[0]) == 1 && filler->board)
	{
		ft_strcpy(filler->board[(*index)++], line + 4);
		if (*(index) == filler->board_y)
			*index = 0;
	}
	if (ft_strstr(line, "Piece"))
		define_token(filler, line);
	if (filler->token && (line[0] == '*' || line[0] == '.'))
	{
		ft_strcpy(filler->token[(*index)++], line);
		if (*(index) == filler->token_y)
		{
			*index = 0;
			bot(filler);
			ft_clean_mtrx(&filler->token);
		}
	}
}

int				main(void)
{
	t_filler	filler;
	char		*line;
	int			index;

	index = 0;
	line = NULL;
	ft_bzero(&filler, sizeof(t_filler));
	while (get_next_line(0, &line) > 0)
	{
		read_all(&filler, line, &index);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	ft_clean_mtrx(&filler.board);
	return (0);
}
