#include "gtest/gtest.h"
#include <concrt.h>
#include "../LibProject/Lib.h"
#include "../../GoogleTestExtension/GoogleTestAdapter/Resources/GTA_Traits.h"

#include "../Tests/Main.cpp"

TEST(Crashing, TheCrash)
{
	__asm {
		mov esp, 0
	}
}

TEST(Crashing, AddFails)
{
	EXPECT_EQ(1000, Add(10, 10));
}

TEST(Crashing, AddPasses)
{
	EXPECT_EQ(20, Add(10, 10));
}

TEST(Crashing, LongRunning)
{
	Concurrency::wait(2000);
	EXPECT_EQ(1, 1);
}
