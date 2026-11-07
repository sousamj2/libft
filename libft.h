/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marisous <marisous@student.42lisb...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/25 15:36:15 by marisous          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2026/11/07 08:27:15 by marisous         ###   ########.fr       */
=======
/*   Updated: 2026/11/07 08:11:19 by marisous         ###   ########.fr       */
>>>>>>> 189a4cd (Update on the AI doxygen.)
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

/**
 * @brief Represents a node in a singly linked list.
 *
 * @param content Data stored in the node.
 * @param next Pointer to the next node in the list.
 */
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

/**
 * @brief Tests for an alphabetic character.
 *
 * @param c Character to test, representable as an unsigned char or EOF.
 * @return Non-zero if the character is an alphabet letter, 0 otherwise.
 */
int				ft_isalpha(int c);

/**
 * @brief Tests for a digit (0 through 9).
 *
 * @param c Character to test.
 * @return Non-zero if the character is a digit, 0 otherwise.
 */
int				ft_isdigit(int c);

/**
 * @brief Tests for an alphanumeric character.
 *
 * @param c Character to test.
 * @return Non-zero if the character is alphanumeric, 0 otherwise.
 */
int				ft_isalnum(int c);

/**
 * @brief Tests whether c is a 7-bit ASCII character.
 *
 * @param c Character to test.
 * @return Non-zero if c is between 0 and 127 inclusive, 0 otherwise.
 */
int				ft_isascii(int c);

/**
 * @brief Tests for any printable character including space.
 *
 * @param c Character to test.
 * @return Non-zero if c is printable, 0 otherwise.
 */
int				ft_isprint(int c);

/**
 * @brief Fills the first n bytes of the memory area pointed to by s with
 * the constant byte c.
 *
 * @param s Pointer to the block of memory to fill.
 * @param c Byte value to set (converted to unsigned char).
 * @param n Number of bytes to be set.
 * @return Pointer to the memory area s.
 */
void			*ft_memset(void *s, int c, size_t n);

/**
 * @brief Erases the data in the n bytes of the memory starting at the location
 * pointed to by s, by writing zeroes ('\0') to that area.
 *
 * @param s Pointer to the block of memory to clear.
 * @param n Number of bytes to set to zero.
 */
void			ft_bzero(void *s, size_t n);

/**
 * @brief Calculates the length of the string s.
 *
 * @param s Null-terminated string to measure.
 * @return The number of characters preceding the terminating null character.
 */
size_t			ft_strlen(const char *s);

/**
 * @brief Copies n bytes from memory area src to memory area dest. The memory
 * areas must not overlap; use ft_memmove if they do.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void			*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Copies n bytes from src to dest. The memory areas may overlap; copy
 * takes place safely without data corruption.
 *
 * @param dest Pointer to the destination memory area.
 * @param src Pointer to the source memory area.
 * @param n Number of bytes to copy.
 * @return Pointer to dest.
 */
void			*ft_memmove(void *dest, const void *src, size_t n);

/**
 * @brief Copies up to size - 1 characters from the null-terminated string src
 * to dst, null-terminating the result if size is not zero.
 *
 * @param dst Destination buffer.
 * @param src Source string to copy.
 * @param size Total size of the destination buffer.
 * @return Total length of the string attempted to be created (length of src).
 */
size_t			ft_strlcpy(char *dst, const char *src, size_t size);

/**
 * @brief Appends string src to the end of dst. Appends at most
 * size - strlen(dst) - 1 bytes, null-terminating the result.
 *
 * @param dst Destination string buffer.
 * @param src Source string to append.
 * @param size Total size of the destination buffer.
 * @return Total length of the string attempted to create (initial dst length
 * plus src length, or size + src length if dst was not null-terminated).
 */
size_t			ft_strlcat(char *dst, const char *src, size_t size);

/**
 * @brief Converts a lower-case letter to the corresponding upper-case letter.
 *
 * @param c Character to convert.
 * @return Converted uppercase character, or c unchanged if not lowercase.
 */
int				ft_toupper(int c);

/**
 * @brief Converts an upper-case letter to the corresponding lower-case letter.
 *
 * @param c Character to convert.
 * @return Converted lowercase character, or c unchanged if not uppercase.
 */
int				ft_tolower(int c);

/**
 * @brief Locates the first occurrence of character c in the string s.
 *
 * @param s String to search.
 * @param c Character to locate (converted to char).
 * @return Pointer to the matched character or NULL if not found.
 */
char			*ft_strchr(const char *s, int c);

/**
 * @brief Locates the last occurrence of character c in the string s.
 *
 * @param s String to search.
 * @param c Character to locate (converted to char).
 * @return Pointer to the matched character or NULL if not found.
 */
char			*ft_strrchr(const char *s, int c);

/**
 * @brief Compares at most the first n bytes of strings s1 and s2.
 *
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @param n Maximum number of bytes to compare.
 * @return Difference s1[i] - s2[i] at the first mismatch, or 0 if identical.
 */
int				ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial n bytes of memory area s for the first
 * instance of c.
 *
 * @param s Memory area to scan.
 * @param c Byte to search for (interpreted as unsigned char).
 * @param n Number of bytes to analyze.
 * @return Pointer to the matching byte or NULL if not found within n bytes.
 */
void			*ft_memchr(const void *s, int c, size_t n);

/**
 * @brief Compares the first n bytes of two memory areas s1 and s2.
 *
 * @param s1 First memory block.
 * @param s2 Second memory block.
 * @param n Number of bytes to compare.
 * @return Difference (byte of s1 - byte of s2) at mismatch, or 0 if equal.
 */
