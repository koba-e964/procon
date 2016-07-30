/**
 * ---==== Counting the Number of 12-Cycles in an undirected bipartite Graph  ====---
 *
 * AUTHORS: Anton N. Voropaev 
 * ```````  Artem M. Karavaev ( http://www.flowproblem.ru )
 *      
 * CREATED: 25.11.2009     
 * ```````     
 * VERSION: 6.0 ( from 18.03.2010 )     
 * ```````
 */

#define VERSION "6.0"

#define N 128   // The maximum number of vertices ( YOU MAY CHANGE IT )
#define K 12    // The length of the cycles ( DO NOT CHANGE )

#include "Int128.h"
using namespace Zeal;

typedef Int128 TAnswer;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n, m;
FILE * in, * out = stdout;

int A1 [ N ] [ N ];
int A2 [ N ] [ N ];
int A3 [ N ] [ N ];
int A4 [ N ] [ N ];
TAnswer A [ K ] [ N ] [ N ];

TAnswer c12b ( );

// Multiply A * B. A contains only 0 and 1.
void MulMatrix ( int A [ N ] [ N ], int B [ N ] [ N ], int C [ N ] [ N ] ) {
	int i, j, r;
	for ( i = 0; i < n; i ++ )		
		for ( r = 0; r < n; r ++ )
			if ( A [ i ] [ r ] )
				for ( j = 0; j < n; j ++ )
					C [ i ] [ j ] += B [ r ] [ j ];
}
// The same function but for Int128
void MulMatrix ( int A [ N ] [ N ], TAnswer B [ N ] [ N ], TAnswer C [ N ] [ N ] ) {
	int i, j, r;
	for ( i = 0; i < n; i ++ )		
		for ( r = 0; r < n; r ++ )
			if ( A [ i ] [ r ] )
				for ( j = 0; j < n; j ++ )
					C [ i ] [ j ] += B [ r ] [ j ];
}

void Init ( ) {
	int i, p, q;

	fscanf ( in, "%d %d", &n, &m );  	  
	if ( n > N ) {
	  fprintf ( stderr, "n is too big (%d), make constant `N' bigger\n", n );
		exit ( 1 );
	}
  for ( i = 0; i < m; i ++ ) {
  	fscanf ( in, "%d %d", &p, &q );
  	A1 [ p - 1 ] [ q - 1 ] = 1;
  	A1 [ q - 1 ] [ p - 1 ] = 1;
  	A [ 0 ] [ p - 1 ] [ q - 1 ] = 1;
  	A [ 0 ] [ q - 1 ] [ p - 1 ] = 1;
  } 		
	
	MulMatrix ( A1, A1, A2 );
	MulMatrix ( A1, A2, A3 );
	MulMatrix ( A1, A3, A4 );
	for ( i = 1; i < K; i ++ ) 
		MulMatrix ( A1, A [ i - 1 ], A [ i ] );
}

int main ( int argc, char * argv [ ] ) {

	int i;

	if ( argc < 2 ) {
  	fprintf ( stderr, "Usage: %s ``input-file'' [ ``output-file'' ]\n", argv [ 0 ] );
  	return 0;
	}
	if ( argc > 3 ) {
  	fprintf ( stderr, "Too many parameters: %d\n", argc );
  	return 1;
	}
      
	if ( ( in = fopen ( argv [ 1 ], "r" ) ) == NULL ) {
		fprintf ( stderr, "Cannot open file %s for reading\n", argv [ 1 ] );
		return 1;
	}  
	if ( argc == 3 && ( out = fopen ( argv [ 2 ], "w" ) ) == NULL ) {
		fprintf ( stderr, "Cannot open file %s for writing\n", argv [ 2 ] );
		return 1;
	} 

	Init ( );

	c12b ( ) . print ( out );

	return 0;
}

