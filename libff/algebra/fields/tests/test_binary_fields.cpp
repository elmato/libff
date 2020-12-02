/**
 *****************************************************************************
 Tests for all binary fields. This test was copied from libiop. It mainly
 makes sure the arithmetic is correct, which can be done with exact test cases
 since unlike F_p^n classes these are fixed fields. More thorough tests are
 in test_all_fields.
 *****************************************************************************
 * @author     This file is part of libff, developed by SCIPR Lab
 *             and contributors (see AUTHORS).
 * @copyright  MIT license (see LICENSE file)
 *****************************************************************************/
#include <gtest/gtest.h>

#include "libff/algebra/fields/binary/gf32.hpp"
#include "libff/algebra/fields/binary/gf64.hpp"
#include "libff/algebra/fields/binary/gf128.hpp"
#include "libff/algebra/fields/binary/gf192.hpp"
#include "libff/algebra/fields/binary/gf256.hpp"

using namespace libff;

gf32 gf32_mul(const uint32_t &a_val, const uint32_t &b_val)
{
    return gf32(a_val) * gf32(b_val);
}

gf64 gf64_mul(const uint64_t &a_val, const uint64_t &b_val)
{
    return gf64(a_val) * gf64(b_val);
}

gf128 gf128_mul(const uint64_t &a_val_high, const uint64_t &a_val_low, const uint64_t &b_val_high, const uint64_t &b_val_low)
{
    return gf128(a_val_high, a_val_low) * gf128(b_val_high, b_val_low);
}

gf192 gf192_mul(const uint64_t &a_val_high, const uint64_t &a_val_mid, const uint64_t &a_val_low,
                const uint64_t &b_val_high, const uint64_t &b_val_mid, const uint64_t &b_val_low)
{
    return gf192(a_val_high, a_val_mid, a_val_low) * gf192(b_val_high, b_val_mid, b_val_low);
}

gf256 gf256_mul(const uint64_t &a_val_high, const uint64_t &a_val_midh,
                const uint64_t &a_val_midl, const uint64_t &a_val_low,
                const uint64_t &b_val_high, const uint64_t &b_val_midh,
                const uint64_t &b_val_midl, const uint64_t &b_val_low)
{
    return gf256(a_val_high, a_val_midh, a_val_midl, a_val_low) *
           gf256(b_val_high, b_val_midh, b_val_midl, b_val_low);
}

/* test cases generated by sage/gf32.sage script */

TEST(GF32Test, MultiplicationTest) {
    EXPECT_EQ(gf32_mul(0xec71187bLL, 0x3c2b4dc6LL), gf32(0x18a792bdLL));
    EXPECT_EQ(gf32_mul(0xe24186cdLL, 0xc7b13dc2LL), gf32(0x5d8822c4LL));
    EXPECT_EQ(gf32_mul(0x0c053421LL, 0xe357be15LL), gf32(0x9692f4d2LL));
    EXPECT_EQ(gf32_mul(0xd0d42130LL, 0x3e597e24LL), gf32(0xc7ea9d01LL));
    EXPECT_EQ(gf32_mul(0x394b1a86LL, 0x3674def5LL), gf32(0xafa1ca21LL));
    EXPECT_EQ(gf32_mul(0xaf9995cbLL, 0x4c12835bLL), gf32(0x795b61feLL));
    EXPECT_EQ(gf32_mul(0x494cccf7LL, 0x47d58182LL), gf32(0xab95d1beLL));
    EXPECT_EQ(gf32_mul(0x00f6c1e7LL, 0x1dc6cb1eLL), gf32(0x2d4bd0c9LL));
    EXPECT_EQ(gf32_mul(0x81fe4a5fLL, 0xc975aa50LL), gf32(0x6f64a32eLL));
    EXPECT_EQ(gf32_mul(0x6903f854LL, 0x701eca01LL), gf32(0xee8735bbLL));
}

