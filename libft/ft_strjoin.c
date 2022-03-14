/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:18:55 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by vitya on 04.05.2021.
//
//Функция производит конкотенацию строк в новый массив. При условии, что
// отсутствует какая-либо строка, конкатенация не производится.

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	if (s1 != NULL)
		len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 != NULL)
		str = (char *)malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	else
		str = (char *)malloc(sizeof(char) * (len_s2 + 1));
	if (!str)
		exit(1);
	if (s1 != NULL)
		while (s1[i])
			str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
