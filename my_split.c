/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:29:35 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/05 15:15:42 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"

char *my_split(char *s)
{
	char *s2;
	// printf("%s\n", s);
	s2 = ft_strtrim(s, " ");
	printf("%s", s2);
	
	return (s2);
}

int main(int ac, char **av, char **env)
{
	if (ac > 1)
	{
		my_split(av[1]);
	}
}
