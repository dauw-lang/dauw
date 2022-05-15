#pragma once

#include <dauw/common.hpp>
#include <dauw/ast/ast.hpp>


namespace dauw
{
  // Class that defines the interpreter
  class Interpreter : public ExprVisitor, public std::enable_shared_from_this<Interpreter>
  {
    private:
      int depth = 0;


    public:
      void print_depth();
      void print(const expr_ptr& expr);

      // Visitor implementation
      virtual void visit_literal(const expr_literal_ptr& expr) override;
      virtual void visit_sequence(const expr_sequence_ptr& expr) override;
      virtual void visit_record(const expr_record_ptr& expr) override;
      virtual void visit_name(const expr_name_ptr& expr) override;
      virtual void visit_function(const expr_function_ptr& expr) override;
      virtual void visit_grouped(const expr_grouped_ptr& expr) override;
      virtual void visit_call(const expr_call_ptr& expr) override;
      virtual void visit_get(const expr_get_ptr& expr) override;
      virtual void visit_unary(const expr_unary_ptr& expr) override;
      virtual void visit_binary(const expr_binary_ptr& expr) override;
      virtual void visit_if(const expr_if_ptr& expr) override;
      virtual void visit_for(const expr_for_ptr& expr) override;
      virtual void visit_while(const expr_while_ptr& expr) override;
      virtual void visit_until(const expr_until_ptr& expr) override;
      virtual void visit_block(const expr_block_ptr& expr) override;
      virtual void visit_def(const expr_def_ptr& expr) override;
  };
}
