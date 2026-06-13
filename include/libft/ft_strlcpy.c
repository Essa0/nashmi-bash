/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 20:32:50 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:59:07 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
/*
int main(void)
{
    char dest[10];
    size_t ret;

    // Test 1: size larger than src length
    ret = strlcpy(dest, "hello", sizeof(dest));
    printf("Test 1 - dest: '%s', returned length: %zu\n", dest, ret);

    // Test 2: size smaller than src length (truncation)
    ret = strlcpy(dest, "hello world", 6);
    printf("Test 2 - dest: '%s', returned length: %zu\n", dest, ret);

    // Test 3: size == 0 (no copying)
    ret = strlcpy(dest, "hello", 0);
    printf("Test 3 - dest unchanged, returned length: %zu\n", ret);

    // Test 4: size == 1 (only room for null terminator)
    ret = strlcpy(dest, "abc", 1);
    printf("Test 4 - dest: '%s', returned length: %zu\n", dest, ret);

    // Test 5: empty source string
    ret = strlcpy(dest, "", sizeof(dest));
    printf("Test 5 - dest: '%s', returned length: %zu\n", dest, ret);

    return 0;
}
*/
