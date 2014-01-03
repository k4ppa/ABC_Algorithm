#ifndef COSTANT_H_
#define COSTANT_H_

#define SN 10
#define NUMBER_OF_EMPLOYED 5
#define NUMBER_OF_ONLOOKER SN-NUMBER_OF_EMPLOYED
#define D 10
#define LIMIT 200
#define MAX_CYCLES 30000
#define TOURNAMENT_SIZE_RATE 30
#define calcolateTournamentSize() (((NUMBER_OF_EMPLOYED / 100) * TOURNAMENT_SIZE_RATE) < 1? 1 : ((NUMBER_OF_EMPLOYED / 100) * TOURNAMENT_SIZE_RATE))

#define SPHERE 1
#define ROSENBROCK 2
#define ACKLEY 3
#define GRIEWANK 4
#define WEIERSTRASS 5
#define RASTRIGIN 6
#define NON_CONTINUOUS_RASTRIGIN 7
#define SCHWEFEL 8

#define FUNCTION SPHERE

#endif
