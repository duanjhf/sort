/*
 * insertionSort.c.
 * Description: insertionSort.c.
 * Author: duan. Created on: 2016年4月24日
 * copyright(c)2016. LICENSE("GPL/BSD")
 */

#include "sort.h"

SORT_TYPE *insertionSort(SORT_TYPE *head, uint32 elmCnt)
{
	uint32 idx_i		= 0;
	uint32 idx_j		= 0;
	SORT_TYPE *swap		= NULL;
	SORT_TYPE *cmp		= NULL;
	SORT_TYPE *prev		= NULL;

	if ((NULL == head) || (0 == elmCnt)) {
		sortError("input failed.\r\n");
		return NULL;
	}

	if (1 == elmCnt) {
		return head;
	}

	swap = SORT_NEXT(head);
	for (idx_i = 1; idx_i < elmCnt; ++ idx_i) {
		cmp = swap;
		for (idx_j = idx_i; idx_j > 0; -- idx_j) {
			prev = SORT_PREV(cmp);
			if (SORT_CMP(prev, cmp)) {
				SORT_SWAP(prev, cmp);
			} else {
				break;
			}
			SORT_PREV_SELF(cmp);
		}
		SORT_NEXT_SELF(swap);
	}
	return head;
}
