#ifndef __memory_H                                      // -*- c++ -*- 
#define __memory_H
/*
 * Copyright (c) 2001 Stephen Williams (steve@icarus.com)
 * Copyright (c) 2001 Stephan Boettcher <stephan@nevis.columbia.edu>
 *
 *    This source code is free software; you can redistribute it
 *    and/or modify it in source code form under the terms of the GNU
 *    General Public License as published by the Free Software
 *    Foundation; either version 2 of the License, or (at your option)
 *    any later version.
 *
 *    This program is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU General Public License for more details.
 *
 *    You should have received a copy of the GNU General Public License
 *    along with this program; if not, write to the Free Software
 *    Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA
 */
#if !defined(WINNT)
#ident "$Id: memory.h,v 1.1 2001/05/01 01:09:39 steve Exp $"
#endif

#include "pointers.h"
#include "functor.h"

typedef struct vvp_memory_s *vvp_memory_t;
typedef unsigned char *vvp_memory_bits_t;
typedef struct vvp_memory_index_s *vvp_memory_index_t;

void memory_new(vvp_memory_t mem, char *name, int lsb, int msb,
		unsigned idxs, long *idx);
void memory_port_new(vvp_memory_t mem, vvp_ipoint_t ix, 
		     unsigned nbits, unsigned bitoff);
void memory_init_nibble(vvp_memory_t mem, unsigned idx, unsigned char val);

void memory_set(vvp_memory_t mem, unsigned idx, unsigned char val);
unsigned memory_get(vvp_memory_t mem, unsigned idx);
void schedule_memory(vvp_memory_t mem, unsigned idx, 
		     unsigned char val, unsigned delay);

unsigned memory_addr_width(vvp_memory_t mem);
unsigned memory_data_width(vvp_memory_t mem);

vvp_memory_t memory_find(char *label);
vvp_memory_t memory_create(char *label);

/*
 * $Log: memory.h,v $
 * Revision 1.1  2001/05/01 01:09:39  steve
 *  Add support for memory objects. (Stephan Boettcher)
 *
 */

#endif
