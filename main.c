/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ugdaniel <ugdaniel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:27:20 by ugdaniel          #+#    #+#             */
/*   Updated: 2021/05/04 14:29:25 by ugdaniel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dest, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, size_t count);
ssize_t	ft_read(int fd, void *buf, size_t count);
char	*ft_strdup(const char *s);

void	test_ft_strlen(void)
{
	char	str[] = "Hello World!";
	char	str2[] = "comment ca va lololololollololololollololololol";
	char	str3[] = "";

	printf("--------------------------\n");
	printf("----- ft_strlen test -----\n");
	printf("--------------------------\n");
	printf("%s\n", str);
	printf("strlen: %lu\n", strlen(str));
	printf("ft_strlen: %lu\n", ft_strlen(str));
	printf("--------------------------\n");
	printf("%s\n", str2);
	printf("strlen: %lu\n", strlen(str2));
	printf("ft_strlen: %lu\n", ft_strlen(str2));
	printf("--------------------------\n");
	printf("(empty string)%s\n", str3);
	printf("strlen: %lu\n", strlen(str3));
	printf("ft_strlen: %lu\n\n", ft_strlen(str3));
}

void	test_ft_strcpy()
{
	char	str[] = "Hello World!";
	char	str2[] = "comment ca va";
	char	str3[] = "";
	char	dest[] = "aaaaaaaaaaaaa";

	printf("--------------------------\n");
	printf("----- ft_strcpy test -----\n");
	printf("--------------------------\n");
	printf("before:\nstr: %s\ndest: %s\n", str, dest);
	strcpy(dest, str);
	printf("after:\nstr: %s\ndest: %s\n", str, dest);
	printf("--------------------------\n");
	printf("before:\nstr2: %s\ndest: %s\n", str2, dest);
	strcpy(dest, str2);
	printf("after:\nstr2: %s\ndest: %s\n", str2, dest);
	printf("--------------------------\n");
	printf("before (empty string):\nstr3: %s\ndest: %s\n", str3, dest);
	strcpy(dest, str3);
	printf("after:\nstr3: %s\ndest: %s\n", str3, dest);
}

void	test_ft_strcmp()
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

void	test_write(int fd, char *s, size_t len)
{
	printf("-------------------------\n");
	int	a;
	errno = 0;
	printf("write(%d, \"%s\", %zu):\t\t", fd, s, len);
	fflush(stdout);
	a = write(fd, s, len); 
	printf("\nreturn %d\n", a);
	if (a < 0)
		printf("errno: %s\n", strerror(errno));
	printf("\nft_write(%d, \"%s\", %zu):\t", fd, s, len);
	fflush(stdout);
	errno = 0;
	write(1, "\n", 1);
	a = ft_write(fd, s, len); 
	printf("\nreturn %d\n", a);
	if (a < 0)
		printf("errno: %s\n", strerror(errno));
	fflush(stdout);
}

void	test_ft_write(void)
{
	printf("-------------------------\n");
	printf("----- ft_write test -----\n");
	fflush(stdout);
	test_write(1, "coucou", 6);
	test_write(1, "coucou", 4);
	test_write(1, "coucou", 2);
	test_write(1, "coucou", 0);
	test_write(2, "coucou", 0);
	test_write(2, "coucou", 2);
	test_write(2, "coucou", 4);
	test_write(2, "coucou", 6);
	test_write(4, "coucou", 6);
	test_write(4, "coucou", 2);
	test_write(4, "coucou", 0);
}

void	test_read(char *name, size_t len, char wrongfd)
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

void	test_ft_read(void)
{
	printf("------------------------\n");
	printf("----- ft_read test -----\n");
	fflush(stdout);
	test_read("test.txt", 7, 0);
	test_read("test.txt", 89, 0);
	test_read("test.txt", 2, 0);
	test_read("test.txt", 7, 1);
}

void	test_strdup(char *str)
{
	char *buf;
	char *buf2;

	printf("--------------------------\n");
	buf = strdup(str);
	buf2 = ft_strdup(str);
	printf("strdup(\"%s\") à %p:\n%s à %p\n\n", str, str, buf, buf);
	printf("ft_strdup(\"%s\") à %p:\n%s à %p\n", str, str, buf2, buf2);
	free(buf);
	free(buf2);
}

void	test_ft_strdup(void)
{
	printf("--------------------------\n");
	printf("----- ft_strdup test -----\n");
	fflush(stdout);;
	test_strdup("Coucou");
	test_strdup("dazdazdazdazdazdaazdza");
	test_strdup("");
	test_strdup("salut");
}

int		main(void)
{
	test_ft_strlen();
	test_ft_strcpy();
	test_ft_strcmp();
	test_ft_write();
	test_ft_read();
	test_ft_strdup();
	return (0);
}