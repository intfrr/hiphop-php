/*
   +----------------------------------------------------------------------+
   | HipHop for PHP                                                       |
   +----------------------------------------------------------------------+
   | Copyright (c) 2010-2013 Facebook, Inc. (http://www.facebook.com)     |
   | Copyright (c) 1997-2010 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
*/

#ifndef incl_HPHP_EXT_ZLIB_H_
#define incl_HPHP_EXT_ZLIB_H_

#include "hphp/runtime/base/base-includes.h"
#include "hphp/runtime/ext/ext_file.h"

namespace HPHP {
///////////////////////////////////////////////////////////////////////////////
// zlib functions

Variant f_readgzfile(CStrRef filename, bool use_include_path = false);
Variant f_gzfile(CStrRef filename, bool use_include_path = false);
Variant f_gzcompress(CStrRef data, int level = -1);
Variant f_gzuncompress(CStrRef data, int limit = 0);
Variant f_gzdeflate(CStrRef data, int level = -1);
Variant f_gzinflate(CStrRef data, int limit = 0);
Variant f_gzencode(CStrRef data, int level = -1,
                   int encoding_mode = k_FORCE_GZIP);
Variant f_gzdecode(CStrRef data);
String f_zlib_get_coding_type();
Variant f_qlzcompress(CStrRef data, int level = 1);
Variant f_qlzuncompress(CStrRef data, int level = 1);
Variant f_sncompress(CStrRef data);
Variant f_snuncompress(CStrRef data);
Variant f_nzcompress(CStrRef uncompressed);
Variant f_nzuncompress(CStrRef compressed);
Variant f_lz4compress(CStrRef uncompressed);
Variant f_lz4hccompress(CStrRef uncompressed);
Variant f_lz4uncompress(CStrRef compressed);

///////////////////////////////////////////////////////////////////////////////
// stream functions

Resource f_gzopen(CStrRef filename, CStrRef mode,
                  bool use_include_path = false);

bool f_gzclose(CResRef zp);
Variant f_gzread(CResRef zp, int64_t length = 0);
Variant f_gzseek(CResRef zp, int64_t offset, int64_t whence = k_SEEK_SET);
Variant f_gztell(CResRef zp);
bool f_gzeof(CResRef zp);
bool f_gzrewind(CResRef zp);
Variant f_gzgetc(CResRef zp);
Variant f_gzgets(CResRef zp, int64_t length = 1024);
Variant f_gzgetss(CResRef zp, int64_t length = 0,
                  CStrRef allowable_tags = null_string);
Variant f_gzpassthru(CResRef zp);
Variant f_gzputs(CResRef zp, CStrRef str, int64_t length = 0);
Variant f_gzwrite(CResRef zp, CStrRef str, int64_t length = 0);

///////////////////////////////////////////////////////////////////////////////
}

#endif // incl_HPHP_EXT_ZLIB_H_
