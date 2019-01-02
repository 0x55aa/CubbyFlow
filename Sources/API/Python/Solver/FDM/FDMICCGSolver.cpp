/*************************************************************************
> File Name: FDMICCGSolver.cpp
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: FDMICCGSolver functions for CubbyFlow Python API.
> Created Time: 2018/02/14
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#include <API/Python/Solver/FDM/FDMICCGSolver.h>
#include <Core/Solver/FDM/FDMICCGSolver2.h>
#include <Core/Solver/FDM/FDMICCGSolver3.h>

#include <pybind11/pybind11.h>

using namespace CubbyFlow;

void AddFDMICCGSolver2(pybind11::module& m)
{
	pybind11::class_<FDMICCGSolver2, FDMICCGSolver2Ptr, FDMLinearSystemSolver2>(m, "FDMICCGSolver2",
		R"pbdoc(
			2-D finite difference-type linear system solver using conjugate gradient.
		)pbdoc")
	.def(pybind11::init<uint32_t, double>(),
		pybind11::arg("max_number_of_iterations"),
		pybind11::arg("tolerance"))
	.def_property_readonly("max_number_of_iterations", &FDMICCGSolver2::GetMaxNumberOfIterations,
		R"pbdoc(
			Max number of ICCG iterations.
		)pbdoc")
	.def_property_readonly("last_number_of_iterations", &FDMICCGSolver2::GetLastNumberOfIterations,
		R"pbdoc(
			The last number of ICCG iterations the solver made.
		)pbdoc")
	.def_property_readonly("tolerance", &FDMICCGSolver2::GetTolerance,
		R"pbdoc(
			The max residual tolerance for the ICCG method.
		)pbdoc")
	.def_property_readonly("last_residual", &FDMICCGSolver2::GetLastResidual,
		R"pbdoc(
			The last residual after the ICCG iterations.
		)pbdoc");
}

void AddFDMICCGSolver3(pybind11::module& m)
{
	pybind11::class_<FDMICCGSolver3, FDMICCGSolver3Ptr, FDMLinearSystemSolver3>(m, "FDMICCGSolver3",
		R"pbdoc(
			3-D finite difference-type linear system solver using conjugate gradient.
		)pbdoc")
	.def(pybind11::init<uint32_t, double>(),
		pybind11::arg("max_number_of_iterations"),
		pybind11::arg("tolerance"))
	.def_property_readonly("max_number_of_iterations", &FDMICCGSolver3::GetMaxNumberOfIterations,
		R"pbdoc(
			Max number of ICCG iterations.
		)pbdoc")
	.def_property_readonly("last_number_of_iterations", &FDMICCGSolver3::GetLastNumberOfIterations,
		R"pbdoc(
			The last number of ICCG iterations the solver made.
		)pbdoc")
	.def_property_readonly("tolerance", &FDMICCGSolver3::GetTolerance,
		R"pbdoc(
			The max residual tolerance for the ICCG method.
		)pbdoc")
	.def_property_readonly("last_residual", &FDMICCGSolver3::GetLastResidual,
		R"pbdoc(
			The last residual after the ICCG iterations.
		)pbdoc");
}