// Low-level functions for atomic operations: MIPS version  -*- C++ -*-

// Copyright (C) 2001, 2002, 2003, 2004 Free Software Foundation, Inc.
//
// This file is part of the GNU ISO C++ Library.  This library is free
// software; you can redistribute it and/or modify it under the
// terms of the GNU General Public License as published by the
// Free Software Foundation; either version 2, or (at your option)
// any later version.

// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License along
// with this library; see the file COPYING.  If not, write to the Free
// Software Foundation, 59 Temple Place - Suite 330, Boston, MA 02111-1307,
// USA.

// As a special exception, you may use this file as part of a free software
// library without restriction.  Specifically, if other files instantiate
// templates or use macros or inline functions from this file, or you compile
// this file and link it with other files to produce an executable, this
// file does not by itself cause the resulting executable to be covered by
// the GNU General Public License.  This exception does not however
// invalidate any other reasons why the executable file might be covered by
// the GNU General Public License.

#include <bits/atomicity.h>

namespace __gnu_cxx
{
  _Atomic_word
  __attribute__ ((__unused__))
  __exchange_and_add(volatile _Atomic_word* __mem, int __val)
  {
    _Atomic_word __result, __tmp;
    
    __asm__ __volatile__
      ("/* Inline exchange & add */\n\t"
       ".set	push\n\t"
       ".set	mips2\n\t"
       ".set	noreorder\n\t"
       ".set	nomacro\n"
       "1:\tll	%0,(%2)\n\t"
       "addu	%1,%3,%0\n\t"
       "sc	%1,(%2)\n\t"
       ".set	reorder\n\t"
       "beqzl	%1,1b\n\t"
       ".set	pop\n\t"
       "/* End exchange & add */\n"
       : "=&r"(__result), "=&r"(__tmp), "+r"(__mem)
       : "r"(__val)
       : "memory");

    return __result;
  }
  
  void
  __atomic_add(volatile _Atomic_word* __mem, int __val)
  { __exchange_and_add(__mem, __val); }
} // namespace __gnu_cxx
