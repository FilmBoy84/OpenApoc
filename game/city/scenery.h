#pragma once

#include "library/sp.h"
#include "library/vec.h"
#include <set>

namespace OpenApoc
{

class TileObjectScenery;
class SceneryTileDef;
class Building;
class Collision;
class GameState;
class Framework;
class TileMap;

class Scenery : public std::enable_shared_from_this<Scenery>
{

  public:
	SceneryTileDef &tileDef;

	const Vec3<float> getPosition() const
	{ // The "position" is the center, so offset by {0.5,0.5}
		Vec3<float> offsetPos = pos;
		offsetPos += Vec3<float>{0.5, 0.5, 0.0};
		return offsetPos;
	}

	Vec3<int> pos;
	// May be NULL for no building
	sp<Building> building;
	sp<TileObjectScenery> tileObject;

	std::set<sp<Scenery>> supports;
	std::set<sp<Scenery>> supportedBy;

	void handleCollision(GameState &state, Collision &c);

	bool damaged;
	bool falling;

	void update(Framework &fw, GameState &state, unsigned int ticks);
	void collapse(GameState &state);

	bool canRepair() const;
	void repair(TileMap &map);

	bool isAlive() const;

	Scenery(SceneryTileDef &tileDef, Vec3<int> pos, sp<Building> bld);
	~Scenery() = default;
};
} // namespace OpenApoc