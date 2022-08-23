#pragma once
#include "Core.h"

namespace Ranger
{
	class RANGER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	};

	Application* CreateApplication();
}


