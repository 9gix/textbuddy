#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "text_buddy.h"
#include "add_command.h"
#include "delete_command.h"
#include <cassert>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace textbuddycommandtest {
    TEST_CLASS(TestTaskCommandExecution) {
        TEST_METHOD(ExecuteSearchCommand){

        }
    };

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
            Command* cmd = tb->parseCommand("add wash laundry");
            cmd->execute();
            Assert::AreEqual(std::string("wash laundry"), tb->getTaskList().at(0).memo);
        }
        
        TEST_METHOD(ParseDeleteCommand) {
            tb->addTask("Task 1");
            Command* cmd = tb->parseCommand("delete 1");
            cmd->execute();
            Assert::AreEqual(0, (int)tb->getTaskList().size());
        }

        TEST_METHOD(ParseClearCommand) {
            for (int i = 0; i < 10; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }
            Command* cmd = tb->parseCommand("clear");
            cmd->execute();
            Assert::IsTrue(tb->getTaskList().empty());
        }

        TEST_METHOD(ParseDisplayCommand) {
            Command* cmd = tb->parseCommand("display");
            cmd->execute();
            std::stringstream out;
            out << cmd;
            Assert::AreEqual(std::string("Task List is empty\n"), out.str());
        }

        /*
        TEST_METHOD(ParseSortCommand) {
            Command* cmd = tb->parseCommand("sort");
            cmd->execute()
        }

        TEST_METHOD(ParseSearchCommand) {
            Command* cmd = tb->parseCommand("search laundry");
            cmd->execute();
        }
        */
    };
}