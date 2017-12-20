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

#ifndef WIZTK_GUI_ABSTRACT_EVENT_HANDLER_HPP_
#define WIZTK_GUI_ABSTRACT_EVENT_HANDLER_HPP_

#include "wiztk/base/sigcxx.hpp"
#include "wiztk/base/string.hpp"

#include "wiztk/gui/event-node.hpp"

#include <memory>

namespace wiztk {
namespace gui {

class MouseEvent;
class KeyEvent;

class ViewSurface;
class AbstractView;
class Output;

/**
 * @ingroup gui
 * @brief The base class to handle events and interact with surface
 *
 * AbstractEventHandler is the base class for most classes in GUI
 * module, it handles input events from input manager and interact with
 * the surface it hold.
 *
 * There're 2 important sub class:
 * 
 * - AbstractShellView: this is the base class for windows/menus/popups, 
 *   which have own shell surface.
 * - AbstractView: this is the base class for views layouted and show in
 *   a shell view.
 *
 * @see Input
 * @see Surface
 */
class WIZTK_EXPORT AbstractEventHandler : public base::Trackable {

  friend class Input;
  friend class Display;
  friend class ViewSurface;

  friend class AbstractView;
  friend class AbstractShellView;

 public:

  using String = base::String;
  template<typename ... Args> using SignalRef = typename base::SignalRef<Args...>;
  template<typename ... Args> using Signal = typename base::Signal<Args...>;

  WIZTK_DECLARE_NONCOPYABLE(AbstractEventHandler);

  /**
   * @brief Nested class represents an mouse event node.
   */
  class MouseEventNode : public EventNode<MouseEventNode> {

   public:

    WIZTK_DECLARE_NONCOPYABLE_AND_NONMOVALE(MouseEventNode);
    MouseEventNode() = delete;

    /**
     * @brief Constructor
     * @param event_handler An AbstractEventHandler object
     *
     * @note The parameter cannot be nullptr.
     */
    explicit MouseEventNode(AbstractEventHandler *event_handler)
        : EventNode<MouseEventNode>(), event_handler_(event_handler) {}

    /**
     * @brief Destructor
     */
    ~MouseEventNode() override = default;

    inline AbstractEventHandler *event_handler() const { return event_handler_; }

    static MouseEventNode *Get(const AbstractEventHandler *event_hander);

   private:

    AbstractEventHandler *event_handler_;

  };

  /**
    * @brief Nested class represents an mouse motion event node.
    */
  class MouseMotionEventNode : public EventNode<MouseMotionEventNode> {

   public:

    WIZTK_DECLARE_NONCOPYABLE_AND_NONMOVALE(MouseMotionEventNode);
    MouseMotionEventNode() = delete;

    /**
     * @brief Constructor
     * @param event_handler An AbstractEventHandler object
     *
     * @note The parameter cannot be nullptr.
     */
    explicit MouseMotionEventNode(AbstractEventHandler *event_handler)
        : EventNode<MouseMotionEventNode>(), event_handler_(event_handler) {}

    /**
     * @brief Destructor
     */
    ~MouseMotionEventNode() override = default;

    inline AbstractEventHandler *event_handler() const { return event_handler_; }

    static MouseMotionEventNode *Get(const AbstractEventHandler *event_handler);

   private:

    AbstractEventHandler *event_handler_;

  };

  /**
   * @brief Default constructor
   */
  AbstractEventHandler();

  /**
   * @brief Destructor
   */
  ~AbstractEventHandler() override;

  const String &GetName() const;

  void SetName(const String &name);

 protected:

  /**
   * @brief Virtual callback when mouse device enter this object
   */
  virtual void OnMouseEnter(MouseEvent *event) = 0;

  /**
   * @brief Virtual callback when mouse device leave this object
   */
  virtual void OnMouseLeave() = 0;

  /**
   * @brief Virtual callback when mouse moving on this object
   */
  virtual void OnMouseMove(MouseEvent *event) = 0;

  /**
   * @brief Virtual callback when mouse button pressed on this object
   */
  virtual void OnMouseDown(MouseEvent *event) = 0;

  /**
   * @brief Virtual callback when mouse button released on this object
   * @param event
   */
  virtual void OnMouseUp(MouseEvent *event) = 0;

  /**
   * @brief Virtual callback when a keyboard key is prssed down on this object
   */
  virtual void OnKeyDown(KeyEvent *event) = 0;

  /**
   * @brief Virtual callback when a keyboard key is released on this object
   * @param event
   */
  virtual void OnKeyUp(KeyEvent *event) = 0;

  virtual void OnRequestSaveGeometry(AbstractView *view) = 0;

  /**
   * @brief A view request an update
   * @param view A view in hierarchy wants to update this object
   */
  virtual void OnRequestUpdateFrom(AbstractView *view) = 0;

  virtual void OnRenderSurface(ViewSurface *surface) = 0;

  virtual void OnEnterOutput(const ViewSurface *surface, const Output *output) = 0;

  virtual void OnLeaveOutput(const ViewSurface *surface, const Output *output) = 0;

  /**
   * @brief Disable this virtual method
   * @param token
   */
  void AuditDestroyingToken(base::internal::Token */*token*/) final;

 private:

  struct Private;

  std::unique_ptr<Private> p_;

};

} // namespace gui
} // namespace wiztk

#endif // WIZTK_GUI_ABSTRACT_EVENT_HANDLER_HPP_
