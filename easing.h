#include<Novice.h>
#define _USE_MATH_DEFINES
#include <math.h>
namespace Easing {

	float easeOutQuad(float t) {

		return 1.0f - (1.0f - t) * (1.0f - t);
	}

	float easeInQuad(float t) {

		return t * t;
	}

	float easeInOutQuart(float t) {
		return t < 0.5 ? 8 * t * t * t * t : 1 - (float)pow(-2 * t + 2, 4) / 2;
	}


	float easeInQuart(float t) {

		return t * t * t * t;
	}
}