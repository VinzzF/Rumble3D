#pragma once
#include <cmath>
#include <limits>


#define R3D_PRECISION_LEVEL_LOW 0
#define R3D_PRECISION_LEVEL_MED 1
#define R3D_PRECISION_LEVEL_HIGH 2


/************************************************************************/
// Edit here
/************************************************************************/
#define R3D_CURRENT_PRECISION_LEVEL R3D_PRECISION_LEVEL_LOW
//#define R3D_DLL_EXPORT
//#define R3D_DLL_IMPORT


namespace r3
{
	/* float */
	#if ((R3D_CURRENT_PRECISION_LEVEL) == R3D_PRECISION_LEVEL_LOW)
	using real = float;

	#define R3D_REAL_MIN					FLT_MIN
	#define R3D_REAL_MAX					FLT_MAX

	#define R3D_REAL_PRECISION_DECIMAL_DIG	FLT_DECIMAL_DIG
	#define R3D_REAL_PRECISION_DIG			FLT_DIG
	#define R3D_REAL_MANT_DIG				FLT_MANT_DIG

	#define R3D_REAL_EPSILON				FLT_EPSILON
	#define R3D_REAL_MAX_10_EXP				FLT_MAX_10_EXP
	#define R3D_REAL_MAX_EXP				FLT_MAX_EXP
	#define R3D_REAL_MIN_10_EXP				FLT_MIN_10_EXP
	#define R3D_REAL_MIN_EXP				FLT_MIN_EXP
	#define R3D_REAL_MIN_POS_VALUE			FLT_TRUE_MIN	

	// GLM
	/*#define GLM_PRECISION_MEDIUMP_FLOAT
	#define GLM_PRECISION_MEDIUMP_DOUBLE
	#define GLM_PRECISION_MEDIUMP_INT
	#define GLM_PRECISION_MEDIUMP_UINT*/

	/* double */
	#elif ((R3D_CURRENT_PRECISION_LEVEL) == R3D_PRECISION_LEVEL_LOW)
	using real = double;

	#define R3D_REAL_MIN					DBL_MIN
	#define R3D_REAL_MAX					DBL_MAX

	#define R3D_REAL_PRECISION_DECIMAL_DIG	DBL_DECIMAL_DIG
	#define R3D_REAL_PRECISION_DIG			DBL_DIG
	#define R3D_REAL_MANT_DIG				DBL_MANT_DIG

	#define R3D_REAL_EPSILON				DBL_EPSILON
	#define R3D_REAL_MAX_10_EXP				DBL_MAX_10_EXP
	#define R3D_REAL_MAX_EXP				DBL_MAX_EXP
	#define R3D_REAL_MIN_10_EXP				DBL_MIN_10_EXP
	#define R3D_REAL_MIN_EXP				DBL_MIN_EXP
	#define R3D_REAL_MIN_POS_VALUE			DBL_TRUE_MIN

	// GLM
	#define GLM_PRECISION_MEDIUMP_FLOAT
	#define GLM_PRECISION_MEDIUMP_DOUBLE
	#define GLM_PRECISION_MEDIUMP_INT
	#define GLM_PRECISION_MEDIUMP_UINT



	/* long double */
	#else
	using real = long double;

	#define R3D_REAL_MIN					LDBL_MIN
	#define R3D_REAL_MAX					LDBL_MAX

	#define R3D_REAL_PRECISION_DECIMAL_DIG	LDBL_DIG
	#define R3D_REAL_PRECISION_DIG			LDBL_DIG
	#define R3D_REAL_MANT_DIG				LDBL_MANT_DIG

	#define R3D_REAL_EPSILON				LDBL_EPSILON
	#define R3D_REAL_MAX_10_EXP				LDBL_MAX_10_EXP
	#define R3D_REAL_MAX_EXP				LDBL_MAX_EXP
	#define R3D_REAL_MIN_10_EXP				LDBL_MIN_10_EXP
	#define R3D_REAL_MIN_EXP				LDBL_MIN_EXP
	#define R3D_REAL_MIN_POS_VALUE			LDBL_TRUE_MIN

	// GLM
	#define GLM_PRECISION_HIGHP_FLOAT
	#define GLM_PRECISION_HIGHP_DOUBLE
	#define GLM_PRECISION_HIGHP_INT
	#define GLM_PRECISION_HIGHP_UINT

	#endif // __PRECISION_LEVEL_EROS__
}