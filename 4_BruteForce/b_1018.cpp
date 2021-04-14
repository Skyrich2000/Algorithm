/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1018.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 22:30:04 by ycha              #+#    #+#             */
/*   Updated: 2021/01/20 22:56:41 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int n;
int m;
int map[55][55] = {0, };
int ans[8][8] = {
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
	{1, -1, 1, -1, 1, -1, 1, -1},
	{-1, 1, -1, 1, -1, 1, -1, 1},
};

int check(int y, int x) {
	int ret;

	ret = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			ret += (map[y + i][x + j] * ans[i][j] == 1) ? 1 : 0;
		}
	}
	return (min(ret, 64 - ret));
}

int solve() {
	int ret;

	ret = 99;
	for (int i = 0; i < n - 7; i++) {
		for (int j = 0; j < m - 7; j++) {
			ret = min(ret, check(i, j));
		}
	}
	return (ret);
}

int	main(void) {
	char temp;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> temp;
			map[i][j] = (temp == 'W') ? 1 : -1;
		}
	}
	cout << solve() << endl;
	return (0);
}

