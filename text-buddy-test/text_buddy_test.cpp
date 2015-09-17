#include "stdafx.h"
#include "CppUnitTest.h"
#include <string>
#include "text_buddy.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace textbuddytest {
    TEST_CLASS(TestTaskAdd) {
    private:
        TextBuddy* tb;
    public:

        TEST_METHOD_INITIALIZE(Setup) {
            tb = new TextBuddy();
        }

        TEST_METHOD_CLEANUP(TearDown) {
            delete tb;
        }

        TEST_METHOD(AddMultipleTask) {
            int N_OBJ = 5;
            for (int i = 0; i < N_OBJ; ++i) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }

            for (int i = 0; i < N_OBJ; ++i) {
                Assert::AreEqual(std::string("Task ") + std::to_string(i), tb->getTaskList()[i].memo);
            }
            Assert::AreEqual(N_OBJ, (int)tb->getTaskList().size());
        }
    };

    TEST_CLASS(TestTaskDelete) {
    private:
        TextBuddy* tb;
    public:

        TEST_METHOD_INITIALIZE(Setup) {
            tb = new TextBuddy();
        }

        TEST_METHOD_CLEANUP(TearDown) {
            delete tb;
        }

        TEST_METHOD(ClearTask) {
            for (int i = 0; i < 5; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }
            tb->clearTask();
            Assert::IsTrue(tb->getTaskList().empty());
        }

        TEST_METHOD(DeleteFirstTask) {
            for (int i = 0; i <= 2; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }

            tb->deleteTask(0);

            Assert::AreNotEqual(std::string("Task 0"), tb->getTaskList()[0].memo);
            Assert::AreEqual(2, (int)tb->getTaskList().size());
        }

        TEST_METHOD(DeleteMiddleTask) {
            for (int i = 0; i <= 2; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }
            tb->deleteTask(1);

            Assert::AreNotEqual(std::string("Task 1"), tb->getTaskList()[1].memo);
            Assert::AreEqual(2, (int)tb->getTaskList().size());
        }

        TEST_METHOD(DeleteLastTask) {
            for (int i = 0; i <= 2; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }
            tb->deleteTask(2);

            Assert::AreEqual(2, (int)tb->getTaskList().size());
        }

        TEST_METHOD(DeleteNoTask) {
            auto delTask = [this] {tb->deleteTask(0); };
            Assert::ExpectException<std::out_of_range>(delTask);
        }

        TEST_METHOD(DeleteInvalidTask) {
            tb->addTask(std::string("Task 0"));
            auto delTask = [this] {tb->deleteTask(1); };
            Assert::ExpectException<std::out_of_range>(delTask);
        }

        TEST_METHOD(DeleteUntilEmpty) {
            for (int i = 0; i < 5; i++) {
                tb->addTask(std::string("Task ") + std::to_string(i));
            }

            for (int i = 0; i < 5; i++) {
                tb->deleteTask(0);
            }
            Assert::IsTrue(tb->getTaskList().empty());
        }
    };
}