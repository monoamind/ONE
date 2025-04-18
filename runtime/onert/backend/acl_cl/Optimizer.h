/*
 * Copyright (c) 2020 Samsung Electronics Co., Ltd. All Rights Reserved
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

#ifndef __ONERT_BACKEND_ACL_CL_OPTIMIZER_H__
#define __ONERT_BACKEND_ACL_CL_OPTIMIZER_H__

#include "BackendContext.h"
#include "TensorBuilder.h"

namespace onert::backend::acl_cl
{

class Optimizer
{
public:
  Optimizer(BackendContext *context);

  void optimize();

private:
  BackendContext *_context;
  std::shared_ptr<TensorBuilder> _tensor_builder;
};

} // namespace onert::backend::acl_cl

#endif // __ONERT_BACKEND_ACL_CL_OPTIMIZER_H__
