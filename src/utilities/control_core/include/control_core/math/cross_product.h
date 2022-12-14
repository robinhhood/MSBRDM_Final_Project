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

#ifndef CONTROL_CORE_MATH_CROSS_PRODUCT_H
#define CONTROL_CORE_MATH_CROSS_PRODUCT_H

#include <control_core/types.h>

// the namespace for the project
namespace cc
{

  /*!
  * \brief Maps an elements from cartesian vector space R^3 into an element of
  * the lie algebra of of SO(3).
  */
  template <typename Derived>
  inline Eigen::Matrix<typename Derived::Scalar,3,3>
    hat(const Eigen::MatrixBase<Derived> &v)
  {
    Matrix3 ret;
    ret << 0.0, -v(2), v(1), v(2), 0.0, -v(0), -v(1), v(0), 0.0;
    return ret;
  }

} // namespace cc

#endif