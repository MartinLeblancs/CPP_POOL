//
// Created by mqueru on 1/31/22.
//

#include "../include/IMonitorDisplay.hpp"

Display::GraphicSfml::GraphicSfml() : m_window(sf::VideoMode(1920, 1080), "My GKrellm")
{
	m_font.loadFromFile("./asset/TerminalDosis-Medium.ttf");
	m_backgroundTexture.loadFromFile("./asset/back.jpg");
	m_background.setTexture(m_backgroundTexture);
	m_crossTexture.loadFromFile("./asset/cross.png");
	m_cross1.setTexture(m_crossTexture);
}

void Display::displayGraphicSfml()
{
	Data::UserInfo userInfo;
	Data::DateTime dateTime;
	Data::SystemInfo systemInfo;
	Data::CPUinfos cpuInfos;
	GraphicSfml graphicSfml;
	cpuInfos.getCPUInfos();
	sf::Time time = sf::seconds(0.10);
	while (graphicSfml.m_window.isOpen()) {
		if (graphicSfml.m_clock.getElapsedTime() > time) {
			userInfo.refreshInfos();
			dateTime.refreshInfo();
			systemInfo.refreshInfos();
			draw(graphicSfml, userInfo, systemInfo, dateTime, cpuInfos);
			graphicSfml.m_window.display();
			graphicSfml.m_clock.restart();
		}
		while (graphicSfml.m_window.pollEvent(graphicSfml.m_event)) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) || graphicSfml.m_event.type == sf::Event::Closed)
				graphicSfml.m_window.close();
		}
	}
}

void Display::draw(GraphicSfml &graphicSfml, Data::UserInfo &userInfo, Data::SystemInfo &systemInfo,
				   Data::DateTime &dateTime, Data::CPUinfos &cpuInfos)
{
	graphicSfml.m_window.draw(graphicSfml.m_background);
	graphicSfml.m_text.setFont(graphicSfml.m_font);
	graphicSfml.m_text.setCharacterSize(40);
	event(graphicSfml, userInfo, systemInfo, dateTime, cpuInfos);
	//Date
	graphicSfml.m_text.setString(dateTime.getTime());
	graphicSfml.m_text.setPosition(1500, 10);
	graphicSfml.m_window.draw(graphicSfml.m_text);

	//block: username and hostname
	if (userInfo.getStatus()) {
		sf::RectangleShape part1(sf::Vector2f(565, 200));
		part1.setFillColor(sf::Color(0, 0, 0, 128));
		part1.setPosition(50, 100);
		graphicSfml.m_window.draw(part1);
		graphicSfml.m_cross1.setPosition(550, 100);
		graphicSfml.m_window.draw(graphicSfml.m_cross1);
		graphicSfml.m_text.setString("Username : " + userInfo.getUserName());
		graphicSfml.m_text.setPosition(75, 135);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setString("Hostname : " + userInfo.getHostName());
		graphicSfml.m_text.setPosition(75, 210);
		graphicSfml.m_window.draw(graphicSfml.m_text);
	} else if (!userInfo.getStatus()) {
		sf::RectangleShape part1(sf::Vector2f(110, 70));
		part1.setFillColor(sf::Color(0, 0, 0, 128));
		part1.setPosition(0, 0);
		graphicSfml.m_window.draw(part1);
		graphicSfml.m_text.setString("USER");
		graphicSfml.m_text.setPosition(10, 10);
		graphicSfml.m_window.draw(graphicSfml.m_text);
	}

	//block: System
	if (systemInfo.getStatus()) {
		sf::RectangleShape part2(sf::Vector2f(565, 200));
		part2.setFillColor(sf::Color(0, 0, 0, 128));
		part2.setPosition(50, 350);
		graphicSfml.m_window.draw(part2);
		graphicSfml.m_cross1.setPosition(550, 350);
		graphicSfml.m_window.draw(graphicSfml.m_cross1);
		graphicSfml.m_text.setString("OS : " + systemInfo.getOpSystem());
		graphicSfml.m_text.setPosition(75, 385);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setString("Kernel : " + systemInfo.getKernelVersion());
		graphicSfml.m_text.setPosition(75, 460);
		graphicSfml.m_window.draw(graphicSfml.m_text);
	} else if (!systemInfo.getStatus()) {
		sf::RectangleShape part1(sf::Vector2f(150, 70));
		part1.setFillColor(sf::Color(0, 0, 0, 128));
		part1.setPosition(110, 0);
		graphicSfml.m_window.draw(part1);
		graphicSfml.m_text.setString("SYSTEM");
		graphicSfml.m_text.setPosition(120, 10);
		graphicSfml.m_window.draw(graphicSfml.m_text);
	}
	//Block : CPU
	if (cpuInfos.getStatus()) {
		sf::RectangleShape part3(sf::Vector2f(1230, 900));
		part3.setFillColor(sf::Color(0, 0, 0, 128));
		part3.setPosition(650, 100);
		graphicSfml.m_window.draw(part3);
		graphicSfml.m_cross1.setPosition(1810, 100);
		graphicSfml.m_window.draw(graphicSfml.m_cross1);
		graphicSfml.m_text.setString("CPU Model : " + cpuInfos.getModel());
		graphicSfml.m_text.setPosition(660, 135);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setString("Ghz Max : " + cpuInfos.getGhz());
		graphicSfml.m_text.setPosition(660, 210);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setString("Cores : " + cpuInfos.getCore());
		graphicSfml.m_text.setPosition(660, 285);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setString("Threads : " + std::to_string(cpuInfos.getThreadsNumber()));
		graphicSfml.m_text.setPosition(660, 360);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		cpuInfos.getCPUInfos();
		graphicSfml.m_text.setString("Cpu - Total: " + cpuInfos.getPercent(0) + " %");
		graphicSfml.m_text.setFillColor(sf::Color::White);
		if (std::stof(cpuInfos.getPercent(0)) < 30)
			graphicSfml.m_text.setFillColor(sf::Color::Green);
		else if (std::stof(cpuInfos.getPercent(0)) > 30 && std::stof(cpuInfos.getPercent(0)) < 80)
			graphicSfml.m_text.setFillColor(sf::Color::Yellow);
		else if (std::stof(cpuInfos.getPercent(0)) >= 80)
			graphicSfml.m_text.setFillColor(sf::Color::Red);
		graphicSfml.m_text.setPosition(660, 435);
		graphicSfml.m_window.draw(graphicSfml.m_text);
		graphicSfml.m_text.setFillColor(sf::Color::White);
		for (int i = 1, z = 300; i <= cpuInfos.getThreadsNumber(); i++, z += 75) {
			cpuInfos.getCPUInfos();
			graphicSfml.m_text.setString("Cpu " + std::to_string(i-1) + ": " + cpuInfos.getPercent(i) + " %");
			graphicSfml.m_text.setFillColor(sf::Color::White);
			if (std::stof(cpuInfos.getPercent(i)) < 30)
				graphicSfml.m_text.setFillColor(sf::Color::Green);
			else if (std::stof(cpuInfos.getPercent(i)) > 30 && std::stof(cpuInfos.getPercent(i)) < 80)
				graphicSfml.m_text.setFillColor(sf::Color::Yellow);
			else if (std::stof(cpuInfos.getPercent(i)) >= 80)
				graphicSfml.m_text.setFillColor(sf::Color::Red);
			graphicSfml.m_text.setPosition(1400, z);
			graphicSfml.m_window.draw(graphicSfml.m_text);
			graphicSfml.m_text.setFillColor(sf::Color::White);
		}
	} else if (!cpuInfos.getStatus()) {
		sf::RectangleShape part1(sf::Vector2f(100, 70));
		part1.setFillColor(sf::Color(0, 0, 0, 128));
		part1.setPosition(260, 0);
		graphicSfml.m_window.draw(part1);
		graphicSfml.m_text.setString("CPU");
		graphicSfml.m_text.setPosition(270, 10);
		graphicSfml.m_window.draw(graphicSfml.m_text);
	}
}


