/* Copyright 2017-2018 PaGMO development team

This file is part of the PaGMO library.

The PaGMO library is free software; you can redistribute it and/or modify
it under the terms of either:

  * the GNU Lesser General Public License as published by the Free
    Software Foundation; either version 3 of the License, or (at your
    option) any later version.

or

  * the GNU General Public License as published by the Free Software
    Foundation; either version 3 of the License, or (at your option) any
    later version.

or both in parallel, as here.

The PaGMO library is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
for more details.

You should have received copies of the GNU General Public License and the
GNU Lesser General Public License along with the PaGMO library.  If not,
see https://www.gnu.org/licenses/. */

#ifndef PAGMO_PROBLEM_CEC2013_HPP
#define PAGMO_PROBLEM_CEC2013_HPP

#include <pagmo/config.hpp>

#if !defined(PAGMO_ENABLE_CEC2013)

#error The cec2013.hpp header was included but the CEC 2013 problem is not supported on the current platform.

#endif

#include <string>
#include <utility>
#include <vector>

#include <pagmo/detail/visibility.hpp>
#include <pagmo/problem.hpp>
#include <pagmo/types.hpp>

namespace pagmo
{
/// The CEC 2013 problems: Real-Parameter Single Objective Optimization Competition
/**
 *
 * \image html cec2013.png
 *
 * The 28 problems of the competition on real-parameter single objective optimization problems that
 * was organized for the 2013 IEEE Congress on Evolutionary Computation.
 *
 * \verbatim embed:rst:leading-asterisk
 * .. note::
 *
 *    The code for these UDAs is adapted from the original C code distributed during the competition and
 *    linked below.
 *
 * .. note::
 *
 *    All problems are box-bounded, continuous, single objective problems.
 *
 * .. seealso:
 *
 *    http://www.ntu.edu.sg/home/EPNSugan/index_files/CEC2013/CEC2013.htm
 *    http://web.mysites.ntu.edu.sg/epnsugan/PublicSite/Shared%20Documents/CEC2013/cec13-c-code.zip
 *
 * \endverbatim
 */
class PAGMO_PUBLIC cec2013
{
public:
    /// Constructor
    /**
     * Will construct one of the 28 CEC2013 problems
     *
     * @param prob_id The problem id. One of [1,2,...,28]
     * @param dim problem dimension. One of [2,5,10,20,30,...,100]
     *
     * @throws invalid_argument if \p prob_id is not in [1,18] or if \p dim is not one of
     * [2,5,10,20,30,40,50,60,70,80,90,100]
     */
    cec2013(unsigned int prob_id = 1u, unsigned int dim = 2u);
    // Fitness computation
    vector_double fitness(const vector_double &) const;
    // Box-bounds
    std::pair<vector_double, vector_double> get_bounds() const;
    // Problem name
    std::string get_name() const;
    // Object serialization
    template <typename Archive>
    void serialize(Archive &, unsigned);

private:
    void sphere_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                     int r_flag) const; /* Sphere */
    void ellips_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                     int r_flag) const; /* Ellipsoidal */
    void bent_cigar_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                         int r_flag) const; /* Bent_Cigar */
    void discus_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                     int r_flag) const; /* Discus */
    void dif_powers_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                         int r_flag) const; /* Different Powers */
    void rosenbrock_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                         int r_flag) const; /* Rosenbrock's */
    void schaffer_F7_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                          int r_flag) const; /* Schwefel's 1.2  */
    void ackley_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                     int r_flag) const; /* Ackley's  */
    void weierstrass_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                          int r_flag) const; /* Weierstrass's  */
    void griewank_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                       int r_flag) const; /* Griewank's  */
    void rastrigin_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                        int r_flag) const; /* Rastrigin's  */
    void step_rastrigin_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                             int r_flag) const; /* Noncontinuous Rastrigin's  */
    void schwefel_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                       int r_flag) const; /* Schwefel's  */
    void katsuura_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                       int r_flag) const; /* Katsuura  */
    void bi_rastrigin_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                           int r_flag) const; /* Lunacek Bi_rastrigin Function */
    void grie_rosen_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                         int r_flag) const; /* Griewank-Rosenbrock  */
    void escaffer6_func(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
                        int r_flag) const; /* Expanded Scaffer¡¯s F6  */
    void cf01(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 1 */
    void cf02(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 2 */
    void cf03(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 3 */
    void cf04(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 4 */
    void cf05(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 4 */
    void cf06(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 6 */
    void cf07(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 7 */
    void cf08(const double *x, double *f, const unsigned int nx, const double *Os, const double *Mr,
              int r_flag) const; /* Composition Function 8 */
    void shiftfunc(const double *x, double *xshift, const unsigned int nx, const double *Os) const;
    void rotatefunc(const double *x, double *xrot, const unsigned int nx, const double *Mr) const;
    void asyfunc(const double *x, double *xasy, const unsigned int nx, double beta) const;
    void oszfunc(const double *x, double *xosz, const unsigned int nx) const;
    void cf_cal(const double *x, double *f, const unsigned int nx, const double *Os, double *delta, double *bias,
                double *fit, unsigned int cf_num) const;

    // problem id
    unsigned int m_prob_id;
    // problem data
    std::vector<double> m_rotation_matrix;
    std::vector<double> m_origin_shift;

    // pre-allocated stuff for speed
    mutable std::vector<double> m_y;
    mutable std::vector<double> m_z;
};

} // namespace pagmo

PAGMO_S11N_PROBLEM_EXPORT_KEY(pagmo::cec2013)

#endif
