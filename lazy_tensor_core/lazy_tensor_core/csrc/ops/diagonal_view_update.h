#pragma once

#include "lazy_tensor_core/csrc/ts_backend/TsNode.h"

namespace torch_lazy_tensors {
namespace ir {
namespace ops {

class DiagonalViewUpdate : public TsNode {
 public:
  DiagonalViewUpdate(const torch::lazy::Value& target, const torch::lazy::Value& input,
                     lazy_tensors::int64 offset, lazy_tensors::int64 dim1,
                     lazy_tensors::int64 dim2);

  NodePtr Clone(OpList operands) const override;

  std::string ToString() const override;

  lazy_tensors::int64 offset() const { return offset_; }

  lazy_tensors::int64 dim1() const { return dim1_; }

  lazy_tensors::int64 dim2() const { return dim2_; }

 private:
  lazy_tensors::int64 offset_;
  lazy_tensors::int64 dim1_;
  lazy_tensors::int64 dim2_;
};

}  // namespace ops
}  // namespace ir
}  // namespace torch_lazy_tensors