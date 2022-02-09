//
//
//

#ifndef B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORDISPLAY_HPP
#define B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORDISPLAY_HPP

#include <ncurses.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include "IMonitorModule.hpp"

namespace Display
{
	class GraphicSfml {
		public:
			GraphicSfml();
			virtual ~GraphicSfml(){};

			sf::RenderWindow m_window;
			sf::Event m_event;
			sf::Font m_font;
			sf::Text m_text;
			sf::Sprite m_background, m_cross1, m_cross2;
			sf::Texture m_backgroundTexture, m_crossTexture;
			sf::Clock m_clock;
			sf::Time m_time;
	};
	void displayHelp();
	void displayGraphicSfml();
	void displayNCurse();
	void draw(GraphicSfml &graphicSfml, Data::UserInfo &userInfo, Data::SystemInfo &systemInfo, Data::DateTime &dateTime, Data::CPUinfos &cpuInfos);
	void event(GraphicSfml &graphicSfml, Data::UserInfo &userInfo, Data::SystemInfo &systemInfo, Data::DateTime &dateTime, Data::CPUinfos &cpuInfos);
}

#endif //B_PDG_300_PAR_3_1_PDGRUSH3_MATTHIEU_QUERU_IMONITORDISPLAY_HPP
