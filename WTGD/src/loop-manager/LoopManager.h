#ifndef LOOP_MANAGER_H
#define LOOP_MANAGER_H

#ifdef DLL_EXPORT
#define LOOP_MANAGER_API __declspec(dllexport)
#else
#define LOOP_MANAGER_API __declspec(dllimport)
#endif

#include <vector>
#include <SFML/Graphics.hpp>
#include "../time-manager/TimeManager.h"
#include "../gameobjects/Gameobject.h"
#include "../components/KeyboardController.h"
#include "../components/JoystickController.h"
#include "../components/Collider.h"
#include <Character.h>
#include <functional>

namespace WTGD
{
	class LOOP_MANAGER_API LoopManager
	{
	//Constructors / Destructor
	public:
		/// <summary>
		/// Default Loop Manager Contructor
		/// </summary>
		LoopManager() : gameWindow(nullptr) {};
		/// <summary>
		/// Default Loop Manager Destructor
		/// </summary>
		~LoopManager();

	//Public Functions
	public:

		/// <summary>
		/// Creates the game window
		/// </summary>
		void createWindow(const float width, const float height, const char* title);

		/// <summary>
		/// Change the amount of max FPS for the game window (standard is 60 FPS)
		/// </summary>
		/// <param name="newLimit">The new FPS limit</param>
		void setMaxFPS(unsigned newLimit);

		/// <summary>
		/// Returns the current frame's FPS
		/// </summary>
		/// <returns></returns>
		unsigned getFPS()const;

		/// <summary>
		/// Toggle the FPS limit ON or OFF depending on the current setting
		/// </summary>
		void fpsLimitToggler();

		/// <summary>
		/// Draws the registered GameObjects on the screen
		/// </summary>
		void draw(std::vector<GameObject*> gameobjects);
		/// <summary>
		/// Updates the registered GameObjects on the screen
		/// </summary>
		/// <param name="gameobjects"></param>
		void update(std::vector<GameObject*> gameobjects);
		/// <summary>
		/// Reacts to events
		/// </summary>
		void pollEvents(/*std::function<void(sf::Event)>, sf::Event evt*/);
		/// <summary>
		/// Updates the game time
		/// </summary>
		void updateGameTime();
		/// <summary>
		/// Adds the GameObjects colliders to the activeColliders vector
		/// </summary>
		/// <param name="gameobjects">GameObjects' colliders to add</param>
		void add_colliders(std::vector<GameObject*> gameobjects);
		/// <summary>
		/// Set the desired event to check during runtime
		/// </summary>
		/// <param name="func">Function to point</param>
		/// <param name="evt">sf::Event to pass</param>
		void set_input_func(std::function<void(sf::Event)> func, sf::Event evt) { input_func = func; input_event = evt; }

		void base_input_func() {}

	//Private Members
	public:
		sf::RenderWindow* gameWindow;

		unsigned maxFPS = 60;
		bool isFpsLimited = true;

		WTGD::TimeManager timeManager;
		float elapsedTime = 0.0f;
		sf::Time lastTime, currentTime;

		std::function<void(sf::Event)> input_func = nullptr;
		sf::Event input_event;

		std::vector<Collider*> activeColliders;
	};
}

#endif LOOP_MANAGER_H

