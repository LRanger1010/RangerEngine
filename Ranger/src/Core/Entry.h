#pragma once

#ifdef PLATFORM_WINDOWS

extern Ranger::Application* Ranger::CreateApplication();
int main(int argc, char** argv)
{
	auto game = Ranger::CreateApplication();
	game->Run();
	delete game;
}
#endif