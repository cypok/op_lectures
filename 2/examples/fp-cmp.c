// Author: Michael Borgwardt, http://floating-point-gui.de
// Version for C: Vladimir Parfinenko.

#include <math.h>
#include <float.h>
#include <stdbool.h>

bool nearlyEqual(float a, float b, float relError) {
    float diff = fabs(a - b);

    if (a == b) {
        // shortcut, handles infinities
        return true;
    } else if (a == 0 || b == 0 || diff < FLT_MIN) {
        // a or b is zero or both are extremely close to it
        // relative error is less meaningful here
        return diff < (relError * FLT_MIN);
    } else {
        // use relative error
        float sum = fmin(fabs(a) + fabs(b), FLT_MAX);
        return diff / sum < relError;
    }
}

// TESTS:

#include <assert.h>

#define FLT_MIN_DENORM 1.4e-45f
#define FLT_NAN (0.0f/0.0f)
#define FLT_POSITIVE_INFINITY (1.0f/0.0f)
#define FLT_NEGATIVE_INFINITY (-FLT_POSITIVE_INFINITY)

static bool nearlyEqual2(float a, float b) {
    return nearlyEqual(a, b, 0.00001f);
}

// Regular large numbers - generally not problematic.
static void big() {
    assert(nearlyEqual2(1000000.0f, 1000001.0f));
    assert(nearlyEqual2(1000001.0f, 1000000.0f));
    assert(!nearlyEqual2(10000.0f, 10001.0f));
    assert(!nearlyEqual2(10001.0f, 10000.0f));
}

// Negative large numbers.
static void bigNeg() {
    assert(nearlyEqual2(-1000000.0f, -1000001.0f));
    assert(nearlyEqual2(-1000001.0f, -1000000.0f));
    assert(!nearlyEqual2(-10000.0f, -10001.0f));
    assert(!nearlyEqual2(-10001.0f, -10000.0f));
}

// Numbers around 1.
static void mid() {
    assert(nearlyEqual2(1.0000001f, 1.0000002f));
    assert(nearlyEqual2(1.0000002f, 1.0000001f));
    assert(!nearlyEqual2(1.0002f, 1.0001f));
    assert(!nearlyEqual2(1.0001f, 1.0002f));
}

// Numbers around -1.
static void midNeg() {
    assert(nearlyEqual2(-1.000001f, -1.000002f));
    assert(nearlyEqual2(-1.000002f, -1.000001f));
    assert(!nearlyEqual2(-1.0001f, -1.0002f));
    assert(!nearlyEqual2(-1.0002f, -1.0001f));
}

// Numbers between 1 and 0.
static void small() {
    assert(nearlyEqual2(0.000000001000001f, 0.000000001000002f));
    assert(nearlyEqual2(0.000000001000002f, 0.000000001000001f));
    assert(!nearlyEqual2(0.000000000001002f, 0.000000000001001f));
    assert(!nearlyEqual2(0.000000000001001f, 0.000000000001002f));
}

// Numbers between -1 and 0.
static void smallNeg() {
    assert(nearlyEqual2(-0.000000001000001f, -0.000000001000002f));
    assert(nearlyEqual2(-0.000000001000002f, -0.000000001000001f));
    assert(!nearlyEqual2(-0.000000000001002f, -0.000000000001001f));
    assert(!nearlyEqual2(-0.000000000001001f, -0.000000000001002f));
}

// Comparisons involving zero.
static void zero() {
    assert(nearlyEqual2(0.0f, 0.0f));
    assert(nearlyEqual2(0.0f, -0.0f));
    assert(nearlyEqual2(-0.0f, -0.0f));
    assert(!nearlyEqual2(0.00000001f, 0.0f));
    assert(!nearlyEqual2(0.0f, 0.00000001f));
    assert(!nearlyEqual2(-0.00000001f, 0.0f));
    assert(!nearlyEqual2(0.0f, -0.00000001f));

    assert(nearlyEqual(0.0f, 1e-40f, 0.01f));
    assert(nearlyEqual(1e-40f, 0.0f, 0.01f));
    assert(!nearlyEqual(1e-40f, 0.0f, 0.000001f));
    assert(!nearlyEqual(0.0f, 1e-40f, 0.000001f));

    assert(nearlyEqual(0.0f, -1e-40f, 0.1f));
    assert(nearlyEqual(-1e-40f, 0.0f, 0.1f));
    assert(!nearlyEqual(-1e-40f, 0.0f, 0.00000001f));
    assert(!nearlyEqual(0.0f, -1e-40f, 0.00000001f));
}

