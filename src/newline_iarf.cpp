/**
 * @file newline_iarf.cpp
 *
 * @author  Ben Gardner
 * @author  Guy Maurel
 * extract from newlines.cpp
 * @license GPL v2+
 */

#include "newline_iarf.h"

#include "newline_add.h"
#include "newline_del_between.h"
#include "newlines_between.h"
#include "prototypes.h"


constexpr static auto LCURRENT = LNEWLINE;


using namespace uncrustify;


void newline_iarf(Chunk *pc, iarf_e av)
{
   LOG_FUNC_ENTRY();

   LOG_FMT(LNFD, "%s(%d): ", __func__, __LINE__);
   log_func_stack(LNFD, "CallStack:");
   Chunk *after = Chunk::NullChunkPtr;

   if (pc != nullptr)
   {
      after = pc->GetNextNnl();
   }

   if (  (pc != nullptr && pc->Is(CT_FPAREN_OPEN))                         // Issue #2914
      && pc->GetParentType() == CT_FUNC_CALL
      && after->Is(CT_COMMENT_CPP)
      && options::donot_add_nl_before_cpp_comment())
   {
      return;
   }
   newline_iarf_pair(pc, after, av);
} // newline_iarf


void newline_iarf_pair(Chunk *before, Chunk *after, iarf_e av, bool check_nl_assign_leave_one_liners)
{
   LOG_FUNC_ENTRY();

   LOG_FMT(LNEWLINE, "%s(%d): ", __func__, __LINE__);
   log_func_stack(LNEWLINE, "CallStack:");

   if (  before == nullptr
      || before == Chunk::NullChunkPtr
      || after == nullptr
      || after == Chunk::NullChunkPtr
      || after->Is(CT_IGNORED))
   {
      return;
   }

   if (av & IARF_ADD)
   {
      if (  check_nl_assign_leave_one_liners
         && options::nl_assign_leave_one_liners()
         && after->TestFlags(PCF_ONE_LINER))
      {
         log_rule_B("nl_assign_leave_one_liners");
         return;
      }
      Chunk *nl = newline_add_between(before, after);
      LOG_FMT(LNEWLINE, "%s(%d): newline_add_between '%s' and '%s'\n",
              __func__, __LINE__, before->Text(), after->Text());

      if (  nl != nullptr
         && av == IARF_FORCE
         && nl->GetNlCount() > 1)
      {
         nl->SetNlCount(1);
      }
   }
   else if (av & IARF_REMOVE)
   {
      LOG_FMT(LNEWLINE, "%s(%d): newline_remove_between '%s' and '%s'\n",
              __func__, __LINE__, before->Text(), after->Text());
      newline_del_between(before, after);
   }
} // newline_iarf_pair
