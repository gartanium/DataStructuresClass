#include "stdafx.h"
#include "CppUnitTest.h"
#include "queueIterator.h"
#include "deque.h"
#include "helpRequest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			QueueIterator testObj(50);
			
			testObj = 0;

			testObj--;
			Assert::AreEqual(49, testObj.currentIndex());	
		}

		TEST_METHOD(Resize_Test)
		{
			Deque<int> testObj;
			
			testObj.push_back(1);

		}

		TEST_METHOD(helpRequestTest)
		{
			string name = "kyle";
			string className = "kyle'sClass";
			int time = 40;

			HelpRequest testObj(time, name, className);

			Assert::AreEqual(name, testObj.getName());
			Assert::AreEqual(time, testObj.getTime());
			Assert::AreEqual(className, testObj.getClass());
		}
		TEST_METHOD(helpRequestTestDeque)
		{
			string name = "kyle";
			string className = "kyle'sClass";
			int time = 40;
			Deque<HelpRequest> testDeque;

			HelpRequest testObj(time, name, className);
			testDeque.push_back(testObj);

			Assert::AreEqual(name, testDeque.front().getName());
			Assert::AreEqual(time, testDeque.front().getTime());
			Assert::AreEqual(className, testDeque.front().getClass());
		}

	};
}