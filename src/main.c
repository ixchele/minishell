/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajji <ihajji@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 15:02:11 by ihajji            #+#    #+#             */
/*   Updated: 2025/04/12 18:49:03 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main(int ac __attribute__((unused)), char **av __attribute__((unused)),
		 char **env)
{
	char cwd[PATH_MAX];
	char prompt[PATH_MAX + 50];
	char *line;

	(void)env;
	while (1)
	{
		// if (getcwd(cwd, sizeof(cwd)) == NULL)
		// 	perror("getcwd"); // NOTE : error case (dont know how to handle it at this time)
		prompt[0] = '\0';
		strcat(prompt, "\033[1;34m");
		strcat(prompt, cwd);
		strcat(prompt, "\033[0m");
		strcat(prompt, " minishell$ ");
		line = readline(prompt);
		if (!line)
		{
			printf("exit\n");
			break;
		}
		if (*line)
			add_history(line);
		printf("command: %s\n", line);
		free(line);
	}
	return 0;
}
