/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 17:32:26 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/27 14:21:29 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_filler
{
	char			player_1;
	char			player_2;
	char			**board;
	int				board_x;
	int				board_y;
	char			**token;
	int				token_x;
	int				token_y;
}					t_filler;

int					**distance(t_filler *filler);
int					bot(t_filler *filler);

#endif
