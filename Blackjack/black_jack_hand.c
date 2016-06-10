/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   black_jack_hand.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdieulan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/10 14:56:54 by rdieulan          #+#    #+#             */
/*   Updated: 2016/06/10 15:12:18 by rdieulan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int black_jack_hand(char *hand)
{
	int i;
	int score;
	int aces;

	i = 0;
	aces = 0;
	score = 0;
	while (hand[i] != '\n')
	{
		if (hand[i] == 'T' || hand[i] == 'J' || hand[i] == 'D' || hand[i] == 'K')
			score += 10;
		else if (hand[i] == 'A')
		{
			score += 10;
			aces += 1;
		}
		else
			score += hand[i] - 48;
		i++;
	}
	while (score > 21 && aces > 0)
	{
		score -= 9;
		aces -= 1;
	}
	return (score);
}

int		main(int argc, char **argv)
{
	char *hand = "AA8\n";
	int score;

	printf("score = %d\n", black_jack_hand(hand));
	return 0;
}
