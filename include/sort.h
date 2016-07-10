/*
 * sort.h.
 * Description: sort.h.
 * Author: duan. Created on: 2016年4月18日
 * copyright(c)2016. LICENSE("GPL/BSD")
 */

#ifndef INCLUDE_SORT_H_
#define INCLUDE_SORT_H_

#include "sortDefine.h"

int32 sortInit(void);
SORT_TYPE *sort(SORT_ALGORITHM_TYPE type, SORT_TYPE *head, uint32 elmCnt);

SORT_TYPE *selectionSort(SORT_TYPE *head, uint32 elmCnt);
SORT_TYPE *insertionSort(SORT_TYPE *head, uint32 elmCnt);

#endif /* INCLUDE_SORT_H_ */
