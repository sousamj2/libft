/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:39:58 by marisous          #+#    #+#             */
/*   Updated: 2026/11/03 14:30:23 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char ft_upper(unsigned int index, char c);
char	ft_lower(unsigned int index, char c);
char	ft_odd_up_even_down(unsigned int index, char c);
char	ft_up1_down2_id3(unsigned int index, char c);


void	ft_lstiter_fd(t_list *lst, int fd, void (*g)(void *, int))
{
	if (lst == NULL)
		return ;
	g(lst->content, fd);
	ft_lstiter_fd(lst->next, fd, g);
}

void del_call(void *c)
{
	free(c);
}

void *copy_call(void *c)
{
	char *ptr;

	ptr = ft_strdup((char *)c);
	return (ptr);
}

void print_call_char(void *c)
{
	ft_putchar_fd( *(char *) c, 1);
}

void print_call_str(void *c)
{
	ft_putstr_fd( (char *) c, 1);
}

void print_call_char_fd(void *c, int fd)
{
	ft_putchar_fd( *(char *) c, fd);
}

void print_call_str_fd(void *c, int fd)
{
	ft_putstr_fd( (char *) c, fd);
}

void *upper_call_char(void *c)
{
	char letter;
	char *ptr;

	letter = ft_toupper(*((char *)c));
	ptr = ft_strdup(&letter);
	return (ptr);
}



void *upper_call_srt(void *c)
{
	char *str;

	str = ft_strmapi((char *) c, ft_upper);
	return (str);
}

void *lower_call_srt(void *c)
{
	char *str;

	str = ft_strmapi((char *) c, ft_lower);
	return (str);
}

void *lower_call_char(void *c)
{
	char letter;
	char *ptr;

	letter = ft_tolower(*((char *)c));
	ptr = ft_strdup(&letter);
	return (ptr);
}


char	ft_upper(unsigned int index, char c)
{
	if (index == 0)
		return (ft_toupper(c));
	else
		return (ft_toupper(c));
}

char	ft_lower(unsigned int index, char c)
{
	if (index == 0)
		return (ft_tolower(c));
	else
		return (ft_tolower(c));
}

char	ft_odd_up_even_down(unsigned int index, char c)
{
	if (index % 2 == 1)
		return (ft_toupper(c));
	else
		return (ft_tolower(c));
}

char	ft_up1_down2_id3(unsigned int index, char c)
{
	if (index % 3 == 1)
		return (ft_toupper(c));
	else if (index % 3 == 2)
		return (ft_tolower(c));
	else
		return (c);
}
