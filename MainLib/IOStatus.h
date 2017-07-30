#pragma once

#ifndef FALSE
#define FALSE               0
#endif
#ifndef TRUE
#define TRUE                1
#endif

enum eCursor {
	NONE	= 0x00,
	UP		= 0x01,
	DOWN	= 0x02,
	RIGHT	= 0x04,
	LEFT	= 0x08,
};
