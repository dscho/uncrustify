/**
 * @file newlines_func_pre_blank_lines.h
 * prototype for newlines_func_pre_blank_lines.cpp
 *
 * @author  Ben Gardner
 * @author  Guy Maurel
 * extract from newlines.cpp
 * @license GPL v2+
 */
#ifndef NEWLINES_FUNC_PRE_BLANK_LINES_H_INCLUDED
#define NEWLINES_FUNC_PRE_BLANK_LINES_H_INCLUDED

#include "chunk.h"

/**
 * Add one/two newline(s) before the chunk.
 * Adds before comments
 * Adds before destructor
 * Doesn't do anything if open brace before it
 * "code\n\ncomment\nif (...)" or "code\ncomment\nif (...)"
 */
void newlines_func_pre_blank_lines(Chunk *start, E_Token start_type);

#endif /* NEWLINES_FUNC_PRE_BLANK_LINES_H_INCLUDED */