TEST(GF32Test, InverseTest) {
    for (std::size_t i = 0; i < 10; i++) {
        const gf32 a = gf32::random_element();
        const gf32 a_inv = a.inverse();

        EXPECT_EQ(a*a_inv, gf32(1));
    }
}

/* test cases generated by sage/gf64.sage script */

TEST(GF64Test, MultiplicationTest) {
    EXPECT_EQ(gf64_mul(0x4c12835baf9995cbLL, 0x47d58182494cccf7LL), gf64(0xcd8d885948717796LL));
    EXPECT_EQ(gf64_mul(0x1dc6cb1e00f6c1e7LL, 0xc975aa5081fe4a5fLL), gf64(0x68a12cd69de5ba13LL));
    EXPECT_EQ(gf64_mul(0x701eca016903f854LL, 0x1bff27de896d5a63LL), gf64(0x3f2b03920fe6f850LL));
    EXPECT_EQ(gf64_mul(0x84949f71b013dafdLL, 0xc8642090f94902a6LL), gf64(0x0260be4b638467b4LL));
    EXPECT_EQ(gf64_mul(0x415405db8945dfb1LL, 0xe45f3b3b4fafbbfdLL), gf64(0xeedd9f3f9a790308LL));
    EXPECT_EQ(gf64_mul(0x4556f8aac66f427fLL, 0xb1d2219b0266de02LL), gf64(0xbdfd1cb2a183fd56LL));
    EXPECT_EQ(gf64_mul(0x3dddbcee3039f5fcLL, 0xfc9de0af7ec40b3fLL), gf64(0xab78b6d459d0d7a9LL));
    EXPECT_EQ(gf64_mul(0xc63a3ae27b186b00LL, 0x7218e0e28cba2badLL), gf64(0x7cc11d40edaf1d46LL));
    EXPECT_EQ(gf64_mul(0xbfe1ca4a7ccb135fLL, 0x6cbf9a222a7f80a7LL), gf64(0x6afbe201c18d9334LL));
    EXPECT_EQ(gf64_mul(0x38567cdad827aacfLL, 0xfa309c33b717dd13LL), gf64(0xc2db83d1400e7d58LL));
}

TEST(GF64Test, InverseTest) {
    for (std::size_t i = 0; i < 10; i++) {
        const gf64 a = gf64::random_element();
        const gf64 a_inv = a.inverse();

        EXPECT_EQ(a*a_inv, gf64(1));
    }
}
/* test cases generated by sage/gf128.sage script */

TEST(GF128Test, MultiplicationTest) {
    EXPECT_EQ(gf128_mul(0xb1d2219b0266de02LL, 0x4556f8aac66f427fLL, 0xfc9de0af7ec40b3fLL, 0x3dddbcee3039f5fcLL), gf128(0xf0b63cd2d8d9acb7LL, 0x14c9965cbb45f242LL));
    EXPECT_EQ(gf128_mul(0x7218e0e28cba2badLL, 0xc63a3ae27b186b00LL, 0x6cbf9a222a7f80a7LL, 0xbfe1ca4a7ccb135fLL), gf128(0x9a68dc276e08964aLL, 0x94cf56a81986e62fLL));
    EXPECT_EQ(gf128_mul(0xfa309c33b717dd13LL, 0x38567cdad827aacfLL, 0x8418b817f5caf84cLL, 0x3590e0c94d76b16aLL), gf128(0x0d4af0a0c7778f42LL, 0xa52cdf9b42326edcLL));
    EXPECT_EQ(gf128_mul(0xf7903a9c58e4223cLL, 0x0cdc30af062ba589LL, 0x4193e34b8241b8b6LL, 0x8d73a6d58a9833adLL), gf128(0x1aebbb2a40e6bdc5LL, 0x40b58b1663f1e7baLL));
    EXPECT_EQ(gf128_mul(0x81f59dadf3516810LL, 0x657e286088c96142LL, 0x12356e70b09e27a6LL, 0x56aa86373c498fddLL), gf128(0x6f1931b5b32adfd6LL, 0x3d0721c2dd988b1dLL));
    EXPECT_EQ(gf128_mul(0x0fe9a9f10ea6b3beLL, 0x614becf0f6981970LL, 0xf764a67447957a65LL, 0x897bb93561e04d72LL), gf128(0x7082df4ae39182f8LL, 0x29ead6ff7a231a76LL));
    EXPECT_EQ(gf128_mul(0xb6f0e7fe834a305fLL, 0x5d1bce4867374275LL, 0xf507be43450e596cLL, 0x7625671a07a1b127LL), gf128(0x7d87898bb86b9700LL, 0x288b33919644a559LL));
    EXPECT_EQ(gf128_mul(0x00a7fced16ffa59bLL, 0x7009d6ea6cbc3723LL, 0xb4dab96b1454919dLL, 0x23fad70584b9ff24LL), gf128(0x6f67249586163ab9LL, 0xbb823abc98939faeLL));
    EXPECT_EQ(gf128_mul(0x5756b56a1d208f91LL, 0xac2c97ebcf121998LL, 0x633c9cefc089eb74LL, 0x0fd73239d93bd077LL), gf128(0xb2658b016f98c47fLL, 0x9dfa616729b5e040LL));
    EXPECT_EQ(gf128_mul(0xf55ab02f9dae69b8LL, 0xc1c42adfa999b078LL, 0xfae308c406eb08feLL, 0x49bfcd0bd4d96b01LL), gf128(0xdf0f7f62ecc610e1LL, 0x9bcec94d9f08f412LL));
}

