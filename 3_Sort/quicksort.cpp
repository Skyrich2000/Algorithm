/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ycha <ycha@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:09:19 by ycha              #+#    #+#             */
/*   Updated: 2021/01/24 17:29:33 by ycha             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int temp[1000001];

void divide(int* start, int* end) {
	int pivot;
	int* mid;
	int* t_start;
	int* t_end;
	
	t_start = temp;
	t_end = temp + (end - start) - 1;
	pivot = *start;
	if (start + 1 < end) {
		for(int* pos = start + 1; pos < end; pos++) {
			if (*pos <= pivot)
				*t_start++ = *pos;
			else
				*t_end-- = *pos;
		}
		*t_start = pivot;
		mid = start + (t_start - temp);
		for(int *pos = start, *t_pos = temp; pos < end; pos++, t_pos++)
			*pos = *t_pos;
		divide(start, mid);
		divide(mid + 1, end);
	}
}

void sort(int arr[], int n) {
        divide(arr, arr + n);
}

int main(void) {
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
