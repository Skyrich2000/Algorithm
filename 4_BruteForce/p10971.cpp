/* ************************************************************************** */
/*									    */
/*							:::      ::::::::   */
/*   p10971.cpp                                         :+:      :+:    :+:   */
/*						    +:+ +:+	 +:+     */
/*   By: ycha <ycha@student.42seoul.kr>	     +#+  +:+       +#+	*/
/*						+#+#+#+#+#+   +#+	   */
/*   Created: 2021/01/20 23:50:32 by ycha	      #+#    #+#	     */
/*   Updated: 2021/01/24 14:42:11 by ycha             ###   ########.fr       */
/*									    */
/* ************************************************************************** */

#include <iostream>
#include <utility>

using namespace std;

int n;
int W[11][11] = {0, };
bool visit[11] = {false, };

int rec(int curr, int first, int cnt) {
	int ret;

	if (cnt == n - 1)
		return (W[curr][first] ? W[curr][first] : 10000000);
	ret = 10000000;
	visit[curr] = true;
	for (int i = 0; i < n; i++) {
		if (visit[i] || W[curr][i] == 0)
			continue;
		ret = min(ret, rec(i, first, cnt + 1) + W[curr][i]);
	}
	visit[curr] = false;
	return (ret);
}

int solve() {
	int ret;

	ret = 10000000;
	for (int i = 0; i < n; i++)
		ret = min(ret, rec(i, i, 0));
	return (ret);
}

int     main(void) {
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> W[i][j];
	cout << solve() << endl;
	return (0);
}

