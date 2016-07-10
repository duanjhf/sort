/*
 * sortArrTest.c.
 * Description: sortArrTest.c.
 * Author: duan. Created on: 2016年4月24日
 * copyright(c)2016. LICENSE("GPL/BSD")
 */

#include "sortTest.h"
#include "sort.h"

void sortArrTest(SORT_ALGORITHM_TYPE sortType)
{
	int32 idx = 0;
	int32 testArr[] = {4, 2, 2, 3, 8, 9, 7, 1, 1};
	int32 cnt = sizeof(testArr) / sizeof(testArr[0]);

	sortDebug("sort type = %d\r\n", sortType);
	sort(sortType, (int32 *)&testArr[0], cnt);

	for (idx = 0; idx < cnt; ++ idx) {
		printf("%d\t", testArr[idx]);
	}
	printf("\r\n");
}

