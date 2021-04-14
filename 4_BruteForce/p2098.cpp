/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p2098.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/24 19:22:51 by ycha              #+#    #+#             */
/*   Updated: 2021/02/24 20:09:13 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#define INF 10000000

using namespace std;

int n;
int W[16][16];
int dp[16][65536];

void pre() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input() {
	pre();
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> W[i][j];
}


int rec(int curr, int visit) {
	int ret;

	visit |= (1 << curr);
	if (visit == ~(-1 << n))
		return (W[curr][0] ? W[curr][0] : INF);
	if (dp[curr][visit])
		return(dp[curr][visit]);
	ret = INF;
	for (int i = 1; i < n; i++) {
		if ((visit & (1 << i)) || W[curr][i] == 0)
			continue;
		ret = min(ret, rec(i, visit) + W[curr][i]);
	}
	dp[curr][visit] = ret;
	return (ret);
}

void solve() {
	cout << rec(0, 0) << endl;
}

int	main(void) {
	input();
	solve();
	return (0);
}
