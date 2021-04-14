/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boardcover.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 06:04:58 by ycha              #+#    #+#             */
/*   Updated: 2021/01/17 17:53:12 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ostream>
#include <utility>

using namespace std;

int h;
int w;
int leftspace;
bool map[25][25] = {0, };

/*
** type 0 : ##
			#
** type 1 : ##
			 #
** type 2 : #
			##
** type 3 : #
		   ##
**
*/

int block[4][3][2] = { //[type][pos] = {y, x}
	{{0, 0}, {0, 1},
	 {1, 0}},
	{{0, 0}, {0, 1},
			 {1, 1}},
	{{0, 0},
	 {1, 0}, {1, 1}},
	{		 {0, 0},
	 {1, -1}, {1, 0}}
};

bool fill(int y, int x, int type)
{
	int dx;
	int dy;

	for (int i = 0; i < 3; i++) {
		dy = block[type][i][0];
		dx = block[type][i][1];
		if (!map[y + dy][x + dx])
			return (false);
	}
	for (int i = 0; i < 3; i++) {
		dy = block[type][i][0];
		dx = block[type][i][1];
		map[y + dy][x + dx] = false;
	}
	return (true);
}

void unfill(int y, int x, int type)
{
	int dx;
	int dy;

	for (int i = 0; i < 3; i++) {
		dy = block[type][i][0];
		dx = block[type][i][1];
		map[y + dy][x + dx] = true;
	}
}

void print(int y, int x)
{
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cout << (map[i][j] ? '.' : 'O');
		}
		cout << endl;
	}
	cout << y << x << endl;
}

int	rec(int y, int x)
{
	int ret;

	ret = 0;
	if (x >= w - 1)
		return (rec(y + 1, 0));
	if (y >= h - 1)
		return (1);
	if (!map[y][x])
		return (rec(y, x + 1));
	for (int i = 0; i < 4; i++) {
		if (fill(y, x, i)) {
			ret += rec(y, x + 1);
			unfill(y, x, i);
		}
	}
	return (ret);
}

int	solve()
{
	char temp;

	leftspace = 0;
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> temp;
			map[i][j] = (temp == '.') ? true : false;
			leftspace += map[i][j];
		}
	}
	if (leftspace % 3 != 0)
		return (0);
	return (rec(0, 0));
}

int	main(void)
{
	int C;

	cin >> C;
	while(C--)
		cout << solve() << endl;
	return (0);
}

