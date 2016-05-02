/*
 * selectionSort.c.
 * Description: selectionSort.c.
 * Author: duan. Created on: 2016年4月18日
 * copyright @ 2016. LICENSE("GPL/BSD")
 */

#include "sort.h"

SORT_TYPE *selectionSort(SORT_TYPE *head, uint32 elmCnt)
{
	uint32 idx_i		= 0;
	uint32 idx_j		= 0;
	SORT_TYPE *swap		= NULL;
	SORT_TYPE *cmp		= NULL;
	SORT_TYPE *next		= NULL;

	if ((NULL == head) || (0 == elmCnt)) {
		sortError("input failed.\r\n");
		return NULL;
	}

	if (1 == elmCnt) {
		return head;
	}

	swap = head;
	for (idx_i = 1; idx_i < elmCnt; ++ idx_i) {
		cmp = swap;
		next = swap;
		for (idx_j = idx_i; idx_j < elmCnt; ++ idx_j) {
			SORT_NEXT_SELF(next);
			if (SORT_CMP(cmp, next)) {
				cmp = next;
			}
		}
		if (swap != cmp) {
			SORT_SWAP(swap, cmp);
		}
		SORT_NEXT_SELF(swap);
	}
	return head;
}
