#include <SFML/Graphics.hpp>
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#include "../third_party/imgui-sfml/imgui-SFML.h"
#include "../third_party/imgui/imgui.h"



#include <resources/Assets.hpp>



int main() {
    ShowWindow(GetConsoleWindow(), SW_HIDE);
	// Create the main window
    bool sameWindow = false;
    bool needsRebuilding = false;
    
    sf::RenderWindow window(sf::VideoMode{ { 1600U, 900U }, 32U }, "SFML Window");
    sf::RenderWindow guiWin(sf::VideoMode{ { 480U, 640U }, 32U }, "GUI Window");
    window.setVerticalSyncEnabled(true);
    guiWin.setVerticalSyncEnabled(true);

    auto good = ImGui::SFML::Init(guiWin);


    Assets::Initialize();
    sf::Clock deltaClock;
	sf::Time deltaTime;
    // Start the game loop
    while (window.isOpen())
    {

        deltaTime = deltaClock.restart();

        if (!sameWindow)
        {
            if (needsRebuilding)
            {
                ImGui::SFML::Shutdown();
                window.close();

                window.create(sf::VideoMode{ { 1600U, 900U }, 32U }, "SFML Window");
                guiWin.create(sf::VideoMode{ { 480U, 640U }, 32U }, "GUI Window");
                needsRebuilding = false;
                window.setVerticalSyncEnabled(true);
                guiWin.setVerticalSyncEnabled(true);

                auto good = ImGui::SFML::Init(guiWin);
            }

            { auto isset = window.setActive(true); }
            //window.requestFocus();
            while (const std::optional event = window.pollEvent())
            {



                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                        window.close();
                    if (keyPressed->scancode == sf::Keyboard::Scancode::M)
                    {
                        sameWindow = true;
                        needsRebuilding = true;
                    }
                }
            }

            if (guiWin.isOpen())
            {
                { auto isset = guiWin.setActive(true); }
                while (const std::optional guiEvt = guiWin.pollEvent())
                {
                    if (guiEvt.has_value())
                    {
                        ImGui::SFML::ProcessEvent(guiWin, *guiEvt);

                        if (guiEvt->is<sf::Event::Closed>())
                        {
                            guiWin.close();
                        }
                        else if (const auto* keyPressed = guiEvt->getIf<sf::Event::KeyPressed>())
                        {
                            if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                                guiWin.close();
                            if (keyPressed->scancode == sf::Keyboard::Scancode::M)
                            {
                                sameWindow = true;
                                needsRebuilding = true;
                            }
                        }
                    }
                }
            
                ImGui::SFML::Update(guiWin, deltaTime);


                ImGui::Begin("Change");
                ImGui::Button("Aaaand...");
                ImGui::End();

                guiWin.clear(sf::Color::Blue);

                ImGui::SFML::Render(guiWin);

                guiWin.display();
            }

            if (window.isOpen())
            {
                // Remainder of main loop
                { auto isset = window.setActive(true); }

                window.clear();

                window.display();
            }

        }
        else  // sameWindow == true
        {
            if (needsRebuilding)
            {
                guiWin.close();
                ImGui::SFML::Shutdown();

                window.create(sf::VideoMode{ { 1600U, 900U }, 32U }, "SFML Window");
                auto good = ImGui::SFML::Init(window);

                needsRebuilding = false;
                window.setVerticalSyncEnabled(true);
                window.setActive(true);
            }


            //window.requestFocus();
            while (const std::optional event = window.pollEvent())
            {
                ImGui::SFML::ProcessEvent(window, *event);

                if (event->is<sf::Event::Closed>())
                {
                    window.close();
                }
                else if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>())
                {
                    if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                        window.close();
                    if (keyPressed->scancode == sf::Keyboard::Scancode::M)
                    {
                        sameWindow = false;
                        needsRebuilding = true;
                    }
                }
            }



            if (window.isOpen())
            {
                sf::Time deltaTime = deltaClock.restart();

                ImGui::SFML::Update(window, deltaTime);


                ImGui::Begin("Change");
                ImGui::Button("Aaaand...");
                ImGui::End();


                // Remainder of main loop


                window.clear();

                ImGui::SFML::Render(window);

                window.display();
            }
        }
    }



    if (window.isOpen())
        window.close();
    if (guiWin.isOpen())
        guiWin.close();
    
    ImGui::SFML::Shutdown();
	return 0;
}