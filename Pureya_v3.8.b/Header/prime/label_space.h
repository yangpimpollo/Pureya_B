#pragma once
#ifndef LABEL_SPACE_H_INCLUDED
#define LABEL_SPACE_H_INCLUDED

enum class language { EN = 0, ZH = 1 << 0,SP = 1 << 1 };
enum class settings { WHIDTH, HEIGHT, winStyle, frameLimit, vSync, lan, debug };

struct global {
	enum class res { mamelon, icon, cursor };
	enum class stg { title, new_game, load_game, settings, exit, apply, back, con_tinue };
};

struct load_res {
	enum class res { load1, load2 };
	enum class stg { loading };
};

struct sc_Physics2_res {
	enum class res { tex1 };
	enum class stg { };
};

enum class scene1_id {  };
enum class scene2_id {  };
enum class scene3_id { mamelon, back2, icon, tree, Full_Momentum };


#endif