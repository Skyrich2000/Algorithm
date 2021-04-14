/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boggle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 19:18:15 by ycha              #+#    #+#             */
/*   Updated: 2021/01/10 21:23:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

using namespace std;

string	word;
char	map[5][5];
int	dx[8] = {1, -1, 0, 0, 1, 1, -1, -1};
int	dy[8] = {0, 0, 1, -1, 1, -1, 1, -1};

bool	rec(int y, int x, string w)
{
	if (w.length() == 1)
		return (true);
	if (map[y][x] != w[0])
		return (false);
	for(int i = 0; i < 8; i++)
		if (rec(y + dy[i], x + dx[i], w.substr(1)))
			return (true);
	return (false);
}

bool	solve()
{
	for (int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			if (rec(i, j, word))
				return (true);
	return (false);
}

int	main(void)
{
	for (int i = 0; i < 5; i++)
		for(int j = 0; j < 5; j++)
			cin >> map[i][j];
	cin >> word;
	if (solve())
		cout << "YES";
	else 
		cout << "NO";
	return (0);
}

