/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2810.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:07:22 by ycha              #+#    #+#             */
/*   Updated: 2021/01/17 23:32:45 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int n;
char seat[55] = {0, };

int solve(bool left, int pos)
{
	if (pos >= n)
		return (0);
	if (seat[pos] == 'S')
		return (solve(left, pos + 1));
	return (solve(true, pos + 2) + left);
}

int	main(void)
{
	cin >> n;
	for(int i = 0; i < n; ++i)
		cin >> seat[i];
	cout << n - solve(0, 0) << endl;
	return (0);
}

