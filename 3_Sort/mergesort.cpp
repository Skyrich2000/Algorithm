/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mergesort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:09:12 by ycha              #+#    #+#             */
/*   Updated: 2021/01/24 16:08:08 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdio.h> 

using namespace std;

int temp[1000001];

void merge(int* start, int* end) {
	int* mid;
	int* left;
	int* right;
	int* pos;

	pos = temp;
	mid = start + (end - start) / 2;
	left = start;
	right = mid;
	while(left < mid && right < end) {
		if (*left <= *right)
			*pos++ = *left++;
		else
			*pos++ = *right++;
	}
	while(left < mid)
		*pos++ = *left++;
	while(right < end)
		*pos++ = *right++;
	pos = temp;
	while(start < end)
		*start++ = *pos++;
}

void divide(int* start, int* end) {
	int* mid;

	if (start + 1 < end) {
		mid = start + (end - start) / 2;
		divide(start, mid);
		divide(mid, end);
		merge(start, end);
	}
}

void sort(int arr[], int n) {
	divide(arr, arr + n);
}

int	main(void) {
	int n;
	int arr[1000001];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", arr + i);
	sort(arr, n);
	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return (0);
}

