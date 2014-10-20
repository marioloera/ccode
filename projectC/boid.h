//  boild.h
//  Created by Mario Loera Lozano on 10/20/14.
//  EL2310 C project Boild Algorithm
//  Copyright (c) 2014 kth. All rights reserved.


#ifndef test_boild_h
#define test_boild_h
    //cretete text file for parametes
    void write_parameters(){

        double k_centre = 0.005; //0.005
        double k_cohesion = 0.005;//0.005
        double  k_target = 0.08;//0.08;
        double V_MAX = 25.0; //5.0
        double REPULSION_DISTANCE = 30.0;
        double k_repulsion = 0.2;

        printf("creat file parameters_boids.txt\n ");
        FILE *fw = NULL;
        fw = fopen("parameters_boids.txt", "w");
        /////////////////CREATE A FILE/////////////////
        fprintf(fw,"k_centre = %lf\nk_repulsion = %lf\nk_cohesion = %lf\nk_target = %lf\nV_MAX = %lf\nREPULSION_DISTANCE =%lf",k_centre, k_repulsion, k_cohesion ,k_target,V_MAX,REPULSION_DISTANCE);
        fclose(fw);
        return;
    }

    //update parameters from text file
    double * read_parameters(){
        static double parameters[6];//static point to store the parameter and acces with pointer
        /*
        * param    = k_centre
        * (param+1)= k_repulsion
        * (param+2)= k_cohesion
        * (param+3)= k_target
        * (param+4)= V_MAX
        * (param+5)= REPULSION_DISTANCE
        */
        /////////////////READ A FILE/////////////////
        FILE *fr = NULL;
        fr = fopen("parameters_boids.txt", "r");
        fscanf(fr, "k_centre = %lf\nk_repulsion = %lf\nk_cohesion = %lf\nk_target = %lf\nV_MAX = %lf\nREPULSION_DISTANCE = %lf",&parameters[0],&parameters[1],&parameters[2],&parameters[3],&parameters[4],&parameters[5]);
        fclose(fr);
        //printf("I read parameters: %lf %lf %lf %lf %lf %lf \n",parameters[0],parameters[1],parameters[2],parameters[3],parameters[4],parameters[5]);
        return &parameters[0];//return a point to the first element of the array
    }

    //clamp functions
        int clamp_int(int value, int low, int high){
            return value < low ? low : (value > high ? high : value);
        }
        double clamp_double(double value, double low, double high){
            return value < low ? low : (value > high ? high : value);
        }


        //general structure coordinates x y z
        struct coordinates{
            double x;
            double y;
            double z;
        };
        struct coordinates p_target;//stru for target pos, mouse
        struct coordinates p_average;//postion average
        struct coordinates v_average;//velocity average
        struct coordinates dif;//calculate the distances

    //structure for storage the the boild[N]; with all the elements of positions and velocities
    struct boid{
        struct coordinates pos;
        struct coordinates vel;
        struct coordinates v_cen;
        struct coordinates v_rep;
        struct coordinates v_coh;
        struct coordinates v_tar;
    };

    /*
    //delay funtion
    void delay(int max){
        max=clamp_int(max,1,5);
        long int i;
        for (i=0;i<100000000*max;i++){//printf("\ni=%d\n",i);
        }
        return;
    }
    */

#endif
