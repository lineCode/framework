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

#ifndef WIZTK_GUI_MAIN_LOOP_HPP_
#define WIZTK_GUI_MAIN_LOOP_HPP_

#include "wiztk/async/event-loop.hpp"

#include <memory>

#include <wayland-client.h>

namespace wiztk {
namespace gui {

// Forward declaration:
class Display;

/**
 * @ingroup gui
 * @brief The event loop used in the main thread.
 */
class MainLoop final : public async::EventLoop {

  friend class Application;

 public:

  /**
   * @brief Initialize a singleton main loop.
   * @return
   */
  static MainLoop *Initialize(const Display *display);

  ~MainLoop() final;

 protected:

  MainLoop();

  void Dispatch() final;

 private:

  class SignalEvent : public async::AbstractEvent {

    friend class MainLoop;

   public:

    explicit SignalEvent(MainLoop *main_loop);

    ~SignalEvent() final;

   protected:

    void Run(uint32_t events) final;

   private:

    int signal_fd_ = -1;

    MainLoop *main_loop_ = nullptr;

  };

  class WaylandEvent : public async::AbstractEvent {

    friend class MainLoop;

   public:

    explicit WaylandEvent(MainLoop *main_loop);

    ~WaylandEvent() final;

   protected:

    void Run(uint32_t events) final;

   private:

    MainLoop *main_loop_ = nullptr;

  };

  struct wl_display *wl_display_ = nullptr;

  SignalEvent signal_event_;

  WaylandEvent wayland_event_;

};

} // namespace gui
} // namespace wiztk

#endif // WIZTK_GUI_MAIN_LOOP_HPP_
