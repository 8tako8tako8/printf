/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tauehara <tauehara@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 23:13:17 by tauehara          #+#    #+#             */
/*   Updated: 2020/10/12 01:40:58 by tauehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**mem_free(char **words, int words_i)
{
	int i;

	i = 0;
	while (i < words_i)
		free(words[i]);
	free(words);
	return (NULL);
}

static int	culc_words_cnt(char *s, char c)
{
	int	word_len;
	int	words_cnt;

	word_len = 0;
	words_cnt = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (word_len == 0)
				words_cnt++;
			word_len++;
		}
		else
			word_len = 0;
		s++;
	}
	return (words_cnt);
}

static char	**split_words(char **words, int words_cnt, char *s, char c)
{
	int		word_len;
	int		wi;

	word_len = 0;
	wi = 0;
	while (wi < words_cnt)
	{
		if (*s == c)
		{
			if (word_len)
			{
				if (!(words[wi++] = ft_substr(s - word_len, 0, word_len)))
					return (mem_free(words, wi));
			}
			word_len = 0;
		}
		else
			word_len++;
		s++;
	}
	words[wi] = NULL;
	return (words);
}

char		**ft_split(char const *s, char c)
{
	int		words_cnt;
	char	**words;

	if (!s)
		return (NULL);
	words_cnt = culc_words_cnt((char *)s, c);
	if (!(words = (char **)malloc((words_cnt + 1) * sizeof(char *))))
		return (NULL);
	if (words_cnt == 1)
	{
		if (!(words[0] = ft_strtrim(s, &c)))
			return (mem_free(words, words_cnt));
		words[1] = NULL;
		return (words);
	}
	if (!(words = split_words(words, words_cnt, (char *)s, c)))
		return (NULL);
	return (words);
}
