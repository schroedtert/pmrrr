/**
	C++ template version of LAPACK routine dlaset.
	Based on C code translated by f2c (version 20061008).
*/

#ifndef __ODSET_HPP__
#define __ODSET_HPP__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <float.h>
#include <assert.h>

#define imin(a,b) ( (a) < (b) ? (a) : (b) )

namespace pmrrr { namespace lapack {

	/* Subroutine */ 
	template<typename FloatingType>
	int odset(char *uplo, int *m, int *n, FloatingType *alpha, 
	FloatingType *beta, FloatingType *a, int *lda)
	{
		/* System generated locals */
		int a_dim1, a_offset, i__1, i__2, i__3;

		/* Local variables */
		int i__, j;
		//extern int olsame_(char *, char *);


	/*  -- LAPACK auxiliary routine (version 3.2) -- */
	/*     Univ. of Tennessee, Univ. of California Berkeley and NAG Ltd.. */
	/*     November 2006 */

	/*     .. Scalar Arguments .. */
	/*     .. */
	/*     .. Array Arguments .. */
	/*     .. */

	/*  Purpose */
	/*  ======= */

	/*  ODSET initializes an m-by-n matrix A to BETA on the diagonal and */
	/*  ALPHA on the offdiagonals. */

	/*  Arguments */
	/*  ========= */

	/*  UPLO    (input) CHARACTER*1 */
	/*          Specifies the part of the matrix A to be set. */
	/*          = 'U':      Upper triangular part is set; the strictly lower */
	/*                      triangular part of A is not changed. */
	/*          = 'L':      Lower triangular part is set; the strictly upper */
	/*                      triangular part of A is not changed. */
	/*          Otherwise:  All of the matrix A is set. */

	/*  M       (input) INT */
	/*          The number of rows of the matrix A.  M >= 0. */

	/*  N       (input) INT */
	/*          The number of columns of the matrix A.  N >= 0. */

	/*  ALPHA   (input) DOUBLE PRECISION */
	/*          The constant to which the offdiagonal elements are to be set. */

	/*  BETA    (input) DOUBLE PRECISION */
	/*          The constant to which the diagonal elements are to be set. */

	/*  A       (input/output) DOUBLE PRECISION array, dimension (LDA,N) */
	/*          On exit, the leading m-by-n submatrix of A is set as follows: */

	/*          if UPLO = 'U', A(i,j) = ALPHA, 1<=i<=j-1, 1<=j<=n, */
	/*          if UPLO = 'L', A(i,j) = ALPHA, j+1<=i<=m, 1<=j<=n, */
	/*          otherwise,     A(i,j) = ALPHA, 1<=i<=m, 1<=j<=n, i.ne.j, */

	/*          and, for all UPLO, A(i,i) = BETA, 1<=i<=min(m,n). */

	/*  LDA     (input) INT */
	/*          The leading dimension of the array A.  LDA >= max(1,M). */

	/* ===================================================================== */

	/*     .. Local Scalars .. */
	/*     .. */
	/*     .. External Functions .. */
	/*     .. */
	/*     .. Intrinsic Functions .. */
	/*     .. */
	/*     .. Executable Statements .. */

		/* Parameter adjustments */
		a_dim1 = *lda;
		a_offset = 1 + a_dim1;
		a -= a_offset;

		/* Function Body */
		if (olsame_(uplo, "U")) {

	/*        Set the strictly upper triangular or trapezoidal part of the */
	/*        array to ALPHA. */

		i__1 = *n;
		for (j = 2; j <= i__1; ++j) {
	/* Computing MIN */
			i__3 = j - 1;
			i__2 = imin(i__3,*m);
			for (i__ = 1; i__ <= i__2; ++i__) {
			a[i__ + j * a_dim1] = *alpha;
	/* L10: */
			}
	/* L20: */
		}

		} else if (olsame_(uplo, "L")) {

	/*        Set the strictly lower triangular or trapezoidal part of the */
	/*        array to ALPHA. */

		i__1 = imin(*m,*n);
		for (j = 1; j <= i__1; ++j) {
			i__2 = *m;
			for (i__ = j + 1; i__ <= i__2; ++i__) {
			a[i__ + j * a_dim1] = *alpha;
	/* L30: */
			}
	/* L40: */
		}

		} else {

	/*        Set the leading m-by-n submatrix to ALPHA. */

		i__1 = *n;
		for (j = 1; j <= i__1; ++j) {
			i__2 = *m;
			for (i__ = 1; i__ <= i__2; ++i__) {
			a[i__ + j * a_dim1] = *alpha;
	/* L50: */
			}
	/* L60: */
		}
		}

	/*     Set the first imin(M,N) diagonal elements to BETA. */

		i__1 = imin(*m,*n);
		for (i__ = 1; i__ <= i__1; ++i__) {
		a[i__ + i__ * a_dim1] = *beta;
	/* L70: */
		}

		return 0;

	/*     End of ODSET */

	} /* odset_ */

}

}

#endif
