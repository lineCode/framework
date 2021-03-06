/*
 * Copyright 2016 Freeman Zhang <zhanggyb@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WIZTK_GUI_INTERNAL_ABSTRACT_RENDERING_API_PRIVATE_HPP_
#define WIZTK_GUI_INTERNAL_ABSTRACT_RENDERING_API_PRIVATE_HPP_

#include "wiztk/gui/abstract-rendering-api.hpp"

#include "view-surface_private.hpp"

namespace wiztk {
namespace gui {

/**
 * @brief Structure for private data in AbstractGPUInterface
 */
struct AbstractRenderingAPI::Private {

  WIZTK_DECLARE_NONCOPYABLE_AND_NONMOVALE(Private);

  Private() = default;

  ~Private() = default;

  ViewSurface *surface = nullptr;

};

} // namespace gui
} // namespace wiztk

#endif // WIZTK_GUI_INTERNAL_ABSTRACT_GR_API_PRIVATE_HPP_
