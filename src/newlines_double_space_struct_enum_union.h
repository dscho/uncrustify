/**
 * @file newlines_double_space_struct_enum_union.h
 * prototype for newlines_double_space_struct_enum_union.cpp
 *
 * @author  Ben Gardner
 * @author  Guy Maurel
 * extract from newlines.cpp
 * @license GPL v2+
 */
#ifndef NEWLINES_DOUBLE_SPACE_STRUCT_ENUM_UNION_H_INCLUDED
#define NEWLINES_DOUBLE_SPACE_STRUCT_ENUM_UNION_H_INCLUDED


#include "chunk.h"


//! Make sure there is a blank line after a commented group of values
void newlines_double_space_struct_enum_union(Chunk *open_brace);


#endif /* NEWLINES_DOUBLE_SPACE_STRUCT_ENUM_UNION_H_INCLUDED */
