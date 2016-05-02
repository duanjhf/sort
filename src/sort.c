/*
 * sort.c.
 * Description: sort.c.
 * Author: duan. Created on: 2016年4月24日
 * copyright @ 2016. LICENSE("GPL/BSD")
 */

#include "sort.h"
#include <string.h>

/************************************************************************************************/
/*                                        VARIABLES                                             */
/************************************************************************************************/
static SORT_ALGORITHM _algorithmArr[SORT_ALGORITHM_MAX];

/************************************************************************************************/
/*                                        LOCAL FUNTIIONS                                       */
/************************************************************************************************/
static int32 _sortFuncRegister(SORT_ALGORITHM_TYPE type, SORT_TYPE *func());

static int32 _sortFuncRegister(SORT_ALGORITHM_TYPE type, SORT_TYPE *func())
{
	if (type < SORT_ALGORITHM_MAX) {
		_algorithmArr[type].type = type;
		_algorithmArr[type].func = func;
		return 1;
	}
	return -1;
}

/************************************************************************************************/
/*                                        PUBLIC FUNTIIONS                                      */
/************************************************************************************************/

int32 sortInit(void)
{
	memset(_algorithmArr, 0, sizeof(_algorithmArr));
	_sortFuncRegister(SORT_ALGORITHM_SELECTION, selectionSort);
	_sortFuncRegister(SORT_ALGORITHM_INSERTION, insertionSort);
	return 1;
}

SORT_TYPE *sort(SORT_ALGORITHM_TYPE type, SORT_TYPE *head, uint32 elmCnt)
{
	if (type < SORT_ALGORITHM_MAX && NULL != _algorithmArr[type].func) {
		return _algorithmArr[type].func(head, elmCnt);
	}
	return NULL;
}
