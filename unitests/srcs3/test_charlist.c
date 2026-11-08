/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_charlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 20:25:32 by marisous          #+#    #+#             */
/*   Updated: 2026/11/08 16:59:20 by marisous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <time.h>

char	ft_rand_print(void);
int		ft_rand(int limit);

void	print_call_char(void *c);
void	print_call_char_fd(void *c, int fd);
void	*copy_call(void *c);
void	del_call(void *c);
void	ft_lstiter_fd(t_list *lst, int fd, void (*g)(void *, int));
char	*ft_rand_str_alpnum(int size);
void	*upper_call_char(void *c);
void	*lower_call_char(void *c);
void	*ft_lstrmeli(t_list *lst, size_t to_delete, void (*del)(void*));

char	*ft_set_filename(void);

char	*ft_set_filename(void)
{
	char	*filename;
	char	*file_nparts[2];
	size_t	size_fparts[3];
	size_t	filenamesize;

	file_nparts[0] = "/tmp/fd_";
	file_nparts[1] = ft_rand_str_alpnum(5);
	size_fparts[0] = ft_strlen(file_nparts[0]);
	size_fparts[1] = ft_strlen(file_nparts[1]);
	filenamesize = size_fparts[0] + size_fparts[1];
	filename = malloc((filenamesize + 1) * sizeof(char));
	if (filename == NULL)
		return (NULL);		
	ft_bzero(filename, filenamesize + 1);
	size_fparts[2] = ft_strlcpy(filename, file_nparts[0], size_fparts[0] + 1);
	if (size_fparts[0] != size_fparts[2])
	{
		printf("Error: size file_nparts[0] --- %ld vs %ld",
			size_fparts[0],
			size_fparts[2]);
		return (NULL);
	}
	size_fparts[2] = ft_strlcat(filename, file_nparts[1], filenamesize + 11);
	if (size_fparts[0] + size_fparts[1] != size_fparts[2])
	{
		printf("Error: size file_nparts[1] --- %ld vs %ld",
			size_fparts[0] + size_fparts[1],
			size_fparts[2]);
		return (NULL);
	}
	free(file_nparts[1]);
	return (filename);
}

int	main(void)
{
	char	c;
	char	*content;
	int		ielement;
	int		nelements;
	int		isfront;
	t_list	**char_list;
	t_list	*lst_elem;
	t_list	*head_el;
	int		fd;
	char	*filename;
	t_list	*map_test[3];
	size_t del_i_el;

	srand(time(0));
	head_el = NULL;
	char_list = &head_el;
	del_i_el = ft_rand(10) + 2;
	nelements = ft_rand(20) + del_i_el + 2;
	ielement = 0;
	while (ielement < nelements)
	{
		isfront = ft_rand(2);
		c = ft_rand_print();
		content = malloc(2);
		if (content == NULL)
			return (1);
		content[0] = c;
		content[1] = '\0';		
		lst_elem = ft_lstnew(content);
		if (lst_elem == NULL)
		{
			free(content);
			break ;
		}
		if (isfront && ielement > 0)
			ft_lstadd_front(char_list, lst_elem);
		else
			ft_lstadd_back(char_list, lst_elem);
		ielement++;
	}
	filename = ft_set_filename();
	if (filename == NULL)
		return (1);
	ft_putendl_fd(filename, 1);
	fd = open(filename, O_WRONLY | O_CREAT, S_IRWXU);
	free(filename);
	ft_putstr_fd("Size of char list = ", 1);
	ft_putnbr_fd(ft_lstsize(*char_list), 1);
	ft_putstr_fd(" n elements = ", 1);
	ft_putnbr_fd(nelements, 1);
	fflush(stdout);
	ft_putstr_fd("Size of char list = ", fd);
	ft_putnbr_fd(ft_lstsize(*char_list), fd);
	ft_putstr_fd(" n elements = ", fd);
	ft_putnbr_fd(nelements, fd);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", fd);
	ft_lstiter(*char_list, print_call_char);
	ft_lstiter_fd(*char_list, fd, print_call_char_fd);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", fd);
	map_test[0] = ft_lstmap(*char_list, copy_call, del_call);
	map_test[1] = ft_lstmap(*char_list, upper_call_char, del_call);
	map_test[2] = ft_lstmap(*char_list, lower_call_char, del_call);
	ft_putendl_fd("------\ncopy call", 1);
	ft_putendl_fd("------\ncopy call", fd);
	ft_lstiter(map_test[0], print_call_char);
	ft_lstiter_fd(map_test[0], fd, print_call_char_fd);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", fd);
	map_test[0] = ft_lstrmeli(map_test[0], 0, del_call);
	if (map_test[0] == NULL)
	{
		ft_putendl_fd("Problems with ft_lstrmeli del_call 0", 1);
		return(1);
	}
	ft_putendl_fd("------\ndel 0 call", 1);
	ft_putendl_fd("------\ndel 0 call", fd);
	ft_lstiter(map_test[0], print_call_char);
	ft_lstiter_fd(map_test[0], fd, print_call_char_fd);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", fd);
	ft_putendl_fd("\n------\nupper call", 1);
	ft_putendl_fd("\n------\nupper call", fd);
	ft_lstiter(map_test[1], print_call_char);
	ft_lstiter_fd(map_test[1], fd, print_call_char_fd);
	map_test[1] = ft_lstrmeli(map_test[1], del_i_el, del_call);
	if (map_test[1] == NULL)
	{
		ft_putstr_fd("Problems with ft_lstrmeli del_call ", 1);
		ft_putnbr_fd(del_i_el, 1);
		ft_putendl_fd("", 1);
		return(1);
	}
	ft_putstr_fd("\n------\ndel ", 1);
	ft_putstr_fd("\n------\ndel ", fd);
	ft_putnbr_fd(del_i_el, 1);
	ft_putnbr_fd(del_i_el, fd);
	ft_putendl_fd(" call.", 1);
	ft_putendl_fd(" call.", fd);

	
	ft_lstiter(map_test[1], print_call_char);
	ft_lstiter_fd(map_test[1], fd, print_call_char_fd);
	ft_putendl_fd("", 1);
	ft_putendl_fd("", fd);
	ft_putendl_fd("------\nlower call", 1);
	ft_putendl_fd("------\nlower call", fd);
	ft_lstiter(map_test[2], print_call_char);
	ft_lstiter_fd(map_test[2], fd, print_call_char_fd);
	map_test[2] = ft_lstrmeli(
			map_test[2], ft_lstsize(map_test[2]) - 1, del_call);
	ft_putendl_fd("\n------\ndel last call", 1);
	ft_putendl_fd("\n------\ndel last call", fd);
	ft_lstiter(map_test[2], print_call_char);
	ft_lstiter_fd(map_test[2], fd, print_call_char_fd);
	ft_putendl_fd("\n", 1);
	ft_putendl_fd("\n", fd);
	ft_lstclear(&map_test[0], del_call);
	ft_lstclear(&map_test[1], del_call);
	ft_lstclear(&map_test[2], del_call);
	ft_lstclear(char_list, del_call);
	return (0);
}
