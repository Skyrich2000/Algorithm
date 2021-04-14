/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p3085.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 14:53:05 by ycha              #+#    #+#             */
/*   Updated: 2021/01/15 16:23:23 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int N;
char map[55][55] = {0, };
bool changed = false;
int ret;

/*
** dir 0 : move right
** dir 1 : move down
*/

bool	is_inrange(pair<int, int> pos) {
	int y;
	int x;

	y = pos.first;
	x = pos.second;

	if (y < 0 || y >= N)
		return (false);
	if (x < 0 || x >= N)
		return (false);
	return (true);
}

pair<int, int>	bw(pair<int, int> pos, bool dir) {
	return (make_pair(pos.first + (dir ? -1 : 0), pos.second + (dir ? 0 : -1)));
}

pair<int, int>	fw(pair<int, int> pos, bool dir) {
	return (make_pair(pos.first + (dir ? 1 : 0), pos.second + (dir ? 0 : 1)));
}

pair<int, int>	le(pair<int, int> pos, bool dir) {
	return (make_pair(pos.first + (dir ? 0 : -1), pos.second + (dir ? 1 : 0)));
}

pair<int, int> ri(pair<int, int> pos, bool dir) {
	return (make_pair(pos.first + (dir ? 0 : 1), pos.second + (dir ? -1 : 0)));
}

char	get(pair<int, int> pos) {
	if (!is_inrange(pos))
		return (0);
	return (map[pos.first][pos.second]);
}

bool	change(pair<int, int> from, pair<int, int> to) {
	char temp;

	if (!is_inrange(from) || !is_inrange(to))
		return (false);
	if (get(from) == get(to))
		return (false);
	temp = get(from);
	map[from.first][from.second] = get(to);
	map[to.first][to.second] = temp;
	return (true);
}

void	rec(pair<int, int> pos, bool dir, int count)
{
	pair<int, int> npos;

	if (!is_inrange(pos)) {
	//	cout << endl;
		return ;
	}

	if (get(pos) != get(bw(pos, dir)))
		count = 0;
	ret = max(++count, ret);
	npos = fw(pos, dir);
	//cout << get(pos) << '(' << count << ')' ; 

	if (!changed) {
		changed = true;
		if (change(npos, le(npos, dir))) {
			rec(npos, dir, count);
			change(le(npos, dir), npos);
		}

		if (change(npos, ri(npos, dir))) {
			rec(npos, dir, count);
			change(ri(npos, dir), npos);
		}

		if (change(npos, fw(npos, dir))) {
			rec(npos, dir, count);
			change(fw(npos, dir), npos);
		}
		changed = false;
	}
	rec(npos, dir, count);
}

int	solve()
{
	ret = 0;
	for (int i = 0; i < N; i++) {
		rec(make_pair(i, 0), 0, 1); 
		rec(make_pair(0, i), 1, 1);
	//	cout << "done" << endl;
	}
	return (ret);
			
}

int	main(void)
{
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	cout << solve();
		
	return (0);
}

