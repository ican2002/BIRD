/*
 *	BIRD Coroutines
 *
 *	(c) 2017 Martin Mares <mj@ucw.cz>
 *	(c) 2020 Maria Matejka <mq@jmq.cz>
 *
 *	Can be freely distributed and used under the terms of the GNU GPL.
 */

#ifndef _BIRD_CORO_H_
#define _BIRD_CORO_H_

#include "lib/resource.h"

/* A completely opaque coroutine handle. */
struct coroutine;

/* Run a coroutine. */
struct coroutine *coro_run(pool *, void (*entry)(void *), void *data);

/* Check whether a coroutine has finished. */
_Bool coro_finished(struct coroutine *);

/* Coroutines are independent threads bound to pools.
 * You request a coroutine by calling coro_run().
 * It is forbidden to free a running coroutine; you must defer the free routine
 * until coro_finished() returns 1.
 */

/* Sadly, nobody is waiting for this coroutine. It is done and freeing itself now. */
void coro_self_done(struct coroutine *c);

#endif
