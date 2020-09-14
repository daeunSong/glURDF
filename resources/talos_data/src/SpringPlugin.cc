/*
 * Copyright 2011 Nate Koenig & Andrew Howard
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

#include "SpringPlugin.hh"


using namespace gazebo;

GZ_REGISTER_MODEL_PLUGIN(SpringPlugin)

/////////////////////////////////////////////////
SpringPlugin::SpringPlugin() {}

/////////////////////////////////////////////////
void SpringPlugin::Load(physics::ModelPtr lmodel,
                           sdf::ElementPtr lsdf)
{
  model_ = lmodel;

  // hardcoded params for this test
  if (!lsdf->HasElement("joint_spring"))
    ROS_ERROR_NAMED("SpringPlugin", "No field joint_spring for SpringPlugin");
  else
    jointExplicitName_ = lsdf->Get<std::string>("joint_spring");

  kpExplicit_ = lsdf->Get<double>("kp");

  kdExplicit_ = lsdf->Get<double>("kd");

  axisExplicit_ = lsdf->Get<int>("axis");

  ROS_INFO_NAMED("SpringPlugin",
                 "Loading joint : %s kp: %f kd: %f alongs %d axis",
                 jointExplicitName_.c_str(),
                 kpExplicit_,
                 kdExplicit_,
                 axisExplicit_);
}

/////////////////////////////////////////////////
void SpringPlugin::Init()
{
  jointExplicit_ = model_->GetJoint(jointExplicitName_);

  /*  jointImplicit->SetStiffnessDamping(0, kpImplicit,
      kdImplicit); */

  updateConnection_ = event::Events::ConnectWorldUpdateBegin(
          boost::bind(&SpringPlugin::ExplicitUpdate, this));
}

/////////////////////////////////////////////////
void SpringPlugin::ExplicitUpdate() {
#if GAZEBO_MAJOR_VERSION < 9
  common::Time currTime = model_->GetWorld()->GetSimTime();
#else
  common::Time currTime = model_->GetWorld()->SimTime();
#endif

  common::Time stepTime = currTime - prevUpdateTime_;
  prevUpdateTime_ = currTime;

#if GAZEBO_MAJOR_VERSION < 9
  double pos = jointExplicit_->GetAngle(axisExplicit_).Radian();
#else
  double pos = jointExplicit_->Position(axisExplicit_);
#endif
  double vel = jointExplicit_->GetVelocity(axisExplicit_);
  double force = -kpExplicit_ * pos
                 -kdExplicit_ * vel;
  jointExplicit_->SetForce(axisExplicit_, force);
}
