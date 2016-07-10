/*
 * sortMain.c.
 * Description: sortMain.c.
 * Author: duan. Created on: 2016年4月17日
 * copyright(c)2016. LICENSE("GPL/BSD")
 */

#include "sort.h"
#include "sortTest.h"
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[])
{
	int32 opt						= 0;
	SORT_ALGORITHM_TYPE sortType	= SORT_ALGORITHM_SELECTION;

	while(-1 != (opt = getopt(argc, argv, "t:"))) {
		switch (opt) {
			case 't' :
				if (0 == strncmp("selection", optarg, sizeof("selection"))) {
					sortType = SORT_ALGORITHM_SELECTION;
				} else if (0 == strncmp("insertion", optarg, sizeof("selection"))) {
					sortType = SORT_ALGORITHM_INSERTION;
				} else {
					sortError("unknown sort type %s. use default selection sort\r\n", optarg);
					break;
				}
				sortDebug("sort algorithm %s\r\n", optarg);
				break;
			default:
				sortError("unknown option.\r\n");
				return -1;
		}
	}

	sortInit();
	sortArrTest(sortType);
	return 0;
}