TEST(GF128Test, InverseTest) {
    const gf128 a = gf128::random_element();
    const gf128 a_inv = a.inverse();

    EXPECT_EQ(a*a_inv, gf128(1));
}

/* test cases generated by sage/gf192.sage script */

TEST(GF192Test, MultiplicationTest) {
    EXPECT_EQ(gf192_mul(0x0cdc30af062ba589LL, 0x8418b817f5caf84cLL, 0x3590e0c94d76b16aLL, 0x4193e34b8241b8b6LL, 0x8d73a6d58a9833adLL, 0xf7903a9c58e4223cLL), gf192(0xedb2d77042f07f3eLL, 0xc223197d04425354LL, 0x601e9baa99e6b2fdLL));
    EXPECT_EQ(gf192_mul(0x56aa86373c498fddLL, 0x81f59dadf3516810LL, 0x657e286088c96142LL, 0x0fe9a9f10ea6b3beLL, 0x614becf0f6981970LL, 0x12356e70b09e27a6LL), gf192(0xcf0642476758587aLL, 0x2ed578d8f170b814LL, 0x0b86792ebec24165LL));
    EXPECT_EQ(gf192_mul(0x5d1bce4867374275LL, 0xf764a67447957a65LL, 0x897bb93561e04d72LL, 0xf507be43450e596cLL, 0x7625671a07a1b127LL, 0xb6f0e7fe834a305fLL), gf192(0x2d43614daf895767LL, 0xa0d43a4a59167a19LL, 0x1d01f4493cf9f6bfLL));
    EXPECT_EQ(gf192_mul(0x23fad70584b9ff24LL, 0x00a7fced16ffa59bLL, 0x7009d6ea6cbc3723LL, 0x5756b56a1d208f91LL, 0xac2c97ebcf121998LL, 0xb4dab96b1454919dLL), gf192(0x0b31e0f4e429e2d8LL, 0x91b61a18bdb18fd4LL, 0x35ce63ac64f58838LL));
    EXPECT_EQ(gf192_mul(0xc1c42adfa999b078LL, 0x633c9cefc089eb74LL, 0x0fd73239d93bd077LL, 0xfae308c406eb08feLL, 0x49bfcd0bd4d96b01LL, 0xf55ab02f9dae69b8LL), gf192(0xecd19c6c59d10edeLL, 0x5c081d84ee58552dLL, 0x598aefe615b5a49aLL));
    EXPECT_EQ(gf192_mul(0xf2e6b1294f40ac62LL, 0x512288f4b06917d3LL, 0xd2c36d17d828d9b4LL, 0x206901073d267fa5LL, 0x9a2789bfb11c03c4LL, 0x1cf009d26ee1f80fLL), gf192(0x68fd98a8545f9688LL, 0x1e6f3c0f65f3b25dLL, 0x75fb9afdb21f1278LL));
    EXPECT_EQ(gf192_mul(0xc78b2478a98afb85LL, 0x579c25544b3ba640LL, 0x7766723a1141eddcLL, 0x1d5e8949c38296e0LL, 0x224aa1e6e025b316LL, 0x84eb9e2187501666LL), gf192(0xd33304755a3790f5LL, 0xd9f5f3be81d6054dLL, 0x742cb900f1d5bcf9LL));
    EXPECT_EQ(gf192_mul(0x75bee645ed32bf73LL, 0xfaaf7393e729adf5LL, 0xe4e8ae96b691f6d2LL, 0x94659c82eed44ed6LL, 0x0d6f1491ffab6313LL, 0x034858f4f1f7b14bLL), gf192(0x998f56abe7e4348fLL, 0xcafb5a359d76233dLL, 0x930bfcefe10d3166LL));
    EXPECT_EQ(gf192_mul(0x9ded3331f7e20e08LL, 0xae8f8592118650dfLL, 0x4105e1bce7fda1a5LL, 0x22677e786437ded8LL, 0xeab6bb9efffe16f2LL, 0xae333a6c2e525a7eLL), gf192(0x981afe97f038b8e7LL, 0x2803fd759a41f4e0LL, 0xf80ac10929fc7e3fLL));
    EXPECT_EQ(gf192_mul(0x13ee2aa2bc56bb9fLL, 0x4b28b4a78b34aed6LL, 0xc9a973387db34f3cLL, 0x5980393a96b7e262LL, 0xbee979d0d3e73491LL, 0x724efc0872e555d7LL), gf192(0xce5179b296413b74LL, 0x90b969c3def4555fLL, 0x2de0b46a441b4738LL));
}

