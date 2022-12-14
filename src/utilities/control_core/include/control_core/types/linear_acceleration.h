/*! \file
 *
 * \author Simon Armleder
 *
 * \copyright Copyright 2020 Institute for Cognitive Systems (ICS),
 *    Technical University of Munich (TUM)
 *
 * #### Licence
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *   http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */


#ifndef CONTROL_CORE_LINEAR_ACCELERATION_H
#define CONTROL_CORE_LINEAR_ACCELERATION_H

#include <control_core/utilities/type_guard.h>
#include <control_core/type_bases/linear_acceleration_base.h>

namespace control_core
{
/*!
 * \brief The LinearAcceleration class.
 *
 * The LinearAcceleration is of type Eigen::Vector3 and is
 * represented by the math symbol \f$\ddot{\mathbf{x}}\f$.
 *
 */
template <typename _Scalar>
class LinearAcceleration :
    public Eigen::Matrix<_Scalar,3,1>,
    public LinearAccelerationBase<LinearAcceleration<_Scalar> >,
    TypeGuard
{
  //OW_TYPE_GUARD(LinearAcceleration)

public:
  typedef _Scalar Scalar;
  typedef Eigen::Matrix<_Scalar,3,1> Base;
  typedef LinearAccelerationBase<LinearAcceleration<_Scalar> > LABase;

protected:

public:
  /*!
   * \brief Default Constructor.
   */
  LinearAcceleration()
  {
  }

  /*!
   * \brief Copy constructor.
   */
  LinearAcceleration(const LinearAcceleration& other) :
    Base(other)
  {
  }

  /*!
   * \brief Assignment from Scalar values
   *
   */
  LinearAcceleration(const Scalar& xPP, const Scalar& yPP, const Scalar& zPP) :
    Base(xPP,yPP,zPP)
  {
  }

  /*!
   * \brief Copy constructor.
   *
   * This copy constructor not only works with Eigen matrices
   * but also with their expressions.
   */
  template <typename OtherDerived>
  LinearAcceleration(const Eigen::EigenBase<OtherDerived>& other) :
    Base(other)
  {
  }

  /*!
   * \brief Copy constructor.
   *
   * This copy constructor allows construction from
   * the reference class.
   */
  template <typename OtherDerived>
  LinearAcceleration(const LinearAccelerationRef<OtherDerived>& other) :
    Base(other)
  {
  }


  /*!
   * \brief Use assignment operators of base class.
   */
  using Base::operator=;
  using LABase::operator=;

  /*!
   * \brief Copy constructor.
   */
  LinearAcceleration& operator=(const LinearAcceleration& other)
  {
    Base::operator=(other);
    return *this;
  }

  /*!
   * \brief Assignment operator.
   */
  template<typename OtherDerived>
  LinearAcceleration& operator=(
      const LinearAccelerationRef<OtherDerived>& other)
  {
    Base::operator=(other);
    return *this;
  }

};

}  // namespace control_core

#endif  // CONTROL_CORE_LINEAR_ACCELERATION_H
