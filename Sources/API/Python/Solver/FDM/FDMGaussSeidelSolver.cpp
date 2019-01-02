/*************************************************************************
> File Name: FDMGaussSeidelSolver.cpp
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: FDMGaussSeidelSolver functions for CubbyFlow Python API.
> Created Time: 2018/02/14
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#include <API/Python/Solver/FDM/FDMGaussSeidelSolver.h>
#include <Core/Solver/FDM/FDMGaussSeidelSolver2.h>
#include <Core/Solver/FDM/FDMGaussSeidelSolver3.h>

#include <pybind11/pybind11.h>

using namespace CubbyFlow;

void AddFDMGaussSeidelSolver2(pybind11::module& m)
{
    pybind11::class_<FDMGaussSeidelSolver2, FDMGaussSeidelSolver2Ptr,
                     FDMLinearSystemSolver2>(m, "FDMGaussSeidelSolver2",
                                             R"pbdoc(
			2-D finite difference-type linear system solver using conjugate gradient.
		)pbdoc")
        .def(pybind11::init<uint32_t, uint32_t, double, double, bool>(),
             pybind11::arg("max_number_of_iterations"),
             pybind11::arg("residual_check_interval"),
             pybind11::arg("tolerance"), pybind11::arg("sor_factor") = 1.0,
             pybind11::arg("use_red_black_ordering") = false)
        .def_property_readonly("max_number_of_iterations",
                               &FDMGaussSeidelSolver2::GetMaxNumberOfIterations,
                               R"pbdoc(
			Max number of CG iterations.
		)pbdoc")
        .def_property_readonly(
            "last_number_of_iterations",
            &FDMGaussSeidelSolver2::GetLastNumberOfIterations,
            R"pbdoc(
			The last number of CG iterations the solver made.
		)pbdoc")
        .def_property_readonly("tolerance",
                               &FDMGaussSeidelSolver2::GetTolerance,
                               R"pbdoc(
			The max residual tolerance for the CG method.
		)pbdoc")
        .def_property_readonly("last_residual",
                               &FDMGaussSeidelSolver2::GetLastResidual,
                               R"pbdoc(
			The last residual after the CG iterations.
		)pbdoc")
        .def_property_readonly("sor_factor",
                               &FDMGaussSeidelSolver2::GetSORFactor,
                               R"pbdoc(
			Returns the SOR (Successive Over Relaxation) factor.
		)pbdoc")
        .def_property_readonly("use_red_black_ordering",
                               &FDMGaussSeidelSolver2::GetUseRedBlackOrdering,
                               R"pbdoc(
			Returns true if red-black ordering is enabled.
		)pbdoc");
}

void AddFDMGaussSeidelSolver3(pybind11::module& m)
{
    pybind11::class_<FDMGaussSeidelSolver3, FDMGaussSeidelSolver3Ptr,
                     FDMLinearSystemSolver3>(m, "FDMGaussSeidelSolver3",
                                             R"pbdoc(
			3-D finite difference-type linear system solver using conjugate gradient.
		)pbdoc")
        .def(pybind11::init<uint32_t, uint32_t, double, double, bool>(),
             pybind11::arg("max_number_of_iterations"),
             pybind11::arg("residual_check_interval"),
             pybind11::arg("tolerance"), pybind11::arg("sor_factor") = 1.0,
             pybind11::arg("use_red_black_ordering") = false)
        .def_property_readonly("max_number_of_iterations",
                               &FDMGaussSeidelSolver3::GetMaxNumberOfIterations,
                               R"pbdoc(
			Max number of CG iterations.
		)pbdoc")
        .def_property_readonly(
            "last_number_of_iterations",
            &FDMGaussSeidelSolver3::GetLastNumberOfIterations,
            R"pbdoc(
			The last number of CG iterations the solver made.
		)pbdoc")
        .def_property_readonly("tolerance",
                               &FDMGaussSeidelSolver3::GetTolerance,
                               R"pbdoc(
			The max residual tolerance for the CG method.
		)pbdoc")
        .def_property_readonly("last_residual",
                               &FDMGaussSeidelSolver3::GetLastResidual,
                               R"pbdoc(
			The last residual after the CG iterations.
		)pbdoc")
        .def_property_readonly("sor_factor",
                               &FDMGaussSeidelSolver3::GetSORFactor,
                               R"pbdoc(
			Returns the SOR (Successive Over Relaxation) factor.
		)pbdoc")
        .def_property_readonly("use_red_black_ordering",
                               &FDMGaussSeidelSolver3::GetUseRedBlackOrdering,
                               R"pbdoc(
			Returns true if red-black ordering is enabled.
		)pbdoc");
}