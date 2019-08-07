#include "System.cpp"


int main() {

	System system;

	if ( system.GLFWInit() != 0 ){
		return EXIT_FAILURE;
	}
	if ( system.OpenGLSetup() != 0 ){
		return EXIT_FAILURE;
	}
	if ( system.SystemSetup() != 0 ){
		return EXIT_FAILURE;
	}

	system.Run();

	system.Finish();

	return EXIT_SUCCESS;
}