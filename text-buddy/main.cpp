#include "main.h"
#include "text_buddy.h"

int main(int argc, char* argv[]) {
    TextBuddy app;
    try {
        app.run(argc, argv);
    } catch (const std::invalid_argument&) {
        exit(EXIT_FAILURE);
    }
    return 0;
}