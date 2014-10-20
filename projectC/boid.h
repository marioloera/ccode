//  boild.h
//  Created by Mario Loera Lozano on 10/20/14.
//  Copyright (c) 2014 kth. All rights reserved.

#ifndef test_boild_h
#define test_boild_h
    //cretete text file for parametes
    void write_parameters(){

        double k_centre = 0.005; //0.005
        double k_repulsion = 0.5;
        double k_cohesion = 0.00025;
        double  k_target = 0.08;//0.08;
        double V_MAX = 5.0; //5.0
        double REPULSION_DISTANCE = 30.0;

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

    //delay funtion
    void delay(int max){
        max=clamp_int(max,1,5);
        long int i;
        for (i=0;i<100000000*max;i++){//printf("\ni=%d\n",i);
        }
        return;
    }

    //structure for storage the the boild[N];
    struct position{
        double x;
        double y;
        double z;
    };
    struct velocity{
        double x;
        double y;
        double z;
    };
    struct velocity_centering{
        double x;
        double y;
        double z;
    };
    struct velocity_repulsion{
        double x;
        double y;
        double z;
    };
    struct velocity_cohesion{
        double x;
        double y;
        double z;
    };
    struct velocity_target{
        double x;
        double y;
        double z;
    };
    struct boid{
        struct position pos;
        struct velocity vel;
        struct velocity_centering v_cen;
        struct velocity_repulsion v_rep;
        struct velocity_cohesion v_coh;
        struct velocity_target v_tar;
    };
    //structure for genral x y
    struct general_xy{
        double x;
        double y;
        double z;
    };
    struct general_xy p_target;//stru for target pos, mouse
    struct general_xy p_average;//postion average
    struct general_xy v_average;//velocity average


#endif
