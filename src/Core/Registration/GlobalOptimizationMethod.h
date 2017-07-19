// ----------------------------------------------------------------------------
// -                        Open3D: www.open3d.org                            -
// ----------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2017 Jaesik Park <syncle@gmail.com>
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
// FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
// IN THE SOFTWARE.
// ----------------------------------------------------------------------------

#pragma once

#include <memory>

namespace three {

class PoseGraph;

class GlobalOptimizationOption;

class GlobalOptimizationConvergenceCriteria;

class GlobalOptimizationLineProcessOption;

class GlobalOptimizationMethod
{
public:
	GlobalOptimizationMethod() {}
	virtual ~GlobalOptimizationMethod() {}

public:
	virtual void OptimizePoseGraph(
			PoseGraph &pose_graph,
			const GlobalOptimizationConvergenceCriteria &criteria,
			const GlobalOptimizationLineProcessOption &option) const = 0;
};

class GlobalOptimizationGaussNewton : public GlobalOptimizationMethod
{
public:
	GlobalOptimizationGaussNewton() {}
	~GlobalOptimizationGaussNewton() override {}

public:
	void OptimizePoseGraph(
			PoseGraph &pose_graph,
			const GlobalOptimizationConvergenceCriteria &criteria,
			const GlobalOptimizationLineProcessOption &option) const override;
};

class GlobalOptimizationLevenbergMethodMarquardt : public GlobalOptimizationMethod
{
public:
	GlobalOptimizationLevenbergMethodMarquardt() {}
	~GlobalOptimizationLevenbergMethodMarquardt() override {}

public:
	void OptimizePoseGraph(
			PoseGraph &pose_graph,
			const GlobalOptimizationConvergenceCriteria &criteria,
			const GlobalOptimizationLineProcessOption &option) const override;
};

}	// namespace three
