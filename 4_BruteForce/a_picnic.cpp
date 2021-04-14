/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picnic.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 22:11:06 by ycha              #+#    #+#             */
/*   Updated: 2021/01/17 21:41:16 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int	rec(int n, bool couple[10], bool friends[10][10])
{
	int ret;
	int mate_from;
	int mate_to;

	ret = 0;
	mate_from = -1;
	for (int i = 0; i < n; i++) {
		if (couple[i] == false) {
			mate_from = i;
			break;
		}
	}
	if (mate_from == -1)
		return (1);
	
	for (int i = 0; i < n; i++) {
		mate_to = i;
		if (friends[mate_from][mate_to] == true && couple[mate_to] == false) {
			couple[mate_from] = true;
			couple[mate_to] = true;
			ret += rec(n, couple, friends);
			couple[mate_from] = false;
			couple[mate_to] = false;
		}
	}

	return (ret);
}

int	solve()
{
	int n;
	int m;
	bool couple[10] = {false, };
	bool friends[10][10] = {false, };

	cin >> n >> m;
	
	for (int i = 0; i < m; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		friends[t1][t2] = 1;
		friends[t2][t1] = 1;
	}	
	return (rec(n, couple, friends));
}

int	main(void)
{
	int C;

	cin >> C;
	while(C--)
		cout << solve() << endl;
	return (0);
}

