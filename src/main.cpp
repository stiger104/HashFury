#include "../googletest/include/gtest/gtest.h"
#include "hashblock.h"

#define BEGIN(a)            ((char*)&(a))
#define END(a)              ((char*)&((&(a))[1]))
using namespace std;

string xHash(uint256 n1, uint256 n2)
{
    cout << "Check X11 Hash: \n";
    uint256 res = HashX11(BEGIN(n1), END(n2));
    return res.GetHex();
}

TEST(test1, x11){
EXPECT_EQ("40502f215b739d699765dfe23e1b78a794a3b78c1f99f10ecc33df8d13875769", xHash(100, 200));
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}