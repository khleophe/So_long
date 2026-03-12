/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdabbas <sdabbas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 14:25:44 by sdabbas           #+#    #+#             */
/*   Updated: 2026/03/10 14:43:19 by sdabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_tab(char *mid_tab, char *temp)
{
	char	*mid_tab_temp;

	if (temp == NULL)
	{
		return (mid_tab);
	}
	mid_tab_temp = ft_strjoin(mid_tab, temp);
	free(mid_tab);
	return (mid_tab_temp);
}
