/*
 * Copyright 2017 - 2018 The WizTK Authors.
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

#ifndef WIZTK_SYSTEM_LOGGING_LOGGER_HPP_
#define WIZTK_SYSTEM_LOGGING_LOGGER_HPP_

namespace wiztk {
namespace system {
namespace logging {

/**
 * @ingroup system_logging
 * @brief Logger object.
 */
class Logger {

 public:

  Logger() = default;

  ~Logger() = default;

  /**
   * @brief Send a message to the system log daemon.
   * @param level
   * @param format
   * @param ...
   */
  static void LogToSystem(int level, const char *format, ...);

 private:

};

}
}
}

#endif // WIZTK_SYSTEM_LOGGING_LOGGER_HPP_
