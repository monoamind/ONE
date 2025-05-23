/*
 * Copyright (c) 2023 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __ONERT_EXEC_TRAIN_IGRADIENT_APPLIER_H__
#define __ONERT_EXEC_TRAIN_IGRADIENT_APPLIER_H__

#include <cstdint>

namespace onert::exec::train
{

class IGradientApplier
{
public:
  virtual ~IGradientApplier() = default;

  /**
   * @brief Apply gradients to a trainable tensor
   *
   * @param training_step The number of iterations of the training process.
   */
  virtual void applyGradient(uint32_t training_step) = 0;
};

} // namespace onert::exec::train

#endif // __ONERT_EXEC_TRAIN_IGRADIENT_APPLIER_H__
