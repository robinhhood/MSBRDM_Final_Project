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


#ifndef CONTROL_CORE_EIGEN_TYPEDEF_MACROS_H
#define CONTROL_CORE_EIGEN_TYPEDEF_MACROS_H


/*! \file eigen_typedef_macros.h
 * \brief Contains macros for creating vector and matrix typedefs.
 *
 * These macros are inspired by the macros of the Eigen library.
 */

#include <Eigen/Dense>

/*! \def CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, Size, SizeSuffix)
 * \brief Create the typedefs for vectors, row vectors, matrices.
 *
 * E.g. Vector3ui, Matrix3ui, RowVector3ui.
 */
#define CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, Size, SizeSuffix) \
typedef Eigen::Matrix<Type, Size, Size> Matrix##SizeSuffix##TypeSuffix; \
typedef Eigen::Matrix<Type, Size, 1>    Vector##SizeSuffix##TypeSuffix; \
typedef Eigen::Matrix<Type, 1, Size>    RowVector##SizeSuffix##TypeSuffix;


/*! \def CONTROL_CORE_MAKE_FIXED_TYPEDEFS(Type, TypeSuffix, Size)
 * \brief Create the typedefs for dynamic size matrices with on fixed
 * dimensions.
 *
 * E.g. Matrix3Xui, MatrixX3ui
 */
#define CONTROL_CORE_MAKE_FIXED_TYPEDEFS(Type, TypeSuffix, Size) \
typedef Eigen::Matrix<Type, Size, Eigen::Dynamic> Matrix##Size##X##TypeSuffix; \
typedef Eigen::Matrix<Type, Eigen::Dynamic, Size> Matrix##X##Size##TypeSuffix;


/*! \def CONTROL_CORE_TYPEDEFS_ALL_SIZES(Type, TypeSuffix)
 * \brief Create the typedefs for vectors and matrices.
 *
 * Create the typedefs type \a Type and append the type suffix \a TypeSuffix
 * to the name.
 *
 * E.g. CONTROL_CORE_TYPEDEFS_ALL_SIZES(unsigned int,ui) will
 * create vectors and matrices such as Vector1ui, Matrix3ui, etc.
 */
#define CONTROL_CORE_TYPEDEFS_ALL_SIZES(Type, TypeSuffix) \
CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, 1, 1) \
CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, 2, 2) \
CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, 3, 3) \
CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, 4, 4) \
CONTROL_CORE_MAKE_TYPEDEFS(Type, TypeSuffix, Eigen::Dynamic, X) \
CONTROL_CORE_MAKE_FIXED_TYPEDEFS(Type, TypeSuffix, 2) \
CONTROL_CORE_MAKE_FIXED_TYPEDEFS(Type, TypeSuffix, 3) \
CONTROL_CORE_MAKE_FIXED_TYPEDEFS(Type, TypeSuffix, 4)


#endif // CONTROL_CORE_EIGEN_TYPEDEF_MACROS_H
