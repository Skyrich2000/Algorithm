/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2309.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 23:51:21 by ycha              #+#    #+#             */
/*   Updated: 2021/01/20 22:02:36 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <functional>
#include <iostream>
#include <algorithm>

using namespace std;

int height[9] = {0, };

bool rec(int pos, int count, int sum) {
	if (sum == 100 && count == 7)
		return (true);
	if (count > 7)
		return (false);
	for(int i = pos + 1; i < 9; i++) {
		if (rec(i, count + 1, sum + height[i])) {
			cout << height[i] << endl;
			return (true);
		}
	}
	return (false);
}

void solve() {
	sort(height, height + 9, greater<int>());
	rec(-1, 0, 0);
}

int	main(void) {
	for(int i = 0; i < 9; i++)
		cin >> height[i];
	solve();
	return (0);
}

