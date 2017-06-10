/*-
 * Copyright (c) 2016, Clément Lansmarie
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * * Redistributions of source code must retain the above copyright
 *   notice, this list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright
 *   notice, this list of conditions and the following disclaimer in the
 *   documentation and/or other materials provided with the distribution.
 *
 * * Neither the name of the copyright holder nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 * $agiLib$
 */

#ifndef __AGILIB_BASE_INTEGER__
#define __AGILIB_BASE_INTEGER__

namespace agiLib {
  using u8 = __UINT8_TYPE__;
  using s8 = __INT8_TYPE__;

  using u16 = __UINT16_TYPE__;
  using s16 = __INT16_TYPE__;

  using u32 = __UINT32_TYPE__;
  using s32 = __INT32_TYPE__;

  using u64 = __UINT64_TYPE__;
  using s64 = __INT64_TYPE__;

#define __AGILIB_INTEGER_ASSERTS(bits) \
  static_assert(sizeof(u##bits) == (bits / 8), "Integer size error."); \
  static_assert(sizeof(s##bits) == (bits / 8), "Integer size error.")

  __AGILIB_INTEGER_ASSERTS(8);
  __AGILIB_INTEGER_ASSERTS(16);
  __AGILIB_INTEGER_ASSERTS(32);
  __AGILIB_INTEGER_ASSERTS(64);

#undef __AGILIB_INTEGER_ASSERTS

  namespace Private {
    template<int bits, bool sign>
    struct Integer;

#define __AGILIB_INTEGER_TEMPLATE_TYPES(bits) \
    template<> \
    struct Integer<bits, true> { \
      using Type = s##bits; \
    }; \
    template<> \
    struct Integer<bits, false> { \
      using Type = u##bits; \
    }

    __AGILIB_INTEGER_TEMPLATE_TYPES(8);
    __AGILIB_INTEGER_TEMPLATE_TYPES(16);
    __AGILIB_INTEGER_TEMPLATE_TYPES(32);
    __AGILIB_INTEGER_TEMPLATE_TYPES(64);

#undef __AGILIB_INTEGER_TEMPLATE_TYPES
  }

  template<int bits, bool sign>
  using Integer = typename Private::Integer<bits, sign>::Type;

  template<int bits>
  using SignedInteger = Integer<bits, true>;

  template<int bits>
  using UnsignedInteger = Integer<bits, false>;
}

#endif//__AGILIB_BASE_INTEGER__
