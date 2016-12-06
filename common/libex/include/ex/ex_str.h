#ifndef __LIB_EX_STR_H__
#define __LIB_EX_STR_H__

#include "ex_types.h"

#define EX_CODEPAGE_ACP		0
#define EX_CODEPAGE_UTF8	1

#define EX_RSC_BEGIN	0x01
#define EX_RSC_END		0x02
#define EX_RSC_ALL		EX_RSC_BEGIN | EX_RSC_END

//=================================================
// C Interface
//=================================================

// copy a string from `source` to `target`.
// `size` is size of target buffer.
// if buffer is to small, NULL will return, but `size-1` characters have been copied.
char* ex_strcpy(char* target, size_t size, const char* source);
wchar_t* ex_wcscpy(wchar_t* target, size_t size, const wchar_t* source);


// dupilicate a string.
// must use ex_free() to release the returned value.
char* ex_strdup(const char* src);
wchar_t* ex_wcsdup(const wchar_t* src);

// convert between mutli-bytes and wide char string.
// must use ex_free() to release the returned value.
wchar_t* ex_str2wcs_alloc(const char* in_buffer, int code_page);
char* ex_wcs2str_alloc(const wchar_t* in_buffer, int code_page);

// convert char** argv to wchar_t** argv.
// must use ex_free_argv() to release the returned value.
wchar_t** ex_make_wargv(int argc, char** argv);
void ex_free_wargv(int argc, wchar_t** argv);

EX_BOOL ex_str_only_white_space(const wchar_t* src);
EX_BOOL ex_wcs_only_white_space(const char* src);

//=================================================
// C++ Interface
//=================================================
#ifdef __cplusplus

#include <string>
#include <vector>

typedef std::string ex_astr;
typedef std::wstring ex_wstr;

typedef std::vector<ex_astr> ex_astrs;
typedef std::vector<ex_wstr> ex_wstrs;

bool ex_wstr2astr(const ex_wstr& in_str, ex_astr& out_str, int code_page = EX_CODEPAGE_ACP);
bool ex_wstr2astr(const wchar_t* in_str, ex_astr& out_str, int code_page = EX_CODEPAGE_ACP);
bool ex_astr2wstr(const ex_astr& in_str, ex_wstr& out_str, int code_page = EX_CODEPAGE_ACP);
bool ex_astr2wstr(const char* in_str, ex_wstr& out_str, int code_page = EX_CODEPAGE_ACP);

bool ex_only_white_space(const ex_astr& str_check);
bool ex_only_white_space(const ex_wstr& str_check);

void ex_remove_white_space(ex_astr& str_fix, int ulFlag = EX_RSC_ALL);
void ex_remove_white_space(ex_wstr& str_fix, int ulFlag = EX_RSC_ALL);

ex_astr& ex_replace_all(ex_astr& str, const ex_astr& old_value, const ex_astr& new_value);
ex_wstr& ex_replace_all(ex_wstr& str, const ex_wstr& old_value, const ex_wstr& new_value);


#endif


#endif // __LIB_EX_STR_H__