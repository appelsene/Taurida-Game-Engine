#pragma once

#ifdef TRD_PLATFORM_WINDOWS

extern Taurida::Application* Taurida::CreateApplication();

int main(int argc, char** argv) 
{
	Taurida::Log::Init();
	TRD_CORE_WARN("Initialized Log!");
	int a = 5;
	TRD_INFO("Hello! Var={0}", a);

	auto app = Taurida::CreateApplication();
	app->Run();
	delete app;
}

#endif