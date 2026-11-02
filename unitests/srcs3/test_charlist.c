/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_charlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:25:32 by marisous          #+#    #+#             */
/*   Updated: 2026/11/02 23:28:15 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	ft_rand_print(void);
int		ft_rand(int limit);

void print_call_char(void *c);
void print_call_char_fd(void *c, int fd);
void *copy_call(void *c);
void del_call(void *c);







int main(void)
{
	char	c;
	char	*content;
	int		ielement;
	int		nelements;
	int		isfront;
	t_list **char_list;
	t_list *lst_elem;

	lst_elem = NULL;
	char_list = &lst_elem;
	nelements = ft_rand(100);
	ielement = 0;
	while (ielement < nelements)
	{
		isfront = ft_rand(2);
		c = ft_rand_print();
		content = ft_strdup(&c);
		lst_elem = ft_lstnew(content);
		if (lst_elem == NULL)
		{
			free(content);
			break;
		}
		if (isfront && ielement > 0)
			ft_lstadd_front(char_list, lst_elem);
		else
			ft_lstadd_back(char_list, lst_elem);
		ielement++;
	}
	/* print list contents */
	ft_lstiter(*char_list, print_call);
	ft_lstclear(char_list, del_call);
	return (0);
}
