/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbagecollector.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zbengued <zbengued@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:43:38 by zbengued          #+#    #+#             */
/*   Updated: 2025/04/13 20:36:26 by zbengued         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GARBAGECOLLECTOR_H
# define GARBAGECOLLECTOR_H

# include <stdlib.h>
#include "libft.h"

typedef struct s_gc_node
{
	void				*ptr;
	struct s_gc_node	*next;
}	t_gc_node;

typedef struct s_GC
{
	t_gc_node	*head;
}	t_GC;

#endif
