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


#ifndef CONTROL_CORE_MOMENT_H
#define CONTROL_CORE_MOMENT_H

#include <control_core/utilities/type_guard.h>
#include <control_core/type_bases/moment_base.h>

namespace control_core
{
/*!
 * \brief The Moment class.
 *
 * The Moment is of type Eigen::Vector3 and is
 * represented by the math symbol \f$\mathbf{\mu}\f$.
 *
 */
template <typename _Scalar>
class Moment :
    public Eigen::Matrix<_Scalar,3,1>,
    public MomentBase<Moment<_Scalar> >,
    TypeGuard
{
  //OW_TYPE_GUARD(Moment)

public:
  typedef _Scalar Scalar;
  typedef Eigen::Matrix<_Scalar,3,1> Base;
  typedef MomentBase<Moment<_Scalar> > MBase;

protected:

public:
  /*!
   * \brief Default Constructor.
   */
  Moment()
  {
  }

  /*!
   * \brief Copy constructor.
   */
  Moment(const Moment& other) :
    Base(other)
  {
  }

  /*!
   * \brief Assignment from Scalar values
   *
   */
  Moment(const Scalar& x, const Scalar& y, const Scalar& z) :
    Base(x,y,z)
  {
  }

  /*!
   *  \brief Copy constructor.
   *
   * This copy constructor not only works with Eigen matrices
   * but also with their expressions.
   */
  template <typename OtherDerived>
  Moment(const Eigen::EigenBase<OtherDerived>& other) :
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
  Moment(const MomentRef<OtherDerived>& other) :
    Base(other)
  {
  }


  /*!
   * \brief Use assignment operators of base class.
   */
  using Base::operator=;
  using MBase::operator=;


  /*!
   * \brief Assignment operator.
   */
  Moment& operator=(const Moment& other)
  {
    Base::operator=(other);
    return *this;
  }


  /*!
   * \brief Assignment operator.
   */
  template<typename OtherDerived>
  Moment& operator=(const MomentRef<OtherDerived>& other)
  {
    Base::operator=(other);
    return *this;
  }

};

}  // namespace control_core

#endif  // CONTROL_CORE_MOMENT_H
