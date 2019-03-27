/*
 * swap.c
 *
 *  Created on: Mar 27, 2019
 *      Author: 17hao
 */

void inplace_swap(int *x, int *y) {
	*x = *x ^ *y;
	*y = *x ^ *y;
	*x = *x ^ *y;
}
