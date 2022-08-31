#include <stdlib.h>
#include <stdint.h>
#include "ajit_access_routines.h"
#include "core_portme.h"

#define N 100		//dimension of the img buffer
#define IM_SIZE (N*N)
#define RES_SIZE ((N-3)*(N-3))

char 	__attribute__((aligned(8))) res[RES_SIZE] = {0};
char 	__attribute__((aligned(8))) kernel[16] = 	 { 0,-1,0,0,
							  -1,2,0,0,
							   0,0,0,0,
							   0,0,0,0};

uint8_t __attribute__((aligned(8))) img[10000] = {55,59,59,59,59,60,61,62,62,63,64,65,66,66,67,68,69,70,72,66,32,61,47,28,24,12,15,17,16,13,11,12,12,26,24,18,17,14,13,9,8,10,11,8,7,8,12,16,15,19,19,12,12,12,9,8,7,7,7,7,6,6,7,7,7,7,6,10,19,15,14,36,29,29,26,33,30,19,14,11,16,30,48,65,66,63,66,69,69,68,68,67,67,66,66,66,66,67,67,65,
56,60,60,60,60,61,62,62,62,63,64,65,66,67,67,68,69,71,68,41,18,23,15,15,13,13,15,17,20,20,18,19,19,18,31,29,28,28,24,17,13,11,12,11,8,10,16,20,21,21,27,22,12,12,15,12,7,7,7,8,7,7,7,9,9,8,7,9,11,19,18,34,42,27,10,7,5,5,5,5,7,16,10,10,33,51,43,42,56,71,70,69,68,68,67,68,68,68,68,67,
58,60,60,60,61,62,62,62,63,64,64,65,66,67,68,68,67,53,29,13,10,12,21,14,7,8,7,6,13,20,18,19,27,30,29,41,31,28,35,31,21,17,14,13,9,10,21,25,28,29,30,33,21,15,16,16,12,8,7,8,8,7,7,9,12,11,8,10,12,14,24,26,16,10,9,7,6,8,7,6,6,16,20,13,9,33,67,57,33,36,60,68,70,69,69,68,69,69,68,67,
60,61,60,61,61,62,62,63,63,64,65,66,66,67,67,61,37,14,17,16,13,25,22,12,10,9,12,12,12,22,26,25,21,34,36,43,39,19,27,42,30,24,21,17,15,15,19,30,30,34,35,33,33,19,20,18,14,12,8,10,9,9,7,9,13,17,12,14,13,13,16,13,12,14,10,7,7,8,7,7,7,6,8,12,8,3,20,59,74,51,30,51,60,69,70,69,69,69,68,66,
61,62,61,62,62,63,63,64,64,64,65,66,67,66,57,29,12,25,31,15,20,22,18,23,27,25,22,22,17,15,33,41,35,25,37,46,50,30,14,36,44,29,27,27,22,24,15,28,28,32,37,33,30,27,20,23,12,16,10,12,11,10,7,9,10,18,14,16,16,13,12,12,14,16,9,9,10,8,7,7,8,7,6,7,12,12,4,15,54,72,63,44,60,59,70,70,70,69,68,66,
62,62,62,62,63,63,64,64,65,65,67,67,66,51,24,14,31,43,23,8,6,8,6,7,12,25,38,40,35,20,14,42,52,43,40,45,56,56,20,18,54,32,32,37,28,28,23,28,27,29,31,32,27,30,21,28,16,16,15,11,12,11,7,10,13,17,18,16,21,19,14,13,19,15,15,16,11,10,8,7,8,7,8,7,9,18,14,3,7,49,75,65,49,63,63,71,70,69,68,65,
63,63,63,63,63,64,64,65,66,67,68,67,48,18,26,48,55,28,14,6,9,10,11,15,18,16,22,31,37,43,25,21,50,55,48,36,50,63,44,10,40,36,30,36,31,27,33,25,22,22,22,25,27,32,25,26,20,20,20,13,10,14,8,11,16,16,18,14,22,19,18,15,20,21,23,15,11,11,8,12,10,12,9,7,8,23,42,32,5,6,43,73,56,53,61,69,70,69,67,65,
64,64,64,64,64,65,65,66,67,67,68,52,18,21,62,60,29,15,7,12,9,15,21,20,18,15,14,16,21,35,32,23,34,52,47,31,31,46,50,23,26,36,24,33,26,21,32,25,17,18,19,20,26,25,27,27,25,23,22,15,9,10,11,15,17,13,17,17,20,17,20,16,20,19,18,15,13,18,19,13,11,10,8,8,5,13,37,51,42,7,4,30,72,43,59,67,71,69,67,64,
65,64,65,65,65,66,66,67,67,68,56,29,18,49,56,39,18,8,10,8,9,18,21,22,22,14,10,8,11,16,33,18,28,48,35,32,17,25,37,35,19,30,19,27,21,23,30,27,18,21,19,19,24,26,29,29,25,24,22,16,12,10,13,18,16,16,17,19,16,19,17,17,19,18,20,27,30,21,14,13,13,12,8,6,6,6,30,52,49,35,5,5,21,34,40,66,70,69,67,64,
66,65,66,66,66,66,67,67,68,64,36,21,41,47,24,16,10,15,15,17,21,23,26,28,26,27,21,15,9,11,17,27,15,40,33,23,21,17,27,33,24,29,27,30,28,34,35,38,30,29,25,25,24,27,31,30,26,27,26,21,13,13,15,18,19,18,19,18,20,20,19,13,21,30,35,30,20,19,23,20,15,9,9,8,7,6,8,29,42,28,21,11,21,22,30,52,71,69,67,64,
67,66,66,66,66,67,67,68,70,50,28,22,46,41,36,8,8,9,15,26,31,42,38,33,29,27,24,21,14,10,11,25,31,38,39,25,28,30,30,38,40,50,51,49,55,62,63,65,62,58,48,39,30,30,34,30,29,29,30,20,17,19,20,22,21,19,18,21,23,20,22,33,39,34,27,24,27,25,18,19,12,11,10,8,7,8,8,11,13,21,28,12,30,14,23,36,66,70,68,65,
67,67,67,67,68,68,68,69,67,40,17,32,41,57,23,6,12,10,9,9,20,24,30,38,34,33,31,25,19,16,14,26,53,48,54,36,36,50,53,58,70,74,79,81,90,95,96,100,98,89,71,56,50,47,37,33,32,31,23,22,27,25,24,24,24,25,26,30,28,30,35,30,24,25,28,32,23,17,17,18,13,10,8,7,8,10,9,14,15,22,20,15,17,45,10,27,60,71,69,66,
68,67,67,68,68,68,69,70,58,22,26,42,49,32,9,8,11,11,12,15,17,15,19,27,30,29,33,36,27,31,33,44,65,71,69,59,61,77,86,84,88,98,106,109,111,111,113,115,116,109,93,72,65,57,42,33,30,27,29,34,36,40,38,34,34,38,42,42,36,30,32,32,31,30,25,21,18,20,22,20,13,10,12,11,11,10,15,9,7,18,27,13,6,35,28,12,53,71,70,67,
68,68,68,68,68,69,69,71,49,14,42,40,26,14,8,8,10,14,17,20,16,16,20,21,21,22,28,37,34,40,49,64,79,84,85,88,89,93,96,102,106,110,111,112,113,114,115,116,116,116,115,99,77,55,45,37,34,38,46,54,63,70,69,72,69,60,52,46,44,39,40,34,32,29,27,26,25,21,18,16,14,16,15,15,12,15,11,7,9,7,15,13,7,10,25,13,47,71,72,69,
68,68,69,68,69,69,70,72,34,21,36,20,28,35,9,12,8,9,16,19,15,16,15,13,11,13,18,35,48,52,64,76,82,88,94,99,102,103,102,107,110,110,111,112,113,114,114,115,116,116,117,113,95,78,65,64,66,69,81,95,99,104,107,105,100,88,76,65,55,49,46,44,38,36,35,29,21,17,17,13,15,16,14,15,14,11,10,12,7,6,6,9,8,5,19,18,45,70,74,70,
69,69,69,69,70,69,70,72,28,27,18,23,66,37,23,35,6,9,15,20,19,25,27,28,29,31,36,44,47,57,72,79,85,91,98,98,101,102,106,108,110,112,112,112,114,115,115,116,117,117,117,117,114,109,98,96,100,108,115,116,115,112,112,113,111,107,99,93,85,79,67,56,49,39,33,29,26,24,19,14,12,12,12,11,10,9,11,8,7,7,7,6,6,6,9,15,30,70,75,72,
69,69,69,70,70,70,71,70,21,18,15,51,69,24,30,48,12,13,16,17,22,31,36,34,27,31,43,45,53,66,76,80,88,93,97,98,103,107,109,110,112,113,113,112,113,114,114,114,115,116,116,117,116,116,115,116,118,119,118,117,116,115,114,113,113,110,109,106,102,94,85,77,68,56,46,35,27,26,21,14,10,11,9,10,10,9,11,8,7,7,7,15,10,5,6,9,9,57,76,74,
69,69,70,70,70,71,72,64,15,19,28,55,65,17,28,32,11,10,11,16,17,18,17,21,33,41,40,48,62,72,80,86,89,92,96,101,104,107,110,112,113,113,112,113,114,115,114,114,114,115,116,116,116,117,117,117,117,118,117,116,116,116,115,114,113,111,109,106,101,95,90,82,76,66,59,49,40,26,18,16,14,15,16,15,13,13,15,9,7,6,6,11,14,8,5,7,5,41,75,75,
70,70,70,71,71,71,73,58,11,16,47,55,37,10,21,14,8,8,9,10,13,19,25,33,31,32,43,52,63,78,84,85,89,93,99,103,105,106,109,111,112,114,115,116,116,116,116,116,116,117,118,117,117,117,117,117,117,117,117,116,116,115,115,114,113,112,110,107,104,99,93,90,84,77,70,63,52,42,30,22,17,11,10,11,15,17,15,12,10,7,7,6,7,8,6,6,5,19,69,75,
70,70,71,71,71,71,74,52,22,14,40,53,46,8,9,9,9,8,11,15,18,20,21,23,26,33,43,52,66,77,81,86,90,97,102,103,105,108,110,111,113,116,116,116,116,117,116,117,117,118,118,117,117,117,117,117,117,117,116,116,116,116,114,112,113,112,110,107,104,100,95,88,84,77,71,65,59,52,39,27,20,13,12,14,17,11,10,10,9,7,7,6,6,7,6,6,6,13,53,75,
73,71,71,71,72,72,71,49,20,13,53,52,17,7,16,10,9,9,11,14,17,19,23,22,25,30,38,54,67,76,84,90,94,98,102,104,105,107,110,113,114,115,116,115,116,117,117,117,117,118,117,117,118,117,117,117,117,116,115,115,116,116,115,113,111,112,111,107,103,100,95,90,86,79,75,68,61,56,45,30,23,19,14,16,13,13,12,9,8,8,7,7,7,7,6,6,6,5,21,70,
75,71,71,72,73,72,68,56,18,14,42,38,35,8,7,7,8,8,10,11,14,22,23,20,21,27,43,60,72,78,84,91,95,99,103,107,109,109,110,112,113,114,113,113,115,116,116,117,117,117,117,116,117,118,118,117,118,117,117,115,116,116,114,112,110,110,110,107,104,101,96,92,88,81,75,69,65,60,50,36,23,17,15,15,15,14,12,10,8,7,7,7,7,9,7,6,5,11,14,38,
71,71,71,72,73,71,69,58,18,17,29,38,27,6,7,7,6,7,8,12,17,21,14,14,19,31,47,60,71,78,85,92,98,102,103,107,110,111,109,110,113,112,112,114,115,115,115,115,115,116,115,115,115,117,116,115,116,117,117,116,116,117,115,113,110,110,108,106,103,100,97,93,88,81,75,69,64,58,53,42,27,16,15,15,15,17,13,11,10,9,8,8,7,10,7,6,5,9,13,16,
71,71,72,72,73,70,70,58,27,26,27,23,14,6,6,6,6,6,8,13,23,11,12,16,24,36,43,52,66,78,86,93,101,102,103,106,109,109,109,109,112,113,113,114,115,115,115,115,116,116,114,115,116,115,115,114,115,115,117,115,115,116,115,114,111,108,108,105,104,100,99,95,87,80,73,67,65,58,49,43,32,21,11,11,13,14,13,11,9,7,6,7,7,9,7,6,6,7,16,9,
70,71,71,72,73,71,67,59,43,37,24,7,6,7,6,6,6,6,9,16,17,10,15,18,24,30,38,50,66,76,87,91,98,100,103,102,105,105,107,107,109,113,113,113,114,114,115,115,115,116,115,115,115,115,114,115,116,116,116,115,114,112,113,112,109,108,106,105,105,101,98,94,86,80,73,70,66,56,49,41,33,23,15,11,10,12,14,12,10,7,7,9,9,7,7,7,7,7,12,9,
71,71,72,72,73,73,64,60,64,34,16,5,13,11,5,6,6,7,9,16,11,11,12,13,21,30,43,54,64,75,84,91,95,97,100,98,100,104,107,107,109,112,112,112,114,116,115,115,115,116,116,116,116,114,114,114,116,116,116,115,115,112,111,111,107,105,103,103,104,103,100,93,86,83,75,70,65,54,45,36,32,26,19,14,14,10,11,13,13,12,10,7,7,8,7,7,11,6,8,9,
71,72,72,73,73,74,65,60,73,24,4,15,18,8,5,6,6,7,10,12,8,9,10,16,24,33,45,51,60,76,83,87,91,94,96,95,99,105,107,109,111,112,113,114,115,116,115,115,115,116,116,116,115,114,114,114,115,115,115,115,114,113,112,109,105,101,101,102,104,102,98,91,86,84,77,68,62,54,42,36,26,24,22,15,14,14,13,12,10,9,9,8,7,9,7,6,8,6,6,10,
71,72,72,73,73,74,70,57,59,12,6,10,6,6,6,6,6,7,8,8,7,8,9,16,25,35,43,50,62,77,84,87,90,93,95,95,99,106,107,111,112,113,113,114,114,116,114,112,114,114,112,115,114,114,113,115,114,113,115,115,114,113,112,106,105,102,104,102,100,98,95,88,82,81,80,69,60,54,45,37,26,17,16,19,17,17,15,16,12,8,7,6,7,9,7,6,6,8,8,10,
71,72,72,73,73,74,75,60,23,19,42,8,5,6,6,6,6,6,7,6,7,8,10,14,22,33,43,51,62,71,81,88,92,95,98,98,100,104,107,110,111,112,113,115,117,116,116,113,114,114,112,114,115,115,116,115,115,113,114,114,113,113,111,107,106,103,104,101,99,98,90,85,82,83,79,68,60,53,42,33,25,19,14,13,18,13,9,9,10,10,9,7,6,8,7,6,5,13,12,9,
71,71,72,73,73,74,74,61,11,40,40,10,6,6,6,6,6,6,7,7,7,8,9,12,23,36,46,55,61,73,83,89,94,96,96,100,103,103,105,110,110,110,114,115,116,115,115,115,114,114,113,112,115,115,116,115,115,112,112,113,115,113,111,107,104,103,103,101,96,92,86,82,81,80,74,65,54,45,38,32,23,19,12,9,11,14,12,11,9,8,9,8,7,7,7,6,6,9,9,13,
71,72,72,73,74,74,75,39,25,42,9,6,6,6,6,6,6,7,7,6,6,6,9,15,30,52,62,63,67,79,85,89,95,97,97,101,103,102,104,108,110,110,112,111,114,115,113,115,115,116,114,114,115,115,115,116,116,112,110,112,114,115,111,108,105,105,104,100,96,87,79,79,77,75,71,63,53,44,36,26,22,21,11,8,7,9,9,11,13,12,10,8,8,6,6,6,6,6,6,13,
71,72,72,73,74,75,68,25,33,14,13,9,6,6,6,6,6,6,6,6,6,6,8,19,42,60,65,64,68,83,89,89,98,100,98,101,101,101,103,101,100,99,98,98,105,107,115,115,110,112,115,116,116,116,115,115,115,111,109,112,114,114,114,109,105,105,104,99,94,86,83,78,74,73,70,60,52,45,36,28,19,16,14,8,8,8,10,10,8,9,9,7,7,6,6,6,6,14,7,18,
71,72,72,73,74,76,61,14,8,18,30,8,5,6,6,6,6,6,6,6,6,6,16,37,56,64,68,69,77,83,89,91,97,96,95,97,94,88,77,68,71,68,62,51,63,77,98,93,90,105,116,118,118,115,108,111,115,111,108,110,112,110,109,103,103,103,101,97,91,87,84,78,78,71,63,59,51,44,38,29,20,16,14,11,8,8,9,8,9,8,6,6,6,6,6,5,8,21,9,15,
71,71,72,73,74,76,51,10,9,16,10,6,6,6,6,7,6,6,6,7,7,8,29,56,65,65,65,74,85,89,85,71,55,50,56,64,58,44,28,21,26,24,25,27,27,34,55,66,78,103,114,117,115,108,101,114,115,109,99,101,107,104,101,97,101,101,104,101,96,92,86,82,78,70,62,58,50,43,42,33,18,12,11,9,8,8,9,9,8,7,6,6,6,6,6,6,8,12,8,11,
71,71,72,73,75,73,29,5,7,6,6,6,6,6,7,6,6,6,7,7,6,13,46,64,68,65,68,73,76,74,51,24,17,23,27,24,18,15,16,20,22,23,19,20,33,27,24,47,59,84,108,113,112,100,91,111,108,100,93,91,96,100,94,90,91,96,96,96,99,99,92,88,81,69,65,60,55,48,44,40,26,12,10,9,7,7,8,8,7,6,6,6,6,6,6,6,8,8,6,8,
71,72,72,74,75,61,23,5,6,6,6,6,6,7,6,6,6,7,8,7,6,21,56,67,68,58,44,33,25,19,18,20,23,22,21,19,18,18,15,14,17,18,20,26,41,35,15,39,53,71,104,113,110,92,71,95,89,73,62,61,64,63,61,58,59,60,65,68,82,92,91,88,84,80,71,62,56,51,50,47,34,18,8,7,7,7,6,6,8,7,6,6,6,6,6,7,7,6,12,7,
71,72,73,74,70,52,17,5,6,6,6,6,6,6,5,5,6,8,7,6,6,28,64,69,62,38,17,10,16,15,19,22,26,21,22,25,25,21,15,14,14,16,17,27,38,41,39,55,55,68,105,112,107,90,59,69,56,43,47,46,39,35,34,33,31,27,26,24,30,46,52,55,57,62,63,60,58,55,50,48,43,25,9,7,8,7,7,6,6,6,6,6,7,6,6,7,10,6,10,6,
71,72,72,74,61,33,6,6,6,6,6,6,11,12,9,7,8,8,6,7,8,39,66,67,54,35,26,27,20,21,31,47,57,67,72,74,74,73,63,49,43,41,44,46,50,56,62,65,63,85,105,109,103,92,63,55,48,35,29,35,32,33,30,28,27,23,19,19,20,17,14,21,31,34,50,63,64,57,55,53,52,36,11,7,7,7,6,6,6,6,6,6,6,6,6,6,6,7,17,6,
71,72,73,72,47,12,5,6,7,7,6,11,27,38,54,44,18,6,7,6,11,48,67,66,49,39,44,46,55,55,67,77,83,90,94,91,85,78,71,64,60,57,58,64,69,69,68,73,87,99,105,107,104,98,81,55,51,42,31,31,30,24,17,18,17,15,15,15,12,16,18,18,14,12,15,35,53,51,51,54,54,42,15,6,7,7,6,6,6,6,6,6,6,6,6,6,5,8,14,13,
71,72,73,70,26,4,7,6,6,7,6,15,34,53,75,76,56,16,5,6,22,59,68,61,53,60,69,72,72,80,83,80,70,61,57,55,51,53,50,56,64,71,74,66,65,69,70,77,93,106,114,115,112,107,93,75,60,56,47,39,36,29,26,27,26,32,39,51,54,48,44,35,28,19,9,6,10,12,28,50,54,44,14,6,7,6,6,6,6,6,6,6,6,6,7,5,12,13,3,31,
71,72,74,62,15,5,8,6,7,12,8,13,34,41,50,68,62,18,5,9,37,64,70,68,62,69,78,80,81,69,49,35,30,36,26,23,51,15,60,27,55,56,56,68,68,66,66,75,93,111,119,120,120,115,101,77,61,52,47,45,51,59,61,58,57,61,71,78,80,84,82,76,62,46,27,16,12,9,17,40,53,48,20,7,6,6,6,6,6,6,6,6,6,6,6,6,13,10,9,61,
72,73,74,59,15,6,10,6,7,13,8,12,39,52,48,50,40,8,7,20,49,68,70,73,76,78,84,84,76,57,41,28,45,86,62,29,65,20,61,40,98,95,59,45,61,76,70,76,94,111,119,121,120,116,99,77,60,50,53,53,54,58,58,43,39,38,44,57,63,67,65,69,72,70,59,50,38,24,18,31,50,49,24,8,7,6,6,6,6,6,6,6,6,6,6,6,7,5,41,89,
72,74,73,65,19,5,9,8,7,7,6,9,46,63,59,58,35,11,15,27,57,68,72,77,84,89,91,88,81,75,71,77,77,78,70,64,61,58,68,70,86,83,78,68,68,82,79,85,98,111,119,120,120,114,100,81,63,60,50,36,50,79,102,41,53,26,35,31,16,30,40,48,50,60,69,67,59,47,33,36,51,48,25,10,7,6,6,6,6,6,6,6,6,6,6,6,5,13,68,93,
72,74,75,71,24,5,8,12,6,6,5,9,53,62,62,73,53,33,25,35,62,69,74,83,89,94,96,94,90,93,91,85,90,95,99,103,99,99,100,99,98,96,94,97,98,86,81,92,104,115,120,120,119,112,97,84,69,64,64,55,61,74,94,59,43,27,31,27,36,63,31,22,35,48,61,71,70,63,54,53,53,49,26,10,9,6,6,7,7,6,6,6,6,6,6,6,4,31,82,94,
73,74,74,74,33,5,8,18,8,6,5,10,56,57,65,83,75,55,22,40,64,69,74,85,90,94,100,100,101,102,103,102,100,98,99,102,104,104,103,103,99,96,96,97,92,91,92,95,105,116,120,120,119,111,100,87,78,71,80,86,84,87,92,89,71,61,60,49,63,67,58,45,36,48,63,72,74,72,65,58,55,51,31,11,13,9,8,10,11,9,6,6,6,6,6,5,7,52,91,95,
73,74,75,77,44,7,7,17,11,7,5,11,57,59,73,84,86,58,16,43,63,67,73,83,90,98,102,104,105,108,110,111,110,110,109,109,111,111,109,108,108,107,106,101,100,100,98,97,105,116,119,119,118,112,98,90,84,79,80,88,88,88,94,98,97,92,94,89,83,81,78,70,65,65,67,76,81,78,71,65,58,52,32,14,14,15,12,15,12,13,6,6,6,6,6,4,20,77,96,95,
73,75,76,78,61,13,6,12,13,8,7,11,56,72,82,79,65,31,14,47,61,64,75,82,87,95,103,107,108,110,114,116,118,118,118,118,117,117,116,115,113,110,106,104,105,101,102,101,104,114,119,119,117,111,100,92,88,86,89,91,99,99,97,96,98,99,96,92,87,82,80,82,86,89,83,81,86,84,77,66,59,54,33,12,15,19,16,14,16,15,8,6,6,6,6,5,18,80,99,95,
74,75,76,77,76,37,5,8,9,7,9,11,48,75,78,63,49,22,16,49,59,65,74,79,86,95,103,109,113,114,116,117,118,118,119,117,117,117,115,114,112,107,107,106,102,102,103,103,107,113,118,119,118,111,101,94,91,89,92,95,99,106,108,108,108,107,104,100,97,97,99,100,99,98,96,90,88,84,76,67,58,52,33,14,10,16,18,11,14,12,7,6,6,6,5,7,27,61,97,96,
74,75,76,77,79,68,24,7,11,6,11,15,44,69,63,54,58,27,15,45,60,63,70,78,85,94,104,111,114,116,117,117,117,116,117,117,115,114,113,111,108,107,107,104,102,105,104,106,109,114,117,118,117,111,101,96,92,89,90,94,97,102,106,111,115,115,114,113,113,112,112,110,107,105,101,97,86,80,73,63,57,51,36,16,15,12,18,15,14,9,7,7,7,6,11,21,67,60,86,97,
75,76,76,77,78,80,62,18,20,16,8,18,48,76,62,63,80,37,15,44,60,62,69,76,83,89,104,111,112,114,116,118,117,117,116,113,112,113,111,111,110,107,105,104,104,103,104,107,107,110,112,112,110,108,100,92,90,90,89,92,94,101,104,107,111,113,115,115,114,114,114,112,110,108,105,98,86,76,71,62,55,49,36,16,18,17,19,21,17,9,8,8,7,6,23,39,89,75,71,96,
74,75,76,77,79,80,80,56,28,36,12,14,50,81,69,72,84,41,13,44,57,61,65,73,82,89,98,106,108,113,116,118,116,113,114,114,113,113,112,111,109,106,104,104,98,98,100,102,103,107,111,113,108,103,96,88,85,88,90,93,95,101,104,105,106,107,110,114,113,114,114,113,111,108,104,97,86,76,68,59,54,49,32,14,13,24,28,24,15,8,9,7,6,9,25,55,98,88,67,91,
74,76,77,77,78,78,81,81,53,35,25,11,43,76,73,68,81,47,16,43,57,62,67,73,83,90,95,102,107,111,114,114,112,114,114,114,114,112,112,111,111,109,106,97,93,94,95,99,103,109,114,117,117,108,96,89,80,82,85,91,97,100,101,105,106,106,105,109,112,113,115,113,111,108,102,94,86,75,65,58,51,48,29,12,10,20,38,45,20,6,7,6,6,16,29,74,99,96,82,89,
75,76,77,78,79,80,81,83,80,51,26,14,36,64,68,59,58,37,17,44,58,63,68,73,83,91,95,100,104,104,107,108,113,115,113,114,114,114,113,111,111,109,97,94,99,98,95,99,106,114,120,121,122,120,107,90,83,83,82,85,99,103,103,107,107,107,106,106,108,110,109,110,108,103,99,92,83,73,64,57,49,45,24,12,14,15,38,53,18,6,7,6,8,21,56,95,96,95,90,92,
76,77,78,78,79,80,81,82,84,80,52,21,29,62,63,66,71,42,17,43,59,62,66,74,83,93,94,94,100,102,106,109,113,114,113,114,115,115,115,112,108,100,95,106,112,109,105,105,110,119,123,122,122,123,111,94,90,97,97,90,92,102,105,107,107,109,109,109,108,106,103,105,101,100,94,86,83,72,62,53,49,42,17,10,28,22,35,49,14,6,7,6,8,38,89,103,101,99,94,94,
76,77,78,78,79,80,81,82,83,85,82,59,32,55,63,70,84,66,23,41,55,57,68,78,86,91,93,93,100,101,106,110,112,113,114,115,116,114,113,110,102,92,98,110,112,113,109,103,104,114,120,119,118,115,104,92,96,107,105,99,89,96,102,106,110,110,107,110,108,106,102,101,96,92,82,77,77,69,58,53,46,37,15,17,34,40,34,37,12,6,6,5,12,73,105,103,102,100,97,95,
77,77,78,78,79,80,81,82,83,84,85,85,65,50,58,72,80,76,37,40,54,57,65,78,87,91,92,92,98,101,106,109,111,113,115,117,117,114,112,107,97,89,91,96,74,49,58,77,90,101,107,107,104,99,86,72,60,55,71,92,88,89,99,105,109,110,110,110,107,102,101,98,93,88,81,76,73,68,58,51,43,32,17,36,38,41,38,23,10,6,6,5,19,88,106,103,102,100,98,96,
77,78,78,79,79,80,81,82,82,83,85,86,84,64,59,69,81,78,47,45,55,56,63,76,87,87,91,92,96,101,106,109,112,115,115,115,116,117,115,109,102,92,84,84,52,26,18,19,43,73,84,82,79,70,38,13,11,24,58,89,83,89,98,106,111,111,111,111,108,104,98,95,93,88,79,73,71,67,59,50,39,24,18,33,36,39,36,18,7,7,9,6,22,89,106,103,102,100,99,96,
77,78,78,79,80,80,81,82,83,83,83,85,86,74,62,70,74,69,45,47,54,57,64,74,83,87,94,94,97,102,106,108,112,114,116,117,118,117,115,112,110,103,83,71,71,77,79,67,52,64,70,69,63,57,46,58,69,81,91,86,85,98,103,107,111,111,111,110,109,105,99,94,89,84,75,70,66,64,56,46,35,18,31,53,50,41,43,24,8,8,10,7,31,95,105,103,102,101,99,96,
78,79,79,79,80,81,82,82,83,84,84,85,86,81,63,62,68,71,47,42,55,58,59,69,78,88,93,93,98,101,106,110,113,115,117,118,117,117,116,115,112,107,94,74,65,67,69,55,53,71,87,91,77,63,51,63,79,77,72,76,97,105,108,110,114,113,111,108,108,106,99,94,88,82,67,67,66,61,53,43,32,19,57,71,55,45,46,39,29,16,8,5,50,102,103,102,101,100,99,96,
78,79,80,80,80,81,82,83,83,84,85,85,86,85,71,55,59,65,46,39,49,55,59,64,76,85,88,92,97,102,107,110,112,115,117,117,117,116,116,115,111,104,91,85,80,74,65,57,73,81,81,87,80,76,65,52,58,62,70,85,98,105,108,111,113,112,111,111,108,104,98,91,86,78,62,66,67,60,50,37,28,29,65,67,52,44,38,51,45,16,6,9,71,107,104,102,100,99,98,96,
79,80,80,80,81,81,82,83,84,84,85,85,86,86,83,62,36,35,30,34,46,53,62,64,73,77,88,95,97,100,107,109,112,114,115,114,113,112,110,104,99,90,86,77,76,71,67,71,78,68,83,91,70,74,69,60,61,61,67,80,95,99,103,109,113,113,112,111,108,103,97,90,84,79,69,66,67,56,46,38,26,32,52,50,47,42,25,31,24,8,4,27,93,107,105,104,102,101,99,96,
79,80,80,81,81,82,83,83,84,85,86,87,88,86,88,79,39,21,19,34,48,53,59,61,67,73,84,91,96,98,104,107,111,113,113,109,98,97,90,91,89,80,74,65,68,65,66,71,82,78,76,81,67,79,78,67,67,61,55,71,82,83,91,99,108,112,112,111,108,101,96,90,83,79,76,69,62,52,41,37,28,38,41,20,17,31,25,17,7,6,9,62,105,106,105,104,103,101,100,97,
80,81,81,81,82,82,83,84,84,85,86,87,86,86,89,87,55,29,17,29,46,56,58,66,72,78,82,88,92,98,104,107,109,110,104,93,86,83,84,87,81,66,63,67,66,66,72,79,82,74,86,82,72,83,81,67,55,53,51,57,68,70,72,83,94,103,107,106,104,100,97,86,80,76,76,65,57,48,43,38,29,40,55,30,25,34,32,16,7,6,27,85,105,105,105,104,103,101,99,97,
81,82,82,82,82,82,83,84,85,85,86,87,87,88,90,90,60,33,17,28,42,55,61,65,68,72,81,86,89,96,103,106,107,101,85,79,70,71,78,77,69,64,66,74,71,81,90,98,94,74,72,78,80,84,87,68,61,56,46,44,52,57,52,57,68,83,99,103,102,99,96,87,78,73,67,57,48,45,38,34,23,36,53,49,36,29,27,14,14,34,62,80,93,101,104,103,102,101,99,97,
81,83,83,83,83,83,83,84,85,86,87,88,88,89,90,91,68,42,22,27,40,48,59,63,67,71,78,76,84,93,99,105,102,88,70,73,73,68,74,75,65,65,74,81,91,103,102,108,108,83,66,84,91,98,103,89,74,61,54,48,52,52,50,50,52,65,89,97,97,97,91,83,76,70,60,55,52,44,38,32,20,20,30,28,15,17,23,19,36,82,105,105,103,103,104,104,103,101,99,97,
82,83,83,83,84,84,84,85,86,87,87,88,88,89,90,91,78,51,24,26,42,48,55,61,69,70,76,78,83,87,93,102,93,80,74,74,79,66,72,79,73,77,84,87,99,105,102,104,113,110,88,91,100,102,103,98,80,75,59,56,55,51,44,44,49,59,73,92,94,93,87,76,71,65,62,58,53,44,35,31,16,6,7,10,10,13,29,49,74,94,107,108,107,106,105,104,103,101,100,97,
83,84,84,84,84,84,85,86,86,87,87,88,89,90,90,92,86,59,28,21,39,51,55,57,64,69,75,76,74,82,92,96,91,76,81,88,90,72,67,71,74,84,85,85,79,76,76,70,74,86,98,92,86,79,78,76,79,74,63,65,64,56,51,55,55,56,67,89,93,89,81,71,63,63,56,51,49,40,37,31,13,6,6,7,10,10,34,84,104,101,103,107,106,105,105,104,103,101,100,97,
84,84,85,85,85,85,86,87,87,87,88,89,89,90,91,91,89,70,38,17,38,46,52,50,60,69,75,72,71,77,85,89,91,85,88,95,92,71,64,63,67,69,56,47,47,50,52,53,47,54,66,55,50,56,62,61,62,69,74,70,68,59,53,64,70,65,67,80,89,87,78,71,64,55,55,49,46,38,33,21,9,6,6,7,8,9,41,89,107,108,105,106,107,106,105,104,103,101,100,98,
84,85,85,86,86,86,86,87,87,88,89,89,90,91,91,91,89,78,42,13,32,42,50,49,58,69,73,71,71,74,84,91,98,93,81,91,94,87,73,65,54,48,52,62,70,77,79,74,67,57,55,53,52,53,51,49,43,40,49,60,58,54,48,60,74,72,66,76,86,79,72,64,58,56,55,48,42,36,26,16,7,6,6,7,7,6,38,83,101,107,107,106,106,105,105,104,103,102,100,98,
84,86,86,86,86,87,87,88,88,88,89,90,90,91,91,91,88,72,35,9,27,42,48,50,58,69,72,67,68,70,84,91,96,98,87,83,91,91,97,98,90,83,84,81,87,97,100,101,104,95,88,94,94,91,83,80,70,55,42,39,43,47,57,66,71,79,73,80,86,77,65,57,55,58,52,45,38,31,23,11,6,7,7,7,7,6,22,73,97,106,107,107,106,105,105,104,104,102,101,98,
84,86,86,86,87,87,88,89,89,89,89,90,91,91,92,92,87,68,26,7,17,36,42,43,55,64,71,69,66,70,79,84,93,88,81,82,91,94,95,96,94,93,97,100,102,106,107,110,112,111,110,110,110,106,100,94,92,82,76,72,69,69,77,83,86,81,82,87,80,71,57,50,55,53,49,42,36,30,21,8,6,7,7,7,8,8,10,55,95,106,107,107,106,106,105,104,104,102,101,99,
84,86,87,87,88,88,89,89,90,90,90,89,90,92,92,92,85,59,17,7,10,31,36,42,46,59,67,70,70,70,73,81,89,87,75,77,91,97,92,90,82,76,81,82,81,83,81,80,73,80,81,80,87,93,94,93,93,85,83,78,71,75,88,86,85,79,82,88,79,65,54,52,56,46,44,37,31,23,12,7,6,6,7,8,9,10,8,26,74,100,106,107,106,106,105,104,104,102,101,99,
85,86,87,87,88,89,90,90,90,91,91,90,91,91,88,83,69,37,11,7,7,18,34,36,40,48,57,64,72,67,74,80,85,82,76,80,87,86,87,89,84,73,70,56,53,46,46,43,34,42,43,44,51,62,67,69,72,66,70,72,76,73,83,84,76,78,78,83,76,64,60,52,51,47,41,31,25,13,8,7,6,7,7,7,8,13,15,17,49,89,99,104,106,105,105,105,104,103,102,99,
86,87,88,88,88,89,90,91,91,91,91,91,91,90,84,74,56,24,10,8,8,13,19,28,34,38,54,63,63,67,72,74,77,80,80,77,83,78,81,87,92,84,67,56,52,44,51,46,42,48,41,44,54,48,48,53,56,60,68,71,75,76,76,75,73,75,81,81,71,63,55,47,46,43,31,25,18,12,7,7,8,7,8,8,7,15,26,22,48,92,98,102,105,105,105,105,104,104,102,99,
86,88,88,89,89,90,91,91,91,92,92,93,93,90,82,69,51,25,11,8,8,16,13,17,26,36,46,53,60,65,66,67,69,75,72,66,66,72,78,89,90,92,82,74,72,66,67,64,55,51,56,58,56,54,55,61,65,69,76,79,81,81,78,77,72,69,74,68,61,55,52,47,38,33,25,19,15,12,7,8,8,8,10,12,11,11,25,33,50,86,99,102,104,105,105,105,104,104,103,100,
87,88,89,89,90,90,91,92,92,93,93,93,93,88,79,73,53,29,13,7,8,18,22,14,19,28,39,54,53,59,61,65,65,66,70,69,68,70,79,86,88,92,90,90,88,85,81,77,80,79,73,70,66,76,80,82,86,85,79,81,78,71,65,69,70,62,63,62,61,54,49,47,36,29,21,12,15,11,6,8,8,7,9,16,25,22,23,31,52,81,98,105,105,105,105,105,104,104,103,100,
87,89,89,90,90,91,92,92,92,93,93,93,91,85,78,71,42,18,10,7,9,21,32,29,15,17,25,38,48,58,53,61,60,74,72,75,77,80,81,84,91,98,100,101,97,93,93,99,103,100,89,85,85,91,97,95,97,87,82,81,72,68,64,69,71,68,64,59,53,45,41,39,32,22,13,14,20,12,7,9,11,10,8,12,32,43,48,45,59,83,94,102,105,105,105,105,104,104,103,100,
88,90,90,91,91,91,92,93,93,93,94,94,91,81,69,55,26,11,9,8,10,25,35,38,30,16,17,27,43,47,45,48,60,68,69,72,75,79,86,87,89,100,102,99,102,100,108,112,106,104,102,96,99,102,102,99,100,95,81,75,67,64,61,67,62,59,52,53,45,40,30,29,20,13,13,21,24,12,9,12,27,26,16,22,35,41,54,64,72,82,91,98,101,103,105,105,104,104,103,100,
88,90,90,91,91,92,93,93,93,93,94,95,93,79,59,35,15,10,8,9,12,26,41,44,44,37,24,16,26,34,42,41,46,58,64,65,72,82,82,80,86,93,92,102,105,102,108,107,101,104,92,104,106,102,99,105,99,90,82,76,71,58,67,65,60,51,48,46,36,30,24,19,13,14,24,29,19,11,9,24,58,46,42,64,70,58,56,73,86,90,95,99,100,102,104,104,104,104,103,101,
87,89,90,91,92,92,93,94,94,94,95,96,96,86,59,36,22,10,16,30,32,33,40,43,49,46,39,30,15,22,30,34,37,48,63,73,75,66,75,78,82,84,92,100,107,109,108,104,104,100,99,107,108,98,100,101,93,80,75,71,65,57,62,58,53,45,39,35,27,22,15,12,16,24,30,28,17,21,31,56,85,74,83,97,98,90,86,92,98,99,101,103,104,104,104,104,104,105,103,101,
87,89,90,91,92,93,94,95,96,96,96,96,96,92,80,68,35,20,49,68,57,40,41,45,50,53,45,44,30,15,17,22,29,42,55,63,64,67,71,67,70,85,91,97,89,99,96,103,106,98,96,104,107,104,103,97,91,78,73,67,61,51,49,50,43,32,24,22,18,13,14,21,27,29,29,26,14,28,58,84,100,101,103,108,109,106,106,103,104,106,105,104,104,104,105,105,105,105,104,101,
87,89,90,91,93,94,95,96,96,97,96,97,96,95,91,78,40,50,80,75,51,35,40,48,50,56,56,47,41,30,18,13,22,26,37,52,62,68,64,64,69,83,85,91,85,92,94,87,102,101,94,93,101,102,97,87,74,64,65,70,63,54,47,40,28,23,22,15,11,14,20,32,37,30,24,22,13,11,34,86,109,110,109,110,110,109,109,108,107,106,106,105,105,105,105,105,105,105,104,102,
87,89,91,92,93,95,95,96,97,97,97,97,98,97,94,88,60,72,86,53,19,22,39,46,48,53,58,55,52,43,35,25,16,15,22,40,54,59,58,65,71,75,71,88,86,95,97,87,100,104,102,91,92,91,93,80,61,61,62,63,58,45,39,32,18,13,13,12,18,26,28,37,38,32,24,20,13,10,11,36,85,110,112,111,110,109,108,108,107,106,105,105,105,105,105,105,105,105,105,103,
88,90,91,93,94,95,96,97,97,97,96,97,98,99,100,98,78,73,62,21,6,20,39,46,50,52,51,55,55,52,47,41,30,19,16,26,37,52,57,59,64,65,76,82,80,86,90,89,101,99,96,82,90,90,90,74,65,65,60,52,47,40,28,18,12,12,16,24,28,36,41,42,40,33,26,23,14,9,11,11,30,81,110,111,110,109,108,107,106,106,105,105,105,105,105,105,106,106,106,104,
88,91,92,94,95,96,97,98,98,98,98,99,100,100,101,101,94,72,29,8,6,19,39,47,53,55,56,64,65,58,56,51,41,31,20,16,21,34,47,49,50,51,65,71,74,73,75,75,86,82,80,82,78,80,75,64,60,52,47,43,38,31,15,9,15,24,30,38,40,44,48,43,44,35,29,27,16,9,12,13,12,29,81,108,110,109,108,107,106,105,105,105,105,105,105,105,106,106,106,104,
89,92,94,95,96,97,98,99,99,99,99,100,100,101,102,103,89,42,12,10,7,19,39,48,55,55,57,63,61,63,60,54,48,48,42,25,15,17,29,35,37,41,49,55,54,55,61,59,63,70,68,70,62,61,55,48,48,41,38,35,21,14,11,18,26,33,36,44,46,47,49,47,43,37,32,28,17,9,11,14,15,12,30,82,109,109,108,107,106,105,105,105,105,105,106,106,106,106,106,105,
91,94,95,97,98,98,99,99,99,100,100,100,100,101,103,98,56,16,14,12,7,20,38,48,54,59,60,60,59,63,63,61,54,52,50,45,32,23,17,20,25,26,32,39,42,44,47,52,55,51,52,45,45,47,41,33,29,30,25,16,12,17,26,33,36,35,44,50,50,53,51,46,45,38,33,29,19,10,11,13,14,15,13,34,86,108,108,107,106,105,105,105,105,105,106,106,106,107,107,105,
93,95,96,98,98,99,100,100,100,100,100,101,101,102,102,72,22,14,17,14,8,21,38,48,55,57,60,61,60,61,64,64,59,59,56,53,47,45,36,21,18,19,22,26,25,27,29,34,37,33,29,30,30,26,21,19,16,15,12,17,27,34,38,41,46,48,51,52,50,56,53,48,43,37,33,28,21,11,11,13,13,14,14,13,39,92,108,107,106,105,105,105,105,105,106,106,107,107,107,106,
93,96,97,99,99,100,100,100,101,101,101,102,102,104,89,36,12,15,16,15,9,22,38,47,55,60,61,62,64,63,64,67,66,62,63,62,57,54,52,39,32,25,22,20,20,26,29,29,25,27,25,24,20,16,15,16,15,21,30,33,39,39,40,49,52,55,54,55,56,54,51,48,40,33,30,28,22,10,11,14,12,14,15,14,13,49,98,108,106,105,105,105,105,106,106,106,107,107,108,106,
95,97,99,100,101,101,101,101,102,102,102,102,104,98,54,14,13,14,17,16,10,24,38,47,53,56,60,66,67,68,69,69,68,67,64,65,62,54,48,49,48,45,47,37,32,32,28,22,24,23,23,21,21,21,27,36,32,37,35,39,43,48,49,51,54,60,60,63,60,59,51,45,40,33,30,28,22,9,12,16,13,12,14,15,13,15,62,103,106,105,105,105,105,106,106,107,107,108,108,107,
96,98,100,101,101,102,102,103,102,102,103,103,102,71,20,11,13,15,19,17,11,25,37,44,50,53,58,65,70,71,72,71,69,65,63,62,60,56,59,52,48,53,55,55,53,53,52,43,50,52,48,45,44,44,41,41,42,44,42,46,54,58,58,59,61,61,65,64,57,56,56,50,44,38,34,30,22,9,12,17,17,12,13,15,15,12,24,78,105,106,105,105,105,106,106,107,107,108,109,107,
97,100,101,102,102,103,103,103,103,103,104,105,85,32,11,12,13,16,20,20,12,23,38,43,45,50,57,64,69,73,75,74,73,68,64,67,65,63,60,60,57,54,60,65,66,66,64,65,62,59,59,56,54,55,48,46,52,51,48,50,55,61,64,64,66,62,66,69,64,58,56,53,46,40,34,29,21,9,14,18,19,14,12,14,14,14,11,36,91,106,105,105,105,106,106,107,108,109,109,108,
99,101,102,103,103,103,104,103,104,104,105,96,47,12,12,12,13,15,18,21,14,20,39,47,49,52,56,61,67,72,76,75,78,80,76,72,70,69,67,67,66,66,69,69,71,69,70,74,71,67,69,63,62,60,54,52,52,54,59,57,58,67,67,70,72,69,69,68,65,62,57,52,46,41,35,30,20,12,16,19,22,18,13,12,13,14,13,12,55,100,106,105,105,105,106,107,108,109,110,108,
101,102,103,104,104,104,104,105,105,105,102,66,16,11,14,13,13,14,18,22,19,15,38,48,50,53,56,60,67,72,75,77,79,81,80,76,73,72,70,69,73,75,75,74,71,70,73,76,74,71,71,67,66,61,60,60,61,66,68,69,71,72,72,73,74,71,71,70,65,60,56,53,48,42,37,29,16,13,18,22,24,21,14,14,15,14,14,10,18,70,101,106,106,106,106,107,108,109,110,109,
102,104,104,104,105,105,105,105,106,106,88,32,10,14,15,13,13,15,17,22,24,14,30,47,51,54,58,63,66,71,75,77,78,78,81,81,78,74,72,71,71,74,75,75,71,70,74,76,77,74,69,69,71,68,67,68,68,67,68,70,71,71,73,75,75,73,71,68,63,59,55,51,48,44,40,27,12,13,19,23,24,23,15,14,16,16,14,12,9,21,50,76,95,103,106,108,108,109,110,109,
103,105,106,105,105,105,105,106,107,103,59,14,13,16,16,14,13,14,18,25,24,17,21,43,50,54,59,64,69,72,74,76,79,80,80,81,81,81,78,74,73,74,73,71,71,73,74,77,76,74,70,67,66,69,67,66,66,68,69,70,73,76,76,76,75,71,68,66,63,59,55,52,48,45,39,25,9,12,20,25,26,25,17,13,14,16,15,14,11,8,7,15,32,52,71,87,101,109,111,110,
104,106,106,106,106,106,106,107,104,79,28,12,14,16,18,15,13,14,20,26,24,18,14,34,50,55,58,62,67,71,73,76,78,80,82,83,82,82,82,81,77,79,77,76,74,75,76,79,78,74,70,69,68,69,68,68,68,70,73,76,78,78,76,74,73,70,67,64,62,58,53,51,46,42,35,22,8,10,20,27,27,27,21,17,12,13,14,14,13,10,8,6,5,6,11,22,41,66,87,100,
105,106,106,106,106,107,107,95,61,28,14,14,15,16,17,15,13,14,19,24,24,21,12,21,45,55,57,60,66,70,74,76,80,82,81,81,80,82,82,83,82,83,82,82,80,76,76,78,76,73,71,71,71,74,74,73,75,78,78,78,77,77,75,73,72,72,69,66,62,58,53,49,44,38,31,18,7,11,23,30,29,29,26,21,13,14,15,14,13,11,9,8,7,7,7,6,7,11,21,37,
106,107,107,107,107,100,78,40,14,14,16,16,16,16,17,14,13,13,18,25,27,23,14,12,32,49,55,60,64,69,72,74,77,81,83,84,84,82,83,82,80,81,83,85,85,84,83,80,79,79,78,79,81,81,80,78,77,77,77,78,77,77,76,74,72,72,70,65,62,58,52,47,43,37,27,14,7,15,28,34,32,29,26,23,17,15,15,15,13,11,9,9,7,7,7,7,8,9,8,8,
106,106,103,94,76,49,22,10,12,19,19,17,15,16,16,14,12,14,17,24,26,24,20,10,19,39,50,56,60,65,69,73,75,78,82,83,83,82,82,82,80,80,79,80,81,79,80,79,78,77,77,77,78,78,78,78,77,78,79,80,80,78,75,73,72,70,67,63,60,56,51,46,42,33,23,12,7,18,28,30,30,32,31,30,22,15,16,16,14,11,10,9,8,8,8,8,8,9,9,10,
};


