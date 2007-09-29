/**
 * \file
 * <!--
 * Copyright 2003, 2004 Develer S.r.l. (http://www.develer.com/)
 * This file is part of DevLib - See README.devlib for information.
 * -->
 *
 * \brief Portable abstraction for high-resolution time handling (interface)
 *
 * \author Bernardo Innocenti <bernie@develer.com>
 */
#ifndef HPTIME_H
#define HPTIME_H

/* sparse? */
#ifdef __CHECKER__
	/* Any random OS would do */
	#define __unix__
#endif

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

#ifdef _WIN32

	/** our type for "high precision absolute time" */
	typedef __int64 hptime_t;

	#define HPTIME_TICKS_PER_SECOND		(10000000I64)
	#define HPTIME_TICKS_PER_MILLISEC	(10000I64)
	#define HPTIME_TICKS_PER_MICRO		(10I64)

#elif defined(__unix__) || (defined(__APPLE__) && defined(__MACH__))

	#include <stdint.h> /* int64_t */

	#ifndef DEVLIB_MTIME_DEFINED
		#define DEVLIB_MTIME_DEFINED 1 /* Resolve conflict with <cfg/compiler.h> */
		typedef int32_t mtime_t;
		#define SIZEOF_MTIME_T (32 / CPU_BITS_PER_CHAR)
		#define MTIME_INFINITE 0x7FFFFFFFL
	#endif

	/** Type for "high precision absolute time". */
	typedef int64_t hptime_t;

	#define HPTIME_TICKS_PER_SECOND		(1000000LL)
	#define HPTIME_TICKS_PER_MILLISEC	(1000LL)
	#define HPTIME_TICKS_PER_MICRO		(1LL)

#else /* !__unix__ */
	#error OS dependent support code missing for this OS
#endif /* !__unix__ */

/**
 * Return the current time with the maximum precision made available from the hosting OS
 */
extern hptime_t hptime_get(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* HPTIME_H */
