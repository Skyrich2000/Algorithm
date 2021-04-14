/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p5585.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 22:31:03 by ycha              #+#    #+#             */
/*   Updated: 2021/01/17 22:48:19 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int type[6] = {500, 100, 50, 10, 5, 1};

int solve(int n)
{
	if (n == 0)
		return (0);
	for(int i = 0; i < 6; i++) {
		if (n >= type[i]) {
			n -= type[i];
			break;
		}
	}
	return (solve(n) + 1);
}

int	main(void)
{
	int n;

	cin >> n;
	cout << solve(1000 - n) << endl;
	return (0);
}

