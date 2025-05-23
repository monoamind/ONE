/*
 * Copyright (c) 2018 Samsung Electronics Co., Ltd. All Rights Reserved
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ONERT_EXEC_FEATURE_NCHW_VIEW_H__
#define __ONERT_EXEC_FEATURE_NCHW_VIEW_H__

#include "Reader.h"

#include "backend/ITensor.h"
#include "ir/Shape.h"
#include "util/logging.h"

#include <cassert>

namespace onert::exec::feature::nchw
{

template <typename T> class View final : public Reader<T>
{
public:
  using Strides = typename Reader<T>::Strides;
  // Construct for buffer of model inputs
  View(const ir::FeatureShape &shape, const Strides &strides, T *ptr, size_t len)
    : Reader<T>{shape, strides, ptr, len}
  {
    // DO NOTHING
  }

  // Construct for backend tensor
  View(::onert::backend::ITensor *tensor) : Reader<T>{tensor}
  {
    // DO NOTHING
  }

public:
  using Reader<T>::at;
  T &at(uint32_t batch, uint32_t ch, uint32_t row, uint32_t col)
  {
    return const_cast<T &>(Reader<T>::getRef(batch, ch, row, col));
  }
  T &at(uint32_t ch, uint32_t row, uint32_t col)
  {
    return const_cast<T &>(Reader<T>::getRef(0, ch, row, col));
  }
};

} // namespace onert::exec::feature::nchw

#endif // __ONERT_EXEC_FEATURE_NCHW_VIEW_H__
