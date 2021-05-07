/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:27:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/05/07 13:14:01 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

typedef struct	s_list
{
	void	*data;
	struct	s_list *next;
}				t_list;

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *dest, const char *src);
int				ft_strcmp(const char *s1, const char *s2);
ssize_t			ft_write(int fd, const void *buf, size_t count);
ssize_t			ft_read(int fd, void *buf, size_t count);
char			*ft_strdup(const char *s);

/* Bonuses */
void			ft_list_push_front(t_list **begin_list, void *data);
int				ft_list_size(t_list *begin);

void			test_ft_strlen(void)
{
	char	str[] = "Hello World!";
	char	str2[] = "comment ca va lololololollololololollololololol";
	char	str3[] = "";

	printf("--------------------------\n");
	printf("----- ft_strlen test -----\n");
	printf("--------------------------\n");
	printf("str: %s\n", str);
	printf("strlen: %lu\n", strlen(str));
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("--------------------------\n");
	printf("str: %s\n", str2);
	printf("strlen: %lu\n", strlen(str2));
	printf("ft_strlen: %lu\n", ft_strlen(str2));
	printf("--------------------------\n(empty string)\n");
	printf("str: %s\n", str3);
	printf("strlen: %lu\n", strlen(str3));
	printf("ft_strlen: %lu\n", ft_strlen(str3));
}

void			test_strcpy(char *src)
{
	char	dest[] = "aaaaaaaaaa";

	printf("str: %s\ndest before: \"%s\"\n", src, dest);
	ft_strcpy(dest, src);
	printf("dest after: \"%s\"\n", dest);
	fflush(stdout);
}

void			test_ft_strcpy(void)
{
	printf("--------------------------\n");
	printf("----- ft_strcpy test -----\n");
	printf("--------------------------\n");
	fflush(stdout);
	test_strcpy("coucou");
	printf("--------------------------\n");
	test_strcpy("cou");
	printf("--------------------------\n");
	test_strcpy("c");
	printf("--------------------------\n(empty string)\n");
	test_strcpy("");
}

void			test_ft_strcmp()
{
	char	str[] = "Hello World!";
	char	str2[] = "Hello World!";
	char	str3[] = "salut a tous";
	char	str4[] = "salut o tous";
	char	str5[] = "";
	char	str6[] = "";
	char	str7[] = "dzadazdzadzadzadaz";
	char	str8[] = "dzadazdazdzadzadzad";

	printf("--------------------------\n");
	printf("----- ft_strcmp test -----\n");
	printf("--------------------------\n");
	printf("str: %s\nstr2: %s\n", str, str2);
	printf("strcmp: %d\n", strcmp(str, str2));
	printf("ft_strcmp: %d\n", ft_strcmp(str, str2));
	printf("--------------------------\n");
	printf("str3: %s\nstr4: %s\n", str3, str4);
	printf("strcmp: %d\n", strcmp(str3, str4));
	printf("ft_strcmp: %d\n", ft_strcmp(str3, str4));
	printf("--------------------------\n");
	printf("(empty strings)\nstr5: %s\nstr6: %s\n", str5, str6);
	printf("strcmp: %d\n", strcmp(str5, str6));
	printf("ft_strcmp: %d\n", ft_strcmp(str5, str6));
	printf("--------------------------\n");
	printf("str7: %s\nstr8: %s\n", str7, str8);
	printf("strcmp: %d\n", strcmp(str7, str8));
	printf("ft_strcmp: %d\n", ft_strcmp(str7, str8));
}

void			test_write(int fd, char *s, size_t len)
{
	int	a;
	errno = 0;
	printf("------------------------\n");
	printf("write(%d, \"%s\", %zu) :\t\t", fd, s, len);
	fflush(stdout);
	a = write(fd, s, len); 
	printf("\nreturn %d\n", a);
	if (a < 0)
		printf("errno %s\n", strerror(errno));
	write(1, "\n", 1);
	printf("ft_write(%d, \"%s\", %zu) :\t", fd, s, len);
	fflush(stdout);
	errno = 0;
	a = ft_write(fd, s, len); 
	printf("\nreturn %d\n", a);
	if (a < 0)
		printf("errno %s\n", strerror(errno));
	fflush(stdout);
}

