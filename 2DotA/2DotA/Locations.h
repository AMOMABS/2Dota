#pragma once
#include <map>
#include "Point.h"
#include <string>

namespace{
	const point Sun_fontain = { 4,75 };
	const point Moon_fontain = { 198,4 };
	const point Sun_mid_tower2 = { 80,45 };
	const point Sun_mid_tower1 = { 40,57 };
	const point Moon_mid_tower2 = { 95,52 };
	const point Moon_mid_tower1 = { 200,35 };
	const point Moon_troika = { 130,50 };
	const point Moon_forest = { 100,40 };
	const point Moon_top_tower1 = { 120,10 };
	const point Moon_top_tower2 = { 35,11 };
	const point Moon_niz_tower1 = { 180,30 };
	const point Moon_niz_tower2 = { 181,71 };
	const point Sun_top_tower1 = { 20,55 };
	const point Sun_top_tower2 = { 21,23 };
	const point Sun_niz_tower1 = { 22,74 };
	const point Sun_niz_tower2 = { 65,73 };
	const point Sun_troika = { 60,34 };
	const point Sun_forest = { 81,65 };

	std::multimap <point, std::string> locations1{ {Sun_fontain,"Sun fontain"},{Moon_fontain,"Moon fontain"},{Sun_mid_tower2, "mid sun tower2"},
		{Sun_mid_tower1,"mid sun tower1"},{Sun_troika,"troika"},{Sun_forest,"forest"},{Sun_top_tower1,"top sun tower1"},{Sun_top_tower2,"top sun tower2"},
		{ Sun_niz_tower1,"niz sun tower1" },{Sun_niz_tower2,"niz sun tower2"},{ Moon_mid_tower2, " Moon mid tower2 " },{ Moon_mid_tower1," Moon mid tower1" },
		{ Moon_troika,"Moon troika" }, { Moon_forest,"Moon forest" }, { Moon_top_tower1,"Moon top tower1" },{ Moon_top_tower2,"Moon top tower2" },
		{ Moon_niz_tower1,"Moon niz tower1" }, { Moon_niz_tower2,"Moon niz tower2" } };
}