void enable_serial()
{
	// enable the serial device.
	__ajit_write_serial_control_register__ ( TX_ENABLE | RX_ENABLE | RX_INTR_ENABLE );
	ee_printf("enabled serial.\n"); 
}

void main () 
{
	
		
	int n = N;		
	int i = 0, j = 0, kernel_size = 4;

	uint32_t start_time = ajit_barebones_clock();

	sconv(img, 16, n, kernel, res);		//asm subroutine (for 8bit signed)

	//print_matrix_u8(kernel, n, n);
	
	uint32_t end_time   = ajit_barebones_clock();
	ee_printf("main: start_time=%d, end_time=%d, elapsed=%d\n", 
				start_time, end_time, end_time-start_time);

	print_matrix_8(res, n-kernel_size+1, n-kernel_size+1);
}

void print_matrix(int* m, int x, int y)
{
	int i = 0, j = 0;
	int temp = 0;
	for(i = 0; i < x ; i++)
	{
		for(j = 0; j < y ; j++)
		{
			ee_printf("%d,",*(m+temp) );
			temp++;
		}
	ee_printf("\n");
	}
}

void print_matrix_8(char* m, int x, int y)
{
	int i = 0, j = 0;
	int temp = 0;
	for(i = 0; i < x ; i++)
	{
		for(j = 0; j < y ; j++)
		{
			ee_printf("%i, ",(char) *(m+temp) );
			temp++;
		}
	ee_printf("\n");
	}
}