void Display::event(GraphicSfml &graphicSfml, Data::UserInfo &userInfo, Data::SystemInfo &systemInfo,
					Data::DateTime &dateTime, Data::CPUinfos &cpuInfos)
{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 550 && sf::Mouse::getPosition(graphicSfml.m_window).x < 590 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 120 && sf::Mouse::getPosition(graphicSfml.m_window).y < 145 &&
				userInfo.getStatus())
					userInfo.setStatus(false);
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 0 && sf::Mouse::getPosition(graphicSfml.m_window).x < 100 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 0 && sf::Mouse::getPosition(graphicSfml.m_window).y < 50 &&
				!userInfo.getStatus())
					userInfo.setStatus(true);
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 550 && sf::Mouse::getPosition(graphicSfml.m_window).x < 600 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 350 && sf::Mouse::getPosition(graphicSfml.m_window).y < 405 &&
				systemInfo.getStatus())
				systemInfo.setStatus(false);
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 110 && sf::Mouse::getPosition(graphicSfml.m_window).x < 280 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 0 && sf::Mouse::getPosition(graphicSfml.m_window).y < 50 &&
				!systemInfo.getStatus())
				systemInfo.setStatus(true);
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 1810 && sf::Mouse::getPosition(graphicSfml.m_window).x < 1855 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 110 && sf::Mouse::getPosition(graphicSfml.m_window).y < 145 &&
				cpuInfos.getStatus())
				cpuInfos.setStatus(false);
			if (sf::Mouse::getPosition(graphicSfml.m_window).x > 260 && sf::Mouse::getPosition(graphicSfml.m_window).x < 400 &&
				sf::Mouse::getPosition(graphicSfml.m_window).y > 0 && sf::Mouse::getPosition(graphicSfml.m_window).y < 50 &&
				!cpuInfos.getStatus())
				cpuInfos.setStatus(true);
		}
}