// Comparisons involving extreme values (overflow potential).
static void extremeMax() {
    assert(nearlyEqual2(FLT_MAX, FLT_MAX));
    assert(!nearlyEqual2(FLT_MAX, -FLT_MAX));
    assert(!nearlyEqual2(-FLT_MAX, FLT_MAX));
    assert(!nearlyEqual2(FLT_MAX, FLT_MAX / 2));
    assert(!nearlyEqual2(FLT_MAX, -FLT_MAX / 2));
    assert(!nearlyEqual2(-FLT_MAX, FLT_MAX / 2));
}

// Comparisons involving infinities.
static void infinities() {
    assert(nearlyEqual2(FLT_POSITIVE_INFINITY, FLT_POSITIVE_INFINITY));
    assert(nearlyEqual2(FLT_NEGATIVE_INFINITY, FLT_NEGATIVE_INFINITY));
    assert(!nearlyEqual2(FLT_NEGATIVE_INFINITY, FLT_POSITIVE_INFINITY));
    assert(!nearlyEqual2(FLT_POSITIVE_INFINITY, FLT_MAX));
    assert(!nearlyEqual2(FLT_NEGATIVE_INFINITY, -FLT_MAX));
}

// Comparisons involving NaN values.
static void nans() {
    assert(!nearlyEqual2(FLT_NAN, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, 0.0f));
    assert(!nearlyEqual2(-0.0f, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, -0.0f));
    assert(!nearlyEqual2(0.0f, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, FLT_POSITIVE_INFINITY));
    assert(!nearlyEqual2(FLT_POSITIVE_INFINITY, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, FLT_NEGATIVE_INFINITY));
    assert(!nearlyEqual2(FLT_NEGATIVE_INFINITY, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, FLT_MAX));
    assert(!nearlyEqual2(FLT_MAX, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, -FLT_MAX));
    assert(!nearlyEqual2(-FLT_MAX, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, FLT_MIN));
    assert(!nearlyEqual2(FLT_MIN, FLT_NAN));
    assert(!nearlyEqual2(FLT_NAN, -FLT_MIN));
    assert(!nearlyEqual2(-FLT_MIN, FLT_NAN));
}

// Comparisons of numbers on opposite sides of 0.
static void opposite() {
    assert(!nearlyEqual2(1.000000001f, -1.0f));
    assert(!nearlyEqual2(-1.0f, 1.000000001f));
    assert(!nearlyEqual2(-1.000000001f, 1.0f));
    assert(!nearlyEqual2(1.0f, -1.000000001f));
    assert(nearlyEqual2(10 * FLT_MIN_DENORM, 10 * -FLT_MIN_DENORM));
    assert(!nearlyEqual2(10000 * FLT_MIN_DENORM, 10000 * -FLT_MIN_DENORM));
}

// The really tricky part - comparisons of numbers very close to zero.
static void ulp() {
    assert(nearlyEqual2(FLT_MIN_DENORM, FLT_MIN_DENORM));
    assert(nearlyEqual2(FLT_MIN_DENORM, -FLT_MIN_DENORM));
    assert(nearlyEqual2(-FLT_MIN_DENORM, FLT_MIN_DENORM));
    assert(nearlyEqual2(FLT_MIN_DENORM, 0));
    assert(nearlyEqual2(0, FLT_MIN_DENORM));
    assert(nearlyEqual2(-FLT_MIN_DENORM, 0));
    assert(nearlyEqual2(0, -FLT_MIN_DENORM));

    assert(!nearlyEqual2(0.000000001f, -FLT_MIN_DENORM));
    assert(!nearlyEqual2(0.000000001f, FLT_MIN_DENORM));
    assert(!nearlyEqual2(FLT_MIN_DENORM, 0.000000001f));
    assert(!nearlyEqual2(-FLT_MIN_DENORM, 0.000000001f));
}

int main() {
    big();
    bigNeg();
    mid();
    midNeg();
    small();
    smallNeg();
    zero();
    extremeMax();
    infinities();
    nans();
    opposite();
    ulp();
    return 0;
}
