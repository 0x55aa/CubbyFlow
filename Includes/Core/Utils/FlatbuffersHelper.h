/*************************************************************************
> File Name: FlatbuffersHelper.h
> Project Name: CubbyFlow
> This code is based on Jet Framework that was created by Doyub Kim.
> References: https://github.com/doyubkim/fluid-engine-dev
> Purpose: Helper functions for Flatbuffers.
> Created Time: 2017/05/01
> Copyright (c) 2018, Chan-Ho Chris Ohk
*************************************************************************/
#ifndef CUBBYFLOW_FLATBUFFERS_HELPER_H
#define CUBBYFLOW_FLATBUFFERS_HELPER_H

#include <Core/Size/Size2.h>
#include <Core/Size/Size3.h>
#include <Core/Vector/Vector2.h>
#include <Core/Vector/Vector3.h>

#include <Flatbuffers/generated/BasicTypes_generated.h>

namespace CubbyFlow
{
	inline fbs::Size2 CubbyFlowToFlatbuffers(const Size2& vec)
	{
		return fbs::Size2(vec.x, vec.y);
	}

	inline fbs::Size3 CubbyFlowToFlatbuffers(const Size3& vec)
	{
		return fbs::Size3(vec.x, vec.y, vec.z);
	}

	inline fbs::Vector2D CubbyFlowToFlatbuffers(const Vector2D& vec)
	{
		return fbs::Vector2D(vec.x, vec.y);
	}

	inline fbs::Vector3D CubbyFlowToFlatbuffers(const Vector3D& vec)
	{
		return fbs::Vector3D(vec.x, vec.y, vec.z);
	}

	inline Size2 FlatbuffersToCubbyFlow(const fbs::Size2& vec)
	{
		return Size2({ vec.x(), vec.y() });
	}

	inline Size3 FlatbuffersToCubbyFlow(const fbs::Size3& vec)
	{
		return Size3({ vec.x(), vec.y(), vec.z() });
	}

	inline Vector2D FlatbuffersToCubbyFlow(const fbs::Vector2D& vec)
	{
		return Vector2D(vec.x(), vec.y());
	}

	inline Vector3D FlatbuffersToCubbyFlow(const fbs::Vector3D& vec)
	{
		return Vector3D(vec.x(), vec.y(), vec.z());
	}

	template <typename GridType, typename FbsFactoryFunc, typename FbsGridType>
	void SerializeGrid(flatbuffers::FlatBufferBuilder* builder, const std::vector<GridType>& gridList, FbsFactoryFunc func, std::vector<flatbuffers::Offset<FbsGridType>>* fbsGridList)
	{
		for (const auto& grid : gridList)
		{
			auto type = builder->CreateString(grid->GetTypeName());

			std::vector<uint8_t> gridSerialized;
			grid->Serialize(&gridSerialized);

			auto fbsGrid = func(*builder, type, builder->CreateVector(gridSerialized.data(), gridSerialized.size()));
			fbsGridList->push_back(fbsGrid);
		}
	}

	template <typename FbsGridList, typename GridType, typename FactoryFunc>
	void DeserializeGrid(FbsGridList* fbsGridList, FactoryFunc factoryFunc, std::vector<GridType>* gridList)
	{
		for (const auto& grid : (*fbsGridList))
		{
			auto type = grid->type()->c_str();

			std::vector<uint8_t> gridSerialized(grid->data()->begin(), grid->data()->end());

			auto newGrid = factoryFunc(type);
			newGrid->Deserialize(gridSerialized);

			gridList->push_back(newGrid);
		}
	}
}

#endif