TAnswer c12b ( ) { 
		TAnswer s, t; int i1, i2, i3, i4, i5, i6; s = 0;

	int i, m = n * n;

		int64u t1  = 0, t2  = 0, t3  = 0, t4  = 0, t5  = 0, t6  = 0, t7  = 0, t8  = 0, t9  = 0, t10 = 0,
	       t11 = 0, t12 = 0, t13 = 0, t14 = 0, t15 = 0, t16 = 0, t17 = 0, t18 = 0, t19 = 0, t20 = 0,
	       t21 = 0, t22 = 0, t23 = 0, t24 = 0, t25 = 0, t26 = 0, t27 = 0, t28 = 0, t29 = 0, t30 = 0,
	       t31 = 0, t32 = 0, t33 = 0, t34 = 0, t35 = 0, t36 = 0, t37 = 0, t38 = 0, t39 = 0, t40 = 0,
	       t41 = 0, t42 = 0, t43 = 0, t44 = 0, t45 = 0, t46 = 0, t47 = 0, t48 = 0, t49 = 0, t50 = 0,
	       t51 = 0, t52 = 0, t53 = 0, t54 = 0, t55 = 0, t56 = 0, t57 = 0, t58 = 0, t59 = 0;


	for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;
		if ( A1[i1][i2] )
			for(i3 = 0; i3 < n; i3++)   
				if ( A1[i1][i3] )
				for(i4 = 0; i4 < n; i4++)   
					if ( A1[i2][i4] && A1[i3][i4] )
					for(i5 = 0; i5 < n; i5++)   
						if ( A1[i2][i5] && A1[i3][i5] )
						for(i6 = 0; i6 < n; i6++) {
							t1 += ( A1[i4][i6]&A1[i5][i6]&A1[i1][i6] );
						}
	}

	s += TAnswer ( t1 ) * 82;

	t1 = 0;

	for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;
		if (A1[i1][i2] )
			for(i3 = 0; i3 < n; i3++)  
				if (A1[i1][i3] )
				for(i4 = 0; i4 < n; i4++)  
					if ( A1[i2][i4] && A1[i3][i4] )
					for(i5 = 0; i5 < n; i5++) { 
						t1 += (A2[i2][i3]*A2[i5][i5])*(A1[i4][i5]&A1[i1][i5]);
						t2 += (A2[i1][i5]*A2[i4][i5])*(A1[i3][i5]&A1[i2][i5]);
					}
	}

  s += TAnswer ( t1 ) * (-132);
  s += TAnswer ( t2 ) * (-360);

  for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;
			for(i3 = 0; i3 < n; i3++) { 
				for(i4 = 0; i4 < n; i4++) { 
s += -8 * A[1][i1][i2]*A[1][i2][i4]*A[1][i2][i3];
s += 12 * A[1][i3][i4]*A[2][i2][i3]*A[0][i2][i3]*A[1][i1][i2];
s += 6 * A[1][i3][i4]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i2];
s += 12 * A[0][i2][i3]*A[1][i1][i2]*A[1][i3][i4]*A[1][i3][i4]*A[1][i3][i4]*A[0][i2][i4];
}}}

  for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;
		if ( A1[i1][i2] )
			for(i3 = 0; i3 < n; i3++) { 
				for(i4 = 0; i4 < n; i4++) { 
s += 4758 * A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i3]*A[0][i2][i4]*A[0][i3][i4]*A[1][i1][i4];
s += -216 * A[1][i1][i1]*A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i3]*A[1][i4][i4]*A[0][i3][i4]*A[0][i2][i4];
s += -144 * A[0][i1][i4]*A[0][i1][i2]*A[1][i1][i3]*A[1][i2][i4]*A[1][i2][i4];
s += -376 * A[0][i1][i3]*A[0][i1][i2]*A[1][i3][i4]*A[0][i1][i4]*A[1][i2][i3]*A[1][i2][i4];
s += -1056 * A[0][i1][i2]*A[0][i1][i3]*A[0][i3][i4]*A[1][i1][i1]*A[0][i2][i4]*A[1][i2][i3]*A[1][i1][i4];
s += -708 * A[0][i1][i3]*A[0][i1][i2]*A[0][i3][i4]*A[1][i2][i3]*A[1][i1][i4]*A[1][i1][i4]*A[0][i2][i4];
s += 3 * A[0][i1][i2]*A[0][i1][i4]*A[1][i4][i4]*A[1][i2][i2]*A[0][i2][i3]*A[1][i1][i1]*A[1][i3][i3]*A[0][i3][i4];
s += 24 * A[0][i1][i2]*A[1][i2][i2]*A[0][i2][i3]*A[1][i1][i1]*A[1][i3][i4]*A[1][i1][i3];
s += 12 * A[0][i1][i2]*A[1][i2][i3]*A[0][i2][i4]*A[1][i4][i4]*A[1][i1][i1]*A[1][i1][i4];
s += 36 * A[0][i1][i2]*A[2][i1][i2]*A[0][i1][i4]*A[1][i4][i4]*A[0][i2][i3]*A[1][i3][i3]*A[0][i3][i4];
s += 72 * A[0][i1][i2]*A[2][i1][i2]*A[0][i2][i3]*A[1][i3][i4]*A[1][i1][i3];
s += 36 * A[0][i1][i3]*A[0][i1][i2]*A[1][i3][i3]*A[0][i2][i4]*A[1][i4][i4]*A[1][i2][i3]*A[1][i1][i4];
s += 36 * A[0][i1][i3]*A[0][i1][i2]*A[0][i1][i4]*A[1][i4][i4]*A[1][i2][i4]*A[1][i3][i3]*A[1][i2][i3];
s += 132 * A[0][i3][i4]*A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[0][i2][i4]*A[3][i1][i4];
s += 96 * A[0][i1][i3]*A[0][i1][i2]*A[0][i3][i4]*A[1][i4][i4]*A[1][i1][i4]*A[1][i2][i3]*A[1][i2][i3];
s += 96 * A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i4]*A[1][i4][i4]*A[1][i3][i4];
s += 114 * A[2][i1][i3]*A[0][i3][i4]*A[0][i1][i3]*A[0][i1][i2]*A[2][i2][i4]*A[0][i2][i4];
s += 192 * A[2][i1][i3]*A[0][i1][i3]*A[0][i1][i2]*A[1][i4][i4]*A[0][i2][i4]*A[1][i2][i3]*A[0][i3][i4];
s += 132 * A[0][i1][i3]*A[0][i1][i2]*A[0][i3][i4]*A[1][i1][i4]*A[1][i2][i3]*A[2][i2][i4];
s += 15 * A[0][i1][i2]*A[1][i2][i4]*A[1][i2][i4]*A[1][i1][i3]*A[1][i1][i3]*A[0][i3][i4];
s += 18 * A[1][i1][i1]*A[0][i1][i2]*A[0][i1][i3]*A[0][i2][i4]*A[1][i4][i4]*A[1][i2][i3]*A[1][i2][i3]*A[0][i3][i4];
s += 264 * A[0][i3][i4]*A[0][i1][i3]*A[0][i1][i2]*A[2][i3][i4]*A[1][i1][i4]*A[1][i2][i3]*A[0][i2][i4];
s += 132 * A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i4]*A[1][i2][i3]*A[1][i3][i4]*A[1][i3][i4]*A[0][i1][i4];
s += 33 * A[0][i1][i4]*A[0][i1][i2]*A[1][i2][i4]*A[1][i2][i4]*A[1][i1][i3]*A[1][i1][i3]*A[0][i2][i3]*A[0][i3][i4];
}}}


	for ( i = 0; i < m; i ++ ) { 
		i1 = i / n;
		i2 = i - i1 * n;
			for(i3 = 0; i3 < n; i3++) { 
s += 1068 * A[1][i1][i1]*A[1][i1][i3]*A[1][i1][i2];
s += 7680 * A[0][i1][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3];
s += -108 * A[1][i1][i3]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -96 * A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -48 * A[2][i1][i3]*A[1][i1][i1]*A[1][i1][i2];
s += -552 * A[1][i1][i1]*A[0][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[1][i2][i2]*A[1][i1][i3];
s += -888 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[1][i2][i3];
s += -336 * A[1][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i3][i3];
s += -528 * A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i1]*A[1][i1][i1];
s += -3600 * A[0][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[1][i1][i3]*A[2][i1][i2];
s += -1152 * A[1][i1][i1]*A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i2]*A[1][i2][i3]*A[1][i2][i3];
s += -192 * A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[1][i1][i3];
s += -5568 * A[2][i1][i3]*A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3];
s += -696 * A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[0][i1][i2]*A[1][i1][i1];
s += 48 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[1][i3][i3]*A[1][i1][i3]*A[1][i2][i2]*A[0][i2][i3];
s += 24 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i3]*A[1][i3][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i2];
s += 48 * A[1][i1][i1]*A[1][i1][i1]*A[2][i1][i2]*A[1][i2][i3]*A[0][i1][i2];
s += 48 * A[1][i1][i1]*A[1][i1][i1]*A[2][i2][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i3][i3];
s += 24 * A[1][i1][i1]*A[1][i1][i1]*A[1][i3][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3];
s += 24 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i3];
s += 96 * A[1][i3][i3]*A[1][i1][i2]*A[0][i1][i3]*A[2][i1][i3]*A[1][i1][i1];
s += 48 * A[1][i1][i2]*A[3][i3][i3]*A[0][i1][i3]*A[1][i1][i1];
s += 48 * A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[1][i3][i3]*A[1][i1][i1];
s += 24 * A[3][i2][i2]*A[1][i2][i3]*A[1][i1][i2];
s += 24 * A[2][i1][i2]*A[0][i1][i2]*A[2][i2][i3]*A[1][i1][i1];
s += 12 * A[1][i2][i3]*A[1][i2][i3]*A[2][i1][i2]*A[1][i3][i3];
s += 240 * A[0][i1][i2]*A[0][i1][i3]*A[1][i1][i1]*A[1][i2][i3]*A[3][i2][i3];
s += 288 * A[0][i1][i2]*A[2][i1][i2]*A[0][i2][i3]*A[1][i3][i3]*A[1][i1][i1]*A[1][i1][i3];
s += 288 * A[0][i1][i2]*A[2][i1][i2]*A[0][i1][i3]*A[1][i3][i3]*A[1][i2][i3]*A[1][i1][i1];
s += 144 * A[1][i1][i1]*A[1][i1][i1]*A[2][i2][i3]*A[0][i1][i2]*A[0][i2][i3]*A[1][i1][i3];
s += 144 * A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[1][i1][i3];
s += 96 * A[1][i1][i2]*A[1][i1][i2]*A[2][i2][i3]*A[0][i1][i3]*A[1][i3][i3];
s += 48 * A[1][i2][i3]*A[1][i1][i3]*A[1][i1][i2]*A[1][i1][i2]*A[1][i3][i3];
s += 552 * A[2][i1][i3]*A[0][i1][i3]*A[0][i1][i2]*A[2][i1][i2]*A[1][i2][i3];
s += 384 * A[1][i1][i1]*A[2][i1][i3]*A[0][i1][i3]*A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3];
s += 384 * A[1][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[2][i2][i3]*A[1][i1][i3]*A[1][i1][i3];
s += 24 * A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i3]*A[1][i1][i1]*A[1][i1][i1];
s += 144 * A[0][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[3][i1][i1]*A[0][i1][i3];
s += 384 * A[2][i1][i2]*A[0][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i1][i3]*A[1][i1][i3];
s += 96 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[0][i1][i3]*A[1][i3][i3]*A[0][i2][i3];
s += 30 * A[1][i1][i2]*A[1][i1][i3]*A[1][i1][i3]*A[1][i2][i3]*A[1][i2][i3];
s += 24 * A[1][i1][i2]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
s += 288 * A[0][i1][i2]*A[2][i1][i2]*A[0][i2][i3]*A[1][i1][i3]*A[1][i1][i3]*A[1][i1][i3];
s += -12 * A[1][i1][i1]*A[0][i1][i2]*A[1][i3][i3]*A[3][i1][i3]*A[0][i2][i3]*A[1][i2][i2];
s += -24 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i3]*A[1][i3][i3]*A[1][i2][i3]*A[1][i2][i2];
s += -24 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i3]*A[4][i1][i2];
s += -24 * A[1][i2][i3]*A[3][i2][i3]*A[1][i3][i3]*A[1][i1][i2];
s += -12 * A[2][i2][i3]*A[2][i2][i3]*A[1][i3][i3]*A[1][i1][i2];
s += -4 * A[1][i1][i1]*A[1][i2][i2]*A[1][i2][i3]*A[1][i1][i2]*A[1][i3][i3]*A[1][i1][i3];
s += -72 * A[0][i1][i2]*A[2][i1][i2]*A[1][i3][i3]*A[0][i2][i3]*A[3][i1][i3];
s += -72 * A[0][i1][i2]*A[2][i1][i3]*A[1][i2][i3]*A[2][i1][i2]*A[1][i3][i3];
s += -72 * A[0][i1][i3]*A[0][i1][i2]*A[4][i1][i2]*A[1][i2][i3]*A[1][i3][i3];
s += -24 * A[1][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[3][i3][i3]*A[1][i2][i2]*A[1][i1][i3];
s += -12 * A[1][i1][i1]*A[0][i1][i2]*A[0][i2][i3]*A[3][i2][i2]*A[1][i3][i3]*A[1][i1][i3];
s += -24 * A[2][i1][i2]*A[0][i2][i3]*A[1][i1][i1]*A[0][i1][i2]*A[1][i3][i3]*A[2][i2][i3];
s += -24 * A[2][i1][i2]*A[3][i3][i3]*A[0][i2][i3]*A[1][i1][i1]*A[0][i1][i2];
s += -24 * A[1][i1][i1]*A[2][i1][i2]*A[0][i1][i2]*A[1][i3][i3]*A[1][i2][i3]*A[1][i2][i3];
s += -24 * A[3][i3][i3]*A[2][i2][i3]*A[1][i1][i2]*A[0][i2][i3];
s += -12 * A[1][i1][i2]*A[3][i3][i3]*A[1][i2][i3]*A[1][i2][i3];
s += -12 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[0][i2][i3]*A[3][i3][i3];
s += -6 * A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i3][i3];
s += -96 * A[0][i1][i3]*A[4][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[0][i1][i2];
s += -192 * A[2][i1][i3]*A[0][i1][i3]*A[1][i2][i3]*A[3][i2][i3]*A[0][i1][i2];
s += -72 * A[2][i1][i2]*A[3][i3][i3]*A[1][i1][i3]*A[0][i2][i3]*A[0][i1][i2];
s += -48 * A[1][i1][i3]*A[1][i1][i3]*A[2][i2][i3]*A[2][i2][i3]*A[0][i1][i2];
s += -72 * A[1][i1][i3]*A[1][i1][i1]*A[0][i1][i2]*A[2][i2][i3]*A[2][i2][i3]*A[0][i2][i3];
s += -24 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
s += -36 * A[1][i1][i1]*A[0][i1][i2]*A[0][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[3][i2][i3];
s += -12 * A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i2][i3];
s += -96 * A[2][i1][i2]*A[2][i2][i3]*A[0][i2][i3]*A[1][i1][i3]*A[1][i1][i3]*A[0][i1][i2];
s += -12 * A[3][i3][i3]*A[0][i1][i3]*A[0][i2][i3]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += -8 * A[1][i1][i3]*A[1][i1][i3]*A[1][i2][i3]*A[1][i2][i3]*A[1][i1][i2]*A[1][i1][i2];
}
s += -65760 * A[1][i1][i2];
s += 31788 * A[2][i1][i2];
s += -23112 * A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -2952 * A[3][i1][i2];
s += -24792 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 4176 * A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 1404 * A[0][i1][i2]*A[1][i2][i2]*A[1][i2][i2]*A[1][i1][i1]*A[1][i1][i1];
s += 888 * A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += 168 * A[4][i1][i2];
s += 12240 * A[0][i1][i2]*A[1][i1][i1]*A[1][i2][i2]*A[2][i1][i2];
s += 6072 * A[1][i1][i2]*A[3][i2][i2];
s += 3288 * A[1][i1][i1]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 15414 * A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += 10224 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 4136 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += -288 * A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -144 * A[0][i1][i2]*A[1][i2][i2]*A[1][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -72 * A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -24 * A[1][i2][i2]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -24 * A[3][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -6 * A[5][i1][i2];
s += -2928 * A[0][i1][i2]*A[1][i2][i2]*A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -888 * A[0][i1][i2]*A[3][i2][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -888 * A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -2136 * A[1][i1][i1]*A[3][i1][i1]*A[1][i1][i2];
s += -336 * A[3][i2][i2]*A[2][i1][i2];
s += -7320 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += -864 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -1572 * A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
s += -384 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i2][i2];
s += -1356 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i1];
s += -168 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 144 * A[1][i2][i2]*A[0][i1][i2]*A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 72 * A[3][i2][i2]*A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 72 * A[1][i1][i2]*A[1][i1][i2]*A[1][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 216 * A[1][i1][i1]*A[1][i1][i1]*A[3][i1][i1]*A[1][i1][i2];
s += 372 * A[0][i1][i2]*A[1][i1][i1]*A[1][i2][i2]*A[4][i1][i2];
s += 264 * A[5][i2][i2]*A[1][i1][i2];
s += 264 * A[1][i1][i1]*A[3][i1][i2]*A[1][i1][i2]*A[1][i2][i2];
s += 132 * A[1][i2][i2]*A[1][i1][i1]*A[2][i1][i2]*A[2][i1][i2];
s += 48 * A[1][i1][i1]*A[1][i1][i1]*A[2][i1][i2]*A[0][i1][i2]*A[1][i2][i2]*A[1][i2][i2];
s += 96 * A[1][i1][i1]*A[1][i1][i1]*A[3][i2][i2]*A[0][i1][i2]*A[1][i2][i2];
s += 24 * A[3][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2];
s += 24 * A[1][i1][i1]*A[1][i1][i1]*A[1][i2][i2]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 48 * A[3][i1][i1]*A[2][i1][i2]*A[1][i1][i1];
s += 12 * A[3][i2][i2]*A[3][i1][i2];
s += 648 * A[1][i1][i1]*A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += 1020 * A[0][i1][i2]*A[4][i1][i2]*A[2][i1][i2];
s += 888 * A[2][i1][i2]*A[3][i2][i2]*A[0][i1][i2]*A[1][i1][i1];
s += 336 * A[3][i2][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
s += 288 * A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[1][i1][i1]*A[1][i2][i2];
s += 384 * A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
s += 168 * A[3][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
s += 30 * A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += 108 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 484 * A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += 408 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i2];
s += 192 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i1];
s += 48 * A[1][i1][i1]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 8 * A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += -48 * A[0][i1][i2]*A[1][i2][i2]*A[4][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -24 * A[0][i1][i2]*A[5][i2][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -48 * A[1][i2][i2]*A[3][i1][i2]*A[1][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -24 * A[1][i2][i2]*A[2][i1][i2]*A[2][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -48 * A[1][i1][i1]*A[1][i1][i2]*A[5][i1][i1];
s += -12 * A[5][i2][i2]*A[2][i1][i2];
s += -288 * A[1][i1][i1]*A[0][i1][i2]*A[4][i1][i2]*A[2][i1][i2];
s += -48 * A[3][i2][i2]*A[2][i1][i2]*A[0][i1][i2]*A[1][i1][i1]*A[1][i1][i1];
s += -24 * A[3][i2][i2]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2];
s += -96 * A[1][i1][i1]*A[2][i1][i2]*A[1][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
s += -48 * A[1][i1][i1]*A[3][i1][i1]*A[0][i1][i2]*A[3][i2][i2];
s += -48 * A[1][i1][i1]*A[1][i2][i2]*A[1][i1][i2]*A[1][i1][i2]*A[3][i1][i1];
s += -48 * A[5][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += -24 * A[3][i1][i2]*A[3][i1][i2]*A[1][i1][i2];
s += -24 * A[1][i1][i2]*A[3][i2][i2]*A[3][i2][i2];
s += -6 * A[3][i1][i1]*A[3][i2][i2]*A[1][i1][i2];
s += -144 * A[3][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += -96 * A[1][i1][i1]*A[0][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += -96 * A[3][i1][i2]*A[1][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += -24 * A[3][i1][i1]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 12 * A[1][i1][i1]*A[0][i1][i2]*A[1][i2][i2]*A[6][i1][i2];
s += 12 * A[1][i1][i2]*A[7][i2][i2];
s += 12 * A[1][i1][i2]*A[1][i1][i1]*A[5][i1][i2]*A[1][i2][i2];
s += 12 * A[1][i1][i1]*A[1][i2][i2]*A[4][i1][i2]*A[2][i1][i2];
s += 6 * A[1][i1][i1]*A[3][i1][i2]*A[3][i1][i2]*A[1][i2][i2];
s += 36 * A[2][i1][i2]*A[6][i1][i2]*A[0][i1][i2];
s += 18 * A[4][i1][i2]*A[4][i1][i2]*A[0][i1][i2];
s += 24 * A[1][i1][i1]*A[0][i1][i2]*A[3][i2][i2]*A[4][i1][i2];
s += 24 * A[1][i1][i1]*A[2][i1][i2]*A[5][i2][i2]*A[0][i1][i2];
s += 24 * A[3][i2][i2]*A[3][i1][i2]*A[1][i1][i2]*A[1][i1][i1];
s += 12 * A[1][i1][i2]*A[1][i1][i2]*A[5][i2][i2]*A[1][i1][i1];
s += 12 * A[2][i1][i2]*A[2][i1][i2]*A[1][i1][i1]*A[3][i2][i2];
s += 12 * A[5][i2][i2]*A[3][i1][i1]*A[0][i1][i2];
s += 36 * A[0][i1][i2]*A[4][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
s += 12 * A[5][i1][i2]*A[1][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 18 * A[3][i1][i2]*A[3][i1][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 12 * A[3][i1][i1]*A[2][i1][i2]*A[3][i2][i2]*A[0][i1][i2];
s += 6 * A[3][i1][i1]*A[3][i2][i2]*A[1][i1][i2]*A[1][i1][i2];
s += 3 * A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2]*A[2][i1][i2];
}
 


for ( i1 = 0; i1 < n; i1 ++ ) { 
s += 14400 * A[1][i1][i1];
s += 54000 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 43288 * A[3][i1][i1];
s += -20400 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -72444 * A[1][i1][i1]*A[3][i1][i1];
s += 3600 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 23868 * A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 1739 * A[5][i1][i1];
s += -240 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -4176 * A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -3012 * A[1][i1][i1]*A[5][i1][i1];
s += -3120 * A[3][i1][i1]*A[3][i1][i1];
s += 288 * A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 744 * A[1][i1][i1]*A[1][i1][i1]*A[5][i1][i1];
s += 126 * A[7][i1][i1];
s += 1068 * A[3][i1][i1]*A[3][i1][i1]*A[1][i1][i1];
s += -72 * A[1][i1][i1]*A[1][i1][i1]*A[1][i1][i1]*A[5][i1][i1];
s += -192 * A[1][i1][i1]*A[7][i1][i1];
s += -108 * A[3][i1][i1]*A[3][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += -264 * A[3][i1][i1]*A[5][i1][i1];
s += 24 * A[7][i1][i1]*A[1][i1][i1]*A[1][i1][i1];
s += 12 * A[9][i1][i1];
s += 48 * A[3][i1][i1]*A[1][i1][i1]*A[5][i1][i1];
s += 8 * A[3][i1][i1]*A[3][i1][i1]*A[3][i1][i1];
s += -12 * A[9][i1][i1]*A[1][i1][i1];
s += -12 * A[7][i1][i1]*A[3][i1][i1];
s += -6 * A[5][i1][i1]*A[5][i1][i1];
s += 1 * A[11][i1][i1];
} 
	return s /= 24;
}
