/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zshkukan <zshkukan@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 13:30:17 by zshkukan          #+#    #+#             */
/*   Updated: 2025/08/24 10:46:17 by zshkukan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest == src || n == 0)
		return (dest);
	if (src > dest)
	{
		while (i < n)
		{
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			((unsigned char *) dest)[n] = ((unsigned char *) src)[n];
		}
	}
	return (dest);
}
/* int main() {
  char str[] = "hello world";
  char str2[5];
  
  ft_memmove(str2 , str , 9);
  printf("%s\n", str2);
  
  printf("\n");
  
  memmove(str2 , str, 9);
  printf("%s\n", str2);
  
  return 0;
}
*/
