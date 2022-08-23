#include <Header.h>

class TestGame : public Ranger::Application
{
public:
	TestGame() {
		Debug::Init();
		Debug::Log("Hello World! {0}", 5);
		Debug::LogWarn("Hello World!");
		Debug::LogError("Hello World! var = {0}, {1}", 1, 2);
	}
	~TestGame() {}

private:

};

Ranger::Application* Ranger::CreateApplication()
{
	return new TestGame();
}