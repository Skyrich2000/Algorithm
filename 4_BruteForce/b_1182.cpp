/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p1182.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 14:49:28 by ycha              #+#    #+#             */
/*   Updated: 2021/01/20 22:22:01 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

using namespace std;

int n;
int s;
int nums[25] = {0, };

int rec(int pos, int sum) {
	int ret;
	
	if (pos == n)
		return (sum == s ? 1 : 0);
	ret = 0;
	for (int i = pos + 1; i <= n; i++)
		ret += rec(i, sum + nums[i]);
	return (ret);
}

int solve() {
	return (rec(-1, 0) - (s == 0));
}

int	main(void) {
	cin >> n >> s;
	for(int i = 0; i < n; i++)
		cin >> nums[i];
	cout << solve() << endl;
	return (0);
}

