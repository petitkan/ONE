/*
 * Copyright (c) 2021 Samsung Electronics Co., Ltd. All Rights Reserved
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

#include "CircleCloneNode.h"

namespace luci
{

luci::CircleNode *CloneNodeLet<CN::KLMN>::visit(const luci::CircleMaxPool2D *node)
{
  if (node->fusedActivationFunction() == luci::FusedActFunc::UNDEFINED)
    return nullptr;
  if (node->padding() == luci::Padding::UNDEFINED)
    return nullptr;

  auto *cloned = _graph->nodes()->create<luci::CircleMaxPool2D>();
  {
    cloned->fusedActivationFunction(node->fusedActivationFunction());
    cloned->padding(node->padding());
    cloned->filter()->h(node->filter()->h());
    cloned->filter()->w(node->filter()->w());
    cloned->stride()->h(node->stride()->h());
    cloned->stride()->w(node->stride()->w());
  }
  return cloned;
}

} // namespace luci