void 			test_ft_write(void)
{
	printf("-------------------------\n");
	printf("----- ft_write test -----\n");
	fflush(stdout);
	test_write(1, "coucou", 6);
	test_write(1, "coucou", 2);
	test_write(1, "coucou", 0);
	test_write(2, "coucou", 0);
	test_write(2, "coucou", 4);
	test_write(2, "coucou", 6);
	test_write(4, "coucou", 6);
}
void			test_read(char *name, size_t len, char wrongfd)
{
	printf("-------------------------\n");
	char buf[100];
	int	a, fd;
	errno = 0;
	for (int i = 0; i < 100; i++)
		buf[i] = 0;
	fd = open(name, O_RDONLY);
	a = read(wrongfd ? 8 : fd, buf, len); 
	printf("read(%s, buf, %zu)\n", wrongfd ? "wrong_fd" : "fd", len);
	printf("buf : \t\t\"%s\"\n", buf);
	printf("return %d\n", a);
	if (a < 0)
		printf("errno : %s\n", strerror(errno));
	fflush(stdout);
	close(fd);

	errno = 0;
	write(1, "\n", 1);
	for (int i = 0; i < 100; i++)
		buf[i] = 0;
	fd = open(name, O_RDONLY);
	a = ft_read(wrongfd ? 8 : fd, buf, len); 
	printf("ft_read(%s, buf, %zu)\n",wrongfd ? "wrong_fd" : "fd", len);
	printf("buf : \t\t\"%s\"\n", buf);
	printf("return %d\n", a);
	if (a < 0)
		printf("errno : %s\n", strerror(errno));
	fflush(stdout);
	close(fd);
}

void			test_ft_read(void)
{
	printf("------------------------\n");
	printf("----- ft_read test -----\n");
	fflush(stdout);
	test_read("test.txt", 7, 0);
	test_read("test.txt", 89, 0);
	test_read("test.txt", 2, 0);
	test_read("test.txt", 7, 1);
}

void			test_strdup(char *str)
{
	char *buf;
	char *buf2;

	printf("str: %s | addr: %p\n\n", str, str);
	buf = strdup(str);
	buf2 = ft_strdup(str);
	printf("strdup(\"%s\"): %s | addr: %p\n", str, buf, buf);
	printf("ft_strdup(\"%s\"): %s | addr: %p\n", str, buf2, buf2);
	free(buf);
	free(buf2);
}

void			test_ft_strdup(void)
{
	printf("--------------------------\n");
	printf("----- ft_strdup test -----\n");
	printf("--------------------------\n");
	fflush(stdout);;
	test_strdup("Coucou");
	printf("--------------------------\n");
	test_strdup("dazdazdazdazdazdaazdza");
	printf("--------------------------\n(empty string)\n");
	test_strdup("");
	printf("--------------------------\n");
	test_strdup("salut");
}

t_list			*new_elem(void *data)
{
	t_list	*ret;

	if (!(ret = malloc(sizeof(t_list))))
		return (NULL);
	ret->data = data;
	ret->next = NULL;
	printf("elem %s created\n", data);
	return (ret);
}

void			test_ft_list_size(void)
{
	t_list 		*tmp = NULL;
	t_list		*begin = new_elem("1");
	t_list		*e1 = new_elem("2");
	t_list		*e2 = new_elem("3");
	t_list		*e3 = new_elem("4");
	t_list		*e4 = new_elem("5");
	t_list		*e5 = new_elem("6");

	begin->next = e1;
	e1->next = e2;
	e2->next = e3;
	printf("ft_list_size: %d\n", ft_list_size(begin));
	e3->next = e4;
	e4->next = e5;
	printf("added 2 elements in the list\n");
	printf("ft_list_size: %d\n", ft_list_size(begin));
	while (begin)
	{
		tmp = begin;
		begin = begin->next;
		free(tmp);
		tmp = NULL;
	}
}

int				main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	test_ft_list_size();
	return (0);
}