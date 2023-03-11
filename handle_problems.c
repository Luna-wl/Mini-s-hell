/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_problems.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wluedara <wluedara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:11:40 by wluedara          #+#    #+#             */
/*   Updated: 2023/03/12 00:01:28 by wluedara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hell.h"
#include "colours.h"

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\f' || c == '\v' || c == '\r' \
	|| c == '\n')
		return (1);
	return (0);
}

int	is_tokens(char c)
{
	char	*tokens;
	int		i;

	i = 0;
	tokens = "|<>";
	while (i < 3)
	{
		if (c == tokens[i])
			return (i);
		i++;
	}
	return (-1);
}

// int	detect_quote(char *s)
// {
// 	int	i;
// 	// int	j;

// 	i = 0;
// 	// j = 0;
// 	printf(YEL"s = %s\n", s);
// 	while (s[i])
// 	{
// 		if (s[i] == '\'' || s[i] == '\"')
// 			i++;
		
// 	}
// 	return (0);
// }

// int main()
// {
// 	char *s = "'f''a''h'";
// 	detect_quote(s);
// }
