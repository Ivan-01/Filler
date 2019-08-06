/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mtrx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ititkov <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/21 18:59:48 by ititkov           #+#    #+#             */
/*   Updated: 2019/05/22 20:05:07 by ititkov          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_create_mtrx(int height, int width)
{
	char		**mtrx;
	int			i;

	mtrx = (char **)malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
		mtrx[i++] = (char *)malloc(sizeof(char) * (width + 1));
	mtrx[i] = NULL;
	return (mtrx);
}
