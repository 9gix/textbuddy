#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "text_buddy.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace textbuddycommandtest {
    TEST_CLASS(TestTaskCommandParser) {
    private:
        TextBuddy* tb;
    public:

        TEST_METHOD_INITIALIZE(Setup) {
            tb = new TextBuddy();
        }

        TEST_METHOD_CLEANUP(TearDown) {
            delete tb;
        }

        TEST_METHOD(ParseAddCommand) {
            TextBuddyCommand tbc = tb->parseCommand("add wash laundry");
            Assert::AreEqual(tbc.command, TextBuddy::COMMAND_ADD);
            Assert::AreEqual(tbc.argument, std::string("wash laundry"));
        }

        TEST_METHOD(ParseDeleteCommand) {
            TextBuddyCommand tbc = tb->parseCommand("delete wash laundry");
            Assert::AreEqual(tbc.command, TextBuddy::COMMAND_DELETE);
            Assert::AreEqual(tbc.argument, std::string("wash laundry"));
        }

        TEST_METHOD(ParseClearCommand) {
            TextBuddyCommand tbc = tb->parseCommand("clear");
            Assert::AreEqual(tbc.command, TextBuddy::COMMAND_CLEAR);
        }

        TEST_METHOD(ParseDisplayCommand) {
            TextBuddyCommand tbc = tb->parseCommand("display");
            Assert::AreEqual(tbc.command, TextBuddy::COMMAND_DISPLAY);
        }

        TEST_METHOD(ParseExitCommand) {
            TextBuddyCommand tbc = tb->parseCommand("exit");
            Assert::AreEqual(tbc.command, TextBuddy::COMMAND_EXIT);
        }
    };
}