int				ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string
 * little in the string big, where not more than len characters are searched.
 *
 * @param big String to be searched.
 * @param little Substring to find.
 * @param len Maximum number of characters to search within big.
 * @return Pointer to the start of the substring, big if little is empty, or
 * NULL if not found.
 */
char			*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Converts the initial portion of the string pointed to by nptr to int.
 *
 * @param nptr String representation of an integral number.
 * @return The converted integer value.
 */
int				ft_atoi(const char *nptr);

/**
 * @brief Allocates memory for an array of n elements of size bytes each and
 * initializes all bytes to zero.
 *
 * @param n Number of elements.
 * @param size Size in bytes of each element.
 * @return Pointer to allocated zeroed memory, or NULL if allocation fails.
 */
void			*ft_calloc(size_t n, size_t size);

/**
 * @brief Duplicates the string s by allocating sufficient memory with malloc.
 *
 * @param s String to duplicate.
 * @return Pointer to the duplicate string, or NULL if allocation fails.
 */
char			*ft_strdup(const char *s);

/**
 * @brief Allocates and returns a substring from the string 's'. The substring
 * begins at index 'start' and has maximum size 'len'.
 *
 * @param s String from which to create the substring.
 * @param start Start index of the substring in string 's'.
 * @param len Maximum length of the substring.
 * @return The substring, or NULL if memory allocation fails.
 */
char			*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates and returns a new string, which is the result of the
 * concatenation of 's1' and 's2'.
 *
 * @param s1 Prefix string.
 * @param s2 Suffix string.
 * @return The new concatenated string, or NULL if memory allocation fails.
 */
char			*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Allocates and returns a copy of 's1' with the characters specified in
 * 'set' removed from the beginning and the end of the string.
 *
 * @param s1 The string to be trimmed.
 * @param set Reference set of characters to trim.
 * @return The trimmed string, or NULL if memory allocation fails.
 */
char			*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates and returns an array of strings obtained by splitting 's'
 * using the character 'c' as a delimiter. Array ends with a NULL pointer.
 *
 * @param s String to be split.
 * @param c Delimiter character.
 * @return Array of new strings resulting from the split, or NULL on failure.
 */
char			**ft_split(char const *s, char c);

/**
 * @brief Allocates and returns a string representing the integer received as
 * an argument. Negative numbers are handled.
 *
 * @param n Integer to convert.
 * @return String representing the integer, or NULL if allocation fails.
 */
char			*ft_itoa(int n);

/**
 * @brief Applies the function 'f' to each character of the string 's' to create
 * a new string resulting from successive applications of 'f'.
 *
 * @param s String on which to iterate.
 * @param f Function to apply to each character and its index.
 * @return String created from successive applications of 'f', or NULL.
 */
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' on each character of the string passed as
 * argument, passing its index as first argument. Each character is passed by
 * address to 'f' to be modified if necessary.
 *
 * @param s String on which to iterate.
 * @param f Function to apply to each character of 's' and its index.
 */
void			ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 *
 * @param c Character to output.
 * @param fd File descriptor on which to write.
 */
void			ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 *
 * @param s String to output.
 * @param fd File descriptor on which to write.
 */
void			ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor followed
 * by a newline.
 *
 * @param s String to output.
 * @param fd File descriptor on which to write.
 */
void			ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 *
 * @param n Integer to output.
 * @param fd File descriptor on which to write.
 */
void			ft_putnbr_fd(int n, int fd);

/**
 * @brief Allocates and returns a new list node. Member variable 'content' is
 * initialized with the given content, and 'next' is initialized to NULL.
 *
 * @param content Content to store in the new node.
 * @return The new node, or NULL if allocation fails.
 */
t_list			*ft_lstnew(void *content);

/**
 * @brief Adds the node 'new' at the beginning of the list.
 *
 * @param lst Address of a pointer to the first link of a list.
 * @param new Address of a pointer to the node to be added to the list.
 */
void			ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of nodes in a list.
 *
 * @param lst Beginning of the list.
 * @return Number of nodes in the list.
 */
unsigned int	ft_lstsize(t_list *lst);

/**
 * @brief Returns the last node of the list.
 *
 * @param lst Beginning of the list.
 * @return Last node of the list, or NULL if list is empty.
 */
t_list			*ft_lstlast(t_list *lst);

/**
 * @brief Adds the node 'new' at the end of the list.
 *
 * @param lst Address of a pointer to the first link of a list.
 * @param new Address of a pointer to the node to be added to the list.
 */
void			ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter a node and frees the memory of the node's
 * content using the function 'del' given as a parameter and free the node.
 * The memory of 'next' is not freed.
 *
 * @param lst Node to be freed.
 * @param del Address of the function used to delete the content.
 */
void			ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given node and every successor of that node,
 * using the function 'del' and free(). Finally, the pointer to the list
 * is set to NULL.
 *
 * @param lst Address of a pointer to a node.
 * @param del Address of the function used to delete the content of the node.
 */
void			ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content
 * of each node.
 *
 * @param lst Address of a pointer to a node.
 * @param f Address of the function used to iterate on the list.
 */
void			ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 'f' on the content of
 * each node. Creates a new list resulting of the successive applications of
 * the function 'f'. The 'del' function is used to delete the content of a node
 * if needed.
 *
 * @param lst Address of a pointer to a node.
 * @param f Address of the function used to iterate on the list.
 * @param del Address of the function used to delete the content of a node.
 * @return The new list, or NULL if the allocation fails.
 */
t_list			*ft_lstmap(
					t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));

#endif
