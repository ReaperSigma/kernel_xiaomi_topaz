/* SPDX-License-Identifier: GPL-2.0 */
#undef TRACE_SYSTEM
#define TRACE_SYSTEM block

#define TRACE_INCLUDE_PATH trace/hooks

#if !defined(_TRACE_HOOK_BLOCK_H) || defined(TRACE_HEADER_MULTI_READ)
#define _TRACE_HOOK_BLOCK_H

#include <linux/tracepoint.h>
#include <trace/hooks/vendor_hooks.h>

#ifdef __GENKSYMS__
#include <../block/blk-mq-tag.h>
#include <../block/blk-mq.h>
#include <linux/blk-mq.h>
#endif

struct blk_mq_tags;
struct blk_mq_alloc_data;
struct blk_mq_tag_set;
struct request;

DECLARE_HOOK(android_vh_blk_alloc_rqs,
	TP_PROTO(size_t *rq_size, struct blk_mq_tag_set *set,
		struct blk_mq_tags *tags, unsigned int hctx_idx),
	TP_ARGS(rq_size, set, tags, hctx_idx));

DECLARE_HOOK(android_vh_blk_rq_ctx_init,
	TP_PROTO(struct request *rq, struct blk_mq_tags *tags,
		struct blk_mq_alloc_data *data, u64 alloc_time_ns),
	TP_ARGS(rq, tags, data, alloc_time_ns));

DECLARE_HOOK(android_vh_blk_account_io_done,
        TP_PROTO(struct request *rq),
        TP_ARGS(rq));

#endif /* _TRACE_HOOK_BLOCK_H */

/* This part must be outside protection */
#include <trace/define_trace.h>
