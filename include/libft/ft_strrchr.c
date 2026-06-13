/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:57:04 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:59:31 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		i;

	i = ft_strlen(s);
	while (s[i] != (char)c && i > 0)
	{
		i--;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	else
		return (NULL);
}
/*
int main(void)
{
        const char *test1 = "hello world";
        const char *test2 = "42 is the answer";
        const char *test3 = "abcabcabc";
        const char *test4 = "";
        const char *test5 = "null\0invisible";

        // Test 1: last occurrence of 'l'
        printf("Test 1: %s\n", ft_strrchr(test1, 'l'));

        // Test 2: last occurrence of ' '
        printf("Test 2: %s\n", ft_strrchr(test2, ' '));

        // Test 3: last occurrence of 'a'
        printf("Test 3: %s\n", ft_strrchr(test3, 'a'));

        // Test 4: not found ('z')
        printf("Test 4: %s\n", ft_strrchr(test1, 'z'));

        // Test 5: empty string, search for '\0'
        printf("Test 5: %s\n", ft_strrchr(test4, '\0'));

        // Test 6: find null terminator in string with embedded null
        printf("Test 6: %s\n", ft_strrchr(test5, '\0'));

        return 0;
}
*/
