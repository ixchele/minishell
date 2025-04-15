/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:25:47 by zbengued          #+#    #+#             */
/*   Updated: 2025/04/13 21:15:59 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char *get_env_val(char **env, const char *word)
{
	int (len) = ft_strlen(word);
	int (i) = 0;
	while (env[i])
	{
		if (!ft_strncmp(env[i], word, len))
	}
}
