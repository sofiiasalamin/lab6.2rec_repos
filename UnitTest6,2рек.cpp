#include "pch.h"
#include "CppUnitTest.h"
#include "../6,2рек/6,2рек.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest62Rec
{
    TEST_CLASS(UnitTest62Rec)
    {
    public:
       
        TEST_METHOD(IndexOfMax_FirstOfEqualMaximums)
        {
            int a[10] = { 3, -5, 17, 2, 9, -8, 17, 0, 4, 1 };
            Assert::AreEqual(2, IndexOfMax(a, 10, 0, 0));
        }

        
        TEST_METHOD(IndexOfMax_AllNegative)
        {
            int a[10] = { -5, -3, -9, -1, -7, -8, -2, -6, -4, -10 };
            Assert::AreEqual(3, IndexOfMax(a, 10, 0, 0));
        }

        TEST_METHOD(IndexOfMax_AtTheEnd)
        {
            int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            Assert::AreEqual(9, IndexOfMax(a, 10, 0, 0));
        }

        TEST_METHOD(SwapMaxMin_SingleElement_NotChanged)
        {
            int a[1] = { 7 };
            Assert::IsFalse(SwapMaxMin(a, 1));
            Assert::AreEqual(7, a[0]);
        }

       
        TEST_METHOD(SwapMaxMin_MaxAndMinExchanged)
        {
            int a[10] = { 3, -5, 17, 2, 9, -8, 12, 0, 4, 1 };
            SwapMaxMin(a, 10);
            Assert::AreEqual(-8, a[2]);                  
            Assert::AreEqual(17, a[5]);                  
        }

        
        TEST_METHOD(Create_ValuesInRange)
        {
            int a[10];
            for (int k = 0; k < 100; k++)              
            {
                Create(a, 10, -20, 50, 0);
                for (int i = 0; i < 10; i++)
                {
                    Assert::IsTrue(a[i] >= -20);
                    Assert::IsTrue(a[i] <= 50);
                }
            }
        }
    };
}