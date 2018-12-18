#include <View.hpp>

int main(int argc, char** argv){
	glimac::FilePath applicationPath(argv[0]);
    View view;
    view.window(applicationPath);
    return 0;
}