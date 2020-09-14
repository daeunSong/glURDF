/*
 * Copyright (C) 2012 Open Source Robotics Foundation
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */
#ifndef __GAZEBO_SPRING_TEST_PLUGIN_HH__
#define __GAZEBO_SPRING_TEST_PLUGIN_HH__

#include <string>
#pragma GCC diagnostic push
#pragma GCC system_header

#include "gazebo/common/Plugin.hh"
#include "gazebo/physics/physics.hh"
#include "gazebo/util/system.hh"
#include <ros/ros.h>

#pragma GCC diagnostic pop

namespace gazebo
{
class GAZEBO_VISIBLE SpringPlugin : public ModelPlugin
{
public: SpringPlugin();
public: virtual void Load(physics::ModelPtr _model, sdf::ElementPtr _sdf);
public: virtual void Init();

private: void ExplicitUpdate();

private: event::ConnectionPtr updateConnection_;

private: physics::ModelPtr model_;

private: common::Time prevUpdateTime_;

private: physics::JointPtr jointExplicit_;
private: std::string jointExplicitName_;

  /// \brief simulate spring/damper with ExplicitUpdate function
private: double kpExplicit_;

  /// \brief simulate spring/damper with ExplicitUpdate function
private: double kdExplicit_;
    
  /// \brief Specify on which axis the spring is applied.
private: int axisExplicit_;
};
}
#endif
