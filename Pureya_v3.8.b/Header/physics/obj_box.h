//#pragma once
//#ifndef OBJ_BOX_H_INCLUDED
//#define OBJ_BOX_H_INCLUDED
//
//#include <iostream> 
//#include <SFML/Graphics.hpp>
//#include "physics/math.h"
//
//class game_core;
//
//class obj_box : public sf::Drawable
//{
//public:
//	obj_box();
//	obj_box(game_core& arg, sf::Vector2f position, sf::Vector2f size, std::string id = "none");
//	~obj_box();
//	void update(sf::Event event, sf::Time deltaTime);
//	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
//
//	void addTextureBox(sf::Vector2f rel_position, sf::Vector2f size);
//
//	inline sf::Vector2f getPosition() { return position; }	
//	inline sf::Vector2f getSize() { return size; }
//	inline std::string getID() { return id; }
//	inline sf::Vector2f getDirection() { return direction; }
//	inline sf::Vector2f getCorner() { return position + size; }
//	inline sf::Vector2f getNexPosition() { return position + (direction * speed); }
//	inline sf::Vector2f getNexCorner() { return position + size + (direction * speed); }
//
//	inline void setPosition(sf::Vector2f arg) { position = arg; }
//	inline void setSize(sf::Vector2f arg) { size = arg; }
//	inline void setID(std::string arg) { id = arg; }
//	inline void move(sf::Vector2f arg) { direction = normalize(arg); }
//	inline void setTexture(sf::Texture arg) { obj_texture = arg; }
//
//	inline void setAllBox(std::vector<obj_box*>& all_ABbox_arg) { all_ABbox = all_ABbox_arg; }
//	inline void addActiveCollision(int arg) { active.push_back(arg); }
//
//	
//	
//protected:
//	std::vector<int> active;
//	std::vector<obj_box*> all_ABbox;
//
//private:
//	game_core* app;
//	sf::Vector2f position, size;
//	std::string id;
//
//	sf::Vector2f direction = sf::Vector2f(0.f, 0.f);
//	float speed = 0.10f;
//	float z_buffer;
//	float delta_zbuff = 0.f;
//	float delta_zbuff0;
//
//	sf::RectangleShape drawABox, texbox;
//	sf::Texture obj_texture;
//	sf::CircleShape r1, r2, r3, r4, r5;
//	sf::Vertex lineL[2], lineR[2];
//	sf::Color color1 = sf::Color(64, 224, 208);
//	sf::Color color2 = sf::Color(224, 62, 78);
//	sf::Color color3 = sf::Color(144, 0, 255);
//
//	//   ...  temporal funtions ........
//
//	void collisionDetection();
//	void clickPress();
//	void StatusMode();
//	void clickRelease();
//
//	//   ...  temporal variables .......
//
//	sf::Vector2f mousePos;
//	sf::Vector2f mosPoss0;
//	sf::Vector2f size0;
//	sf::Vector2f position0;
//
//	int click_mode;
//	bool click = false;	
//	bool selected = false;
//	bool inR1, inR2, inR3, inR4, inR5, inBox;
//};
//
//#endif
