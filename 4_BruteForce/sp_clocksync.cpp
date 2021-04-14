/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clocksync.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 16:46:39 by ycha              #+#    #+#             */
/*   Updated: 2021/01/17 19:17:32 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int temp;
int g_ret;
int g_clock[10];
int g_switch[10][5] = {
	{0, 1, 2, -1, -1},
	{3, 7, 9, 11, -1},
	{4, 10, 14, 15, -1},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15, -1},
	{3, 14, 15, -1, -1},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

void press(int switch_index)
{
	int clock_index;

	for(int i = 0; i < 5; i++) {
		clock_index = g_switch[switch_index][i];
		if (clock_index == -1)
			break;
		g_clock[clock_index] += 1;
	}
}

bool is_done()
{
	for(int i = 0; i < 16; i++) {
		if (g_clock[i] % 4 != 0)
			return (false);
	}
	return (true);
}

void print()
{
	for(int i = 0; i < 16; i++)
		cout << g_clock[i] << " ";
	cout << endl;
}

void rec(int switch_index, int count)
{
	if (switch_index >= 10) {
		if (is_done())
			g_ret = min(g_ret, count);
		return ;
	}
	switch_index++;
	temp ++;
//	cout << switch_index << endl;
	for(int i = 0; i < 4; i++) {
		rec(switch_index, count + i);
		press(switch_index);
	}
}

int solve(void)
{
	temp = 0;
	g_ret = 99;
	for (int i = 0; i < 16; i++) {
		cin >> g_clock[i];
		g_clock[i] /= 3;
	}
	rec(-1, 0);
//	cout << temp << endl;
	return (g_ret == 99 ? -1 : g_ret);
}

int	main(void)
{
	int C;

	cin >> C;
	while(C--)
		cout << solve() << endl;
	return (0);
}
