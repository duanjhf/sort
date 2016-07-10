/*
 * sortDefine.h.
 * Description: sortDefine.h.
 * Author: duan. Created on: 2016年4月17日
 * copyright(c)2016. LICENSE("GPL/BSD")
 */

#ifndef INCLUDE_SORTDEFINE_H_
#define INCLUDE_SORTDEFINE_H_

#include <stdio.h>

typedef	char			int8;
typedef	short			int16;
typedef	int				int32;
typedef	unsigned char	uint8;
typedef	unsigned short	uint16;
typedef	unsigned int	uint32;


/************************************************ debug **********************************************/
extern char *basename(char *path);
#define	sortDebug(fmt, args...)	\
		printf("[sortDebug] %s, %d, %s: "fmt, (char *)basename(__FILE__), __LINE__, __FUNCTION__, ##args)
#define	sortError(fmt, args...)	\
		printf("[!!!!, sortError] %s, %d, %s: "fmt, (char *)basename(__FILE__), __LINE__, __FUNCTION__, ##args)

/******************************************** sort define *******************************************/
typedef	int32					SORT_TYPE;
#define	SORT_CMP(cmp, next)		( (*(cmp)) > (*(next)) )
#define	SORT_NEXT_SELF(now)		( ++ (now) )
#define	SORT_NEXT(now)			( (now) + 1 )
#define	SORT_PREV_SELF(now)		( -- (now) )
#define	SORT_PREV(now)			( (now) - 1)
#define	SORT_SWAP(swap, cmp)	do { SORT_TYPE tmp = *(swap); *(swap) = *(cmp); *(cmp) = tmp; } while (0)

/************************************* sort algorithm define ****************************************/
typedef enum
{
	SORT_ALGORITHM_SELECTION,
	SORT_ALGORITHM_INSERTION,
	SORT_ALGORITHM_MAX,
} SORT_ALGORITHM_TYPE;

typedef struct
{
	SORT_ALGORITHM_TYPE type;
	SORT_TYPE * (*func)(SORT_TYPE *head, uint32 elmCnt);
} SORT_ALGORITHM;

#endif /* INCLUDE_SORTDEFINE_H_ */