TEST(GF192Test, InverseTest) {
    const gf192 a = gf192::random_element();
    const gf192 a_inv = a.inverse();

    EXPECT_EQ(a*a_inv, gf192(1));
}

/* test cases generated by sage/gf256.sage script */

TEST(GF256Test, MultiplicationTest) {
    EXPECT_EQ(gf256_mul(0xf764a67447957a65LL, 0x897bb93561e04d72LL, 0x0fe9a9f10ea6b3beLL, 0x614becf0f6981970LL, 0xf507be43450e596cLL, 0x7625671a07a1b127LL, 0xb6f0e7fe834a305fLL, 0x5d1bce4867374275LL), gf256(0x7830000656b147bbLL, 0x84aedc89d9eef7d5LL, 0x206521a58a74c76dLL, 0x15b45070f9272694LL));
    EXPECT_EQ(gf256_mul(0xb4dab96b1454919dLL, 0x23fad70584b9ff24LL, 0x00a7fced16ffa59bLL, 0x7009d6ea6cbc3723LL, 0x633c9cefc089eb74LL, 0x0fd73239d93bd077LL, 0x5756b56a1d208f91LL, 0xac2c97ebcf121998LL), gf256(0xec433aa096b7c5a3LL, 0xb988c6486912b0ffLL, 0xf4974416b3ec0351LL, 0xa0abd7439b4a90b4LL));
    EXPECT_EQ(gf256_mul(0xfae308c406eb08feLL, 0x49bfcd0bd4d96b01LL, 0xf55ab02f9dae69b8LL, 0xc1c42adfa999b078LL, 0x1cf009d26ee1f80fLL, 0xf2e6b1294f40ac62LL, 0x512288f4b06917d3LL, 0xd2c36d17d828d9b4LL), gf256(0xd4c9b1f1b6032f4aLL, 0x5a443906b0fd92f4LL, 0x069ef58da6005ef0LL, 0x81149bf7a2a4e9efLL));
    EXPECT_EQ(gf256_mul(0x579c25544b3ba640LL, 0x7766723a1141eddcLL, 0x206901073d267fa5LL, 0x9a2789bfb11c03c4LL, 0x1d5e8949c38296e0LL, 0x224aa1e6e025b316LL, 0x84eb9e2187501666LL, 0xc78b2478a98afb85LL), gf256(0xc92ed4a7f831b22eLL, 0x42d345a89b213da0LL, 0x6ca9b1401b327636LL, 0x81a1d4e28ecb3203LL));
    EXPECT_EQ(gf256_mul(0x034858f4f1f7b14bLL, 0x75bee645ed32bf73LL, 0xfaaf7393e729adf5LL, 0xe4e8ae96b691f6d2LL, 0xae8f8592118650dfLL, 0x4105e1bce7fda1a5LL, 0x94659c82eed44ed6LL, 0x0d6f1491ffab6313LL), gf256(0x3c58c4917b50380aLL, 0x155a26d3e04dc3f9LL, 0x0ece08a653d5d785LL, 0xa0491208d489ad20LL));
    EXPECT_EQ(gf256_mul(0x22677e786437ded8LL, 0xeab6bb9efffe16f2LL, 0xae333a6c2e525a7eLL, 0x9ded3331f7e20e08LL, 0x724efc0872e555d7LL, 0x13ee2aa2bc56bb9fLL, 0x4b28b4a78b34aed6LL, 0xc9a973387db34f3cLL), gf256(0x31c713050f9fe79fLL, 0x91f3134564072e28LL, 0xbd3b97df5ceaa321LL, 0x85ae031df2087301LL));
    EXPECT_EQ(gf256_mul(0xe103fdd38559f718LL, 0xbde830a033005e9dLL, 0x5980393a96b7e262LL, 0xbee979d0d3e73491LL, 0x24d79165090b54bbLL, 0x6be4979855b9f4a1LL, 0x3c84f51267ae0f3eLL, 0x49762387dc75fbcfLL), gf256(0xaf3c148f5a6d62b6LL, 0xcb2caa9c1491eb09LL, 0x9d964ce7c25f9cc4LL, 0xf0774bdc5efd321bLL));
    EXPECT_EQ(gf256_mul(0xc8d362a82d40e33dLL, 0x7ebb79ea0539aab6LL, 0xd4cb229a76bbfdf8LL, 0xe1ed007e6b4d18c4LL, 0xc5ff42586ffe84beLL, 0x2fa0d6324909d6bcLL, 0xd059de8a3f216806LL, 0x11ce6283a327c2aeLL), gf256(0x6d8f5131a50a1174LL, 0x3716b1b7b85aa29fLL, 0x786f09fc7add372aLL, 0xd9be899417749c66LL));
    EXPECT_EQ(gf256_mul(0xa34a5c6dc2269e92LL, 0xd4926e0f5173ba59LL, 0xad04af41cefd288cLL, 0xd6910fac0958e021LL, 0xb8efe59559134148LL, 0xe2df550b05c8346bLL, 0x471c649050d8df10LL, 0x3c4ddb6e1d7bdf2bLL), gf256(0x31bc02040d35ef67LL, 0xf4df56b7f489a233LL, 0x94a98345cd1c505eLL, 0x9b8880399d5b6f17LL));
    EXPECT_EQ(gf256_mul(0x0dd2d419a879877eLL, 0xbbd7c0e1cb89df45LL, 0xb920792cb175a788LL, 0xfe328eb0319d0dd7LL, 0xfdd10984711604a6LL, 0x449e2950c151d1f4LL, 0x06b95b1542038a8aLL, 0xbbc51592da56e2feLL), gf256(0x5eac8a0dfe585d7dLL, 0x8bb81c1be4902348LL, 0xb441d39d98693d34LL, 0x480e988c351ac9f3LL));
}

TEST(GF256Test, InverseTest) {
    const gf256 a = gf256::random_element();
    const gf256 a_inv = a.inverse();

    EXPECT_EQ(a*a_inv, gf256(1));
}