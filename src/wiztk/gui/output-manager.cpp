/*
 * Copyright 2017 The WizTK Authors.
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

#include "wiztk/gui/output-manager.hpp"

#include "output_private.hpp"

namespace wiztk {
namespace gui {

OutputManager::~OutputManager() {
  Clear();
}

void OutputManager::AddOutput(Output *output) {
  auto *node = output->p_.get();
  deque_.push_front(node);
}

Output *OutputManager::GetActiveOutput() const {
  return deque_.count() > 0 ? deque_[0]->proprietor : nullptr;
}

void OutputManager::Clear() {
  deque_.clear([](base::CountedDequeNodeBase *obj) {
    auto *node = static_cast<Output::Private *>(obj);
    Output *output = node->proprietor;
    delete output;
  });
}

Output *OutputManager::FindByID(uint32_t id) const {
  Output *output = nullptr;

  for (OutputPrivateDeque::Iterator it = deque_.begin(); it != deque_.end(); ++it) {
    if (it->proprietor->GetID() == id) {
      output = it->proprietor;
      break;
    }
  }

  return output;
}

}
}
