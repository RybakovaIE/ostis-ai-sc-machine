/*
 * This source file is part of an OSTIS project. For the latest info, see http://ostis.net
 * Distributed under the MIT License
 * (See accompanying file COPYING.MIT or copy at http://opensource.org/licenses/MIT)
 */

#ifndef _sc_allocator_h_
#define _sc_allocator_h_

#include <glib.h>
#include <memory.h>
#include "malloc.h"

typedef gpointer sc_pointer;
typedef gconstpointer sc_const_pointer;

#define sc_mem_stats() \
  ({ \
    mallopt(M_TRIM_THRESHOLD, 64 * 1024); \
    mallopt(M_MMAP_THRESHOLD, 512 * 1024); \
    mallopt(M_MMAP_MAX, 100000); \
    mallopt(M_TOP_PAD, 256 * 1024); \
  })

#define sc_mem_new(struct_type, n_structs) g_new0(struct_type, n_structs)

#define sc_mem_realloc(mem, n_blocks, n_blocks_bytes) g_realloc_n(mem, n_blocks, n_blocks_bytes)

#define sc_mem_set(pointer, constant, n_structs) memset(pointer, constant, n_structs)

#define sc_mem_cpy(source, dest, n_structs) memcpy(source, dest, n_structs)

#define sc_mem_free(pointer) g_free((sc_pointer)pointer)

#define sc_mem_trim() malloc_trim(0)

#endif
